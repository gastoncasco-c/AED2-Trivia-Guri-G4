#ifndef TESTADISTICAS_H
#define TESTADISTICAS_H

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "tHistorial.h"

FILE *archHistorial;
tRegistroRespuesta regHist;
tGuri claveGuri;
tGuri mejorGuri;

int puntosGuri, aciertosGuri, respondidasGuri;
int totalGeneralPuntos, maxPuntos;

void leerRegistroHist() {
    fread(&regHist, sizeof(tRegistroRespuesta), 1, archHistorial);
}

void inicializarCorte() {
    archHistorial = fopen("Historial.dat", "rb");
    totalGeneralPuntos = 0;
    maxPuntos = -1;
    strcpy(mejorGuri, "Ninguno");

    printf("\n======================================================\n");
    printf("   INFORME ESTADISTICO POR GURI \n");
    printf("======================================================\n");
    leerRegistroHist();
}

void inicioCorte() {
    puntosGuri = 0;
    aciertosGuri = 0;
    respondidasGuri = 0;
    strcpy(claveGuri, regHist.guri);
    printf("\nGuri: %s\n", claveGuri);
}

void calcularRequerimientos() {
    respondidasGuri++;
    puntosGuri += regHist.puntosObtenidos;
    if (regHist.acerto) {
        aciertosGuri++;
    }
}

void finCorte() {
    float efectividad = (respondidasGuri > 0) ? ((float)aciertosGuri / respondidasGuri) * 100.0 : 0.0;

    printf("  -> Preguntas respondidas: %d | Aciertos: %d (%.1f%%) | Puntaje total: %d pts\n",
           respondidasGuri, aciertosGuri, efectividad, puntosGuri);

    totalGeneralPuntos += puntosGuri;

    if (puntosGuri > maxPuntos) {
        maxPuntos = puntosGuri;
        strcpy(mejorGuri, claveGuri);
    }
}

void finalizacionCorte() {
    printf("\n------------------------------------------------------\n");
    printf("PUNTAJE ACUMULADO GLOBAL: %d pts\n", totalGeneralPuntos);
    printf("MEJOR GURI:  %s (%d pts)\n", mejorGuri, (maxPuntos < 0 ? 0 : maxPuntos));
    printf("======================================================\n");
    fclose(archHistorial);
}

void emitirInformeCorteControl() {
    inicializarCorte();
    if (archHistorial == NULL) {
        printf("Aun no existen partidas guardadas en Historial.dat.\n");
        return;
    }
    if (feof(archHistorial)) {
        printf("El archivo Historial.dat esta vacio.\n");
        fclose(archHistorial);
        return;
    }

    while (!feof(archHistorial)) {
        inicioCorte();
        while (!feof(archHistorial) && strcmp(regHist.guri, claveGuri) == 0) {
            calcularRequerimientos();
            leerRegistroHist();
        }
        finCorte();
    }
    finalizacionCorte();
}

#endif
