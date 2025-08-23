#include <stdio.h>
#include <stdlib.h>

// Estructura de nodo
typedef struct Nodo {
    int dato;
    struct Nodo* siguiente;
} Nodo;

// Función para crear un nuevo nodo
Nodo* crearNodo(int dato) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

// Función para insertar un nodo al final de la lista circular
void insertarFinal(Nodo** cabeza, int dato) {
    Nodo* nuevoNodo = crearNodo(dato);

    if (*cabeza == NULL) {
        *cabeza = nuevoNodo;
        nuevoNodo->siguiente = *cabeza;
    }
    else {
        Nodo* temp = *cabeza;
        while (temp->siguiente != *cabeza) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevoNodo;
        nuevoNodo->siguiente = *cabeza;
    }
}

// Función para eliminar un nodo por su valor
void eliminarNodo(Nodo** cabeza, int valor) {
    if (*cabeza == NULL) {
        printf("La lista está vacía.\n");
        return;
    }

    Nodo* actual = *cabeza;
    Nodo* anterior = NULL;

    // Caso especial: si solo hay un nodo
    if (actual->siguiente == *cabeza && actual->dato == valor) {
        free(actual);
        *cabeza = NULL;
        printf("Nodo con valor %d eliminado.\n", valor);
        return;
    }

    // Buscar el nodo a eliminar
    do {
        if (actual->dato == valor) {
            if (anterior == NULL) {
                // Caso especial: eliminar el primer nodo
                Nodo* temp = *cabeza;

                // Encuentra el último nodo para actualizar su enlace
                while (temp->siguiente != *cabeza) {
                    temp = temp->siguiente;
                }
                temp->siguiente = actual->siguiente;
                *cabeza = actual->siguiente;
            }
            else {
                // Caso general: nodo intermedio o final
                anterior->siguiente = actual->siguiente;
            }
            free(actual);
            printf("Nodo con valor %d eliminado.\n", valor);
            return;
        }
        anterior = actual;
        actual = actual->siguiente;
    } while (actual != *cabeza);

    // Si no se encuentra el nodo
    printf("Nodo con valor %d no encontrado.\n", valor);
}

// Función para imprimir los elementos de la lista circular
void imprimirLista(Nodo* cabeza) {
    if (cabeza == NULL) {
        printf("La lista está vacía.\n");
        return;
    }

    Nodo* temp = cabeza;
    do {
        printf("%d -> ", temp->dato);
        temp = temp->siguiente;
    } while (temp != cabeza);
    printf("(vuelve al inicio)\n");
}

// Función principal
int main() {
    Nodo* cabeza = NULL;

    // Insertar elementos en la lista circular
    insertarFinal(&cabeza, 10);
    insertarFinal(&cabeza, 20);
    insertarFinal(&cabeza, 30);
    insertarFinal(&cabeza, 40);

    // Imprimir la lista circular
    printf("Elementos en la lista circular:\n");
    imprimirLista(cabeza);

    // Eliminar nodos
    printf("\nEliminando nodo con valor 20:\n");
    eliminarNodo(&cabeza, 20);
    imprimirLista(cabeza);

    printf("\nEliminando nodo con valor 10:\n");
    eliminarNodo(&cabeza, 10);
    imprimirLista(cabeza);

    printf("\nEliminando nodo con valor 40:\n");
    eliminarNodo(&cabeza, 40);
    imprimirLista(cabeza);

    printf("\nEliminando nodo con valor 30:\n");
    eliminarNodo(&cabeza, 30);
    imprimirLista(cabeza);

    return 0;
}
