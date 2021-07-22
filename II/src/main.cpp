#include "LinkedList.hpp"
#include "Stack.hpp"
#include "Queue.hpp"

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

int main(int argc, char const *argv[]){
    
    if (argc > 2){
        std::cout << "Uso: " << argv[0] <<" instrucoes.txt" << "\n";
        return 1;
    }

    LinkedList<int> l;
    Stack s;
    Queue q;

    std::ifstream arquivo_entrada("instrucoes.txt");
    if(!arquivo_entrada.is_open()){
        std::cerr << "arquivo não existe " <<"\n";
        return 1;
    }
    std::string mensagemArquivo;
    
    while(!arquivo_entrada.eof()){  
        getline(arquivo_entrada, mensagemArquivo);
        if(mensagemArquivo.empty()){
            continue;
        }
        std::string estrutura;
        std::string operacao;
        int value = 0;
        int position = 0;
        std::stringstream stream(mensagemArquivo);
        stream >> estrutura;
        stream >> operacao;
        if (operacao == "insertAtBack" || "insertAtFront"|| "push" || "pushBack"){
            stream >> value;
        }else if (operacao == "insetAt"){
            stream >> value;
            stream >> position;
        }else if (operacao == "removeAt"){
            stream >> position;
        }
        
        if (estrutura == "list"){
            if (operacao == "size"){
                size_t size = l.size();
                std::cout << "Tamanho da Lista: " << size << "\n";
            }else if (operacao == "insertAt"){
                std::cout << "Inserindo elemento na posição " <<  position << " da lista:" << value << "\n";
                l.insertAt(value, position+1);
            }else if (operacao == "removeAt"){
                std::cout << "Removendo elemento da posição: "<< position << "\n";
                l.removeAt(position);
            }else if (operacao == "insertAtFront"){
                std::cout << "Inserindo elemento no inicio da lista:  "<< value << "\n";
                l.insertAtFront(value);
            }else if (operacao == "insertAtBack"){
                std::cout << "Inserindo elemento no fim da lista:  "<< value << "\n";
                l.insertAtBack(value);
            }else if (operacao == "removeAtFront"){
                std::cout << "Removendo elemento do inicio da lista."<< "\n";
                l.removeAtFront();
            }else if (operacao == "size"){
                std::cout << "Removendo elemento do fim da lista."<< "\n";
                l.removeAtBack();
            }else if (operacao == "print"){
                std::cout << "Imprimindo lista:" << "\n";
                l.print();
            }
            
        }else if (estrutura == "stack"){
            if (operacao == "size"){
                size_t size = s.size();
                std::cout << "Tamanho da Pilha: " << size << "\n";
            }else if(operacao == "push"){
                std::cout << "Inserindo elemento na pilha: " << value << "\n";
                s.push(value);
            }else if(operacao == "top"){
                int top = s.top();
                std::cout << "Elemento do topo da  pilha: " << top << "\n";
            }else if(operacao == "pop"){
                std::cout << "Removendo elemento do topo da pilha" << "\n";
                s.pop();
            }
        }else if (estrutura == "queue"){
            if (operacao == "size"){
                size_t size = q.size();
                std::cout << "Tamanho da Fila: " << size << "\n";
            }else if (operacao == "pushBack"){
                std::cout << "Inserindo elemento na fila: " << value << "\n";
                q.pushBack(value);
            }else if(operacao == "popFront"){
                std::cout << "Removendo elemento da fila" << "\n";
                q.popFront();
            }else if(operacao == "front"){
                int front = q.front();
                std::cout << "primeiro elemento da fila: " << front << "\n";
            }
            else if(operacao == "back"){
                int back = q.back();
                std::cout << "ultimo elemento da fila: " << back << "\n";
            }
        }else if (estrutura != "queue" || "stack" || "list"){
            std::cout << "comando não encontrado, README.md para mais informações" << "\n";
        }
         
    }
   
    return 0;
}