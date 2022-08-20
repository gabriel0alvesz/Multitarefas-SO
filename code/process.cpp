#include "process.hpp"

Files::Files(){}
Files::~Files(){}

void Files::ReadingFiles(){

     int count = 1;
     int colum = 1;
     string line, token;
     char del = ','; //arquivos .csv
     map<string, vector<int> > m;

     ifstream process ("../input/D.csv");

     while(!process.eof()){

          getline(process,line);

          stringstream sstream(line);

          colum = 1;
          while (getline(sstream, token, del)){

               if(colum < 5){token.append(" ").append(to_string(colum));}
               
               m[token].push_back(count);
               colum++;
          }

          count++;
     }

     PrintMap(m);
     cout << endl << endl;

     process.close();
}

void Files::PrintMap(map<string, vector<int> > m){

     map<string, vector<int> >::iterator it;

     for(it = m.begin(); it != m.end(); ++it){

          cout << it->first << " Linhas: ";

          for(int n: it->second){

               cout << n << " ";
          }

          cout << endl;
     }
}



