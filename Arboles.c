#include "funcionesArboles.h"
/*
* Busca un elemento en un arbol binario
*/
int buscar(nodo_t *arbolbp, int elemento)
{
    if (arbolbp == NULL)
        return 0;
    if (elemento == arbolbp->elemento)
        return 1;
    if (elemento < arbolbp->elemento)
        return buscar(arbolbp->izq, elemento);
    else
        return buscar(arbolbp->der, elemento);
}
/*
* Inserta un elemento en un arbol binario
*/
int insertar(nodo_t **arbolbp, int elemento)
{
    if (*arbolbp == NULL)
    {
        *arbolbp = (nodo_t *)malloc(sizeof(nodo_t));
        (*arbolbp)->elemento = elemento;
        (*arbolbp)->izq = (*arbolbp)->der = NULL;
        return 1;
    }
    if (elemento == (*arbolbp)->elemento)
        return 0;
    if (elemento < (*arbolbp)->elemento)
        return insertar(&((*arbolbp)->izq), elemento);
    else
        return insertar(&((*arbolbp)->der), elemento);
}
/*
 *Imprime un arbol binario
 */
void imprimirNivel(nodo_t *arbolbp, int nivel)
{
    int i;
    if (arbolbp == NULL)
        return;
    imprimirNivel(arbolbp->der, nivel + 1);
    for (i = 0; i < nivel; i++)
        printf(" ");
    printf("%d\n", arbolbp->elemento);
    imprimirNivel(arbolbp->izq, nivel + 1);
}
/*
* Busca el menor elemento en un arbol binario
*/
int menor(nodo_t *arbolbp, int *elemento)
{
    if (arbolbp == NULL)
        return 0;
    while (arbolbp->izq != NULL)
        arbolbp = arbolbp->izq;
    *elemento = arbolbp->elemento;
    return 1;
}
/*
* Busca el mayor elemento en un arbol binario
*/
int mayor(nodo_t *arbolbp, int *elemento)
{
    if (arbolbp == NULL)
        return 0;
    while (arbolbp->der != NULL)
        arbolbp = arbolbp->der;
    *elemento = arbolbp->elemento;
    return 1;
}
/*
* Cuenta el numero de nodos en un arbol binario
*/
int nro_nodos(nodo_t *arbolbp)
{
    if (arbolbp == NULL)
        return 0;
    return nro_nodos(arbolbp->izq) + nro_nodos(arbolbp->der) + 1;
}
/*
* Elimina todos los nodos de un arbol binario
*/
void borrar_arbol(nodo_t *arbolbp)
{
    if (arbolbp == NULL)
        return;
    borrar_arbol(arbolbp->izq);
    borrar_arbol(arbolbp->der);
    free(arbolbp);
}
/*
* Borra un nodo de un arbol binario,
* nota primera llamada raiz=borrar(raiz,clave);
*/
nodo_t *borrar(nodo_t *arbolbp, int elemento)
{
    nodo_t *ap;
    if (arbolbp == NULL)
        return NULL;
    if (elemento == arbolbp->elemento)
    { // se encontro el elemento a borrar
        if (arbolbp->izq == arbolbp->der)
        {
            // el nodo tiene ambos subarboles
            free(arbolbp);
            // vacios, retorna un arbol vacio
            return NULL;
        }
        if (arbolbp->izq == NULL)
        { // el nodo tiene el subarbol izquierdo
            ap = arbolbp->der;
            // vacio, retorna el subarbol derecho
            free(arbolbp);
            return ap;
        }
        if (arbolbp->der == NULL)
        { // el nodo tiene el subarbol derecho
            ap = arbolbp->izq;
            // vacio, retorna el subarbol izquierdo
            free(arbolbp);
            return ap;
        }
        ap = arbolbp->izq;
        // El nodo tiene ambos subarboles,
        while (ap->der != NULL)
            // reeemplaza el elemento por su
            ap = ap->der;
        // predecesor y borra el nodo que
        arbolbp->elemento = ap->elemento;
        // contenia al predecesor
        arbolbp->izq = borrar(arbolbp->izq, ap->elemento);
        return (arbolbp);
    }
    if (elemento < arbolbp->elemento)
        arbolbp->izq = borrar(arbolbp->izq, elemento);
    else
        arbolbp->der = borrar(arbolbp->der, elemento);
    return arbolbp;
}
/*
Calcula la altura de un arbol binario       
*/
int h_arbol(nodo_t *arbolbp)
{
    int hi = 0, hd = 0;

    if (arbolbp == NULL)
        return 0;
    if (arbolbp->izq != NULL)
        hi = 1 + h_arbol(arbolbp->izq);
    if (arbolbp->der != NULL)
        hd = 1 + h_arbol(arbolbp->der);
    if (hd > hi)
        return hd;
    return hi;
}
/*
* Recorrido inorden de un arbol binario
*/
void inorden(nodo_t *arbolbp)
{
    if (arbolbp == NULL)
        return;
    inorden(arbolbp->izq);
    printf("%d ", arbolbp->elemento);
    inorden(arbolbp->der);
}
/*
* Recorrido preorden de un arbol binario
*/
void preorden(nodo_t *arbolbp)
{
    if (arbolbp == NULL)
        return;
    printf("%d ", arbolbp->elemento);
    preorden(arbolbp->izq);
    preorden(arbolbp->der);
}
/*
* Recorrido postorden de un arbol binario
*/
void postorden(nodo_t *arbolbp)
{
    if (arbolbp == NULL)
        return;
    postorden(arbolbp->izq);
    postorden(arbolbp->der);
    printf("%d ", arbolbp->elemento);
}
/*
* Suma los nodos del arbol
*/
int suma(nodo_t *a)
{
    if (!a)
        return 0;
    return suma(a->izq) + suma(a->der) + a->elemento;
}
/*
    calcula el promedio de todos los nodos del arbol
*/
double promedio(nodo_t *a)
{
    if (!a)
        return 0;
    return suma(a) / nro_nodos(a);
}

