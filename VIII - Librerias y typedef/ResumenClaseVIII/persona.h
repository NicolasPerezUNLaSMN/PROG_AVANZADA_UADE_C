#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED


#define MAX_MASCOTAS 3

#include "mascota.h"

// Definici�n de la estructura Persona con array de mascotas
struct Persona {
    char nombre[20];
    int edad;
    float altura;
    MascotaPtr mascotas[MAX_MASCOTAS];
};

typedef struct Persona * PersonaPtr;

// ======================
//      PROTOTIPOS
// ======================


// Persona
PersonaPtr cargarPersonaTeclado();
void mostrarPersona(PersonaPtr p);

#endif // PERSONA_H_INCLUDED
