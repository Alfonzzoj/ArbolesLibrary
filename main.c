#include <stdio.h>
#include <stdlib.h>
#include "arboles.h"

// Ejemplo de progragama principal para usar la libreria de arboles
int op=1, valor,e;
nodo_t *arbol = NULL;

int menu(){
	int op;
	system("cls");
	printf("===    SISTEMA  DE    ARBOL BINARIO   === \n\n");
	printf("Introduzca la accion a realizar \n");
	printf("1:= Insertar un elemento\n");
	printf("2:= Buscar un elemento\n");
	printf("3:= Imprimir el arbol\n");
	printf("4:= Imprimir el arbol en nivel determinado\n");
	printf("5:= Buscar el elemento menor\n");
	printf("6:= Buscar el elemento mayor\n");
	printf("7:= Numero de nodos del arbol\n");
	printf("8:= Borrar elemento (nodo) \n");
	printf("9:= Borrar Arbol completo \n");
	printf("10:= Ver altura de arbol \n");
	printf("11:= Sumar los elementos del arbol \n");
	printf("12:= Promedio de elementos del arbol \n");
	printf("13:= Sumar hojas del arbol \n");
	printf("14:= Mostrar numero de hojas del arbol \n");
	printf("15:= Promedio de las hojas del arbol \n");
	printf("16:= Calcular costo de ruta en arbol \n");
	printf("0:= Salir \n \n");
	scanf("%d", &op);
	return op;
}


int main()
{
	while (op != 0)
	{
		op = menu();

		switch (op)
		{
			// Insertar un elemento
			case 1:
				printf("Introduzca el valor a insertar \n");
				scanf("%d", &valor);
				insertar(&arbol, valor);
				printf("Elemento insertado \n");
				pausar();
				system("pause");

			break;
			// Buscar un elemento
			case 2:
				printf("Introduzca el valor a buscar \n");
				scanf("%d", &valor);
				if (buscar(arbol, valor))
					printf("El valor %d se encuentra en el arbol \n", valor);
				else
					printf("El valor %d no se encuentra en el arbol \n", valor);
				pausar();
				system("pause");

			break;
			// Imprimir el arbol
			case 3:
				imprimirNivel(arbol, 0);
				pausar();
				system("pause");
			break;
			// Imprimir el arbol en nivel determinado
			case 4:
				printf("Introduzca el nivel del arbol \n");
				scanf("%d", &valor);
				imprimirNivel(arbol, valor);
				pausar();
				system("pause");

			break;
			// Buscar el elemento menor
			case 5:
				menor(arbol, &e);
				printf("El menor elemento del arbol es %d \n", e);
				pausar();
				system("pause");

			break;
			// Buscar el elemento mayor
			case 6:
				mayor(arbol, &e);
				printf("El mayor elemento del arbol es %d \n", e);
				pausar();
				system("pause");
			break;
			// Numero de nodos del arbol
			case 7:
				printf("El numero de nodos del arbol es %d \n", nro_nodos(arbol));
				pausar();
				system("pause");
			break;
			// Borrar elemento (nodo)
			case 8:
				printf("Introduzca el valor a borrar \n");
				scanf("%d", &valor);
				arbol= borrar(arbol, valor);
				printf("Elemento %d borrado \n", valor);
				pausar();
				system("pause");
			break;
			// Borrar Arbol completo
			case 9:
				borrar_arbol(arbol);
				printf("Arbol borrado \n");
				pausar();
				system("pause");
			break;
			// Ver altura de arbol
			case 10:
				printf("La altura del arbol es %d \n", h_arbol(arbol));
				pausar();
				system("pause");
			break;
			// Sumar los elementos del arbol
			case 11:
				printf("La suma de los elementos del arbol es %d \n", suma(arbol));
				pausar();
				system("pause");
			break;
			// Promedio de elementos del arbol
			case 12:
				printf("El promedio de los elementos del arbol es %d \n", promedio(arbol));
				pausar();
				system("pause");
			break;
			// Sumar hojas del arbol
			case 13:
				printf("La suma de las hojas del arbol es %d \n", sumahojas(arbol));
				pausar();
				system("pause");
			break;
			// Mostrar numero de hojas del arbol
			case 14:
				printf("El numero de hojas del arbol es %d \n", nrohojas(arbol));
				pausar();
				system("pause");
			break;
			// Promedio de las hojas del arbol
			case 15:
				printf("El promedio de las hojas del arbol es %d \n", prom_hojas(arbol));
				pausar();
				system("pause");
			break;
			// Calcular costo de ruta en arbol
			case 16:
				printf("Introduzca el valor,hasta donde calcular la ruta \n");
				scanf("%d", &valor);
				printf("El costo de la ruta es %d \n", suppMaxcosto(arbol,valor,0));
				pausar();
				system("pause");
			break;

			default:
				printf("Opcion no valida \n");
				pausar();
				system("pause");
			break;
		}
	}
	return 0;
}