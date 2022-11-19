#include "process.hpp"

int main(){

   cout << "\n---------------------------- ROUND-ROBIN ----------------------------\n";
   ReadingFiles();
   sleep(1);

   cout << "\n---------------------------- Menor JOB s/Threads ----------------------------\n";
   MakeStage5();
   sleep(1);

   cout << "\n---------------------------- Menor JOB c/Threads ----------------------------\n";
   MakeStage_aux();
}