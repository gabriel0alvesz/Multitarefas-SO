#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

using namespace std;
    
class Files{

    public:

        Files();
        ~Files();

        void ReadingFiles();
        void PrintMap(map<string, vector<int> > m);

};


