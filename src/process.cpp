#include "process.hpp"

void Tokenizar(string line_token, unordered_map<string, vector<int> > *itens,unordered_map<string, vector<int> > *classes, int count_line){

     int count_column = 1;
     stringstream sstream(line_token);
     string token;
     char del = ',';

     unordered_map<string, vector<int> >::iterator it;

     while (getline(sstream, token, del)){

          if(count_column < 5){
               
               token.append(" ").append(to_string(count_column));
               (*itens)[token].push_back(count_line);
          
          }else{(*classes)[token].push_back(count_line);}
               
          count_column++;
     }

}

void ReadingFiles(){

     int count_line = 1;
     string line, token;
     char del = ','; //arquivos .csv
     unordered_map< string, vector<int> > itens;
     unordered_map< string, vector<int> > classes;

     ifstream process("./src/input/D.csv");

     if(process.is_open()){

          while(!process.eof()){

               getline(process,line);

               Tokenizar(line,&itens,&classes,count_line);
               count_line++;     
          }

          PrintMap(itens);
          cout << endl << endl;
          PrintMap(classes);

     }else{

          cout << "erro" << endl;
     }

     process.close();
}

void PrintMap(unordered_map<string, vector<int> > map){

     unordered_map<string, vector<int> >::iterator it;

     cout << endl << endl;
     
     for(it = map.begin(); it != map.end(); ++it){

          cout << it->first << " Linhas: ";

          for(int n: it->second){

               cout << n << " ";
          }

          cout << endl;
     }
}



