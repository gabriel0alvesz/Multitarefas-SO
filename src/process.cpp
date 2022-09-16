#include "process.hpp"

void TokenizarInColumn(string line_token, unordered_map<string, vector<int> > *itens,unordered_map<string, vector<int> > *classes, int count_line){

     int count_column = 1;
     stringstream sstream(line_token);
     string token;
     char del = ',';

     unordered_map<string, vector<int> >::iterator it;

     while (getline(sstream, token, del)){

          if(count_column < 5){
               
               token.append(",").append(to_string(count_column));
               (*itens)[token].push_back(count_line);
          
          }else{(*classes)[token].push_back(count_line);}
               
          count_column++;
     }
}

void TokenizarInLine(string line_token, unordered_map<int, vector<string> > *itens,unordered_map<string, vector<int> > *classes, int count_line){

     int count_column = 1;
     stringstream sstream(line_token);
     string token;
     char del = ',';

     unordered_map<string, vector<int> >::iterator it;

     while (getline(sstream, token, del)){

          if(count_column < 5){
               
               token.append(",").append(to_string(count_column));
               (*itens)[count_line].push_back(token);
          
          }

          count_column++;
     }
}

 void FileReadingD(unordered_map< string, vector<int> > *itensD,  unordered_map< string, vector<int> > *classesD){

     int count_line = 1;
     string line;
     char del = ','; //arquivos .csv

     ifstream process("./src/input/D.csv");

     if(process.is_open()){

          while(!process.eof()){

               getline(process,line);

               TokenizarInColumn(line,itensD,classesD,count_line);
               count_line++;     
          }

     }else{cout << "erro" << endl;}

     process.close();
}

void FileReadingT(unordered_map<int, vector<string> > *itensT,  unordered_map<string, vector<int> > *classesT){

     int count_line = 1;
     string line;
     char del = ','; //arquivos .csv

     ifstream process("./src/input/T.csv");

     if(process.is_open()){

          while(!process.eof()){

               getline(process,line);

               TokenizarInLine(line,itensT,classesT,count_line);
               count_line++;     
          }

     }else{cout << "erro" << endl;}

     process.close();
}

void ReadingFiles(){

     unordered_map<int, vector<string> > itensT;
     unordered_map<string, vector<int> > classesT;
     
     unordered_map<string, vector<int> > itensD;
     unordered_map<string, vector<int> > classesD;

     /**
      * A impressão dos arquivos tokenizados é no formato:
      * [chave,coluna] - linhas em que essa chave aparece nesta coluna. 
      */

     FileReadingD(&itensD,&classesD);
     FileReadingT(&itensT,&classesT);

     cout << "\nArquivos foram lidos!\n";
     
     int op = 1;

     while(op != 0){

          cout << "\nQual arquivo deseja imprimir?\n" << "[0] - EXIT!\t[1] - D.csv\t[2] - T.csv\n" << ">>>> ";
          cin >> op;

          switch (op){
               
               case 0:
                    cout << "\nEnd of program\n\n";
               break;

               case 1:
                    cout << "\nArquivo D.csv\n";
                    PrintMap(itensD);
                    PrintMap(classesD);
               break;

               case 2:
                    cout << "\nArquivo T.csv\n";
                    PrintMap1(itensT);
                    PrintMap(classesT);
               break;

               default:
                    cout << "opção invalida!" << endl;
               break;
          }
     }
     
     //procurando se existe determiand valor na chave de D
     int cont_aux = 0;
     unordered_map<int, vector<string> > :: iterator it;
     
     cout << "Quais valores de T estão presentes como chave de D?" << endl << endl;
     for(it = itensT.begin(); it != itensT.end(); ++it){

          for(string n: it->second){

               if(itensD.find(n) == itensD.end ()){

                    cout << "chave " << n << " encontrada!" << endl;
                    cont_aux++;
               }
          }
     }

     cout << cont_aux << endl;

}

void PrintMap(unordered_map<string, vector<int> > map){

     unordered_map<string, vector<int> >::iterator it;

     cout << endl << endl;
     
     for(it = map.begin(); it != map.end(); ++it){

          cout << it->first << " :: ";

          for(int n: it->second){

               cout << n << " ";
          }

          cout << endl;
     }
}

void PrintMap1(unordered_map<int, vector<string> > map){

     unordered_map<int, vector<string> >::iterator it;

     cout << endl << endl;
     
     for(it = map.begin(); it != map.end(); ++it){

          cout << it->first << " :: ";

          for(string n: it->second){

               cout << n << " ";
          }

          cout << endl;
     }
}



