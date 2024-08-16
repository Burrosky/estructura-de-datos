#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

typedef struct Nodo {
    int dato;
    struct Nodo* izquierdo;
    struct Nodo* derecho;
    struct Nodo* padre;
} Nodo;

Nodo Arbol;

Nodo* CrearNodo(int dato, Nodo* padre) {

    Nodo* nodo = (Nodo*)malloc(sizeof(Nodo));
    nodo->dato = dato;
    nodo->derecho = nodo->izquierdo = NULL;
    nodo->padre = padre;
    return nodo;
}

void DestruirNodo(Nodo* nodo) {

    nodo->derecho = nodo->izquierdo = NULL;
    free(nodo);

}


void InsertarConPadre(Nodo* &arbol, Nodo* padre, int dato) {


    if (arbol == NULL)
    {
        arbol = CrearNodo(dato, padre);
    }
    else {
        int dato_raiz = arbol->dato;
        if (dato < dato_raiz)
        {
            InsertarConPadre(arbol->izquierdo, arbol, dato);
        }
        else {
            InsertarConPadre(arbol->derecho, arbol, dato);
        }
    }
}

void Insertar(Nodo* &arbol,  int dato) {

    InsertarConPadre(arbol, NULL, dato);
}

void Preorden(Nodo* arbol) {

    if (arbol == NULL) {
        cout << " - ";
    }
    else
    {
        cout << "( " << arbol->dato;
        Preorden(arbol->izquierdo);
        Preorden(arbol->derecho);
        cout << " )";

    }
    

}

void Inorden(Nodo* arbol) {

    if (arbol == NULL) {
        cout << " - ";
    }
    else
    {
        cout << " ( ";
        Inorden(arbol->izquierdo);
        cout << "" << arbol->dato;
        Inorden(arbol->derecho);
        cout << " ) ";

    }


}

void Postorden(Nodo* arbol) {

    if (arbol == NULL) {
        cout << " - ";
    }
    else
    {
        cout << "( ";
        Postorden(arbol->izquierdo);
        Postorden(arbol->derecho);
        cout << " " << arbol->dato << " )";
        
        

    }


}

int Existencia(Nodo* arbol, int dato) {

    if (arbol == NULL)
    {
        return 0;
    }else if(arbol->dato == dato) {
        return 1;
    }
    else if (dato < arbol->dato) {
        return Existencia(arbol->izquierdo, dato);
    }
    else
    {
        return Existencia(arbol->derecho, dato);
    }
}

Nodo* Obtener(Nodo* arbol, int dato) {

    if (arbol == NULL)
    {
        return NULL;
    }
    else if (arbol->dato == dato) {
        return arbol;
    }
    else if (dato < arbol->dato) {

        return Obtener(arbol->izquierdo, dato);
    }
    else {

        return Obtener(arbol->derecho, dato);
    
    }

}

static void Reemplazar(Nodo* arbol, Nodo* nuevoNodo) {

    if (arbol->padre)
    {
        if (arbol->dato == arbol->padre->izquierdo->dato)
        {
            arbol->padre->izquierdo = nuevoNodo;
        }
        else if (arbol->dato == arbol->padre->derecho->dato) {
            
            arbol->padre->derecho = nuevoNodo;
        }
    }

    if (nuevoNodo)
    {
        nuevoNodo->padre = arbol->padre;

    }

}

static Nodo* Minimo(Nodo* arbol) {

    if (arbol == NULL) {
        return NULL;
    }
    if (arbol->izquierdo)
    {
        return Minimo(arbol->izquierdo);
    }
    else {
        return arbol;
    }

}

static void EliminarNodo(Nodo* nodo) {

    if (nodo->izquierdo && nodo->derecho)
    {
        Nodo* minimo = Minimo(nodo->derecho);
        nodo->dato = minimo->dato;
        EliminarNodo(minimo);

    }
    else if (nodo->izquierdo) {
        Reemplazar(nodo, nodo->izquierdo);
        DestruirNodo(nodo);
    }
    else if (nodo->derecho) {
        Reemplazar(nodo, nodo->derecho);
        DestruirNodo(nodo);
    }
    else {
        Reemplazar(nodo, NULL);
        DestruirNodo(nodo);
    }

}

void Eliminar(Nodo* arbol, int dato) {

    if (arbol == NULL)
    {
        return;
    }
    else if (dato < arbol->dato) {
        Eliminar(arbol->izquierdo, dato);
    }
    else if (dato > arbol->dato) {
        Eliminar(arbol->derecho, dato);
    }
    else {
        EliminarNodo(arbol);
    }

}

 

int main()
{
    Nodo* arbol = NULL;

    Insertar(arbol, 5); Postorden(arbol);  cout << "" << endl;
    Insertar(arbol, 10); Postorden(arbol);  cout << "" << endl;
    Insertar(arbol, 4);  Postorden(arbol);  cout << "" << endl;
    Insertar(arbol, 3);  Postorden(arbol);  cout << "" << endl;
    Insertar(arbol, 4);  Postorden(arbol);  cout << "" << endl;
    Insertar(arbol, 2);  Postorden(arbol);  cout << "" << endl;
    Eliminar(arbol, 4);  Postorden(arbol);  cout << "" << endl;
    Eliminar(arbol, 4);  Postorden(arbol);  cout << "" << endl;

   /* if (Existencia(arbol, 3)) {
        cout << "se, we" << endl;
    } */

    return 0;
}
