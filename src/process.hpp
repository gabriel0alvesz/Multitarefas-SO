#ifndef PROCESS_HPP
#define PROCESS_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>

using namespace std;

/**
 * @brief Faz a leitura do arquivo D.csv e T.csv - Realiza a etapa 1.
 */
void ReadingFiles();

/**
 * @brief Leitura do Arquivo D.csv.
 * 
 * @param itensD Endereço Hash de itensD (&itensD).
 * @param classesD Endereço Hash de classesD (&classesD).
 */
void FileReadingD(unordered_map< string, vector<int> > *itensD,  unordered_map< string, vector<int> > *classesD);

/**
 * @brief Faz Leitura do arquivo T.csv.
 * 
 * @param itensT Endereço Hash de itensT (&itensT).
 * @param classesT Endereço Hash de classesT (&classesT).
 */
void FileReadingT(unordered_map< int, vector<string> > *itensT,  unordered_map< string, vector<int> > *classesT);
int Menu();

/**
 * @brief Faz a checagem dos valores do Map de ItensT com as keys do Map de itensD.
 * 
 * @param itensT Endereço do Map (&itensT).
 * @param newItens Endereço do Map de receberá a chaves presentes em ambos (&newItens).
 */
void CheckKeyValues(unordered_map<int, vector<string> > *itensD,unordered_map< int, vector<string> > *itensT, unordered_map< int, vector<string> > *newItens);

/**
 * @brief Faz as permutações.
 * 
 * @param itensT Endereço do Map (&itensT).
 * @param newItensPerm Endereço do Map quie armazenará as permutações (&newItensPerm).
 */
void Combination(unordered_map<int, vector<string> > *newItens, unordered_map<int, vector<vector<string> > > *newItensPerm);

/**
 * @brief Tokeniza linha a linha e separa keys por coluna
 * 
 * @param line_token Linha a ser tokenizada
 * @param itens Endereço Hash de itens (&itens)
 * @param classes Endereço Hash de classes (&classes)
 * @param count_line contador de linhas
 */
void TokenizarInColumn(string line_token, unordered_map<string, vector<int> > *itens,unordered_map<string, vector<int> > *classes, int count_line);

/**
 * @brief Tokeniza linha a linha e separa keys por linha
 * 
 * @param line_token Linha a ser tokenizada
 * @param itens Endereço Hash de itens (&itens)
 * @param classes Endereço Hash de classes (&classes)
 * @param count_line contador de linhas
 */
void TokenizarInLine(string line_token, unordered_map<int, vector<string> > *itens,unordered_map<string, vector<int> > *classes, int count_line);

/**
 * @brief Imprime a Hash escolhida.
 * 
 * @param map Hash a ser imprimida.
 */
void PrintMap(unordered_map<string, vector<int> > map);
void PrintMap1(unordered_map<int, vector<string> > map);

/**
 * @brief Imprime Map com todas as permutações.
 * 
 * @param newItensPerm Endereço do Map de Permutações (&newItensPerm).
 */
void PrintPermutation(unordered_map<int, vector<vector<string> > > *newItensPerm);

/**
 * @brief Imprime Map da Quantidade de Intersecções.
 * 
 * @param c_intersection Endereço Hash de Intersecções (&c_intersection).
 */
void PrintHashIntersection(unordered_map<string, int> *c_intersection);

/**
 * @brief Inicia os valores de cada key da Hash como Zero.
 * 
 * @param classesD Endereço da Hash de Classes do arquivo D.csv(&classesD).
 * @param c_intersection Endereço da Hash de intesecções(&c_intersection).
 */
void InitHashIntersection(
    unordered_map<string, vector<int> > *classesD,
    unordered_map<string, int> *c_intersection
);

/**
 * @brief Faz a intersecção das linhas
 * 
 * @param newItensPerm Endereço do Map de Permutações (&newItensPerm).
 * @param itensD Endereço Hash de itens do arquivo D.csv (&itensD).
 * @param classesD Endereço Hash de classes do arquivo D.csv (&classesD).
 */
void MakeIntersection(
    unordered_map<int, vector<vector<string>>> *newItensPerm,
    unordered_map< string, vector<int>> *itensD,
    unordered_map<string, vector<int>> *classesD,
    unordered_map<string, vector<int>> *cache,
    unordered_map<string, int > *class_inter
);

/**
 * @brief Faz a intersecção com as classes
 * 
 * @param classesD Endereço Hash de classes do arquivo D.csv (&classesD).
 * @param class_aux Endereço da Hash auxiliar (&class_aux).
 * @param vec_result Vetor resultade das intersecções de combinação (vec_result).
 */
void IntersectionOnClass(
    unordered_map<string, vector<int> > *classesD,
    unordered_map<string, int > *class_aux,
    vector<int> vec_result
);

/**
 * @brief Verifica qual a classe com mais intersecções.
 * 
 * @param class_aux Endereço da Hash auxiliar (&class_aux).
 * @param class_inter Endereço da Hash principal de armazenamento (&class_inter).
 */
void VerifyMaxClass(
    unordered_map<string, int > *class_aux,
    unordered_map<string, int > *class_inter
);


#endif

