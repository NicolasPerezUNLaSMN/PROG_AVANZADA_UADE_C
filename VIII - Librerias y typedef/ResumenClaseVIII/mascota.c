#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "mascota.h"

// ======================
//      FUNCIONES
// ======================

MascotaPtr cargarMascota() {
    MascotaPtr m = (MascotaPtr) malloc(sizeof(struct Mascota));

    printf("Ingrese nombre de la mascota (o ENTER para dejar vacio): ");
    fflush(stdin);
    fgets(m->nombre, 20, stdin);
    size_t len = strlen(m->nombre);
    if(len > 0 && m->nombre[len-1] == '\n') {
        m->nombre[len-1] = '\0';
    }
    if(strlen(m->nombre) == 0) {
        m->raza[0] = '\0';
        return m;
    }
    printf("Ingrese raza de la mascota: ");
    fgets(m->raza, 20, stdin);
    len = strlen(m->raza);
    if(len > 0 && m->raza[len-1] == '\n') {
        m->raza[len-1] = '\0';
    }
    return m;
}

void mostrarMascota(MascotaPtr m) {
    if(strlen(m->nombre) == 0) {
        printf("[Posicion vacia]\n");
    } else {
        printf("Mascota -> Nombre: %s | Raza: %s\n", m->nombre, m->raza);
    }
}

void ordenarMascotasPorNombre(MascotaPtr mascotas[], int n) {
    for(int i=0; i < n-1; i++) {
        for(int j=0; j < n-1-i; j++) {
            if(strlen(mascotas[j]->nombre) > 0 && strlen(mascotas[j+1]->nombre) > 0) {
                if(strcmp(mascotas[j]->nombre, mascotas[j+1]->nombre) > 0) {
                    MascotaPtr temp = mascotas[j];
                    mascotas[j] = mascotas[j+1];
                    mascotas[j+1] = temp;
                }
            } else if(strlen(mascotas[j]->nombre) > 0 && strlen(mascotas[j+1]->nombre) == 0) {
                MascotaPtr temp = mascotas[j];
                mascotas[j] = mascotas[j+1];
                mascotas[j+1] = temp;
            }
        }
    }
}

int buscarMascota(MascotaPtr mascotas[], int n, char nombreBuscado[]) {
    for(int i=0; i < n; i++) {
        if(strcmp(mascotas[i]->nombre, nombreBuscado) == 0) {
            return i;
        }
    }
    return -1;
}

int eliminarMascota(MascotaPtr mascotas[], int n, char nombreEliminar[]) {
    int pos = buscarMascota(mascotas, n, nombreEliminar);
    if(pos == -1) return 0;
    mascotas[pos]->nombre[0] = '\0';
    mascotas[pos]->raza[0] = '\0';
    return 1;
}

// Agrega una mascota por teclado si hay espacio
// Retorna 1 si agregó, 0 si no hay lugar
int agregarMascota(MascotaPtr mascotas[], int n) {
    for(int i=0; i < n; i++) {
        if(strlen(mascotas[i]->nombre) == 0) {  // posición libre
            printf("Ingrese datos de la nueva mascota para la posicion %d:\n", i+1);
            mascotas[i] = cargarMascota();

            // Verificamos que no hayan ingresado vacío (nombre)
            if(strlen(mascotas[i]->nombre) == 0) {
                printf("No se ingreso nombre valido. Mascota no agregada.\n");
                return 0;
            }
            return 1;
        }
    }
    return 0; // no hay lugar
}
