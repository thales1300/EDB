#include "lista.hpp"

#include <fstream>
#include <iostream>
#include <sstream>

Lista::Lista(const std::string& name, Gabarito& gaba) : filename(name), candidatos(nullptr), candidatos_size(0), candidatos_capacity(11){
    candidatos = new Candidato[candidatos_capacity];
    
    std::ifstream arquivo_entrada(filename);
    if(!arquivo_entrada.is_open()){
        std::cerr << "arquivo não existe " <<"\n";
        return;
    }

    for (size_t i = 0; i < 10; i++){
        quest[i].acertos = 0;
        quest[i].erros = 0 ;
        quest[i].brancos = 0;
        quest[i].numero = i+1;
    }
    
    std::string mensagemArquivo;

    while(!arquivo_entrada.eof()){  
        
        if (candidatos_size >= candidatos_capacity) {
            newArray();
        }
        getline(arquivo_entrada, mensagemArquivo);
        std::string recebe;
        std::stringstream stream(mensagemArquivo);

        stream >> candidatos[candidatos_size].nome;

        stream >> candidatos[candidatos_size].respostas[0];
        if (candidatos[candidatos_size].respostas[0] == gaba.respostas[0]){
           candidatos[candidatos_size].acertos ++;
           quest[0].acertos ++;
        }else{
            candidatos[candidatos_size].erros ++;
            quest[0].erros ++;
        }

        if (candidatos[candidatos_size].respostas[0]!= 'A' &&
             candidatos[candidatos_size].respostas[0]!= 'B' &&
             candidatos[candidatos_size].respostas[0]!= 'C' &&
             candidatos[candidatos_size].respostas[0]!= 'D' &&
             candidatos[candidatos_size].respostas[0]!= 'E'){

            candidatos[candidatos_size].brancos ++;
            quest[0].brancos ++;
        }

        stream >> candidatos[candidatos_size].respostas[1];
        if (candidatos[candidatos_size].respostas[1] == gaba.respostas[1]){
           candidatos[candidatos_size].acertos ++;
           quest[1].acertos++ ;
        }else{
            candidatos[candidatos_size].erros ++ ;
            quest[1].erros ++;
        }

        if (candidatos[candidatos_size].respostas[1]!= 'A' &&
             candidatos[candidatos_size].respostas[1]!= 'B' &&
             candidatos[candidatos_size].respostas[1]!= 'C' &&
             candidatos[candidatos_size].respostas[1]!= 'D' &&
             candidatos[candidatos_size].respostas[1]!= 'E'){

            candidatos[candidatos_size].brancos ++ ;
            quest[1].brancos ++;
        }

        stream >> candidatos[candidatos_size].respostas[2];
        if (candidatos[candidatos_size].respostas[2] == gaba.respostas[2]){
           candidatos[candidatos_size].acertos ++ ;
           quest[2].acertos ++;
        }else{
            candidatos[candidatos_size].erros ++;
            quest[2].erros ++;
        }
        
        if (candidatos[candidatos_size].respostas[2]!= 'A' &&
             candidatos[candidatos_size].respostas[2]!= 'B' &&
             candidatos[candidatos_size].respostas[2]!= 'C' &&
             candidatos[candidatos_size].respostas[2]!= 'D' &&
             candidatos[candidatos_size].respostas[2]!= 'E'){

            candidatos[candidatos_size].brancos ++;
            quest[2].brancos ++;
        }

        stream >> candidatos[candidatos_size].respostas[3];
        if (candidatos[candidatos_size].respostas[3] == gaba.respostas[3]){
           candidatos[candidatos_size].acertos ++;
           quest[3].acertos ++;
        }else{
            candidatos[candidatos_size].erros ++ ;
            quest[3].erros ++;
        }
        
        if (candidatos[candidatos_size].respostas[3]!= 'A' &&
             candidatos[candidatos_size].respostas[3]!= 'B' &&
             candidatos[candidatos_size].respostas[3]!= 'C' &&
             candidatos[candidatos_size].respostas[3]!= 'D' &&
             candidatos[candidatos_size].respostas[3]!= 'E'){

            candidatos[candidatos_size].brancos ++;
            quest[3].brancos ++;
        }
        
        stream >> candidatos[candidatos_size].respostas[4];
        if (candidatos[candidatos_size].respostas[4] == gaba.respostas[4]){
           candidatos[candidatos_size].acertos ++;
           quest[4].acertos ++;
        }else{
            candidatos[candidatos_size].erros ++ ;
            quest[4].erros ++;
        }
        
        if (candidatos[candidatos_size].respostas[4]!= 'A' &&
             candidatos[candidatos_size].respostas[4]!= 'B' &&
             candidatos[candidatos_size].respostas[4]!= 'C' &&
             candidatos[candidatos_size].respostas[4]!= 'D' &&
             candidatos[candidatos_size].respostas[4]!= 'E'){

            candidatos[candidatos_size].brancos ++ ;
            quest[4].brancos ++;
        }

        stream >> candidatos[candidatos_size].respostas[5];
        if (candidatos[candidatos_size].respostas[5] == gaba.respostas[5]){
           candidatos[candidatos_size].acertos ++;
           quest[5].acertos ++;
        }else{
            candidatos[candidatos_size].erros ++ ;
            quest[5].erros ++;
        }
        
        if (candidatos[candidatos_size].respostas[5]!= 'A' &&
             candidatos[candidatos_size].respostas[5]!= 'B' &&
             candidatos[candidatos_size].respostas[5]!= 'C' &&
             candidatos[candidatos_size].respostas[5]!= 'D' &&
             candidatos[candidatos_size].respostas[5]!= 'E'){

            candidatos[candidatos_size].brancos ++ ;
            quest[5].brancos ++;
        }

        stream >> candidatos[candidatos_size].respostas[6];
        if (candidatos[candidatos_size].respostas[6] == gaba.respostas[6]){
           candidatos[candidatos_size].acertos ++ ;
           quest[6].acertos ++;
        }else{
            candidatos[candidatos_size].erros ++ ;
            quest[6].erros ++;
        }
        
        if (candidatos[candidatos_size].respostas[6]!= 'A' &&
             candidatos[candidatos_size].respostas[6]!= 'B' &&
             candidatos[candidatos_size].respostas[6]!= 'C' &&
             candidatos[candidatos_size].respostas[6]!= 'D' &&
             candidatos[candidatos_size].respostas[6]!= 'E'){

            candidatos[candidatos_size].brancos ++;
            quest[6].brancos ++;
        }

        stream >> candidatos[candidatos_size].respostas[7];
        if (candidatos[candidatos_size].respostas[7] == gaba.respostas[7]){
           candidatos[candidatos_size].acertos ++ ;
           quest[7].acertos ++ ;
        }else{
            candidatos[candidatos_size].erros ++ ;
            quest[7].erros ++;
        }
        
        if (candidatos[candidatos_size].respostas[7]!= 'A' &&
             candidatos[candidatos_size].respostas[7]!= 'B' &&
             candidatos[candidatos_size].respostas[7]!= 'C' &&
             candidatos[candidatos_size].respostas[7]!= 'D' &&
             candidatos[candidatos_size].respostas[7]!= 'E'){

            candidatos[candidatos_size].brancos ++ ;
            quest[7].brancos ++;
        }

        stream >> candidatos[candidatos_size].respostas[8];
        if (candidatos[candidatos_size].respostas[8] == gaba.respostas[8]){
           candidatos[candidatos_size].acertos ++ ;
           quest[8].acertos ++ ;
        }else{
            candidatos[candidatos_size].erros ++ ;
            quest[8].erros ++;
        }
        
        if (candidatos[candidatos_size].respostas[8]!= 'A' &&
             candidatos[candidatos_size].respostas[8]!= 'B' &&
             candidatos[candidatos_size].respostas[8]!= 'C' &&
             candidatos[candidatos_size].respostas[8]!= 'D' &&
             candidatos[candidatos_size].respostas[8]!= 'E'){

            candidatos[candidatos_size].brancos ++;
            quest[8].brancos ++;
        }

        stream >> candidatos[candidatos_size].respostas[9];

        if (candidatos[candidatos_size].respostas[9] == gaba.respostas[9]){
           candidatos[candidatos_size].acertos ++;
           quest[9].acertos ++;
        }else{
            candidatos[candidatos_size].erros ++;
            quest[9].erros ++;
        }
        
        if (candidatos[candidatos_size].respostas[9]!= 'A' &&
             candidatos[candidatos_size].respostas[9]!= 'B' &&
             candidatos[candidatos_size].respostas[9]!= 'C' &&
             candidatos[candidatos_size].respostas[9]!= 'D' &&
             candidatos[candidatos_size].respostas[9]!= 'E'){

            candidatos[candidatos_size].brancos ++;
            quest[9].brancos ++;
        }

        candidatos_size ++;
        
    } 


}

Lista::~Lista(){
    delete[] candidatos;
}

void Lista::newArray(){
    candidatos_capacity *= 2;
    Candidato* new_array = new Candidato[candidatos_capacity];

    for (size_t i = 0; i < candidatos_size; i++){
        new_array[i] = candidatos[i];
    }
    
    delete[] candidatos;
    candidatos = new_array;
}