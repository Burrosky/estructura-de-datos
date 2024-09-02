#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

typedef struct Nodo {
     char dato;
    vector<Nodo*> hijos;
} Nodo;


Nodo* CrearNodo(char dato) {

    
    Nodo* nodo = new Nodo;

    nodo->dato = dato;
    nodo->hijos = {}; 

    return nodo;
}

Nodo* BuscarNodo(Nodo* nodo, char dato_padre) {

    
    if (nodo == nullptr) {
        return nullptr; 
    }

    
    if (nodo->dato == dato_padre) {
        return nodo;
    }

   
    for (auto hijo : nodo->hijos) {
        Nodo* resultado = BuscarNodo(hijo, dato_padre);
        if (resultado != nullptr) {
            return resultado; 
        }
    }

    return nullptr; 
}

void InsertarNodo(Nodo* arbol, char dato_padre, char dato_hijo) {
        
    Nodo* nodo = BuscarNodo(arbol, dato_padre);
    if (nodo != nullptr)
    {
        Nodo* nodo_hijo = CrearNodo(dato_hijo);
        nodo->hijos.push_back(nodo_hijo);
    }
    else
    {
        cout << "El nodo no existe: " << dato_padre << endl;
    }
    
}

void Imprimir(Nodo* arbol, int nivel = 0) {

    if (!arbol) return;

    
    for (int i = 0; i < nivel; i++) cout << "   ";
    cout << arbol->dato << endl;

    
    for (auto hijo : arbol->hijos) {
        Imprimir(hijo, nivel + 1);
    }
}

int CalcularAltura(Nodo* nodo) {
    if (nodo == nullptr) {
        return 0; 
    }

    if (nodo->hijos.empty()) {
        return 1;
    }

    int alturaMaxima = 0;

    for (auto hijo : nodo->hijos) {
       
        alturaMaxima = max(alturaMaxima, CalcularAltura(hijo));
    }

  
    return 1 + alturaMaxima;
}

int main()
{   
    
    Nodo* arbol = CrearNodo('A');
    InsertarNodo(arbol,'A', 'B');
    InsertarNodo(arbol, 'A', 'Z');
  
    InsertarNodo(arbol, 'B', 'C');
    InsertarNodo(arbol, 'B', 'X');
    InsertarNodo(arbol, 'Z', 'W');
    InsertarNodo(arbol, 'Z', 'H');
    InsertarNodo(arbol, 'H', 'L');
    

    Imprimir(arbol);

    
    cout << "La altura del arbol es: " << CalcularAltura(arbol) << endl;

    return 0;
}


