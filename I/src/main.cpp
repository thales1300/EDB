#include "lista.hpp"
#include "gabarito.hpp"
#include "order.hpp"

#include <iostream>
#include <string>

int main(int argc, char const *argv[]){
    
    if (argc == 1){
        std::cout << "Uso: " << argv[0] <<"respostas.txt " <<"gabarito.txt " <<"\n"
        << "best X Y" << "\n" <<"worst X Y" << "\n" << "best-questions X Y" 
        << "\n" << "worst-questions X Y"<<"\n" << "blank-questions X Y";
        return 1;
    }

    std::string arquivo;
    arquivo = argv[1];

    std::string gabarito;
    gabarito = argv[2];
    
    std::string comando;
    comando = argv[3];

    int quantidade;
    quantidade = atoi(argv[4]);
    
    int quantidade_Q;
    quantidade_Q = atoi(argv[5]);

    Gabarito gaba (gabarito);   
    Lista list (arquivo, gaba);

    if (comando == "best"){
        quickErros(list,0,list.candidatos_size-1);
        for (size_t i = 0; i < quantidade; i++){
            std::cout << i+1 << "- " << list.candidatos[i].nome << " com " 
            << list.candidatos[i].acertos <<" acertos" << "\n";
        }
        
    }else if (comando == "worst"){
        quickAcertos(list,0,list.candidatos_size-1);
        for (size_t i = 0; i < quantidade; i++){
            std::cout << i+1 << "- " << list.candidatos[i].nome << " com " 
            << list.candidatos[i].erros <<" erros"<<"\n";
        }
    }else if (comando == "best-questions"){
        quickQuestErros(list,quantidade_Q);
        for (size_t i = 0; i < quantidade; i++){
            std::cout <<"Questão "<< list.quest[i].numero << ":teve "
            << list.quest[i].acertos << " acertos"<< "\n";
        }
        
    }else if (comando == "worst-questions"){
        quickQuestAcertos(list,quantidade_Q);
        for (size_t i = 0; i < quantidade; i++){
            std::cout <<"Questão "<< list.quest[i].numero << ":teve "
             << list.quest[i].acertos << " acertos"<< "\n";
        }
        
    }else if (comando == "blank-questions"){
        quickQuestBrancos(list,quantidade_Q);
        for (size_t i = 0; i < quantidade  ; i++){
            std::cout <<"Questão "<< list.quest[i].numero << ":teve "
            << list.quest[i].brancos << " brancos"<< "\n";          
        }
        
    }else{
        std::cout << "comando não encontrado, README.md para mais informações" << "\n";
    }
    

    return 0;
}
