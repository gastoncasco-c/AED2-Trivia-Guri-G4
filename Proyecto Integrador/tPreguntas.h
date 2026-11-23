#ifndef TPREGUNTAS_H
#define TPREGUNTAS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PREGUNTAS 200
#define MAX_STR 200

typedef char tString[MAX_STR];

typedef struct {
    tString categoria;          
    tString enunciado;
    tString opciones[3];        
    int respuestaCorrecta;     
    bool usada;                 
} tPregunta;

typedef struct {
    tPregunta lista[MAX_PREGUNTAS];
    int cantidad;
} tBancoPreguntas;


void inicializarBanco(tBancoPreguntas*);
void agregarPregunta(tBancoPreguntas*, const char*, const char*, const char*, const char*, const char*, int);
void cargarBancoInicial(tBancoPreguntas*);
void grabarPreguntasArchivo(tBancoPreguntas);
void leerPreguntasArchivo(tBancoPreguntas*);
void reiniciarPreguntasUsadas(tBancoPreguntas*);
int buscarPreguntaDisponible(tBancoPreguntas*, tString);


void inicializarBanco(tBancoPreguntas *pBanco) {
    pBanco->cantidad = 0;
}

void agregarPregunta(tBancoPreguntas *pBanco, const char *cat, const char *enun,const char *op0, const char *op1, const char *op2, int correcta) {
    if (pBanco->cantidad < MAX_PREGUNTAS) {
        tPregunta p;
        strcpy(p.categoria, cat);
        strcpy(p.enunciado, enun);
        strcpy(p.opciones[0], op0);
        strcpy(p.opciones[1], op1);
        strcpy(p.opciones[2], op2);
        p.respuestaCorrecta = correcta;
        p.usada = false;
        pBanco->lista[pBanco->cantidad++] = p;
    }
}

