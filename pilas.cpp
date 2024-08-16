#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

typedef const char* URL;

typedef struct Nodo {
    URL url;
    struct Nodo* siguiente;
} Nodo;


typedef struct Pila {
    Nodo* cima;
    int longitud;
    
} Pila;



Nodo* CrearNodo(URL url) {

    Nodo* nodo = (Nodo*)malloc(sizeof(Nodo));
    nodo->url = url;
    nodo->siguiente = NULL;
    return nodo;
}

void DestruirNodo(Nodo* nodo) {
   
    nodo->siguiente = NULL;
    free(nodo);
}

Pila* CrearPila() {
    Pila* pila = (Pila*)malloc(sizeof(Pila));
    pila->cima = NULL;
    pila->longitud = 0;
    return pila;
}

void Desapilar(Pila* pila) {

    if (pila->cima != NULL)
    {
        Nodo* eliminar = pila->cima;
        pila->cima = pila->cima->siguiente;
        DestruirNodo(eliminar);
        pila->longitud--;
    }


}

void DestruirPila(Pila* pila) {

    while (pila->cima != NULL)
    {
        Desapilar(pila);
    }
    free(pila);
}

void Apilar(Pila* pila, URL url) {

    Nodo* nodo = CrearNodo(url);
    nodo->siguiente = pila->cima;
    pila->cima = nodo;
    pila->longitud++;

}

void VerPila(Pila* pila) {
    cout << "Total en la pila: " << pila->longitud << endl;
    
    Nodo* actual = pila->cima;
    while (actual != NULL)
    {
        cout << " " << actual->url << endl;
        actual=actual->siguiente;
    }

}





int main()
{
    
    Pila* pila = CrearPila();

   
    Apilar(pila, "aa");
    Apilar(pila, "bb");
    Apilar(pila, "cc");
    Apilar(pila, "zz");
    Apilar(pila, "xx");
    VerPila(pila);
    Desapilar(pila);
    Desapilar(pila);
    VerPila(pila);
    Apilar(pila, "yy");
    DestruirPila(pila);
    pila = CrearPila();
    VerPila(pila);

    return 0;
}

