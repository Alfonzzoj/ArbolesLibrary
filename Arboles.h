typedef struct nodo
{
    int elemento;
    struct nodo *izq, *der;
} nodo_t;

// Busca un elemento en un arbol binario
int buscar(nodo_t *arbolbp, int elemento);
// Inserta un elemento en un arbol binario
int insertar(nodo_t **arbolbp, int elemento);
// Busca el mayor elemento en un arbol binario
int mayor(nodo_t *arbolbp, int *elemento);
// Busca el menor elemento en un arbol binario
int menor(nodo_t *arbolbp, int *elemento);
// Cuenta el numero de nodos en un arbol binario
int nro_nodos(nodo_t *arbolbp);
// Elimina todos los nodos de un arbol binario
void borrar_arbol(nodo_t *arbolbp);
// Borra un nodo de un arbol binario,
nodo_t *borrar(nodo_t *arbolbp, int elemento);
// Calcula la altura de un arbol binario 
int h_arbol(nodo_t *arbolbp);
// Recorrido inorden de un arbol binario
void inorden(nodo_t *arbolbp);
// Recorrido preorden de un arbol binario
void preorden(nodo_t *arbolbp);
// Recorrido postorden de un arbol binario
void postorden(nodo_t *arbolbp);
// Imprime un arbol binario
void imprimirNivel(nodo_t *arbolbp, int nivel);
// Suma los nodos del arbol
int suma(nodo_t *arbolbp);
// calcula el promedio de todos los nodos del arbol
double promedio(nodo_t *arbolbp);
// calcula la suma de las hojas del arbol
int sumahojas(nodo_t *arbolbp);
// calcula el numero de hojas de un arbol
int nrohojas(nodo_t *arbolbp);
// calcula el promedio de las hojas de un arbol
double prom_hojas(nodo_t *arbolbp);
// Insertar balanceado dado un arreglo de elementos ordenados 
// en aforma ascendente los inserta en el arbol
void insertarBalanceado(nodo_t **Arbolbp,int array[],int lim1,int lim2);
// Retorna el mayor costo de una ruta en el arbol
int suppMaxcosto(nodo_t *arbol,int costeA,int costeMAX);
// Retorna el maximo costo de un arbol 
int maxCosto(nodo_t *arbolbp);
