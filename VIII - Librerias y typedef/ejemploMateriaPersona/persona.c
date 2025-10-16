#include <stdio.h>
#include <stdlib.h> ///incluir las libr estandar!!!!
#include <string.h>

#include "persona.h" ///poner " y no < >


void mostrarPersona(PersonaPtr p){

    printf("\n------PERSONA----- \n");
    printf("\tNOMBRE: %s\n", p->nombre);
    printf("\tEDAD: %d\n", p->edad);
    printf("\tPESO: %.2f\n", p->peso);

};

///RESERVA DINAMICA DE LA MEMORIA!!!!!!
PersonaPtr crearPersona(char n[25], int e, float p){
    ///Es un puntero local!!!
    ///AAb12321 se va llamar nuevaPersona
    PersonaPtr nuevaPersona = malloc(sizeof(struct Persona)); ///Persona con basura
    ///malloc reserva la memoria para que siga activa
    ///aun cuando saliste de la localidad

    ///AAb12321 -------hasta---- AAb14121  (Bloqueado)!!!

    nuevaPersona->edad = e;
    nuevaPersona->peso = p;
    strcpy(nuevaPersona->nombre, n);

    return  nuevaPersona; ///AAb12321
};
