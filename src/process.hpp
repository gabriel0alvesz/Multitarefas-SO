#ifndef PROCESS_HPP
#define PROCESS_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;
    
    /**
     * @brief Faz a leitura do arquivo D.csv - Realiza a etapa 1.
     */
    void ReadingFiles();

    /**
     * @brief Tokeniza linha a linha e separa em Hashs distintas
     * 
     * @param line_token Linha a ser tokenizada
     * @param itens Endereço Hash de itens (&itens)
     * @param classes Endereço Hash de classes (&classes)
     * @param count_line contador de linhas
     */
    void Tokenizar(string line_token, unordered_map<string, vector<int> > *itens,unordered_map<string, vector<int> > *classes, int count_line);
    
    /**
     * @brief Imprime a Hash escolhida.
     * 
     * @param map Hash a ser imprimida.
     */
    void PrintMap(unordered_map<string, vector<int> > map);
        

#endif

