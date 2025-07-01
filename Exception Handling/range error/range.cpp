#include <iostream>
#include <vector>
using namespace std;


int main(){
    vector<int> list(10);
    int index;
    cin >> index;

    try{
        cout << list.at(index) << endl;
    }
    catch(out_of_range& e){
        cout << "Error: " << e.what() << endl;
    }
}