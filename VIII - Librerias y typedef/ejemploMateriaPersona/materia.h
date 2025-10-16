#ifndef MATERIA_H_INCLUDED
#define MATERIA_H_INCLUDED


#include "persona.h"

struct Materia{
    int cod;
    char nombre[25];
    PersonaPtr titular; ///[]cosas
};

typedef struct Materia * MateriaPtr;

void mostrarMateria(MateriaPtr m);

MateriaPtr crearMateria(int c, char n[25], PersonaPtr p);



#endif // MATERIA_H_INCLUDED
