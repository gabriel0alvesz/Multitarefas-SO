#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;

class Files{

    public:

        Files();
        ~Files();

        void ReadingFiles();
        void Tokenizar(string line);
        void InsertInMap(string line, int count);
        void PrintMap(unordered_map<string, vector<int> > m);

};


