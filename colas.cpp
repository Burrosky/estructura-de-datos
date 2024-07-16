#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;


typedef struct Nodo {
    int dato;
    struct Nodo* siguiente;
} Nodo;


typedef struct Cola {
    Nodo* primer;
    Nodo* ultimo;
} Cola;


Nodo* CrearNodo(int dato) {

    Nodo* nodo = (Nodo*)malloc(sizeof(Nodo));
    nodo->dato = dato;
    nodo->siguiente = NULL;
    return nodo;
}

void DestruirNodo(Nodo* nodo) {
    nodo->dato = NULL;
    nodo->siguiente = NULL;
    free(nodo);
}

Cola* CrearCola() {
    Cola* cola = (Cola*)malloc(sizeof(Cola));
    cola->primer = cola->ultimo = NULL;
    return cola;
}

void Encolar(Cola* cola, int dato) {
    
    Nodo* nodo = CrearNodo(dato);
    if (!cola->primer)
    {
        cola->primer = nodo;
        cola->ultimo = nodo;
    }
    else
    {
        cola->ultimo->siguiente = nodo;
        cola->ultimo = nodo;
    }
}

int Desencolar(Cola* cola) {
    if (cola->primer == NULL) {
        printf("La cola esta vacia\n");
        return -1;
    }
    
    Nodo* eliminado = cola->primer;
    int valor = eliminado->dato;
    cout << "Valor sacado de la cola:" << valor << "\n" << endl;
    
    cola->primer = cola->primer->siguiente;
    
    if (cola->primer == NULL) {
        cola->ultimo = NULL;
    }
    
    DestruirNodo(eliminado);

    return valor;
}

void EliminarCola(Cola* cola) {
    while (cola->primer)
    {
        Desencolar(cola);
    }
    free(cola);
}

int main()
{
    char op;
    int n;
    Cola* cola = CrearCola();

    do
    {

        cout << "Ingrese una opcion: \n 1) Ingresar elemento a la cola \n 2) Retirar elemento de la cola \n 3) Eliminar cola \n" << endl;
        cin >> op;

        if (op == '1')
        {
            cout << "Ingrese un valor \n" << endl;
            cin >> n;

            Encolar(cola, n);
        }
        else if (op == '2') {
            Desencolar(cola);
           
        }
        else if (op == '3') {

            EliminarCola(cola);
            cola = CrearCola();
        }

        cout << "Ingrese una opcion para ingresar otro elemento a la cola (1 = si, 2 = no): \n ";
        cin >> op;

    } while (op=='1');

    
    return 0;
}

