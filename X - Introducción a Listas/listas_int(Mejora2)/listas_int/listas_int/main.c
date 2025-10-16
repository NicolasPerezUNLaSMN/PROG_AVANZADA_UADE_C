#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

int main()
{
    ListaPtr lista = crearLista();

    printf("\nTAM: %d", obtenerTamanio(lista));
    mostrarLista(lista);


    insertarUltimo(lista, 34);
    insertarPrimero(lista, 4);
    insertarPrimero(lista, 1);
    insertarUltimo(lista, 11);
    insertarPrimero(lista, -26);
    insertarUltimo(lista, 64);
    insertarPrimero(lista, 96);

    ///85 96 -26 44 1 4 34 11 64 101
    printf("\nTAM: %d", obtenerTamanio(lista));
    mostrarLista(lista);


    ///85 96 -26 44 1 4 34 11 64 101
    insertarPosicion(lista, 44, 2);
    insertarPosicion(lista, 85, 0);
    insertarPosicion(lista, 101, 9);
    insertarPosicion(lista, 85, -1);
    insertarPosicion(lista, 85, 12);
    mostrarLista(lista);


    ordenarLista(lista);
     mostrarLista(lista);




    return 0;
}
