#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ==== DECLARACIÓN DE FUNCIONES ====

// Pide al usuario la cantidad de elementos del arreglo
// Pre: ninguna
// Post: devuelve un entero positivo mayor que cero
int pedirCantidad();

// Carga fija en un arreglo de ejemplo (5 elementos)
// Pre: El arreglo existe y tiene espacio suficiente para 5 enteros
// Post: El arreglo se llena con valores fijos {5, 10, 15, 20, 25}
void cargaFija(int arr[], int n);

// Carga manual por teclado
// Pre: El arreglo existe y tiene espacio suficiente
// Post: Cada elemento se llena con el valor ingresado por el usuario
void cargaManual(int arr[], int n);

// Carga aleatoria (0 a 99)
// Pre: El arreglo existe y tiene espacio suficiente
// Post: Cada elemento se llena con un valor aleatorio entre 0 y 99
void cargaAleatoria(int arr[], int n);

// Muestra el arreglo
// Pre: El arreglo existe y contiene n elementos válidos
// Post: Se imprime en pantalla el contenido del arreglo
void mostrarArreglo(int arr[], int n);

// Calcula y devuelve el promedio
// Pre: El arreglo existe y contiene n elementos válidos
// Post: Devuelve el promedio como float
float calcularPromedio(int arr[], int n);

// Cuenta cuántos elementos pares hay
// Pre: El arreglo existe y contiene n elementos válidos
// Post: Devuelve la cantidad de números pares encontrados
int contarPares(int arr[], int n);

// Busca la posición del mínimo
// Pre: El arreglo existe y contiene al menos un elemento
// Post: Devuelve la posición del valor mínimo
int buscarMinimo(int arr[], int n);

// Búsqueda secuencial
// Pre: El arreglo existe y contiene n elementos válidos
// Post: Devuelve la posición del elemento si lo encuentra, o -1 si no
int busquedaSecuencial(int arr[], int n, int valor);

// Cuenta cuántos elementos son mayores que un valor dado
// Pre: El arreglo existe y contiene n elementos válidos
// Post: Devuelve la cantidad de elementos mayores que el valor
int contarMayoresQue(int arr[], int n, float valor);

// ==== MAIN ====
int main() {

    int n = pedirCantidad();
    int arreglo[n];

    int arregloFijo[5];
    int opcion, buscar, encontrado;
    int  posMin;
    float promedio;

    printf("=== EJEMPLO DE ARREGLOS EN C CON FUNCIONES ===\n\n");

    // Carga fija y mostrar
    cargaFija(arregloFijo, 5);
    printf("Carga fija: ");
    mostrarArreglo(arregloFijo, 5);
    printf("\n");

    // Elegir tipo de carga
    printf("Seleccione tipo de carga para el arreglo principal (%d elementos):\n", n);
    printf("1 - Carga manual por teclado\n");
    printf("2 - Carga aleatoria (0 a 99)\n");
    scanf("%d", &opcion);

    if (opcion == 1) {
        cargaManual(arreglo, n);
    } else {
        cargaAleatoria(arreglo, n);
    }

    // Mostrar arreglo
    printf("\nArreglo cargado: ");
    mostrarArreglo(arreglo, n);

    // Calcular y mostrar promedio
    promedio = calcularPromedio(arreglo, n);
    printf("Promedio: %.2f\n", promedio);

    // Contar pares
    printf("Cantidad de numeros pares: %d\n", contarPares(arreglo, n));

    // Buscar mínimo (posición)
    posMin = buscarMinimo(arreglo, n);
    printf("Minimo: %d en la posicion %d\n", arreglo[posMin], posMin);

    // Búsqueda secuencial
    printf("\nIngrese valor a buscar: ");
    scanf("%d", &buscar);
    encontrado = busquedaSecuencial(arreglo, n, buscar);

    if (encontrado != -1) {
        printf("Valor encontrado en posicion %d\n", encontrado);
    } else {
        printf("Valor no encontrado en el arreglo.\n");
    }

    // Contar mayores que el promedio
    printf("Numeros mayores que el promedio: %d\n", contarMayoresQue(arreglo, n, promedio));

    // Pausa para Windows
    system("pause");
    return 0;
}

// ==== IMPLEMENTACIÓN DE FUNCIONES ====

int pedirCantidad() {
    int cantidad;
    do {
        printf("Ingrese la cantidad de elementos del arreglo (mayor a 0): ");
        scanf("%d", &cantidad);
    } while (cantidad <= 0);
    return cantidad;
}

void cargaFija(int arr[], int n) {
    // Carga solo los primeros 5 elementos con valores fijos
    int valores[] = {5, 10, 15, 20, 25};
    for (int i = 0; i < n && i < 5; i++) {
        arr[i] = valores[i];
    }
}

void cargaManual(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Ingrese elemento [%d]: ", i);
        scanf("%d", &arr[i]);
    }
}

void cargaAleatoria(int arr[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
}

void mostrarArreglo(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

float calcularPromedio(int arr[], int n) {
    int suma = 0;
    for (int i = 0; i < n; i++) {
        suma += arr[i];
    }
    return (float)suma / n;
}

int contarPares(int arr[], int n) {
    int pares = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            pares++;
        }
    }
    return pares;
}

int buscarMinimo(int arr[], int n) {
    int pos = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[pos]) {
            pos = i;
        }
    }
    return pos;
}

int busquedaSecuencial(int arr[], int n, int valor) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == valor) {
            return i;
        }
    }
    return -1;
}

int contarMayoresQue(int arr[], int n, float valor) {
    int contador = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > valor) {
            contador++;
        }
    }
    return contador;
}
