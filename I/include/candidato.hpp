#ifndef CANDIDATO_H
#define CANDIDATO_H

#include <string>

struct Candidato {

    std::string nome;
    char respostas[10];
    int acertos;
    int erros;
    int brancos;

};
#endif
