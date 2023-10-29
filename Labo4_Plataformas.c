//Laboratorio 4: Manfred Soza B97755
#include <stdlib.h>
#include <stdio.h>

//Estructura para los nodos de la lista enlazada
struct Node {
    int data;
    struct Node* next;
};

//Función para eliminar un nodo por valor
void eliminarNodo(int valor, struct Node **nodo) {
    struct Node* actual = *nodo;
    struct Node* prev = NULL;

    //Si el nodo a eliminar es el primer nodo
    if (actual != NULL && actual->data == valor) {
        *nodo = actual->next;
        free(actual);
        return;
    }

    //S busca el nodo en la lista
    while(actual != NULL && actual->data != valor) {
        prev = actual;
        actual = actual->next;
    }

    //Nodo no encontrado
    if (actual == NULL) {
        printf("Nodo no encontrado en la lista\n");
        return;
    }

    //Eliminar el nodo encontrado
    prev->next = actual->next;
    free(actual);
}

//Función para imprimir la lista
void imprimirLista(struct Node* nodo) {
    while (nodo != NULL) {
        printf("%d ", nodo->data);
        nodo = nodo->next;
    }
    printf("\n");
}

//Función para liberar la memoria 
void liberarLista(struct Node* head) {
    struct Node* actual = head;
    struct Node* siguiente;

    while (actual != NULL) {
        siguiente = actual->next;
        free(actual);
        actual = siguiente;
    }
}

//Función para insertar un nodo al principio de la lista
void insertar(int dato, struct Node** head) {
    struct Node* nuevo = (struct Node*)malloc(sizeof(struct Node));
    nuevo->data = dato;
    nuevo->next = *head;
    *head = nuevo;
}

//Función para insertar un nodo al final de la lista
void insertarAlFinal(int dato, struct Node** head) {
    struct Node* nuevo = (struct Node*)malloc(sizeof(struct Node));
    nuevo->data = dato;
    nuevo->next = NULL;

    //Si la lista está vacía, el nuevo nodo se convierte en la cabeza de la lista
    if (*head == NULL) {
        *head = nuevo;
    } else {
        struct Node* actual = *head;
        //Se busca el último nodo en la lista
        while (actual->next != NULL) {
            actual = actual->next;
        }
        //Se conecta el nuevo nodo al último nodo
        actual->next = nuevo;
    }
}

//Función para buscar un nodo por valor
int buscar(int valor, struct Node* head) {
    struct Node* actual = head;
    while (actual != NULL) {
        if (actual->data == valor) {
            return 1; //Nodo encontrado
        }
        actual = actual->next;
    }
    return 0; //Nodo no encontrado
}

//Función para obtener el elemento enésimo
int obtenerElementoN(int indice, struct Node* head) {
    int contador = 0;
    struct Node* actual = head;
    while (actual != NULL) {
        if (contador == indice) {
            return actual->data;
        }
        contador++;
        actual = actual->next;
    }
    printf("Elemento en el índice %d no encontrado.\n", indice);
    return -1;
}

int main() {
    struct Node* head = NULL;
    int dato;

    printf("1. Nodo agregado: ");
    insertar(10, &head);
    imprimirLista(head);

    printf("2. Nodo eliminado por valor: 10");
    dato = 10;
    eliminarNodo(dato, &head);
    imprimirLista(head);

    printf("3. Nodo agregado al inicio: ");
    insertar(5, &head);
    imprimirLista(head);

    printf("4. Nodo agregado al final: ");
    insertarAlFinal(15, &head);
    imprimirLista(head);

    printf("5. Buscar nodo por su valor: ");
    dato = 5;
    if (buscar(dato, head)) {
        printf("Nodo con valor %d existe en la lista.\n", dato);
    } else {
        printf("Nodo con valor %d no existe en la lista.\n", dato);
    }

    printf("6. Imprimir lista:\n");
    imprimirLista(head);

    printf("7. Obtener el elemento enésimo:\n");
    int indice = 1;
    int elementoN = obtenerElementoN(indice, head);
    if (elementoN != -1) {
        printf("Elemento en el índice %d: %d\n", indice, elementoN);
    }

    liberarLista(head);
}