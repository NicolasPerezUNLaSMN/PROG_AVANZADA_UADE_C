#include <stdio.h>
#include <string.h>


#include "mascota.h"
#include "persona.h"

// ======================
//      MAIN
// ======================
int main() {
    printf("=== Carga persona y sus 3 mascotas ===\n");
    PersonaPtr p = cargarPersonaTeclado();

    printf("\n=== Mascotas cargadas ===\n");
    mostrarPersona(p);

    printf("\n=== Ordenando mascotas por nombre ===\n");
    ordenarMascotasPorNombre(p->mascotas, MAX_MASCOTAS);
    mostrarPersona(p);

    // Buscar mascota
    char nombreBuscar[20];
    printf("\nIngrese el nombre de la mascota a buscar: ");
    scanf("%19s", nombreBuscar);
    int idx = buscarMascota(p->mascotas, MAX_MASCOTAS, nombreBuscar);
    if (idx != -1) {
        printf("Mascota encontrada en posicion %d:\n", idx);
        mostrarMascota(p->mascotas[idx]);
    } else {
        printf("Mascota '%s' no encontrada.\n", nombreBuscar);
    }

    // Eliminar mascota
    char nombreEliminar[20];
    printf("\nIngrese el nombre de la mascota a eliminar: ");
    scanf("%19s", nombreEliminar);
    int eliminado = eliminarMascota(p->mascotas, MAX_MASCOTAS, nombreEliminar);
    if (eliminado) {
        printf("Mascota '%s' eliminada.\n", nombreEliminar);
    } else {
        printf("No se encontro la mascota '%s' para eliminar.\n", nombreEliminar);
    }

    printf("\n=== Mascotas despues de eliminar ===\n");
    mostrarPersona(p);

    // Intentar agregar una mascota nueva
    printf("\n=== Intentando agregar una mascota nueva ===\n");
    if (agregarMascota(p->mascotas, MAX_MASCOTAS)) {
        printf("Mascota agregada con exito.\n");
    } else {
        printf("No hay espacio para agregar mas mascotas.\n");
    }

    printf("\n=== Mascotas finales ===\n");
    mostrarPersona(p);

    return 0;
}



