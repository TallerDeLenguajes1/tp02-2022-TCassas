#include <stdio.h>
#define M 5

typedef struct PC {
    int velocidadGhz;
    int anioFabricacion;
    char *tipoProcesador;
    int nucleos;
} PC;

int getAnio();
void printComputadora(PC computadora);
void printComputadoras(PC * computadoras);
void printComputadoraMasVieja(PC * computadora);
void printComputadoraMasRapida(PC * computadora);

int main() {
    PC computadoras[M];
    char tiposProcesador[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};
    
    int i;
    for(i = 0; i < M; i++) {
        computadoras[i].velocidadGhz = (1 + rand() % 3);
        computadoras[i].anioFabricacion = getAnio(2015, 2022);
        computadoras[i].tipoProcesador = tiposProcesador[rand() % 6];
        computadoras[i].nucleos = (1 + rand() % 8);
    }
    
    printComputadoras(computadoras);
    printf("\nLa computadora con el menor año de fabricacion es:\n");
    printComputadoraMasVieja(computadoras);
    printf("\nLa computadora mas rapida es:\n");
    printComputadoraMasRapida(computadoras);
    
    return 0;
}

void printComputadoras(PC * computadoras) {
    int i;
    for(i = 0; i < M; i++) {
        printf("-- PC %d --\n", i);
        printComputadora(computadoras[i]);
    }
}

void printComputadoraMasVieja(PC * computadoras) {
    PC computadoraAux = computadoras[0];
    int i;
    for(i = 0; i < M; i++) {
        if(computadoras[i].anioFabricacion <= computadoraAux.anioFabricacion) {
            computadoraAux = computadoras[i];
        }
    }
    printComputadora(computadoraAux);
}

void printComputadoraMasRapida(PC * computadoras) {
    PC computadoraAux = computadoras[0];
    int i;
    for(i = 0; i < M; i++) {
        if(computadoras[i].velocidadGhz >= computadoraAux.velocidadGhz) {
            computadoraAux = computadoras[i];
        }
    }
    printComputadora(computadoraAux);
}

void printComputadora(PC computadora) {
    printf("Velocidad Ghz.: %d\n", computadora.velocidadGhz);
    printf("Año de fabricación: %d\n", computadora.anioFabricacion);
    printf("Cantidad de nucleos: %d\n", computadora.nucleos);
    printf("Tipo procesador: %s\n", computadora.tipoProcesador);
    printf("\n");
}

int getAnio(int min, int max) {
    int diferencia = max - min;
    return (1 + rand() % diferencia) + min;
}