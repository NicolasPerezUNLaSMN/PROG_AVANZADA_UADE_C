#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"


struct Nodo {

    int dato;
    struct Nodo * siguiente;

};


int getDato(NodoPtr nodo){

    return nodo->dato;
};

NodoPtr getSiguiente(NodoPtr nodo){

    return nodo->siguiente;
};

void setDato(NodoPtr nodo, int nuevoDato){

    nodo->dato = nuevoDato;
};

void setSiguiente(NodoPtr nodo, NodoPtr nuevoSiguiente){

    nodo->siguiente = nuevoSiguiente;

};

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
