#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura de un nodo
typedef struct Nodo {
    int dato;
    struct Nodo* prev;
    struct Nodo* next;
} Nodo;

// Función para crear un nuevo nodo
Nodo* crearNodo(int dato) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->dato = dato;
    nuevoNodo->prev = NULL;
    nuevoNodo->next = NULL;
    return nuevoNodo;
}

// Función para insertar un nodo al principio
void insertarInicio(Nodo** cabeza, int dato) {
    Nodo* nuevoNodo = crearNodo(dato);
    if (*cabeza == NULL) {
        *cabeza = nuevoNodo;
    }
    else {
        nuevoNodo->next = *cabeza;
        (*cabeza)->prev = nuevoNodo;
        *cabeza = nuevoNodo;
    }
}

// Función para insertar un nodo al final
void insertarFinal(Nodo** cabeza, int dato) {
    Nodo* nuevoNodo = crearNodo(dato);
    if (*cabeza == NULL) {
        *cabeza = nuevoNodo;
    }
    else {
        Nodo* temp = *cabeza;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = nuevoNodo;
        nuevoNodo->prev = temp;
    }
}

// Función para insertar un nodo en una posición específica
void insertarPosicion(Nodo** cabeza, int dato, int posicion) {
    if (posicion == 0) {
        insertarInicio(cabeza, dato);
        return;
    }

    Nodo* nuevoNodo = crearNodo(dato);
    Nodo* temp = *cabeza;

    for (int i = 0; i < posicion - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("La posición %d está fuera de los límites. Insertando al final.\n", posicion);
        insertarFinal(cabeza, dato);
    }
    else {
        nuevoNodo->next = temp->next;
        nuevoNodo->prev = temp;

        if (temp->next != NULL) {
            temp->next->prev = nuevoNodo;
        }

        temp->next = nuevoNodo;
    }
}

// Función para eliminar un nodo al principio
void eliminarInicio(Nodo** cabeza) {
    if (*cabeza == NULL) {
        printf("La lista está vacía.\n");
        return;
    }

    Nodo* temp = *cabeza;
    *cabeza = (*cabeza)->next;

    if (*cabeza != NULL) {
        (*cabeza)->prev = NULL;
    }

    free(temp);
    printf("Nodo eliminado al inicio.\n");
}

// Función para eliminar un nodo al final
void eliminarFinal(Nodo** cabeza) {
    if (*cabeza == NULL) {
        printf("La lista está vacía.\n");
        return;
    }

    Nodo* temp = *cabeza;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    }
    else {
        *cabeza = NULL; // Si era el único nodo
    }

    free(temp);
    printf("Nodo eliminado al final.\n");
}

// Función para eliminar un nodo en una posición específica
void eliminarPosicion(Nodo** cabeza, int posicion) {
    if (*cabeza == NULL) {
        printf("La lista está vacía.\n");
        return;
    }

    if (posicion == 0) {
        eliminarInicio(cabeza);
        return;
    }

    Nodo* temp = *cabeza;

    for (int i = 0; i < posicion && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("La posición %d está fuera de los límites.\n", posicion);
        return;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    free(temp);
    printf("Nodo eliminado en la posición %d.\n", posicion);
}

// Función para imprimir la lista hacia adelante
void imprimirAdelante(Nodo* cabeza) {
    Nodo* temp = cabeza;
    printf("Lista hacia adelante: ");
    while (temp != NULL) {
        printf("%d -> ", temp->dato);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Función para imprimir la lista hacia atrás
void imprimirAtras(Nodo* cabeza) {
    if (cabeza == NULL) {
        printf("La lista está vacía.\n");
        return;
    }
    Nodo* temp = cabeza;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    printf("Lista hacia atrás: ");
    while (temp != NULL) {
        printf("%d -> ", temp->dato);
        temp = temp->prev;
    }
    printf("NULL\n");
}

// Función principal
int main() {
    Nodo* cabeza = NULL;

    // Insertar elementos en la lista
    insertarInicio(&cabeza, 10);
    insertarFinal(&cabeza, 20);
    insertarPosicion(&cabeza, 15, 1);
    insertarFinal(&cabeza, 30);

    // Imprimir la lista en ambas direcciones
    imprimirAdelante(cabeza);
    imprimirAtras(cabeza);

    // Eliminar nodos
    eliminarInicio(&cabeza);
    imprimirAdelante(cabeza);

    eliminarPosicion(&cabeza, 1);
    imprimirAdelante(cabeza);

    eliminarFinal(&cabeza);
    imprimirAdelante(cabeza);

    return 0;
}
