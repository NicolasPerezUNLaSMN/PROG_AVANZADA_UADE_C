#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED


//Aca escribir!!!
struct Persona{
    char nombre[25];
    int edad;
    float peso;
};

typedef struct Persona * PersonaPtr;


void mostrarPersona(PersonaPtr p);

PersonaPtr crearPersona(char n[25], int e, float p);



#endif // PERSONA_H_INCLUDED
