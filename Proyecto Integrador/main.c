#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h> 

#include "tPreguntas.h"
#include "tHistorial.h"
#include "tEstadisticas.h"

void seleccionarCategoria(tString catDestino) {
    int op;
    printf("\nSeleccione categoria:\n");
    printf("1. Matematicas\n2. Lengua\n3. Ciencias Naturales\n4. Ciencias Sociales\nOpcion: ");
    scanf("%d", &op);
    switch (op) {
        case 1: strcpy(catDestino, "Matematicas"); break;
        case 2: strcpy(catDestino, "Lengua"); break;
        case 3: strcpy(catDestino, "Ciencias Naturales"); break;
        case 4: strcpy(catDestino, "Ciencias Sociales"); break;
        default: strcpy(catDestino, "Matematicas"); break;
    }
}

int main() {
    srand(time(NULL));

    tBancoPreguntas banco;
    tListaHistorial *listaHistorial;
    tGuri guriActual;
    tString categoriaElegida;
    int opcion;

    leerPreguntasArchivo(&banco);
	if (banco.cantidad < 120) {
    cargarBancoInicial(&banco);
    grabarPreguntasArchivo(banco);
}

    cargarHistorialArchivo(&listaHistorial);

    printf("Ingrese su nombre de guri (sin espacios): ");
    scanf("%s", guriActual);
    reiniciarPreguntasUsadas(&banco);

    do {
        printf("\n=== TRIVIA GURI - GURI: %s ===\n", guriActual);
        printf("1. Elegir categoria y responder ronda de 10 preguntas\n");
        printf("2. Mostrar mi puntaje actual\n");
        printf("3. Consultar mis respuestas anteriores\n");
        printf("4. Cambiar de guri (reinicia preguntas usadas)\n");
        printf("5. Ver Ranking e Informe General (Corte de Control)\n");
        printf("0. Guardar y Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: {
                seleccionarCategoria(categoriaElegida);
                printf("\n--- INICIANDO RONDA DE 10 PREGUNTAS DE %s ---\n", categoriaElegida);
                
                int ronda;

             
                for (ronda = 1; ronda <= 10; ronda++) {
                    int id = buscarPreguntaDisponible(&banco, categoriaElegida);

                    if (id == -1) {
                        printf("\nYa no quedan mas preguntas disponibles de %s en esta partida!\n", categoriaElegida);
                        break; 
                    }

                    int respGuri;
                    printf("\n[Pregunta %d/10 - %s] %s\n", ronda, banco.lista[id].categoria, banco.lista[id].enunciado);
                    printf("  1) %s\n", banco.lista[id].opciones[0]);
                    printf("  2) %s\n", banco.lista[id].opciones[1]);
                    printf("  3) %s\n", banco.lista[id].opciones[2]);

                    
                    do {
                        printf("Tu respuesta (1-3): ");
                        scanf("%d", &respGuri);
                        if (respGuri < 1 || respGuri > 3) {
                            printf("Opcion invalida. Debes elegir 1, 2 o 3.\n");
                        }
                    } while (respGuri < 1 || respGuri > 3);

                    tRegistroRespuesta reg;
                    strcpy(reg.guri, guriActual);
                    strcpy(reg.categoria, banco.lista[id].categoria);
                    strcpy(reg.enunciado, banco.lista[id].enunciado);
                    strcpy(reg.respuestaElegida, banco.lista[id].opciones[respGuri - 1]);

                    if ((respGuri - 1) == banco.lista[id].respuestaCorrecta) {
                        printf("Correcto! Sumaste 10 puntos.\n");
                        reg.acerto = true;
                        reg.puntosObtenidos = 10;
                    } else {
                        printf("Incorrecto. La respuesta correcta era: %s\n",
                               banco.lista[id].opciones[banco.lista[id].respuestaCorrecta]);
                        reg.acerto = false;
                        reg.puntosObtenidos = 0;
                    }

                    insertarRespuestaOrdenada(&listaHistorial, reg);
                    grabarHistorialArchivo(listaHistorial);
                }
                printf("\n--- FIN DE LA RONDA DE 10 PREGUNTAS ---\n");
                break;
            }
            case 2: {
                int pts = calcularPuntajeJugador(listaHistorial, guriActual);
                printf("\nPuntaje acumulado de %s: %d puntos.\n", guriActual, pts);
                break;
            }
            case 3: {
                consultarRespuestasAnteriores(listaHistorial, guriActual);
                break;
            }
            case 4: {
                printf("\nIngrese el nuevo nombre de guri: ");
                scanf("%s", guriActual);
                reiniciarPreguntasUsadas(&banco);
                printf("Turno iniciado para %s. Preguntas disponibles reiniciadas.\n", guriActual);
                break;
            }
            case 5: {
                grabarHistorialArchivo(listaHistorial);
                emitirInformeCorteControl();
                break;
            }
            case 0: {
                grabarHistorialArchivo(listaHistorial);
                liberarHistorial(&listaHistorial);
                printf("\nDatos guardados en Historial.dat. Hasta luego!\n");
                break;
            }
            default:
                printf("\nOpcion invalida.\n");
        }
    } while (opcion != 0);

    return 0;
}
