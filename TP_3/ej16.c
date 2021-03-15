/* EJERCICIO 16
Tomando como base el ejercicio anterior, cree otro programa que incluya dos funciones:
a. Una primer función que permita llenar la lista obteniendo los valores de un archivo.
El formato interno de como el archivo guarda los enteros queda a tu elección.
b. Una segunda función que grabe una lista con valores en un archivo. Si el archivo
ya existe, se reemplaza. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

FILE *Fd;

struct nodo {
  int valor;
  struct nodo *siguiente;
};

typedef struct nodo NODO;

NODO *creanodo () {
  return ((NODO *)malloc(sizeof(NODO)));
}

NODO *add(NODO *nuevo, int valor) {
  NODO *q;
  q = creanodo(); //crea un nuevo nodo
  q->valor = rand()%30; //copia valores aleatorios de 0 a 30
  q->siguiente = nuevo;
  nuevo = q;
  return nuevo;
}

int imprime_lista(NODO *nuevo) {
  NODO *p;
  p = nuevo;
  while (p != NULL) {
    return p->valor;
    p = p->siguiente;
  }
}

void funcion_leer(int N, char *nombre) {
  NODO *nuevo;
  char texto[30];
  int lista[100], valor, i, j;
  Fd = fopen(nombre, "r"); //Abre el archivo en modo lectura
  printf("\nAbriendo el archivo en modo lectura.\n");
  if (Fd == NULL) {
    printf("Error al abrir el fichero.\n");
  }
  else {
    printf("Lo que hay en el archivo es:\n");
    i = 0;
    while (feof(Fd) == 0) {
      if (fgets(texto,100,Fd)>0){
        printf("%s",texto);
        sscanf(texto,"%d",&valor);
        lista[i]=valor;
        i++;
      }
    }
  }
  fclose(Fd);
  printf("\nfichero cerrado\n");
  printf("La lista de valores que está en el archivo es:\n");
  printf("[ ");
  for (j = 0; j < i; j++){
    printf("%d ",lista[j]);
  }
  printf("]\n");
}

void funcion_escribir(int N, char *nombre) {
  int valor, i;
  NODO *nuevo;
  nuevo = NULL;
  Fd = fopen(nombre, "w+"); //Abre el archivo en modo escritura. Si ya existe el archivo, se sobreescribe (eso lo indica el '+')
  if (Fd == NULL) {
    printf("Error al abrir el fichero.\n");
  }
  else {
    printf("Archivo abierto en modo escritura.\n");
    printf("Grabando los elementos de la lista en el archivo.\n");

    for (i = 0; i < N; i++) {
      nuevo = add(nuevo, valor);
      fprintf(Fd, "%d\n", imprime_lista(nuevo));
    }
    fclose(Fd);
    printf("Fichero cerrado\n");
  }
}

int main() {
  NODO *nuevo;
  nuevo = NULL;
  int N;
  char nombre[30];
  printf("Nombre del archivo: ");
  fgets(nombre, 30, stdin);
  printf("\nEl archivo se llama: %s", nombre);
  printf("\n");
  printf("Cantidad de elementos de la lista: N = "); scanf("%d", &N);
  funcion_escribir(N, nombre);
  funcion_leer(N, nombre);
  return 0;
}