void cargarBancoInicial(tBancoPreguntas *pBanco) {
    inicializarBanco(pBanco);

    agregarPregunta(pBanco, "Lengua", "Cuantas vocales tiene el abecedario?", "3", "5", "7", 1);
    agregarPregunta(pBanco, "Lengua", "Cual de estas palabras es un sustantivo?", "Correr", "Perro", "Bonito", 1);
    agregarPregunta(pBanco, "Lengua", "Cual es el sinonimo de feliz?", "Triste", "Contento", "Enojado", 1);
    agregarPregunta(pBanco, "Lengua", "Cual es el antonimo (opuesto) de grande?", "Enorme", "Pequeno", "Alto", 1);
    agregarPregunta(pBanco, "Lengua", "Que signo se usa al final de una pregunta?", "!", "?", ".", 1);
    agregarPregunta(pBanco, "Lengua", "Como se llama la palabra que indica una accion?", "Verbo", "Adjetivo", "Articulo", 0);
    agregarPregunta(pBanco, "Lengua", "Cual de estas palabras es un adjetivo?", "Mesa", "Saltar", "Rojo", 2);
    agregarPregunta(pBanco, "Lengua", "Cuantas silabas tiene la palabra MA-RI-PO-SA?", "3", "4", "5", 1);
    agregarPregunta(pBanco, "Lengua", "Con que letra empiezan los nombres propios?", "Minuscula", "Mayuscula", "Numero", 1);
    agregarPregunta(pBanco, "Lengua", "Cual es el plural de la palabra LAPIZ?", "Lapizs", "Lapices", "Los lapiz", 1);
    agregarPregunta(pBanco, "Lengua", "Que palabra rima con GATO?", "Perro", "Pato", "Casa", 1);
    agregarPregunta(pBanco, "Lengua", "Cual de estas palabras esta bien escrita?", "Avion", "Abion", "Habion", 0);
    agregarPregunta(pBanco, "Lengua", "Como se llaman las historias con animales que dejan una ensenanza?", "Fabulas", "Noticias", "Recetas", 0);
    agregarPregunta(pBanco, "Lengua", "Cual es el femenino de CABALLO?", "Caballa", "Yegua", "Vaca", 1);
    agregarPregunta(pBanco, "Lengua", "Cual es el diminutivo de CASA?", "Casona", "Casita", "Casero", 1);
    agregarPregunta(pBanco, "Lengua", "Que letra va siempre despues de la Q?", "A", "U", "O", 1);
    agregarPregunta(pBanco, "Lengua", "Cual de estos es un articulo?", "El", "Saltar", "Rapido", 0);
    agregarPregunta(pBanco, "Lengua", "Donde buscamos el significado de las palabras?", "En el atlas", "En el diccionario", "En el calendario", 1);
    agregarPregunta(pBanco, "Lengua", "Cual es el sinonimo de RAPIDO?", "Lento", "Veloz", "Pesado", 1);
    agregarPregunta(pBanco, "Lengua", "Cuantas letras tiene la palabra SOL?", "2", "3", "4", 1);
    agregarPregunta(pBanco, "Lengua", "Que signo usamos para expresar sorpresa o alegria?", "?", "!", ",", 1);
    agregarPregunta(pBanco, "Lengua", "Cual es el antonimo de FRIO?", "Helado", "Caliente", "Tibio", 1);
    agregarPregunta(pBanco, "Lengua", "En que tiempo esta el verbo COMERE?", "Pasado", "Presente", "Futuro", 2);
    agregarPregunta(pBanco, "Lengua", "Cual de estas palabras es aguda (acento en la ultima silaba)?", "Arbol", "Cancion", "Pajaro", 1);
    agregarPregunta(pBanco, "Lengua", "Como se llama el personaje principal de un cuento?", "Protagonista", "Autor", "Editor", 0);
    agregarPregunta(pBanco, "Lengua", "Cual es el plural de PEZ?", "Pezs", "Peces", "Peses", 1);
    agregarPregunta(pBanco, "Lengua", "Que palabra completa la frase: El pajaro ____ alto?", "vuela", "nada", "ladra", 0);
    agregarPregunta(pBanco, "Lengua", "Cual es la primera letra del abecedario?", "B", "A", "Z", 1);
    agregarPregunta(pBanco, "Lengua", "Como se dice cuando dos palabras significan lo mismo?", "Sinonimos", "Antonimos", "Verbos", 0);
    agregarPregunta(pBanco, "Lengua", "Quien escribio Romeo y Julieta?", "Cervantes", "Einstein", "Shakespeare", 2);


    agregarPregunta(pBanco, "Matematicas", "Cuanto es 5 + 7?", "11", "12", "13", 1);
    agregarPregunta(pBanco, "Matematicas", "Cuanto es 15 - 6?", "8", "9", "10", 1);
    agregarPregunta(pBanco, "Matematicas", "Cuanto es 3 x 4?", "7", "12", "14", 1);
    agregarPregunta(pBanco, "Matematicas", "Cuantos lados tiene un triangulo?", "3", "4", "5", 0);
    agregarPregunta(pBanco, "Matematicas", "Cuanto es la mitad de 20?", "5", "10", "15", 1);
    agregarPregunta(pBanco, "Matematicas", "Cuanto es 10 + 10 + 10?", "20", "30", "40", 1);
    agregarPregunta(pBanco, "Matematicas", "Cuanto es 8 x 7?", "54", "56", "64", 1);
    agregarPregunta(pBanco, "Matematicas", "Cuantos minutos tiene una hora?", "30", "60", "100", 1);
    agregarPregunta(pBanco, "Matematicas", "Que numero sigue despues del 99?", "98", "100", "101", 1);
    agregarPregunta(pBanco, "Matematicas", "Cuantos lados iguales tiene un cuadrado?", "2", "3", "4", 2);
    agregarPregunta(pBanco, "Matematicas", "Cuanto es 20 dividido 2?", "5", "10", "12", 1);
    agregarPregunta(pBanco, "Matematicas", "Cual es el doble de 8?", "14", "16", "18", 1);
    agregarPregunta(pBanco, "Matematicas", "Cuanto es 9 x 2?", "16", "18", "20", 1);
    agregarPregunta(pBanco, "Matematicas", "Si tengo 10 caramelos y como 3, cuantos me quedan?", "6", "7", "8", 1);
    agregarPregunta(pBanco, "Matematicas", "Cuantos centimetros tiene un metro?", "10", "100", "1000", 1);
    agregarPregunta(pBanco, "Matematicas", "Que figura geometrica tiene forma de pelota?", "Cubo", "Esfera", "Piramide", 1);
    agregarPregunta(pBanco, "Matematicas", "Cuanto es 5 x 5?", "20", "25", "30", 1);
    agregarPregunta(pBanco, "Matematicas", "Cual de estos numeros es PAR?", "7", "13", "14", 2);
    agregarPregunta(pBanco, "Matematicas", "Cuanto es 100 - 25?", "65", "75", "85", 1);
    agregarPregunta(pBanco, "Matematicas", "Cuantos meses tiene un ano?", "10", "12", "14", 1);
    agregarPregunta(pBanco, "Matematicas", "Cuanto es 6 x 3?", "15", "18", "21", 1);
    agregarPregunta(pBanco, "Matematicas", "Que numero vale nada por si solo?", "0", "1", "10", 0);
    agregarPregunta(pBanco, "Matematicas", "Cuanto es 144 dividido 12?", "10", "11", "12", 2);
    agregarPregunta(pBanco, "Matematicas", "Si una semana tiene 7 dias, cuantos dias tienen 2 semanas?", "12", "14", "21", 1);
    agregarPregunta(pBanco, "Matematicas", "Cuanto es 50 + 50?", "100", "150", "200", 0);
    agregarPregunta(pBanco, "Matematicas", "Cuantos lados tiene un pentagono?", "4", "5", "6", 1);
    agregarPregunta(pBanco, "Matematicas", "Cual de estos numeros es IMPAR?", "4", "8", "9", 2);
    agregarPregunta(pBanco, "Matematicas", "Cuanto es 7 x 10?", "17", "70", "700", 1);
    agregarPregunta(pBanco, "Matematicas", "Cuanto es 18 dividido 3?", "5", "6", "7", 1);
    agregarPregunta(pBanco, "Matematicas", "Cuantas decenas hay en el numero 40?", "4", "10", "40", 0);


    agregarPregunta(pBanco, "Ciencias Naturales", "Que organo bombea la sangre en el cuerpo humano?", "Pulmon", "Corazon", "Higado", 1);
    agregarPregunta(pBanco, "Ciencias Naturales", "Que tipo de animal es la ballena?", "Pez", "Mamifero", "Anfibio", 1);
    agregarPregunta(pBanco, "Ciencias Naturales", "Que necesitan las plantas del sol para fabricar su alimento?", "Luz", "Fuego", "Viento", 0);
    agregarPregunta(pBanco, "Ciencias Naturales", "Cuantas patas tiene una arana?", "6", "8", "10", 1);
    agregarPregunta(pBanco, "Ciencias Naturales", "Cual es el planeta mas grande del Sistema Solar?", "Tierra", "Marte", "Jupiter", 2);
    agregarPregunta(pBanco, "Ciencias Naturales", "Que gas respiramos para poder vivir?", "Oxigeno", "Helio", "Humo", 0);
    agregarPregunta(pBanco, "Ciencias Naturales", "Como se llama el cambio de oruga a mariposa?", "Metamorfosis", "Fotosintesis", "Evaporacion", 0);
    agregarPregunta(pBanco, "Ciencias Naturales", "Cual es el animal terrestre mas rapido del mundo?", "Leon", "Guepardo", "Caballo", 1);
    agregarPregunta(pBanco, "Ciencias Naturales", "En que estado esta el agua cuando es hielo?", "Liquido", "Solido", "Gaseoso", 1);
    agregarPregunta(pBanco, "Ciencias Naturales", "Que parte de la planta absorbe el agua de la tierra?", "La hoja", "La flor", "La raiz", 2);
    agregarPregunta(pBanco, "Ciencias Naturales", "Cuantos sentidos tiene el ser humano?", "4", "5", "6", 1);
    agregarPregunta(pBanco, "Ciencias Naturales", "Que organo usamos para respirar?", "Los pulmones", "El estomago", "Los rinones", 0);
    agregarPregunta(pBanco, "Ciencias Naturales", "Como se llaman los animales que solo comen plantas?", "Carnivoros", "Herbivoros", "Omnivoros", 1);
    agregarPregunta(pBanco, "Ciencias Naturales", "Cual es la estrella mas cercana a la Tierra?", "La Luna", "El Sol", "Marte", 1);
    agregarPregunta(pBanco, "Ciencias Naturales", "Que insecto fabrica la miel?", "La hormiga", "La abeja", "La mosca", 1);
    agregarPregunta(pBanco, "Ciencias Naturales", "De que color es la clorofila de las hojas?", "Roja", "Verde", "Azul", 1);
    agregarPregunta(pBanco, "Ciencias Naturales", "Como se llaman los animales que nacen de un huevo?", "Viviparos", "Oviparos", "Mamiferos", 1);
    agregarPregunta(pBanco, "Ciencias Naturales", "Que hueso protege nuestro cerebro?", "Las costillas", "El craneo", "El femur", 1);
    agregarPregunta(pBanco, "Ciencias Naturales", "Cual es el satelite natural de la Tierra?", "El Sol", "La Luna", "Venus", 1);
    agregarPregunta(pBanco, "Ciencias Naturales", "A que temperatura hierve el agua?", "50 grados", "100 grados", "200 grados", 1);
    agregarPregunta(pBanco, "Ciencias Naturales", "Que animal tiene el cuello mas largo?", "Elefante", "Jirafa", "Avestruz", 1);
    agregarPregunta(pBanco, "Ciencias Naturales", "Como se llaman los animales que tienen columna vertebral?", "Invertebrados", "Vertebrados", "Insectos", 1);
    agregarPregunta(pBanco, "Ciencias Naturales", "Que sentido usamos con los ojos?", "El oido", "La vista", "El olfato", 1);
    agregarPregunta(pBanco, "Ciencias Naturales", "Cual es el tercer planeta desde el Sol?", "Marte", "Tierra", "Venus", 1);
    agregarPregunta(pBanco, "Ciencias Naturales", "Que animales tienen plumas y pico?", "Los reptiles", "Las aves", "Los peces", 1);
    agregarPregunta(pBanco, "Ciencias Naturales", "Como se llama el agua que cae de las nubes?", "Rocio", "Lluvia", "Neblina", 1);
    agregarPregunta(pBanco, "Ciencias Naturales", "Que vitamina nos da principalmente la luz del sol?", "Vitamina C", "Vitamina D", "Vitamina A", 1);
    agregarPregunta(pBanco, "Ciencias Naturales", "Como se llama el conjunto de todos los huesos del cuerpo?", "Musculatura", "Esqueleto", "Piel", 1);
    agregarPregunta(pBanco, "Ciencias Naturales", "Que comen los animales carnivoros?", "Hierbas", "Carne", "Frutas", 1);
    agregarPregunta(pBanco, "Ciencias Naturales", "Por donde respiran los peces bajo el agua?", "Pulmones", "Branquias", "Nariz", 1);


    agregarPregunta(pBanco, "Ciencias Sociales", "Quien creo la bandera de Argentina?", "Jose de San Martin", "Manuel Belgrano", "Domingo F. Sarmiento", 1);
    agregarPregunta(pBanco, "Ciencias Sociales", "En que provincia argentina se declaro la Independencia en 1816?", "Cordoba", "Buenos Aires", "Tucuman", 2);
    agregarPregunta(pBanco, "Ciencias Sociales", "Cual es la capital de Argentina?", "Rosario", "Buenos Aires", "Mendoza", 1);
    agregarPregunta(pBanco, "Ciencias Sociales", "Que colores tiene la bandera argentina?", "Celeste y blanco", "Azul y rojo", "Verde y amarillo", 0);
    agregarPregunta(pBanco, "Ciencias Sociales", "Quien cruzo la Cordillera de los Andes para liberar paises?", "Manuel Belgrano", "Jose de San Martin", "Mariano Moreno", 1);
    agregarPregunta(pBanco, "Ciencias Sociales", "En que continente se encuentra Argentina?", "Europa", "America", "Asia", 1);
    agregarPregunta(pBanco, "Ciencias Sociales", "Que se celebra el 25 de Mayo en Argentina?", "El Dia de la Bandera", "La Revolucion de Mayo", "El Dia del Maestro", 1);
    agregarPregunta(pBanco, "Ciencias Sociales", "Como se llama la figura amarilla en el centro de la bandera argentina?", "Una estrella", "Un sol", "Una luna", 1);
    agregarPregunta(pBanco, "Ciencias Sociales", "Quien fue llamado el Padre del Aula por crear muchas escuelas?", "Sarmiento", "Belgrano", "San Martin", 0);
    agregarPregunta(pBanco, "Ciencias Sociales", "Cual es el oceano que bana las costas de Argentina?", "Oceano Pacifico", "Oceano Atlantico", "Oceano Indico", 1);
    agregarPregunta(pBanco, "Ciencias Sociales", "Como se llama el edificio donde trabaja el Presidente de Argentina?", "Casa Blanca", "Casa Rosada", "Cabildo", 1);
    agregarPregunta(pBanco, "Ciencias Sociales", "Que dia se celebra el Dia de la Bandera en Argentina?", "20 de Junio", "9 de Julio", "17 de Agosto", 0);
    agregarPregunta(pBanco, "Ciencias Sociales", "Cual es la flor nacional de Argentina?", "La rosa", "El ceibo", "El girasol", 1);
    agregarPregunta(pBanco, "Ciencias Sociales", "Que instrumento sirve para orientarnos y senala el Norte?", "El termometro", "La brujula", "El reloj", 1);
    agregarPregunta(pBanco, "Ciencias Sociales", "Cuantos puntos cardinales principales existen?", "2", "4", "6", 1);
    agregarPregunta(pBanco, "Ciencias Sociales", "Por donde sale el Sol cada manana?", "Por el Oeste", "Por el Este", "Por el Sur", 1);
    agregarPregunta(pBanco, "Ciencias Sociales", "Que edificio historico estaba frente a la Plaza de Mayo en 1810?", "El Obelisco", "El Cabildo", "El Congreso", 1);
    agregarPregunta(pBanco, "Ciencias Sociales", "Como se llama la danza tipica mas famosa de Argentina?", "Samba", "Tango", "Cueca", 1);
    agregarPregunta(pBanco, "Ciencias Sociales", "Que cordillera separa a Argentina de Chile?", "Los Alpes", "Los Andes", "El Himalaya", 1);
    agregarPregunta(pBanco, "Ciencias Sociales", "Quien descubrio America en el ano 1492?", "Fernando de Magallanes", "Cristobal Colon", "Americo Vespucio", 1);
    agregarPregunta(pBanco, "Ciencias Sociales", "Como se llama el documento que tiene las leyes mas importantes del pais?", "Constitucion Nacional", "Codigo Penal", "Diccionario", 0);
    agregarPregunta(pBanco, "Ciencias Sociales", "Que se celebra el 9 de Julio en Argentina?", "Dia de la Independencia", "Dia de la Tradicion", "Dia del Trabajador", 0);
    agregarPregunta(pBanco, "Ciencias Sociales", "Cual es el ave nacional de Argentina?", "El condor", "El hornero", "El aguila", 1);
    agregarPregunta(pBanco, "Ciencias Sociales", "Como se llama el polo que esta mas al sur de la Tierra?", "Polo Norte", "Antartida", "Ecuador", 1);
    agregarPregunta(pBanco, "Ciencias Sociales", "Que medio de transporte anda sobre rieles?", "El avion", "El tren", "El barco", 1);
    agregarPregunta(pBanco, "Ciencias Sociales", "En que estacion del ano hace mas calor?", "Invierno", "Verano", "Otono", 1);
    agregarPregunta(pBanco, "Ciencias Sociales", "Que color del semaforo indica que debemos detenernos?", "Verde", "Amarillo", "Rojo", 2);
    agregarPregunta(pBanco, "Ciencias Sociales", "Como se llama la linea imaginaria que divide la Tierra en Norte y Sur?", "Meridiano", "Ecuador", "Tropico", 1);
    agregarPregunta(pBanco, "Ciencias Sociales", "Quien escribio la letra del Himno Nacional Argentino?", "Vicente Lopez y Planes", "Blas Parera", "Esteban Echeverria", 0);
    agregarPregunta(pBanco, "Ciencias Sociales", "Que bebida tradicional argentina se toma con bombilla?", "Cafe", "Mate", "Te", 1);
}

