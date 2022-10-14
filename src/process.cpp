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
          
          }else{(*classes)[token].push_back(count_line);}

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

void CheckKeyValues(unordered_map<string, vector<int> > *itensD, unordered_map< int, vector<string> > *itensT, unordered_map< int, vector<string> > *newItens){

     unordered_map<int, vector<string> > :: iterator it;
     
     for(it = itensT->begin(); it != itensT->end(); ++it){

          for(string n: it->second){

               if(itensD->find(n) != itensD->end()){(*newItens)[it->first].push_back(n);}
          }
     }

}

void Combination(unordered_map<int, vector<string> > *newItens, unordered_map<int, vector<vector<string> > > *newItensPerm){

     unordered_map<int, vector<string> > :: iterator it;
     vector<string>::iterator itr, itrv, itrb, itrc;
     
     vector<string> vec_aux;
     vector<vector<string> > vec_matrix;
     
     //Acessa cada chave dos itens
     for(it = newItens->begin(); it != newItens->end(); ++it){

          sort((*it).second.begin(), (*it).second.end()); // Custo O(n log(n)) -> ordena cada vetor para facilitar a etapa 3.

          vec_matrix.clear();

          // 1 a 1
          for(itr = it->second.begin(); itr != it->second.end(); ++itr){
               
               vec_aux.clear();
               vec_aux.push_back((*itr));
               vec_matrix.push_back(vec_aux);
          }

          //2 a 2
          for(itr = it->second.begin(); itr != it->second.end(); ++itr){

               itrv = itr;
               ++itrv;
               for(; itrv != it->second.end(); ++itrv){
                    
                    vec_aux.clear();
                    vec_aux.push_back(*itr);
                    vec_aux.push_back(*itrv);
                    vec_matrix.push_back(vec_aux);
               }
          }

          //3 a 3
          for(itr = it->second.begin(); itr != it->second.end(); ++itr){

               itrv = itr;
               ++itrv;

               for(; itrv != it->second.end(); ++itrv){
                    
                    itrb = itrv;
                    ++itrb;

                    for(; itrb != it->second.end(); ++itrb){

                         vec_aux.clear();
                         vec_aux.push_back(*itr);
                         vec_aux.push_back(*itrv);
                         vec_aux.push_back(*itrb);
                         vec_matrix.push_back(vec_aux);

                    }
               }
          }

          
          //4 a 4
          for(itr = it->second.begin(); itr != it->second.end(); ++itr){

               itrv = itr;
               ++itrv;

               for(; itrv != it->second.end(); ++itrv){
                    
                    itrb = itrv;
                    ++itrb;

                    for(; itrb != it->second.end(); ++itrb){
                         
                         itrc = itrb;
                         ++itrc;

                         for(; itrc != it->second.end(); ++itrc){

                              vec_aux.clear();
                              vec_aux.push_back(*itr);
                              vec_aux.push_back(*itrv);
                              vec_aux.push_back(*itrb);
                              vec_aux.push_back(*itrc);
                              vec_matrix.push_back(vec_aux);
                         }
                    }
               }
          }
          

          (*newItensPerm)[it->first] = vec_matrix;
     }
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

void PrintPermutation(unordered_map<int, vector<vector<string> > > *newItensPerm){

     unordered_map<int, vector<vector<string> > >::iterator it_map;
     
     for(it_map = newItensPerm->begin(); it_map != newItensPerm->end(); ++it_map){

          cout << it_map->first << " :: " << endl;;

          for(vector<string> n: it_map->second){

               for(string a: n){
                    cout << a << " ";
               }

               cout << endl;
          }
          cout << endl;
     }
}

void InitHashIntersection(
    unordered_map<string, vector<int> > *classesD,
    unordered_map<string, int > *c_intersection
){

     unordered_map<string, vector<int> >::iterator it;

     for(it = classesD->begin(); it != classesD->end(); ++it){

          (*c_intersection)[it->first] = 0;
     }

}

void PrintHashIntersection(unordered_map<string, int> *c_intersection){

     unordered_map<string, int >::iterator itv;

     for(itv = c_intersection->begin(); itv != c_intersection->end(); ++itv){

          cout << itv->first << " -> " << itv->second << endl;
     } 
}

void MakeIntersection(
    unordered_map<int, vector<vector<string> > > *newItensPerm,
    unordered_map< string, vector<int> > *itensD,
    unordered_map< string, vector<int> > *classesD
){

     unordered_map<int, vector<vector<string> > >::iterator it;
     unordered_map<string, vector<int> >::iterator itr;
     unordered_map<string, int > class_aux, class_inter;

     //InitHashIntersection(&classesD,&class_inter);
     int i; // variavel auxiliar
     
     // Andando dentro da Hash de combinacoes
     for(it = newItensPerm->begin(); it != newItensPerm->end(); ++it){

          InitHashIntersection(classesD,&class_aux);
          cout << endl << it->first << ": "<< endl;
          
          // Caminhando pela matriz
          for(vector<string> vec: it->second){
               
               vector<int> vec_result;
               
               if(vec.size() == 1){

                    itr = itensD->find(vec[0]);

                    if(itr != itensD->end()){
                    
                         vec_result = itr->second;
                    }

               }else{

                    string s1, s2;
                    vector<int> vec1, vec2;
                    bool var_bool = false;
                    
                    for(string str: vec){

                         if(var_bool){

                              s2.assign(str);
                              vec2 = itensD->find(s2)->second;
                              vec_result.clear();

                              set_intersection(
                                   vec1.begin(), vec1.end(),
                                   vec2.begin(),vec2.end(),
                                   back_inserter(vec_result)
                              );

                              vec1 = vec_result;

                         }else{
                              
                              var_bool = true;
                              s1.assign(str);
                              vec1 = itensD->find(s1)->second;
                         } 
                    }
               }

               for(itr = classesD->begin(); itr != classesD->end(); ++itr){

                    vector<int> aux;

                    set_intersection(
                         vec_result.begin(),vec_result.end(),
                         (*classesD)[itr->first].begin(),(*classesD)[itr->first].end(),
                         back_inserter(aux)
                    );


                    class_aux[itr->first] += aux.size();
                    
               }
               
          }

          unordered_map<string, int >::iterator itb;
          string class_aux_str;
          int tam = -1;
          for(itb = class_aux.begin(); itb != class_aux.end(); ++itb){

               if(itb->second > tam){

                    tam = itb->second;
                    class_aux_str.assign(itb->first);
               }
               
          }
          cout << class_aux_str << endl;
          PrintHashIntersection(&class_aux);
     }
     
     cout << endl << endl;

     //PrintHashIntersection(&class_aux);

}


void ReadingFiles(){

     unordered_map<int, vector<string> > itensT;
     unordered_map<string, vector<int> > classesT;
     
     unordered_map<string, vector<int> > itensD;
     unordered_map<string, vector<int> > classesD;

     unordered_map<int, vector<string> > newItens;
     unordered_map<int, vector<vector<string> > > newItensPerm;

     int op = 1;
     while(op != 0){

          cout << "\nFaça as etapas em ordem!\n" << "[0] - EXIT!\t[1] - Faz etapa 1\t[2] - Faz etapa 2";
          cout << "\t[3] - Faz etapa 3\n" << ">>>>>> ";
          cin >> op;

          switch (op){
               
               case 0:
                    cout << "\nEnd of program\n\n";
               break;

               case 1:
                    
                    cout << "\nFazendo etapa 1:\n";
                    
                    FileReadingD(&itensD,&classesD);
                    cout << "\nItensD" << endl;
                    PrintMap(itensD);
                    cout << "\nClassesD" << endl;
                    PrintMap(classesD);
                    
                    FileReadingT(&itensT,&classesT);
                    cout << "\nItensT" << endl;
                    PrintMap1(itensT);
                    cout << "\nClassesT" << endl;
                    PrintMap(classesT);
                    cout << "\nArquivos foram lidos!\n";
               break;

               case 2:
                    cout << "\nFazendo etapa 2:\n";

                    CheckKeyValues(&itensD,&itensT,&newItens);
                    PrintMap1(newItens);

                    cout << "\n============= Combinações ============= " << endl << endl;

                    Combination(&newItens, &newItensPerm);
                    PrintPermutation(&newItensPerm);

               break;

               case 3:
                    cout << "\nFazendo etapa 3:\n";
                    MakeIntersection(&newItensPerm,&itensD,&classesD);

               break;

               default:
                    cout << "opção invalida!" << endl;
               break;
          }
     }


     
}
