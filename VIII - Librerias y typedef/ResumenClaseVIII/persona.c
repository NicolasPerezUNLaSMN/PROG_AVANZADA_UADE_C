#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "persona.h"

PersonaPtr cargarPersonaTeclado() {
    PersonaPtr p = (PersonaPtr) malloc(sizeof(struct Persona));

    printf("Ingrese nombre: ");
    scanf("%19s", p->nombre);

    printf("Ingrese edad: ");
    scanf("%d", &p->edad);

    printf("Ingrese altura: ");
    scanf("%f", &p->altura);

    getchar(); // limpiar buffer para fgets

    for(int i = 0; i < MAX_MASCOTAS; i++) {
        printf("\nCarga mascota #%d\n", i+1);
        p->mascotas[i] = cargarMascota();
    }

    return p;
}

void mostrarPersona(PersonaPtr p) {
    printf("Nombre: %s | Edad: %d | Altura: %.2f\n", p->nombre, p->edad, p->altura);
    printf("Mascotas:\n");
    for(int i = 0; i < MAX_MASCOTAS; i++) {
        printf("  [%d] ", i);
        mostrarMascota(p->mascotas[i]);
    }
}
