#include <stdio.h>   // printf, scanf
#include <stdlib.h>  // rand, srand, system
#include <time.h>    // time (para semilla de números aleatorios)

int main() {
    // Declaración de variables
    int cantidadElementos = 10;
    int arreglo[cantidadElementos]; // arreglo de 10 enteros
    int i, n, opcion, buscar, encontrado;
    int suma = 0, pares = 0, minimo, posicionMin = 0, mayoresProm = 0;
    float promedio;

    // Carga fija (predefinida)
    int arregloFijo[5] = {5, 10, 15, 20, 25};

    printf("=== EJEMPLO DE ARREGLOS EN C ===\n\n");

    // Mostrar carga fija
    printf("Carga fija: ");
    for (i = 0; i < 5; i++) {
        printf("%d ", arregloFijo[i]);
    }
    printf("\n\n");

    // Elegir tipo de carga para 'arreglo'
    printf("Seleccione tipo de carga para el arreglo principal (10 elementos):\n");
    printf("1 - Carga manual por teclado\n");
    printf("2 - Carga aleatoria (0 a 99)\n");
    scanf("%d", &opcion);

    if (opcion == 1) {
        // Carga manual
        for (i = 0; i < cantidadElementos; i++) {
            printf("Ingrese elemento [%d]: ", i);
            scanf("%d", &arreglo[i]);
        }
    } else {
        // Carga aleatoria
        srand(time(NULL)); // semilla aleatoria
        for (i = 0; i < cantidadElementos; i++) {
            arreglo[i] = rand() % 100; // valores entre 0 y 99
        }
    }

    // Mostrar el arreglo cargado
    printf("\nArreglo cargado: ");
    for (i = 0; i < cantidadElementos; i++) {
        printf("%d ", arreglo[i]);
    }
    printf("\n");

    // Calcular suma y promedio
    suma = 0;
    for (i = 0; i < cantidadElementos; i++) {
        suma += arreglo[i];
    }
    promedio = (float)suma / 10;
    printf("Promedio: %.2f\n", promedio);

    // Contar pares
    pares = 0;
    for (i = 0; i < cantidadElementos; i++) {
        if (arreglo[i] % 2 == 0) {
            pares++;
        }
    }
    printf("Cantidad de numeros pares: %d\n", pares);

    // Buscar mínimo
    minimo = arreglo[0];
    posicionMin = 0;
    for (i = 1; i < cantidadElementos; i++) {
        if (arreglo[i] < minimo) {
            minimo = arreglo[i];
            posicionMin = i;
        }
    }
    printf("Minimo: %d en la posicion %d\n", minimo, posicionMin);

    // Buscar valor (búsqueda secuencial)
    printf("\nIngrese valor a buscar: ");
    scanf("%d", &buscar);
    encontrado = 0;
    for (i = 0; i < cantidadElementos; i++) {
        if (arreglo[i] == buscar) {
            printf("Valor encontrado en posicion %d\n", i);
            encontrado = 1;
            break; // detener al encontrar el primero
        }
    }
    if (!encontrado) {
        printf("Valor no encontrado en el arreglo.\n");
    }

    // EXTRA: contar cuántos son mayores que el promedio
    mayoresProm = 0;
    for (i = 0; i < cantidadElementos; i++) {
        if (arreglo[i] > promedio) {
            mayoresProm++;
        }
    }
    printf("Numeros mayores que el promedio: %d\n", mayoresProm);

    // Pausa para Windows
    system("pause");
    return 0;
}
