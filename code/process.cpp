#include "process.hpp"

Files::Files(){}
Files::~Files(){}

void Files::ReadingFiles(){

     ifstream process ("../input/D.csv");
     int count = 0;
     string line;

     while(!process.eof()){
          
          getline(process,line);
          cout << line << endl;
          count++;
          Tokenizar(line);
          cout << endl;
     }

     cout << count << endl;
     
}

void Files::Tokenizar(string line){

     char del = ','; //arquivos .csv

     stringstream sstream(line);
	string token;

	while (getline(sstream, token, del))
		cout << token << endl;

}        


