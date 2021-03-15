/* EJERCICIO 17
Complete el ejercicio anterior adicionando lo siguiente:
Utilizando las funciones del ejercicio anterior: lea un archivo de disco que contenga
un vector; encuentre el menor de los elementos; escale el vector leído con el menor
valor encontrado; grabe el resultado en un nuevo archivo llamado
{NOMBRE_ARCHIVO_ORIGINAL}-escalado​.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int *crear_vector(int N) {
  int *v;
  v = (int *)malloc(N*sizeof(int));
  return v;
}

void cargar_vector(int N, int *v) {
  srand(time(NULL));
  int i;
  for (i = 0; i < N; i++) {
    v[i] = 1 + rand() % 50;
  }
}

void borrar_vector(int *vector) {
  free(vector);
}

FILE *fd;

void funcion_escribir(char *archivo, int *v, int N) { //En esta funcion se carga el vector
  int j;
  fd = fopen(archivo, "w+"); //Abriendo el archivo en modo escritura, si ya existe se reemplaza.
  if (fd == NULL) {
    printf("Error abriendo el fichero como escritura");
  }
  else {
    printf("Grabando en el archivo...\n");
    for (j = 0; j < N; j++){
      fprintf(fd, "%d\n", v[j]);
    }
  }
  fclose(fd);
  printf("Fichero cerrado.\n");
}

int funcion_leer(char *archivo) { //En esta funcion se lee el vector para encontrar el menor elemento. Retorna el menor elemento.
  char texto[30];
  int v[100], valor, i, j;
  fd = fopen(archivo, "r"); //Abre el archivo en modo lectura
  if (fd == NULL) { //Si el apuntador fd apunta a NULL se produce un error. Sería el caso en el que intente abrrir un archivo que no existe, por ejemplo.
    return 0; //error al abrir el fichero.
  }
  else {
    i = 0;
    while (feof(fd) == 0) { //feof (end of file) esta linea indica que mientras no se llegue al final del archivo haga lo que esta dentro del while.
      if (fgets(texto, 100, fd)>0){
        sscanf(texto, "%d", &valor); //imprime los valores del archivo por pantalla.
        v[i] = valor;
        i++;
      }
    }
    int menor = 0;
    for (j = 0; j < i; j++) {
      if (v[j] < v[menor]) {
        menor = j;
      }
    }
    return v[menor];
  }
  fclose(fd);
}


int main(int argc, char** argv) {
  char archivo_original[30];
  printf("Ingrese el nombre del archivo: \n");
  fgets(archivo_original, 30, stdin);
  char archivo_nuevo[30];
  printf("\nIngrese el nombre del nuevo archivo (archivo_original-escalado): \n");
  fgets(archivo_nuevo, 30, stdin);
  int N, i, escalar;
  printf("\nIngresar la longitud del vector: N = "); //N debe se menor o igual a 100
  scanf("%d", &N);
  int *vector = crear_vector(N);
  cargar_vector(N, vector);
  printf("\nCargar el vector en el archivo\n");
  funcion_escribir(archivo_original, vector, N);
  int *vec_esc = crear_vector(N);
  escalar = funcion_leer(archivo_original);
  printf("\nCargar el vector escalado en el nuevo archivo\n");
  for (i = 0; i < N; i++) {
    vec_esc[i] = escalar*vector[i];
  }
  funcion_escribir(archivo_nuevo, vec_esc, N);
  borrar_vector(vector);
  borrar_vector(vec_esc);
  return 0;
}
