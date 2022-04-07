#include <stdio.h>
#define M 5

typedef struct PC {
    int velocidadGhz;
    int anioFabricacion;
    char *tipoProcesador;
    int nucleos;
} PC;

int getAnio();
void printComputadoras(PC * computadoras);

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
    
    return 0;
}

void printComputadoras(PC * computadoras) {
    int i;
    for(i = 0; i < M; i++) {
        printf("-- PC %d --\n", i);
        printf("Velocidad Ghz.: %d\n", computadoras[i].velocidadGhz);
        printf("Año de fabricación: %d\n", computadoras[i].anioFabricacion);
        printf("Cantidad de nucleos: %d\n", computadoras[i].nucleos);
        printf("Tipo procesador: %s\n", computadoras[i].tipoProcesador);
        printf("\n");
    }
}

int getAnio(int min, int max) {
    int diferencia = max - min;
    return (1 + rand() % diferencia) + min;
}