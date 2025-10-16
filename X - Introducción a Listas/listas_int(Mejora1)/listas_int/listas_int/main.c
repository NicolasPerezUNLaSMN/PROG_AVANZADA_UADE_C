#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

int main()
{
    ListaPtr lista = crearLista();

    mostrarLista(lista);

    insertarPrimero(lista, 4);
    insertarPrimero(lista, 1);
    insertarPrimero(lista, -26);
    insertarPrimero(lista, 96);

    mostrarLista(lista);




    return 0;
}
