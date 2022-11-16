#include "process.hpp"

int main(){
    
    ReadingFiles();
    system("clear");
    cout << "\n\n------------------- Nova política - SJF -------------------\n";
    sleep(1);// Sleep apenas para nao imprimir tudo de uma unica vez.
    MakeStage5();

    return 0;
}
