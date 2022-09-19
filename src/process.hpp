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
 * @brief Faz a leitura do arquivo D.csv e T.csv - Realiza a etapa 1.
 */
void ReadingFiles();
void FileReadingD(unordered_map< string, vector<int> > *itensD,  unordered_map< string, vector<int> > *classesD);
void FileReadindT(unordered_map< int, vector<string> > *itensT,  unordered_map< string, vector<int> > *classesT);
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
void Permutation(unordered_map<int, vector<string> > *newItens, unordered_map<int, vector<vector<string> > > *newItensPerm);

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


#endif

