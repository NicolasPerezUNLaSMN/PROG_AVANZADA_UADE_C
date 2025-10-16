#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

ListaPtr crearLista(){

    ListaPtr lista = (ListaPtr) malloc(sizeof(struct Lista));

    lista->primero = NULL;

    return lista;
};

/// 11 3  4   23   32
void insertarPrimero(ListaPtr lista, int dato){

    NodoPtr nuevoNodo = crearNodo(dato, lista->primero);

    lista->primero = nuevoNodo;


};


void insertarUltimo(ListaPtr lista, int dato); //tarea
void insertarPosicion(ListaPtr lista, int dato, int posicion); //tarea


int obtenerPrimero(ListaPtr lista); //tarea
int obtenerUltimo(ListaPtr lista); //tarea
int obtenerPosicion(ListaPtr lista, int pos); //tarea


int eliminarPrimero(ListaPtr lista);
int eliminarUltimo(ListaPtr lista); //tarea
int eliminarPosicion(ListaPtr lista, int pos); //tarea

NodoPtr obtenerPrimeroNodo(ListaPtr lista);
NodoPtr obtenerUltimoNodo(ListaPtr lista); //tarea
NodoPtr obtenerPosicionNodo(ListaPtr lista,int pos); //tarea

int obtenerTamanio(ListaPtr lista); //tarea

void ordenarLista(ListaPtr lista);//tarea
ListaPtr ordenarListaCopia(ListaPtr lista);//tarea
ListaPtr duplicarLista(ListaPtr lista);//tarea

int buscarElemento(ListaPtr lista, int datoBuscado);//tarea

void insertarEnOrden(ListaPtr lista, int dato);//tarea, si la lista está ordenada cada vez que
//se inserta se inserta en la posición que corresponda


void mostrarLista(ListaPtr lista){

    printf("\n<LISTA>\n");
    NodoPtr actual = lista->primero;

    while (actual!=NULL){

        mostrarNodo(actual);
        actual = actual->siguiente;
    }
    printf("\n\n");



};

void liberarLista(ListaPtr lista) {

    NodoPtr actual = lista->primero;

    while (actual!=NULL){

        NodoPtr aux = actual;

        free(actual);
        actual = aux->siguiente;
    };

    free(lista);
}
