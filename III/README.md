# Corretor simples
- Desenvolvido na terceira avaliação de EDB, corretor de palavras de um texto que recebe um dicionário e o texto a ser corrigido.
# Compilação
- Cmake.
# Execução
- ./prog dicionario.txt nome_texto.txt
# Instruções
- dicionario.txt = arquivo contendo um dicionário.
- nome_texto.txt = arquivo contendo o texto a ser analizado.
# Estruturas
- std::unordered_set<std::string> dic. Usando para salvar todas as palavras do dicionário,pois não serão usados palavras repetidas e só serão inseridas uma vez durante a execução,com uma demanda maior para busca, com inserção e busca de O(1) ou O(n).

- std::unordered_set<std::string> palavras_erradas. Usando para salvar as palavras erradas contidas no texto,para evitar que uma palavra errada seja corrigida mais de 2x, usamos as keys para garantir isso, barrando uma palavra de percorrer o dicionário novamente, com inserção de O(1) ou O(n).

- std::multimap<size_t, std::string> sugest. Usado para salvar as sugestões de palavras com levenshtein abaixo de 10, e por seu tipo de estrutura conseguimos ordenar pela key que é o retorno da função levenshtein, com uma inserção O(log n).
