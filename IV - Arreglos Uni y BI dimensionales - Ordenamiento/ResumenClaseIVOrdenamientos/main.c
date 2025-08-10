#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ==== DECLARACIÓN DE FUNCIONES ====

// PRE: tam > 0 y arreglo apunta a un espacio de memoria válido.
// POS: llena el arreglo con números aleatorios entre 0 y 99.
void cargarAleatorio(int arreglo[], int tam);

// PRE: tam > 0 y arreglo inicializado.
// POS: muestra los elementos del arreglo separados por espacio.
void mostrarArreglo(int arreglo[], int tam);

// PRE: tam > 0 y arreglo inicializado.
// POS: ordena el arreglo usando el método Burbuja.
void ordenamientoBurbuja(int arreglo[], int tam);

// PRE: tam > 0 y arreglo inicializado.
// POS: ordena el arreglo usando el método Burbuja Optimizado.
void ordenamientoBurbujaOptimizado(int arreglo[], int tam);

// PRE: tam > 0 y arreglo inicializado.
// POS: ordena el arreglo usando el método de Inserción.
void ordenamientoInsercion(int arreglo[], int tam);

// PRE: tam > 0 y arreglo inicializado.
// POS: ordena el arreglo usando el método de Selección.
void ordenamientoSeleccion(int arreglo[], int tam);

// PRE: tam > 0 y arreglo inicializado.
// POS: ordena el arreglo usando el método Shell.
void ordenamientoShell(int arreglo[], int tam);

// PRE: tam > 0 y arreglo inicializado.
// POS: ordena el arreglo usando Quick Sort.
void ordenamientoQuickSort(int arreglo[], int inicio, int fin);


// ==== FUNCIÓN PRINCIPAL ====
int main() {
    int tam;

    printf("Ingrese cantidad de elementos: ");
    scanf("%d", &tam);

    int arreglo[tam];

    srand(time(NULL)); // Semilla para números aleatorios

    cargarAleatorio(arreglo, tam);

    printf("\nArreglo original:\n");
    mostrarArreglo(arreglo, tam);

    printf("\nBurbuja:\n");
    ordenamientoBurbuja(arreglo, tam);
    mostrarArreglo(arreglo, tam);

    cargarAleatorio(arreglo, tam);
    printf("\nBurbuja Optimizado:\n");
    ordenamientoBurbujaOptimizado(arreglo, tam);
    mostrarArreglo(arreglo, tam);

    cargarAleatorio(arreglo, tam);
    printf("\nInsercion:\n");
    ordenamientoInsercion(arreglo, tam);
    mostrarArreglo(arreglo, tam);

    cargarAleatorio(arreglo, tam);
    printf("\nSeleccion:\n");
    ordenamientoSeleccion(arreglo, tam);
    mostrarArreglo(arreglo, tam);

    cargarAleatorio(arreglo, tam);
    printf("\nShell:\n");
    ordenamientoShell(arreglo, tam);
    mostrarArreglo(arreglo, tam);

    cargarAleatorio(arreglo, tam);
    printf("\nQuickSort:\n");
    ordenamientoQuickSort(arreglo, 0, tam - 1);
    mostrarArreglo(arreglo, tam);

    return 0;
}


// ==== IMPLEMENTACIÓN DE FUNCIONES ====

void cargarAleatorio(int arreglo[], int tam) {
    for (int i = 0; i < tam; i++) {
        arreglo[i] = rand() % 100;
    }
}

void mostrarArreglo(int arreglo[], int tam) {
    for (int i = 0; i < tam; i++) {
        printf("%d ", arreglo[i]);
    }
    printf("\n");
}

void ordenamientoBurbuja(int arreglo[], int tam) {
    for (int i = 0; i < tam - 1; i++) {
        for (int j = 0; j < tam - 1; j++) {
            if (arreglo[j] > arreglo[j + 1]) {
                int aux = arreglo[j];
                arreglo[j] = arreglo[j + 1];
                arreglo[j + 1] = aux;
            }
        }
    }
}

void ordenamientoBurbujaOptimizado(int arreglo[], int tam) {
    int intercambio;
    for (int i = 0; i < tam - 1; i++) {
        intercambio = 0;
        for (int j = 0; j < tam - 1 - i; j++) {
            if (arreglo[j] > arreglo[j + 1]) {
                int aux = arreglo[j];
                arreglo[j] = arreglo[j + 1];
                arreglo[j + 1] = aux;
                intercambio = 1;
            }
        }
        if (!intercambio) break;
    }
}

void ordenamientoInsercion(int arreglo[], int tam) {
    for (int i = 1; i < tam; i++) {
        int actual = arreglo[i];
        int j = i - 1;
        while (j >= 0 && arreglo[j] > actual) {
            arreglo[j + 1] = arreglo[j];
            j--;
        }
        arreglo[j + 1] = actual;
    }
}

void ordenamientoSeleccion(int arreglo[], int tam) {
    for (int i = 0; i < tam - 1; i++) {
        int min = i;
        for (int j = i + 1; j < tam; j++) {
            if (arreglo[j] < arreglo[min]) {
                min = j;
            }
        }
        if (min != i) {
            int aux = arreglo[i];
            arreglo[i] = arreglo[min];
            arreglo[min] = aux;
        }
    }
}

void ordenamientoShell(int arreglo[], int tam) {
    for (int gap = tam / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < tam; i++) {
            int temp = arreglo[i];
            int j;
            for (j = i; j >= gap && arreglo[j - gap] > temp; j -= gap) {
                arreglo[j] = arreglo[j - gap];
            }
            arreglo[j] = temp;
        }
    }
}

void ordenamientoQuickSort(int arreglo[], int inicio, int fin) {
    if (inicio < fin) {
        int pivote = arreglo[inicio];
        int i = inicio + 1;
        int j = fin;
        int temp;

        while (i <= j) {
            while (i <= fin && arreglo[i] <= pivote) i++;
            while (j >= inicio && arreglo[j] > pivote) j--;
            if (i < j) {
                temp = arreglo[i];
                arreglo[i] = arreglo[j];
                arreglo[j] = temp;
            }
        }

        temp = arreglo[inicio];
        arreglo[inicio] = arreglo[j];
        arreglo[j] = temp;

        ordenamientoQuickSort(arreglo, inicio, j - 1);
        ordenamientoQuickSort(arreglo, j + 1, fin);
    }
}
