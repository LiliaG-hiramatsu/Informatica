#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct datos {
  float lectura;
  struct datos *siguiente;
};

typedef struct datos dato;

dato *crear_nodo () {
  return ((dato *)malloc(sizeof(dato)));
}

dato *add_dato(float temp, dato *temperaturas) {
  dato *q, *tmp;         //q es el nuevo nodo creado y tmp es un nodo temporal
  q = crear_nodo();
  if (q != NULL) {       //si q existe en memoria...
    q->lectura = temp;   //q le asigna a lectura lo que traiga temp
    q->siguiente = NULL;    //como es un nodo nuevo hay que indicar a que apuntara
    if (temperaturas == NULL) {     //si el apuntador apunta a null es porque es el ultimo nodo, por lo que se guarda q en el.
      temperaturas = q;
    }
    else {                              // si no apunta a null, entonces hay mas datos para guardar, no es el ultimo
      //Agregar el nodo al final de la lista.
      tmp = temperaturas;               //se guarda el apuntador temperatura en el apuntador temporal
      while (tmp->siguiente != NULL) {      //mientras el apuntador siguiente que asigna el apuntador temporal  no apunte a null
        tmp = tmp->siguiente;               //se actualiza el apuntador temporal haciendo que apunte al nodo siguiente, llamando al apuntador siguiente
      }
      tmp->siguiente = q;               //cuando sale, es decir, el apuntador siguiente apunta a null, entonces se guarda el valor que trae el apuntador q (la temp) en el nodo siguiente.
    }
  }
  else {
    printf("Memoria llena.\n");         //si q es null es porque no hay mas espacio en memoria, no se pudo reservar la memoria (esto nunca pasaria en teoria)
  }
  return temperaturas;
}

float obtener_indice (dato *temperaturas, int indice, int N) { //Devuelve el valor de una determinada posicion de la lista.
  dato *p;
  p = temperaturas;
  float valor;
  while (p != NULL) {
    if (indice <= N) {
      int i = 0;
      while (i < indice) {
        valor = p->lectura;
        p = p->siguiente;
        i++;
      }
      return valor;
    }
  }
}

int menor_lectura_indice(dato *temperaturas) {
  dato *p;
  int it = 0, indice_menor = 0;
  p = temperaturas;
  float menor = p->lectura;
  while (p != NULL) {
    if (p->lectura < menor) {
      menor = p->lectura;
      indice_menor = it;
    }
    it++;
    p = p->siguiente;
  }
  printf("\nLa menor temperatura detectada fue de: %.3f ºC\n", menor);
  return indice_menor;
}

int mayor_lectura_indice(dato *temperaturas) {
  dato *p;
  int it = 0, indice_mayor = 0;
  p = temperaturas;
  float mayor = p->lectura;
  while (p != NULL) {
    if (p->lectura > mayor) {
      mayor = p->lectura;
      indice_mayor = it;
    }
    it++;
    p = p->siguiente;
  }
  printf("\nLa mayor temperatura detectada fue de: %.3f ºC\n", mayor);
  return indice_mayor;
}

float funcion_media(dato *temperaturas, int N) { //N es la cantidad de lecturas de temperatura.
  dato *p;
  p = temperaturas;
  float suma = 0;
  while (p != NULL) {
    suma += p->lectura;
    p = p->siguiente;
  }
  return suma/N;
}

void intercambio(dato *a, dato *b)
{
    float tmp1 = a->lectura;
    a->lectura = b->lectura;
    b->lectura = tmp1;
}

void ordenar_lista(dato *temperaturas) { //Esta funcion es para ordenar la lista de menor a mayor
  int tmp;
  dato *ptr1;
  dato *lptr = NULL;
  do {
    tmp = 0;
    ptr1 = temperaturas;
    while (ptr1->siguiente != lptr) {
      if (ptr1->lectura > ptr1->siguiente->lectura) {
        intercambio(ptr1, ptr1->siguiente);
        tmp = 1;
      }
      ptr1 = ptr1->siguiente;
    }
    lptr = ptr1;
  } while (tmp);
}