void grabarPreguntasArchivo(tBancoPreguntas pBanco) {
    FILE *arch = fopen("Preguntas.dat", "wb");
    if (arch != NULL) {
        fwrite(&pBanco, sizeof(tBancoPreguntas), 1, arch);
        fclose(arch);
    }
}

void leerPreguntasArchivo(tBancoPreguntas *pBanco) {
    FILE *arch = fopen("Preguntas.dat", "rb");
    if (arch != NULL) {
        fread(pBanco, sizeof(tBancoPreguntas), 1, arch);
        fclose(arch);
    } else {
        inicializarBanco(pBanco);
    }
}

void reiniciarPreguntasUsadas(tBancoPreguntas *pBanco) {
    int i;
    for (i = 0; i < pBanco->cantidad; i++) {
        pBanco->lista[i].usada = false;
    }
}

int buscarPreguntaDisponible(tBancoPreguntas *pBanco, tString pCategoria) {
    int disponibles[MAX_PREGUNTAS];
    int totalDisp = 0;
    int i;


    for (i = 0; i < pBanco->cantidad; i++) {
        if (strcmp(pBanco->lista[i].categoria, pCategoria) == 0 && pBanco->lista[i].usada == false) {
            disponibles[totalDisp] = i;
            totalDisp++;
        }
    }


    if (totalDisp == 0) {
        return -1;
    }

 
    int posAzar = rand() % totalDisp;
    int indiceElegido = disponibles[posAzar];

    pBanco->lista[indiceElegido].usada = true;
    return indiceElegido;
}

#endif
