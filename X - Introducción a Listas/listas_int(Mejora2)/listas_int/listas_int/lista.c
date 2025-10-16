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


void insertarUltimo(ListaPtr lista, int dato){

    NodoPtr actual = lista->primero;

    if(actual==NULL){ ///Lista no tiene nodos
        insertarPrimero(lista, dato);
    }else{

        ///  3   4    5     6  XX ->NULL  (TAM 4)
        for ( int i = 0; i<obtenerTamanio(lista)-1; i++){

            actual = actual->siguiente;
        }

        actual ->siguiente = crearNodo(dato,NULL);


    }


}; //tarea
void insertarPosicion(ListaPtr lista, int dato, int posicion){

    int tam = obtenerTamanio(lista);

    /// 1 2 3 ///TAM 3
    if(posicion > tam+1){

        printf("\n\nERROR, no se puede insertar en pos que no existen!!!");

    }else{

        if(posicion<0){

            printf("\n\nERROR, no se puede insertar en pos negativas!!!");
        }else{  ///0 _ _ _ _  tam

            if(posicion == 0){

                insertarPrimero(lista, dato);
            }else{
                if(posicion==tam){

                    insertarUltimo(lista, dato);
                }else{

                    if(posicion>0 && posicion<tam){ ///ALGORITMO
                        /// 12  23  33  XX  34  55     POS 3  ///TAM 5
                        NodoPtr actual = lista->primero;

                        for ( int i = 0 ; i<posicion-1; i++){

                            actual= actual->siguiente;

                        }

                        actual->siguiente = crearNodo(dato, actual->siguiente);



                    }

                }
              }





        }



    }



}; //tarea


int obtenerPrimero(ListaPtr lista); //tarea
int obtenerUltimo(ListaPtr lista); //tarea
int obtenerPosicion(ListaPtr lista, int pos); //tarea


int eliminarPrimero(ListaPtr lista);
int eliminarUltimo(ListaPtr lista); //tarea
int eliminarPosicion(ListaPtr lista, int pos); //tarea

NodoPtr obtenerPrimeroNodo(ListaPtr lista);
NodoPtr obtenerUltimoNodo(ListaPtr lista); //tarea
NodoPtr obtenerPosicionNodo(ListaPtr lista,int pos); //tarea

int obtenerTamanio(ListaPtr lista){

    int i = 0;

    NodoPtr actual = lista->primero;

    while(actual!=NULL){
        i++;
        actual = actual->siguiente;
    }

    return i;

}; //tarea

void ordenarLista(ListaPtr lista){ ///Burbuja

    int aux;

    NodoPtr actual = lista->primero;

    for ( int i = 0 ; i<obtenerTamanio(lista);i++){

         for ( int j = 0 ; j<obtenerTamanio(lista)-1;j++){


                if ( actual->dato > actual->siguiente->dato){

                    aux = actual->dato;
                    actual->dato = actual->siguiente->dato;
                    actual->siguiente->dato = aux;
                }

                actual = actual->siguiente;

        }

        actual = lista->primero;


    }



};///tarea


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
