#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ==== DECLARACIÓN DE FUNCIONES Y PROCEDIMIENTOS ====

// Pre: Ninguna.
// Pos: Devuelve un entero ingresado por el usuario mayor que 0.
int pedirDimension();

// Pre: 'matriz' debe estar declarada con al menos 'filas' x 'columnas'.
// Pos: Llena 'matriz' con números aleatorios entre 0 y 99.
void cargarAleatorio(int filas, int columnas, int matriz[filas][columnas]);

// Pre: 'matriz' debe estar cargada.
// Pos: Muestra la matriz en consola.
void mostrarMatriz(int filas, int columnas, int matriz[filas][columnas]);

// Pre: 'matriz' debe estar cargada.
// Pos: Muestra la suma de cada fila.
void sumarFilas(int filas, int columnas, int matriz[filas][columnas]);

// Pre: 'matriz' debe estar cargada.
// Pos: Muestra la suma de cada columna.
void sumarColumnas(int filas, int columnas, int matriz[filas][columnas]);

// Pre: 'matriz' debe estar cargada.
// Pos: Devuelve la posición (fila, columna) del valor mínimo encontrado.
void buscarMinimo(int filas, int columnas, int matriz[filas][columnas]);


// ==== FUNCIÓN PRINCIPAL ====
int main() {
    srand(time(NULL));

    int filas = pedirDimension();
    int columnas = pedirDimension();

    int matriz[filas][columnas];

    cargarAleatorio(filas, columnas, matriz);
    printf("\nMatriz generada:\n");
    mostrarMatriz(filas, columnas, matriz);

    printf("\nSuma por filas:\n");
    sumarFilas(filas, columnas, matriz);

    printf("\nSuma por columnas:\n");
    sumarColumnas(filas, columnas, matriz);


    buscarMinimo(filas, columnas, matriz);


    return 0;
}


// ==== IMPLEMENTACIÓN ====


int pedirDimension(const char *mensaje) {
    int valor;
    do {
        printf("Por favor ingrese una dimension:\n");
        scanf("%d", &valor);
        if (valor <= 0) {
            printf("Error: el valor debe ser mayor que 0.\n");
        }
    } while (valor <= 0);
    return valor;
}

void cargarAleatorio(int filas, int columnas, int matriz[filas][columnas]) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matriz[i][j] = rand() % 100; // Números entre 0 y 99
        }
    }
}

void mostrarMatriz(int filas, int columnas, int matriz[filas][columnas]) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%3d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void sumarFilas(int filas, int columnas, int matriz[filas][columnas]) {
    for (int i = 0; i < filas; i++) {
        int suma = 0;
        for (int j = 0; j < columnas; j++) {
            suma += matriz[i][j];
        }
        printf("Fila %d: %d\n", i, suma);
    }
}

void sumarColumnas(int filas, int columnas, int matriz[filas][columnas]) {
    for (int j = 0; j < columnas; j++) {
        int suma = 0;
        for (int i = 0; i < filas; i++) {
            suma += matriz[i][j];
        }
        printf("Columna %d: %d\n", j, suma);
    }
}

void buscarMinimo(int filas, int columnas, int matriz[filas][columnas]) {
    int minValor = matriz[0][0];
    int filaMin = 0;
    int colMin = 0;

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (matriz[i][j] < minValor) {
                minValor = matriz[i][j];
                filaMin = i;
                colMin = j;
            }
        }
    }
    printf("\nEl valor minimo esta en la posicion: fila %d, columna %d\n", filaMin, colMin);
}
