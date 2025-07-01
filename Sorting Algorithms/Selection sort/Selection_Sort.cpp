#include <iostream>  
#include <ctime>  
#include <vector>  
#include <string>
#include <array>
#include <fstream>
#include <algorithm>
using namespace std;




vector<int> sort_alg(vector<int> vec) {
    bool sorted = false;
    int smallest = 0;
    int min = 0;

    for (int i = 0; i < vec.size() - 1; i++) {
        min = i;
        for (int j = i + 1; j < vec.size(); j++) {
            if (vec[j] < vec[min]) {
                min = j;
            }
        }
        swap(vec[min], vec[i]);


    }
    return vec;

}

int main() {
    vector<int> vec = {3, 2, 6, 1};
    vec = sort_alg(vec);
    for (int i = 0; i< vec.size(); i++) {
        cout << vec[i];
    }
}