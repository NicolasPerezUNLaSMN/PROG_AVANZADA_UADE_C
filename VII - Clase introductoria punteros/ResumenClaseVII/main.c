#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prototipos
void ejemploPunteroInt();
void ejemploPunteroChar();
void ejemploPunteroArray();
void ejemploPunteroStruct();
void ejemploFuncionRecibePuntero(int * x);
int* ejemploFuncionRetornaPuntero(int n);
void pausa();

struct Persona {
    char nombre[20];
    int edad;
};

int main() {
    printf("=== Ejemplo puntero a int ===\n");
    ejemploPunteroInt();
    pausa();

    printf("\n=== Ejemplo puntero a char (cadena) ===\n");
    ejemploPunteroChar();
    pausa();

    printf("\n=== Ejemplo puntero a array ===\n");
    ejemploPunteroArray();
    pausa();

    printf("\n=== Ejemplo puntero a struct ===\n");
    ejemploPunteroStruct();
    pausa();

    printf("\n=== Ejemplo funcion que recibe puntero ===\n");
    int numero = 12;
    ejemploFuncionRecibePuntero(&numero);
    pausa();

    printf("\n=== Ejemplo funcion que retorna puntero ===\n");
    int *arr = ejemploFuncionRetornaPuntero(5);
    if(arr != NULL) {
        printf("Array retornado desde funcion: ");
        for(int i=0; i<5; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        free(arr);
    }
    pausa();

    printf("¡Listo! Ejemplos de punteros terminados.\n");
    return 0;
}

// Pausa para leer
void pausa() {
    printf("Presione ENTER para continuar...\n");
    while(getchar() != '\n');  // Espera ENTER
}

// --- Ejemplo puntero a int ---
void ejemploPunteroInt() {
    int x = 10;
    int *p = &x;
    printf("Valor de x: %d\n", x);
    printf("Direccion de x: %p\n", (void*)p);
    printf("Valor apuntado por p: %d\n", *p);
    *p = 20;
    printf("Nuevo valor de x tras modificar via puntero: %d\n", x);
}

// --- Ejemplo puntero a char (cadena) ---
void ejemploPunteroChar() {
    char letra = 'A';
    char *pChar = &letra;
    printf("Letra: %c\n", *pChar);

    char nombre[] = "Nykolai";
    char *pNombre = nombre;  // Apunta al primer char del array
    printf("Nombre: %s\n", pNombre);

    printf("Segundo caracter del nombre via puntero: %c\n", *(pNombre + 1));
}

// --- Ejemplo puntero a array ---
void ejemploPunteroArray() {
    int numeros[] = {1, 2, 3, 4, 5};
    int *pArr = numeros; // &numeros[0]

    printf("Array: ");
    for(int i=0; i<5; i++) {
        printf("%d ", *(pArr + i));
    }
    printf("\n");

    // Modificar el 3er elemento vía puntero
    *(pArr + 2) = 100;
    printf("Array despues de modificar el 3er elemento: ");
    for(int i=0; i<5; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");
}

// --- Ejemplo puntero a struct ---
void ejemploPunteroStruct() {
    struct Persona p = {"Nykolai", 35};
    struct Persona *pp = &p;

    printf("Nombre: %s, Edad: %d\n", pp->nombre, pp->edad);
    pp->edad = 36;
    printf("Edad modificada via puntero: %d\n", p.edad);
}

// --- Ejemplo función que recibe puntero ---
void incrementar(int *p) {
    (*p)++;
}

void ejemploFuncionRecibePuntero(int * x) {

    printf("Valor inicial: %d\n", *x);
    incrementar(x);

    printf("Valor despues de incrementar: %d\n", *x);
}

// --- Ejemplo función que retorna puntero ---
int* ejemploFuncionRetornaPuntero(int n) {
    int *arr = (int*)malloc(n * sizeof(int));
    if(arr == NULL) {
        printf("Error al reservar memoria\n");
        return NULL;
    }
    for(int i=0; i<n; i++) {
        arr[i] = i * i;
    }
    return arr;
}