/*
    calcula la suma de las hojas del arbol
*/
int sumahojas(nodo_t *a)
{
    if (!a)
        return 0;
    if (!a->izq && (!a->der))
    {
        return (a->elemento + sumahojas(a->izq) + sumahojas(a->der));
    }
    else
        return sumahojas(a->izq) + sumahojas(a->der);
}
/*
* calcula el numero de hojas de un arbol
*/
int nrohojas(nodo_t *a)
{
    if (!a)
        return 0;
    if (!a->izq && (!a->der))
    {
        return nrohojas(a->izq) + nrohojas(a->der) + 1;
    }
    else
        return nrohojas(a->izq) + nrohojas(a->der);
}
/*
    calcula el promedio de las hojas de un arbol
*/
double prom_hojas(nodo_t *a)
{
    if (!a)
        return 0;
    return sumahojas(a) / nrohojas(a);
}

//Insertar balanceado dado un arreglo de elementos
//  ordenados en aforma ascendente los inserta en el arbol
// lim1 y 2 son limetes superior e inferior del arreglo
void insertarBalanceado(nodo_t **Arbolbp, int array[], int lim1, int lim2)
{
    if (Arbolbp == NULL)
        return;
    else
    {
        insertar(Arbolbp, array[lim1 / 2]);
        insertar(Arbolbp, array[lim2]);
    }
    insertarBalanceado(&((*Arbolbp)->izq), array, lim1, lim2);
    insertarBalanceado(&((*Arbolbp)->izq), array, lim1, lim2);
}

//Retorna el mayor costo de una ruta en el arbol(costo= ala suma de 
// los valores contenidos en los nodos que forman parte de la ruta desde raiz)
// a hoja (para un arbol no necesariamente de busqueda)
int suppMaxcosto(nodo_t *arbol, int costeA, int costeMAX)
{
    if (!arbol)
        return 0;
    suppMaxcosto(arbol->izq, costeA, costeMAX);
    costeA = costeA + arbol->elemento;
    if (costeA > costeMAX)
        costeMAX = costeA;
    return costeMAX;
}
// Retorna el maximo costo de un arbol 
int maxCosto(nodo_t *arbolbp)
{
    if (!arbolbp)
        return 0;
    return suppMaxcosto(arbolbp, 0, 0);
}
