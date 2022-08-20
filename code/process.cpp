#include "process.hpp"

Files::Files(){}
Files::~Files(){}

void Files::ReadingFiles(){

     ifstream process ("../input/D.csv");
     int count = 1;
     int colum = 1;
     string line;

     char del = ','; //arquivos .csv

	string token;

     unordered_map<string, vector<int> > m;

     while(!process.eof()){
          
          getline(process,line);

          stringstream sstream(line);

          unordered_map<string, vector<int> >::iterator it;

          colum = 1;

          while (getline(sstream, token, del)){
               
               token.append(" ").append(to_string(colum));
               it = m.find(token);

               if(it != m.end()){

                    it->second.push_back(count);
               }else{
                    
                    m[token].push_back(count);
               
               }

               colum++;

          }
          
          count++;

     }

     PrintMap(m);
     
}

void Files::PrintMap(unordered_map<string, vector<int> > m){

     unordered_map<string, vector<int> >::iterator it = m.begin();

     vector<int>::iterator it_aux;

     while(++it != m.end()){
          
          cout << it->first << " - ";

          for(it_aux = it->second.begin(); it_aux != it->second.end(); ++it_aux){
               
               cout << *it_aux << " ";
          
          }

          cout << endl;

     }
}

void Files::Tokenizar(string line){

     char del = ','; //arquivos .csv

     stringstream sstream(line);
	string token;

	while (getline(sstream, token, del))
		cout << token << endl;

}      

void Files::InsertInMap(string line, int count){

    

}


