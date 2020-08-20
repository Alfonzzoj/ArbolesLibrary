#include <stdio.h>
#include "Arboles.h"

int main()
{
    nodo_t *arbol = NULL;
    int e;

    insertar(&arbol, 50);
    insertar(&arbol, 25);
    insertar(&arbol, 55);
    insertar(&arbol, 10);
    insertar(&arbol, 26);
    insertar(&arbol, 25);
    insertar(&arbol, 52);
    insertar(&arbol, 56);

    printf(" CosteMAX %d \n", maxCosto(arbol));

    imprimirNivel(arbol, 3);
    return 0;
}