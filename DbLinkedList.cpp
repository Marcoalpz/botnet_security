#include "DbLinkedList.h"
#include <iostream>
#include <limits>
using namespace std;

DbLinkedList::DbLinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
}

DbLinkedList::~DbLinkedList() {
    while (!this->isEmpty()) {
        this->removeFirst();
    }
}

/*
    first()
    Devuelve el primer elemento de la lista
    Complejidad: O(1)
*/

Falla DbLinkedList::first() {
    if (this->size > 0) {
        return this->head->falla;
    } else {
        throw invalid_argument("No existe el elemento.");
    }
}

/*
    last()
    Devuelve el último elemento de la lista
    Complejidad: O(1)
*/
Falla DbLinkedList::last() {
    if (this->size > 0) {
        return this->tail->falla;
    } else {
        throw invalid_argument("No existe el elemento.");
    }
}

/*
    length()
    Devuelve el número de nodos que la lista contiene
    Complejidad: O(1)
*/
int DbLinkedList::length() {
    return this->size;
}

/*
    getAt(int pos)
    Parámetro: número entero que indica posición de la cual se desea obtener el elemento
    Salida: número entero en pos (si existe esa posición)
    Complejidad: O(n)
*/
Falla DbLinkedList::getAt(int pos) {
    if (pos < 0) {
        throw invalid_argument("Posición no puede ser menor a 0.");
    }
    if (pos >= this->size) {
        throw invalid_argument("No se puede acceder al elemento.");
    }
    DbLinkedListNode* current = this->head;
    for (int i = 0; i < pos; i++) {
        current = current->next;
    }
    return current->falla;
}

/*
    isEmpty()
    Salida: valor booleano que indica si la lista está vacía
    Complejidad: O(1)
*/
bool DbLinkedList::isEmpty() {
    return this->head == nullptr;
}

/*
    insertFirst(Falla data)
    Entrada: número entero que se desea insertar al inicio
    Complejidad: O(1)
*/
void DbLinkedList::insertFirst(Falla data) {
    this->head = new DbLinkedListNode(data, nullptr, this->head);
    if (this->size == 0) {
        this->tail = this->head;
    } else if (this->size > 0) {
        this->head->next->prev = head;
    }
    this->size++;
}

/*
    insertLast(Falla data)
    Entrada: número entero que se desea insertar al final
    Complejidad: O(1)
*/
void DbLinkedList::insertLast(Falla data) {
    if (this->size == 0) {
        this->insertFirst(data);
    } else {
        DbLinkedListNode* newNode = new DbLinkedListNode(data,this->tail,nullptr);
        this->tail->next = newNode;
        this->tail = newNode;
        this->size++;
    }
    
}

/*
    insertAt(Falla data, int pos)
    Inserta el valor data en la posición pos
    Entrada: número entero data y número entero pos
    Complejidad: O(n)
*/
void DbLinkedList::insertAt(Falla data, int pos) {
	DbLinkedListNode *newNode = new DbLinkedListNode(data);
	if (pos >= 0 && pos < this->size)
	{
		DbLinkedListNode* current = this->head;
        for (int i = 0; i < pos-1; i++) {
            current = current->next;
        }
		newNode->next = current->next;
        current->next = newNode;
        newNode->next->prev = newNode;
        newNode->prev = current;
		this->size++;
	}
	else
	{
		throw invalid_argument("Posición inválida.");
	}
}

/*
    setAt(Falla data, int pos)
    Cambia el valor en la posición pos por el valor data
    Entrada: número entero data y número entero pos
    Complejidad: O(n)
*/
void DbLinkedList::setAt(Falla falla, int pos) {
    if (pos >= 0 && pos < this->size) {
        DbLinkedListNode* current = this->head;
        for (int i = 0; i < pos; i++) {
            current = current->next;
        }
        current->falla = falla;
    } else {
        throw invalid_argument("Posición inválida.");
    }
}

/*
    removeFirst()
    Elimina el primer nodo de la lista
    Complejidad: O(1)
*/
void DbLinkedList::removeFirst() {
    if (this->size > 0) {
        DbLinkedListNode* headTemp = this->head;
        this->head = this->head->next;
        this->size--;
        if (this->size == 0) {
            this->tail = nullptr;
        } else if (this->size > 0) {
            this->head->prev = nullptr;
        }
        delete headTemp;
    } else {
        throw invalid_argument("No existe el elemento.");
    }
}

/*
    removeLast()
    Elimina el último nodo de la lista
    Complejidad: O(n)
*/
void DbLinkedList::removeLast() {
    if (this->size > 0) {
        DbLinkedListNode* tempTail = this->tail;
        this->tail = this->tail->prev;
        this->size--;
        if (this->size == 0) {
            this->head = nullptr;
        }
        delete tempTail;
    } else {
        throw invalid_argument("No existe el elemento.");
    }
}

/*
    removeAt(int pos)
    Elimina el nodo en pos
    Entrada: número entero que indica la posición
    Complejidad: O(n)
*/
void DbLinkedList::removeAt(int pos) {
    if (pos >= 0 && pos < this->size) {
        if (pos == 0) {
            this->removeFirst();
        } else {
            DbLinkedListNode* current = this->head;
            for (int i = 0; i < pos-1; i++) {
                current = current->next;
            }
            DbLinkedListNode* canceled = current->next;
            current->next = canceled->next;
            current->next->prev = current;
            delete canceled;
            if (pos == this->size-1) {
                this->tail = current;
            }
            this->size--;
        }
    } else {
        throw invalid_argument("Posición inválida.");
    }
}