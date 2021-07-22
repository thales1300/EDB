#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <cstdio>
#include <iostream>
#include <limits>

template <typename T>
class LinkedList{
  public:
    LinkedList(){
    }

    LinkedList(const LinkedList<T>& other){
        clone(other);
    }

    LinkedList& operator=(const LinkedList<T>& other){
        if (&other == this) {
            return *this;
        }

        clear();
        clone(other);
        return *this;
    }

    T& operator[](size_t index){
        if (index >= nodeCount) {
            //erro (lançar exceção)
        }

        Node* current = first;
        size_t currentIndex = 0;

        while (currentIndex < index) {
            current = current->next;
            currentIndex++;
        }

        return current->value;
    }

    ~LinkedList(){
        clear();
    }
    size_t size(){
        return nodeCount;
    }

    void insertAt(T value, size_t position){
        
        if (position > size()) {
            std::cout << "Posição não existe, ultima posição :" << size() << "\n ";
            return;
        }
        size_t currentPosition = 0;
        Node* previousNode = nullptr;
        Node* currentNode = first;

        while (currentPosition < position) {
            previousNode = currentNode;
            currentNode = currentNode->next;

            currentPosition++;
        }

        if (position == 0) {
            if(nodeCount == 0){
                first = new Node();
                first->value = value;
                last = first;
                ++nodeCount;    
            }else{
                Node* other = new Node();

                other->value = value;
                other->next = currentNode;
                currentNode->prev = first;
                first = other;
                ++nodeCount;
            }
        } else {
            if (nodeCount == position){
               Node* other = new Node();

                other->value = value;
                last->next = other;
                other->prev = last;
                last = other;

                ++nodeCount;
            }else{
                Node* other = new Node();
            
                previousNode->next = other;
                other->value = value;
                other->next = currentNode;
                other->prev = previousNode;
                currentNode->prev = other;
                
                ++nodeCount;
            }
            
        }
    }

    void removeAt(size_t position){
        // 1.verificar se a posição é válida
        if (position >= size()) {
            std::cout << "Posição não existe, ultima posição: " << size() << "\n ";
            return;
        }

        // 2.ir até o elemento
        size_t currentPosition = 0;
        Node* previousNode = nullptr;
        Node* currentNode = first;

        while (currentPosition < position) {
            previousNode = currentNode;
            currentNode = currentNode->next;

            currentPosition++;
        }

        if (position == 0) {
            first = currentNode->next;
            delete currentNode;
            --nodeCount;
        } else {
            previousNode->next = currentNode->next;
            delete currentNode;
            --nodeCount;
        }
    }

    void insertAtFront(T value){
        if (first != nullptr) {
            Node* aux = first;
            Node* other = new Node();

            other->value = value;
            other->next = aux;
            aux->prev = first;
            first = other;

            ++nodeCount;
        }else{
            first = new Node();
            first->value = value;
            last = first;
            ++nodeCount;
        }
        
    }

    void insertAtBack(T value){
        if (first != nullptr) {
            
            Node* other = new Node();

            other->value = value;
            last->next = other;
            other->prev = last;
            last = other;

            ++nodeCount;
        } else {
            first = new Node();
            first->value = value;
            last = first;
            ++nodeCount;
        }
    }

    void removeAtFront(){

        Node* currentNode = first;

        first = currentNode->next;
        delete currentNode;
        --nodeCount;
    }

    void removeAtBack(){ // revisar, erro
        Node* currentNode = last;

        last = currentNode->prev;
        delete currentNode;
        last->next = nullptr;
        --nodeCount;
    }

    void print(){
        if (size() == 0) {
            return;
        }

        Node* current = first;

        do {
            std::cout << current->value << std::endl;
            current = current->next;
        } while (current != nullptr);
    }


    void clear(){
        if (nodeCount == 0) {
            return;
        }

        Node* current = first;

        while (current != nullptr) {
            Node* tmp = current->next;
            delete current;
            current = tmp;
        }

        nodeCount = 0;
        first = nullptr;
    }

  private:
    struct Node{
        T value;
        Node* next;
        Node* prev;
    };

    void clone(const LinkedList& other){
        if (other.nodeCount == 0) {
            return;
        }

        Node* current = other.first;

        while (current != nullptr) {
            insertAtBack(current->value);
            current = current->next;
        }
    }

    Node* first = nullptr;
    Node* last = nullptr;
    size_t nodeCount = 0;
};
#endif
