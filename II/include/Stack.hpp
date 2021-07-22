#ifndef STACK_HPP
#define STACK_HPP

#include <cstdio>
#include <iostream>
#include <limits>

class Stack{
    public:
        size_t size(){
            return stackCount;
        }
    
        void push(int value){
            if (first != nullptr) {
                Node* aux = first;
                Node* other = new Node();

                other->value = value;
                other->next = aux;
                first = other;

                ++stackCount;
            }else{
                first = new Node();
                first->value = value;
                ++stackCount;
            }
        }

        int top(){
            return first->value;
        }

        void pop(){
            Node* currentNode = first;

            first = currentNode->next;
            delete currentNode;
            --stackCount;
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

        ~Stack(){
            if (stackCount == 0) {
                return;
            }

            Node* current = first;

            while (current != nullptr) {
                Node* tmp = current->next;
                delete current;
                current = tmp;
            }

            stackCount = 0;
            first = nullptr;
        }
    private:
        size_t stackCount = 0;
        struct Node{
        int value;
        Node* next;
        };
        Node* first = nullptr;
        
};

#endif