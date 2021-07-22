#ifndef GABARITO_H
#define GABARITO_H

#include <string>

struct Gabarito {

    Gabarito(const std::string& filename);
    std::string filename;
    char respostas[10];

};

#endif
