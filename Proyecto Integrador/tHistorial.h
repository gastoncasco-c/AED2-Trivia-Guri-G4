#ifndef THISTORIAL_H
#define THISTORIAL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tPreguntas.h"

typedef char tGuri[40];


typedef struct {
    tGuri guri;        
    tString categoria;
    tString enunciado;
    tString respuestaElegida;
    bool acerto;
    int puntosObtenidos;     
} tRegistroRespuesta;


typedef struct nodoHistorial {
    tRegistroRespuesta dato;
    struct nodoHistorial *siguiente;
} tListaHistorial;


void inicializarHistorial(tListaHistorial**);
bool historialVacio(tListaHistorial*);
void insertarRespuestaOrdenada(tListaHistorial**, tRegistroRespuesta);
void consultarRespuestasAnteriores(tListaHistorial*, tGuri);
int calcularPuntajeJugador(tListaHistorial*, tGuri);
void grabarHistorialArchivo(tListaHistorial*);
void cargarHistorialArchivo(tListaHistorial**);
void liberarHistorial(tListaHistorial**);


void inicializarHistorial(tListaHistorial **pLista) {
    *pLista = NULL;
}

bool historialVacio(tListaHistorial *pLista) {
    return (pLista == NULL);
}


void insertarRespuestaOrdenada(tListaHistorial **pLista, tRegistroRespuesta pDato) {
    tListaHistorial *nuevoNodo = (tListaHistorial*)malloc(sizeof(tListaHistorial));
    nuevoNodo->dato = pDato;
    nuevoNodo->siguiente = NULL;

    if (historialVacio(*pLista) || strcmp(pDato.guri, (*pLista)->dato.guri) < 0) {
        nuevoNodo->siguiente = *pLista;
        *pLista = nuevoNodo;
    } else {
        tListaHistorial *aux = *pLista;
        while (aux->siguiente != NULL && strcmp(aux->siguiente->dato.guri, pDato.guri) <= 0) {
            aux = aux->siguiente;
        }
        nuevoNodo->siguiente = aux->siguiente;
        aux->siguiente = nuevoNodo;
    }
}

void consultarRespuestasAnteriores(tListaHistorial *pLista, tGuri pguri) {
    tListaHistorial *aux = pLista;
    bool encontro = false;

    printf("\n=== HISTORIAL DE RESPUESTAS DE: %s ===\n", pguri);
    while (aux != NULL) {
        if (strcmp(aux->dato.guri, pguri) == 0) {
            encontro = true;
            printf("- [%s] %s\n", aux->dato.categoria, aux->dato.enunciado);
            printf("  Tu respuesta: %s -> %s (+%d pts)\n",
                   aux->dato.respuestaElegida,
                   aux->dato.acerto ? "CORRECTA" : "INCORRECTA",
                   aux->dato.puntosObtenidos);
        }
        aux = aux->siguiente;
    }
    if (!encontro) {
        printf("No se encontraron respuestas registradas para este guri.\n");
    }
}

int calcularPuntajeJugador(tListaHistorial *pLista, tGuri pguri) {
    tListaHistorial *aux = pLista;
    int total = 0;
    while (aux != NULL) {
        if (strcmp(aux->dato.guri, pguri) == 0) {
            total += aux->dato.puntosObtenidos;
        }
        aux = aux->siguiente;
    }
    return total;
}

void grabarHistorialArchivo(tListaHistorial *pLista) {
    FILE *arch = fopen("Historial.dat", "wb");
    tListaHistorial *aux = pLista;
    if (arch != NULL) {
        while (aux != NULL) {
            fwrite(&(aux->dato), sizeof(tRegistroRespuesta), 1, arch);
            aux = aux->siguiente;
        }
        fclose(arch);
    }
}

void cargarHistorialArchivo(tListaHistorial **pLista) {
    FILE *arch = fopen("Historial.dat", "rb");
    tRegistroRespuesta reg;
    inicializarHistorial(pLista);
    if (arch != NULL) {
        while (fread(&reg, sizeof(tRegistroRespuesta), 1, arch) == 1) {
            insertarRespuestaOrdenada(pLista, reg);
        }
        fclose(arch);
    }
}

void liberarHistorial(tListaHistorial **pLista) {
    tListaHistorial *aux = *pLista;
    tListaHistorial *sig;
    while (aux != NULL) {
        sig = aux->siguiente;
        free(aux);
        aux = sig;
    }
    *pLista = NULL;
}

#endif
