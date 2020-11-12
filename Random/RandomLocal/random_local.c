/* Programa random_local.c que incluye unicamente el programa main */
// al ejecutarlo pide el numero de iteraciones
#include "random_local.h"

int main(int argc, char *argv[]){
    int misemilla, itera, i;
    if(argc != 3) {
        fprintf(stderr, "Uso: %s semilla iteraciones\n", argv[0]);
        exit(1);
    }
    misemilla = (long)atoi(argv[1]);
    itera = atoi(argv[2]);
    
    inicializa_random(misemilla); // llamada a otro procedimiento
    
    for(i = 0; i < itera; i++)
        printf("%d : %1.0f\n", i, obtiene_siguiente_random());
    exit(0);
} 