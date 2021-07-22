#ifndef LISTA_H
#define LISTA_H

#include "candidato.hpp"
#include "gabarito.hpp"

#include <string>

struct Lista {
    
    Lista(const std::string& filename,Gabarito& gaba);
    ~Lista();

    std::string filename;
    Candidato* candidatos;
    size_t candidatos_size;
    size_t candidatos_capacity;

    struct Quest{
        int numero;
        int acertos;
        int erros;
        int brancos;
    };
    Quest quest[10];

    void newArray();
};
#endif
