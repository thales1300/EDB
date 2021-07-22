#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <cstdio>
#include <iostream>
#include <limits>

class Queue{
    public:
        size_t size(){
            return queueCount;
        }
    
        void pushBack(int value){
            if (first != nullptr) {
                
                Node* other = new Node();

                other->value = value;
                last->next = other;
                other->prev = last;
                last = other;

                ++queueCount;
            } else {
                first = new Node();
                first->value = value;
                last = first;
                ++queueCount;
            }
        }

        void popFront(){
            Node* currentNode = first;

            first = currentNode->next;
            delete currentNode;
            --queueCount;
        }

        int front(){
            return first->value;
        }
        int back(){
            return last->value;
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

        ~Queue(){
            if (queueCount == 0) {
                return;
            }

            Node* current = first;

            while (current != nullptr) {
                Node* tmp = current->next;
                delete current;
                current = tmp;
            }

            queueCount = 0;
            first = nullptr;
        }
    private:
        size_t queueCount = 0;
        struct Node{
            int value;
            Node* next;
            Node* prev;
        };
        Node* first = nullptr;
        Node* last = nullptr;
};

#endif