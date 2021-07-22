#include "order.hpp"

void quickAcertos(Lista& list,size_t inicio, size_t fim){
   
    int i = inicio;
    int j = fim;

    int meio =((i + j) / 2);
    int pivo = list.candidatos[meio].acertos;

    do{
        while (list.candidatos[i].acertos < pivo){
            i = i + 1;
        }
        while (list.candidatos[j].acertos > pivo){
            j = j - 1;
        }
        
        if(i <= j){
            Candidato aux = list.candidatos[i];
            list.candidatos[i] = list.candidatos[j];
            list.candidatos[j] = aux;
            i = i + 1;
            j = j - 1;
        }
    }while(j > i);
    if(inicio < j){
        quickAcertos(list, inicio, j);
    }
    if(i < fim){
        quickAcertos(list, i, fim);
    } 
}
void quickErros(Lista& list,size_t inicio, size_t fim){

    int i = inicio;
    int j = fim;

    int meio =((i + j) / 2);
    int pivo = list.candidatos[meio].erros;

    do{
        while (list.candidatos[i].erros < pivo){
            i = i + 1;
        }
        while (list.candidatos[j].erros > pivo){
            j = j - 1;
        }
        
        if(i <= j){
            Candidato aux = list.candidatos[i];
            list.candidatos[i] = list.candidatos[j];
            list.candidatos[j] = aux;
            i = i + 1;
            j = j - 1;
        }
    }while(j > i);
    if(inicio < j){
        quickErros(list, inicio, j);
    }
    if(i < fim){
        quickErros(list, i, fim);
    } 
}

void quickQuestErros(Lista& list, size_t fim){
    int i, j;

    for(i = 1; i < fim; i++){
        Lista::Quest tmp = list.quest[i];
        for(j = i-1; j >= 0 && tmp.erros < list.quest[j].erros; j--){
            list.quest[j+1] = list.quest[j];
        }
        list.quest[j+1] = tmp;
    }

}
void quickQuestAcertos(Lista& list,size_t fim){
    
    int i, j;

    for(i = 1; i < fim; i++){
        Lista::Quest tmp = list.quest[i];
        for(j = i-1; j >= 0 && tmp.acertos < list.quest[j].acertos; j--){
            list.quest[j+1] = list.quest[j];
        }
        list.quest[j+1] = tmp;
    }
}

void quickQuestBrancos(Lista& list, size_t fim){
    
    for (int i = 1; i < fim; i++) {
        for (int j = 0; j < i; j++) {
            if (list.quest[i].brancos > list.quest[j].brancos) {
                Lista::Quest tmp = list.quest[i];
                list.quest[i] = list.quest[j];
                list.quest[j] = tmp;
            }
        }
    }
}