#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"



NodoPtr crearNodo(int dato, NodoPtr siguiente){


    NodoPtr nodo = (NodoPtr) malloc(sizeof(struct Nodo));

    nodo->dato = dato;
    nodo->siguiente = siguiente;

    return nodo;

};

void mostrarNodo(NodoPtr nodo){

    printf("{ %d }", nodo->dato);

};


void liberarNodo(NodoPtr nodo){

    free(nodo);


};
