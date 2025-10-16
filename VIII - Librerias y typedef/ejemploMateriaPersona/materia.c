#include <stdio.h>
#include <stdlib.h> ///incluir las libr estandar!!!!
#include <string.h>

#include "materia.h" ///poner " y no < >


void mostrarMateria(MateriaPtr m){


    printf("\n------ Materia ---------\n");
    printf("CODIGO: %d\n", m->cod);
    printf("NOMBRE: %s\n", m->nombre);

    mostrarPersona(m->titular); ///Mostrar los datos del titular

};

MateriaPtr crearMateria(int c, char n[25], PersonaPtr p){

    MateriaPtr materia = malloc(sizeof(struct Materia));

    materia->cod = c;

    materia->titular = p; ///Nuevo

    strcpy(materia->nombre, n);

    return materia;

};
