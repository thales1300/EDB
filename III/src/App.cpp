#include "App.hpp"
#include "Levenshtein.hpp"
#include "Print.hpp"

#include <sstream>
#include <fstream>
#include <cctype>

int App::run(int argc, char* argv[]){
    if (argc != 3){
        show_usage(argv[0]);
        return 1;
    }
    std::string name_dic = argv[1];
    read_dic(name_dic,dic,palavras_erradas);
    std::string name_text = argv[2];
    read_text (name_text,dic,palavras_erradas);
    correct(palavras_erradas,dic);
    return 0;
}

void App::read_dic (std::string name,std::unordered_set<std::string> &dic,std::unordered_set<std::string> &palavras_erradas){

    std::ifstream arquivo_entrada(name);
    if(!arquivo_entrada.is_open()){
        std::cerr << "arquivo não existe " <<"\n";
        return;
    }

    std::string mensagemArquivo;
    
    while(!arquivo_entrada.eof()){  
        getline(arquivo_entrada, mensagemArquivo);
        if(mensagemArquivo.empty()){
            continue;
        }
        std::stringstream stream(mensagemArquivo);
        std::string aux;
        stream >> aux;
        dic.insert(aux); 
    }
    arquivo_entrada.close();
}

void App::read_text (std::string name,std::unordered_set<std::string> &dic,std::unordered_set<std::string> &palavras_erradas){
    std::ifstream arquivo_entrada2(name);
    if(!arquivo_entrada2.is_open()){
        std::cerr << "arquivo não existe " <<"\n";
        return;
    }
    
    std::string mensagemArquivo2;

    while(!arquivo_entrada2.eof()){  
        getline(arquivo_entrada2, mensagemArquivo2);
        if(mensagemArquivo2.empty()){
            continue;
        }
        std::stringstream stream(mensagemArquivo2);
        std::string aux;
        while (!stream.eof()){
            stream >> aux;
            if (ispunct(aux.back())){
                aux.pop_back();
                //remove o ultimo caractere se for um ponto.
            }
            auto it = aux.begin()+1;
            if (!isupper(*it)){
                aux.replace(aux.begin(),aux.begin()+1,1,tolower(aux.front())); 
                /* remove a letra maiuscula no inicio da palavra, 
                se a segunda não for maiuscula */
            }  

            auto it2 = dic.find(aux);
            if(it2 != dic.end()){
                continue;
            }else{
                palavras_erradas.insert(aux);
            }
        }   
    }
    arquivo_entrada2.close();
}

void App::correct(std::unordered_set<std::string> &palavras_erradas,std::unordered_set<std::string> &dic){
    for (auto it : palavras_erradas){
        size_t retorno = 0;
        std::multimap<size_t, std::string> sugest;
        for (auto x : dic){
            retorno = levenshtein(it,x);
            if(retorno <= 10){
                sugest.insert (std::pair<size_t,std::string>(retorno,x));
            }
            
        }
        std::cout << it <<": " << "\n";
        print(sugest);
    }
}

int App::show_usage(const std::string& filerun){
    std::cout << "Uso: " << filerun <<" dicionario.txt texto.txt" << "\n";
    return 1;
}