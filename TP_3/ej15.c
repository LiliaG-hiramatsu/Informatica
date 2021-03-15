/* EJERCICIO 15
Escriba un programa que:
a.Genere una lista simplemente enlazada, de tamaño N con valores aleatorios
enteros, utilizando la función rand(). Use la función srand() para obtener una mejor
aleatoriedad.
b.Recorra el vector y guarde el promedio de los valores en una variable
c.Encuentre el menor de los elementos.*/

//Cada vez que ejecutemos y aumentemos el valor de N, se imprimen nuevos valores en la cabecera de la lista.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct nodo {
  int valor;
  struct nodo *siguiente;
};

typedef struct nodo NODO;

NODO *creanodo () {
  return ((NODO *)malloc(sizeof(NODO)));
}

NODO *add(NODO *nuevo) { //Lo que hace la funcion es añadir un nuevo nodo en la cabecera de la lista
  NODO *q, *tmp;
  q = creanodo();
  if (q != NULL) {
    q->valor = rand()%30;
    q->siguiente = NULL;
    if (nuevo == NULL) {
      nuevo = q;
    }
    else {
      //Agregar el nodo al final de la lista.
      tmp = nuevo;
      while (tmp->siguiente != NULL) {
        tmp = tmp->siguiente;
      }
      tmp->siguiente = q;
    }
  }
  else {
    printf("Memoria llena.\n");
  }
  return nuevo;
}

void imprime_lista(NODO *nuevo) {
  NODO *p;
  p = nuevo;
  printf("\n[ ");
  while (p != NULL) {
    printf("%d ", p->valor);
    p = p->siguiente;
  }
  printf("]\n");
}

void promedio(NODO *nuevo, int N) {
  NODO *p;
  p = nuevo;
  int suma = 0;
  while (p != NULL) {
    suma += p->valor;
    p = p->siguiente;
  }
  int prom = suma/N;
  printf("\nEl promedio es: %d\n", prom);
}

void menor_valor(NODO *nuevo) {
  NODO *p;
  p = nuevo;
  int max = 30, menor;
  int x = 0;
  while (p != NULL) {
    x = p->valor;
    p = p->siguiente;
    if (x < max) {
      max = x;
    }
    menor = max;
  }
  printf("\nEl menor elemento es: %d\n", menor);
}

int main() {
  NODO *nuevo;
  int i, N;
  printf("N = "); scanf("%d", &N); //Tamaño de la lista
  nuevo = NULL;
  for (i = 0; i < N; i++) {
    nuevo = add(nuevo);
  }
  printf("\n**LISTA**\n");
  imprime_lista(nuevo);
  promedio(nuevo, N);
  menor_valor(nuevo);
  return 0;
}
