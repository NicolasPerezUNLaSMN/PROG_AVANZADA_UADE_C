#include <stdio.h>
#include <stdlib.h>

#include "materia.h"

///TAREA: Crear una materia con UN titular(Persona)
int main()
{
    printf("-------- Clase 9/10 ---- Punteros ------\n");

    ///Desde este momento p1 pasa a valer : AAb12321
    ///Reserva dinamica de la memoria!!!!!
    PersonaPtr p1 = crearPersona("Nico", 36, 92.4);
    MateriaPtr m1 = crearMateria(111, "Progracion", p1);

    mostrarMateria(m1);




    return 0;
}
