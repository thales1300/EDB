#ifndef APP_H
#define APP_H

#include <string>
#include <unordered_set>

class App {

    private:
        std::unordered_set<std::string> dic;
        std::unordered_set<std::string> palavras_erradas;
        std::string name;

        void read_dic (std::string name,std::unordered_set<std::string> &dic,std::unordered_set<std::string> &palavras_erradas);
        void read_text (std::string name,std::unordered_set<std::string> &dic,std::unordered_set<std::string> &palavras_erradas);
        void correct (std::unordered_set<std::string> &palavras_erradas,std::unordered_set<std::string> &dic);
        
    public:
        int run(int argc, char* argv[]);
        int show_usage(const std::string& filerun);

};
#endif