float funcion_mediana (dato *temperaturas, int N) {
  dato *p;
	p = temperaturas;
	float med = 0;
  ordenar_lista(temperaturas);
  int h = N/2;
  int k = N/2 + 1;
  float actual = obtener_indice(temperaturas, h, N);
  float posterior = obtener_indice(temperaturas, k, N);
	if (N % 2 == 0) {
		med = (posterior+actual)/2;
	}
	else {
		med = posterior;
	}
	return med;
}

float funcion_varianza(dato *temperaturas, int N) {
  float var = 0;
  float suma = 0, n = N;
  int i;
  float media = funcion_media(temperaturas, N);
  for (i = 0; i < N; i++) {
    float valor = obtener_indice(temperaturas, i, N);
    suma += pow((valor - media), 2);
  }
  var = suma/n;
  return sqrt(var);
}

float funcion_moda(dato *temperaturas, int N) {
  float mod = 0, valor = 0, posterior = 0;
  int i, j, it = 0, contador = 0;
  for (j = 0; j < N; j++) {
      it = 0;
    valor = obtener_indice(temperaturas, j, N);
    for (i = 0; i < N; i++) {
        posterior = obtener_indice(temperaturas, i, N);
        if (valor == posterior) {
            it++;
        }
    }
    if (it > contador) {
        mod = valor;
        contador = it;
    }
  }
  return mod;
}

int main() {
  char fecha[25] = {0};
	float temp = 0;
	char aux[6] = {0};
	char vacio[80] = {0};
	char linea[50] = {0};
	int N = 0, i;

	FILE *fd;

	fd = fopen("/home/lilia/Escritorio/lecturas.txt", "r");

  dato *temperaturas = NULL; //creamos un apuntador de tipo dato llamado temperaturas

	if (fd == NULL) {
  	printf("Error al leer el archivo.\n");
	}
	else {
    while (feof(fd) == 0) {
      int i;
      if (fgets(linea, 50, fd) > 0) {
      	fgets(vacio, 79, fd);
        int suma = 0;
        for (i = 39; i < 46; i++) {
	        aux[suma] = linea[i];
	        suma += 1;
				}
	      temp = atof(aux);
	      temperaturas = add_dato(temp, temperaturas);
	      N++;
    	}
    }
	}

	printf("Cantidad de lecturas realizadas por la estación: N = %d\n", N);
	fclose(fd);

  int indice_menor = menor_lectura_indice(temperaturas);
  fd = fopen("/home/lilia/Escritorio/lecturas.txt", "r");
  int it1 = 0;
  while (feof(fd) == 0) {
    if (fgets(linea, 50, fd) > 0) {
      fgets(vacio, 79, fd);
      if (it1 == indice_menor) {
        for (i = 0; i < 24; i++) {
          fecha[i] = linea[i];
        }
        printf("El día: %s\n", fecha);
      }
    }
    it1++;
  }
  fclose(fd);

  int indice_mayor = mayor_lectura_indice(temperaturas);
  fd = fopen("/home/lilia/Escritorio/lecturas.txt", "r");
  int it2 = 0;
  while (feof(fd) == 0) {
    if (fgets(linea, 50, fd) > 0) {
      fgets(vacio, 79, fd);
      if (it2 == indice_mayor) {
        for (i = 0; i < 24; i++) {
          fecha[i] = linea[i];
        }
        printf("El día: %s\n\n", fecha);
      }
    }
    it2++;
  }
  fclose(fd);

  float media = funcion_media(temperaturas, N);
  float mediana = funcion_mediana(temperaturas, N);
  float desv = funcion_varianza(temperaturas, N);
  float moda = funcion_moda(temperaturas, N);
  printf("Media = %.3f ºC\n", media);
  printf("Mediana = %.3f ºC\n", mediana);
  printf("Desviación estándar = %.3f ºC\n", desv);
  printf("Moda = %.3f ºC\n", moda);

  free(temperaturas);

  return 0;
}
