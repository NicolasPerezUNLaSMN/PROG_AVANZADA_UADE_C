#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "nodo.h"


struct Lista{

    NodoPtr primero;

};


typedef struct Lista * ListaPtr;

ListaPtr crearLista(); ///


void insertarPrimero(ListaPtr lista, int dato);///
void insertarUltimo(ListaPtr lista, int dato); //tarea <----
void insertarPosicion(ListaPtr lista, int dato, int posicion); //tarea x


int obtenerPrimero(ListaPtr lista); //tarea <----
int obtenerUltimo(ListaPtr lista); //tarea <----
int obtenerPosicion(ListaPtr lista,int pos); //tarea

int eliminarPrimero(ListaPtr lista); //tarea <----
int eliminarUltimo(ListaPtr lista); //tarea <----
int eliminarPosicion(ListaPtr lista, int pos); //tarea

NodoPtr obtenerPrimeroNodo(ListaPtr lista);
NodoPtr obtenerUltimoNodo(ListaPtr lista); //tarea
NodoPtr obtenerPosicionNodo(ListaPtr lista,int pos); //tarea

int obtenerTamanio(ListaPtr lista); ///tarea <----

void ordenarLista(ListaPtr lista);///tarea <---- x
ListaPtr ordenarListaCopia(ListaPtr lista);//tarea
ListaPtr duplicarLista(ListaPtr lista);//tarea

int buscarElemento(ListaPtr lista, int datoBuscado);//tarea

void insertarEnOrden(ListaPtr lista, int dato);//tarea, si la lista está ordenada cada vez que
//se inserta se inserta en la posición que corresponda


void mostrarLista(ListaPtr lista); ///

void liberarLista(ListaPtr lista); ///


#endif // LISTA_H_INCLUDED
