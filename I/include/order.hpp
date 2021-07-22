#ifndef ORDER_H
#define ORDER_H

#include "lista.hpp"

#include <iostream>

void quickAcertos(Lista& list,size_t inicio, size_t fim);
void quickErros(Lista& list,size_t inicio, size_t fim);
void quickQuestErros(Lista& list, size_t fim);
void quickQuestAcertos(Lista& list, size_t fim);
void quickQuestBrancos(Lista& list, size_t fim);
#endif