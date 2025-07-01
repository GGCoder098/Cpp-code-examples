#include <iostream>  
#include <ctime>  
#include <vector>  
#include <string>
#include <array>
#include <fstream>
#include <algorithm>
using namespace std;







int main() {
    string line;
    vector<string> names;
    ifstream text("name.txt");
    while (!text.eof()) {
        getline(text, line);
        names.push_back(line);
    }
    sort(names.begin(), names.end());
    text.close();
    ofstream finalsort("name.txt");
    for (int i = 0; i < names.size(); i++) {
        finalsort << names[i] << endl;
    }
    

    






}