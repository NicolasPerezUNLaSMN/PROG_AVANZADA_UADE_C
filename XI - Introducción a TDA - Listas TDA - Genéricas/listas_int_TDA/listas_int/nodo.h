#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

struct Nodo;


typedef struct Nodo * NodoPtr;

int getDato(NodoPtr nodo);
NodoPtr getSiguiente(NodoPtr nodo);

void setDato(NodoPtr nodo, int nuevoDato);
void setSiguiente(NodoPtr nodo, NodoPtr nuevoSiguiente);

NodoPtr crearNodo(int dato, NodoPtr siguiente);
void mostrarNodo(NodoPtr nodo);
void liberarNodo(NodoPtr nodo);





#endif // NODO_H_INCLUDED
