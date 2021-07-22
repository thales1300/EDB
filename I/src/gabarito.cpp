#include "gabarito.hpp"

#include <fstream>
#include <iostream>
#include <sstream>

Gabarito::Gabarito(const std::string& filename){
    std::ifstream arquivo_entrada(filename);
        if(!arquivo_entrada.is_open()){
            std::cerr << "arquivo não existe " <<"\n";
            return;
        }
        std::string mensagemArquivo;
        while(!arquivo_entrada.eof()){  
            getline(arquivo_entrada, mensagemArquivo);
            std::string recebe;
            std::stringstream stream(mensagemArquivo);

            stream >> respostas[0];
            stream >> respostas[1];
            stream >> respostas[2];
            stream >> respostas[3];
            stream >> respostas[4];
            stream >> respostas[5];
            stream >> respostas[6];
            stream >> respostas[7];
            stream >> respostas[8];
            stream >> respostas[9];
        }
}