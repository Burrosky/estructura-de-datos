#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;


typedef struct Libro {
    char titulo[50];
    char autor[50];
    char isbn[20];
}Libro;

typedef struct Nodo {
    Libro libro;
    struct Nodo* siguiente;
}Nodo;

typedef struct Lista {
    Nodo* cabeza;
    int longitud;
}Lista;

Nodo* crearNodo(Libro* libro) {

    Nodo* nodo = (Nodo*)malloc(sizeof(Nodo));

    strncpy_s(nodo->libro.titulo, libro->titulo, 50);
    strncpy_s(nodo->libro.autor, libro->autor, 50);
    strncpy_s(nodo->libro.isbn, libro->isbn, 13);
    nodo->siguiente = NULL;
    return nodo;
}

void destruirNodo(Nodo* nodo) {
    free(nodo);
}

void insertarPrincipio(Lista* lista, Libro* libro) {
    Nodo* nodo = crearNodo(libro);
    nodo->siguiente = lista->cabeza;
    lista->cabeza = nodo;
    lista->longitud++;
}

void insertarFinal(Lista* lista, Libro* libro) {
    Nodo* nodo = crearNodo(libro);
    if (lista->cabeza == NULL) {
        lista->cabeza = nodo;
    }
    else {
        Nodo* puntero = lista->cabeza;

        while (puntero->siguiente)
        { 
            puntero = puntero->siguiente;
        }
            

        puntero->siguiente = nodo;
    }
    lista->longitud++;
}

void insertarDespues(int n, Lista* lista, Libro* libro) {
    Nodo* nodo = crearNodo(libro);
    if (lista->cabeza == NULL)
        lista->cabeza = nodo;
    else {
        Nodo* puntero = lista->cabeza;
        int posicion = 0;
        while (posicion < n && puntero->siguiente) {
            puntero = puntero->siguiente;
            posicion++;
        }
        nodo->siguiente = puntero->siguiente;
        puntero->siguiente = nodo;
    }
    lista->longitud++;
}

void obtener(int n, Lista* lista) {
    if (lista->cabeza == NULL)
    {
        printf("Sin libros para ver \n");
    }
    else {
        Nodo* puntero = lista->cabeza;
        int posicion = 0;
        while (posicion < n && puntero->siguiente) {
            puntero = puntero->siguiente;
            posicion++;
        }
        if (posicion != n) {
            printf("Error durante el recorrido \n");
        } 
        else {
            printf("Titulo: %s\n", puntero->libro.titulo);
            printf("Autor: %s\n", puntero->libro.autor);
            printf("ISBN: %s\n", puntero->libro.isbn);
        }
           
    }
}

int contar(Lista* lista) {
    return lista->longitud;
}

void eliminarPrincipio(Lista* lista) {
    if (lista->cabeza) {
        Nodo* eliminado = lista->cabeza;
        lista->cabeza = lista->cabeza->siguiente;
        destruirNodo(eliminado);
        lista->longitud--;
    }
    else {
        printf("Sin libros para eliminar \n");
    }
}

void eliminarUltimo(Lista* lista) {
    if (lista->cabeza) {
        if (lista->cabeza->siguiente) {
            Nodo* puntero = lista->cabeza;
            while (puntero->siguiente->siguiente)
            {
                puntero = puntero->siguiente;
            }
        
            Nodo* eliminado = puntero->siguiente;
            puntero->siguiente = NULL;
            destruirNodo(eliminado);
            lista->longitud--;
        }
        else {
            Nodo* eliminado = lista->cabeza;
            lista->cabeza = NULL;
            destruirNodo(eliminado);
            lista->longitud--;
        }
    }
    else {
        printf("Sin libros para eliminar \n");
    }
}

void eliminarElemento(int n, Lista* lista) {
    if (lista->cabeza) {
        if (n == 0) {
            Nodo* eliminado = lista->cabeza;
            lista->cabeza = lista->cabeza->siguiente;
            destruirNodo(eliminado);
            lista->longitud--;
        }
        else if (n < lista->longitud) {
            Nodo* puntero = lista->cabeza;
            int posicion = 0;
            while (posicion < (n - 1)) {
                puntero = puntero->siguiente;
                posicion++;
            }
            Nodo* eliminado = puntero->siguiente;
            puntero->siguiente = eliminado->siguiente;
            destruirNodo(eliminado);
            lista->longitud;
        }
    }
    else {
        printf("Sin libros para eliminar \n");
    }
}

void recorrerLista(Lista* lista) {
    Nodo* actual = lista->cabeza;
    while (actual != NULL) {
        printf("Titulo: %s\n", actual->libro.titulo);
        printf("Autor: %s\n", actual->libro.autor);
        printf("ISBN: %s\n", actual->libro.isbn);
        actual = actual->siguiente;
    }
}

void inicializarLista(Lista* lista) {
    lista->cabeza = NULL;
    lista->longitud = 0;
}


int main() {
    char op;
    int n;
    Lista* lista = new Lista;
    Libro* libro = new Libro;

    inicializarLista(lista);

    do {

         cout << "Ingrese una opcion: \n 1) Ingresar libros \n 2) Eliminar libros \n 3) Obtener libros " << endl;
         cin >> op;

        if (op == '1')
        {
            cout << "Ingrese el titulo del libro: " << endl;

            cin >> libro->titulo;

            cout << "Ingrese el autor del libro: " << endl;

            cin >> libro->autor;

            cout << "Ingrese el ISBN del libro: " << endl;

            cin >> libro->isbn;

            cout << "Ingrese una opcion: \n 1) Ingresar al principio \n 2) Ingresar al final \n 3) Ingresar despues de n posicion \n" << endl;
            cin >> op;

            if (op == '1')
            {
                insertarPrincipio(lista, libro);
            }
            else if(op == '2') {
                insertarFinal(lista, libro);
            }
            else if (op == '3') {
                
                cout << "Ingrese n posicion \n" << endl;
                cin >> n;

                insertarDespues(n, lista, libro);
            }

        }
        else if (op == '2') {

            cout << "Ingrese una opcion: \n 1) Eliminar al principio \n 2) Eliminar al final \n 3) Eliminar n posicion \n Total de libros:"  << lista->longitud << "\n" << endl;
            cin >> op;

            if (op == '1')
            {
                eliminarPrincipio(lista);
            }
            else if (op == '2') {
                eliminarUltimo(lista);
            }
            else if (op == '3') {
                
                cout << "Ingrese n posicion \n" << endl;
                cin >> n;

                eliminarElemento(n, lista);
            }

        }
        else if (op == '3') {

            cout << "Ingrese una opcion: \n 1) Ver todos los libros \n 2) Ver un libro especifico \n Total de libros:" << lista->longitud << "\n" << endl;
            cin >> op;

            if (op == '1')
            {
                recorrerLista(lista);
            }
            else if (op == '2') {
                cout << "Ingrese n posicion \n" << endl;
                cin >> n;

                obtener(n, lista);
            }

        }
      
        cout << "Quiere ingresar otro libro, eliminar o ver (1 = si, 2 = no): \n ";
        cin >> op;

    }while (op == '1');


   // recorrerLista(lista);

    return 0;
}