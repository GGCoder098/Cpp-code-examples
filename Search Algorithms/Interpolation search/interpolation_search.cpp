#include <iostream>  
#include <ctime>  
#include <vector>  
#include <string>
#include <array>
#include <fstream>
#include <algorithm>
using namespace std;


vector<int> sort(vector<int> vec) {
    srand((unsigned) time(NULL));
    int random;
    for (int i = 0; i < 50; i++) {
        random = 1 + (rand() % 100);
        vec.push_back(random);
        cout << random << endl;
    }
    sort(vec.begin(), vec.end());
    cout << "_____________" << endl;
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << endl;
    }

    return vec;

}


int interp_search(int key, vector<int> vec) {
    int min = 0;
    int max = vec.size() - 1;
    int sep_el;
    int final_location = -1;
    bool found = false;


    while (found == false) {
        sep_el = min + ((key - vec[min]) * (max - min)) / (vec[max] - vec[min]) ;
        // cout << sep_el << endl;
        if (max < 1 || min > vec.size() - 1) {
            final_location = -2;
            found = true;
        }
        else if (key < vec[sep_el]) {
            max = sep_el - 1;
        }

        else if (key > vec[sep_el]) {
            min = sep_el + 1;
        }

        else if (key == vec[sep_el]) {
            found = true;
            final_location = sep_el;
        }

        
    }
    return final_location;

    

}



int main() {    
    vector<int> vec;
    vec = sort(vec);
    int key;
    int final_location;
    bool done = false;
    while (done == false) {
        cout << "Enter the Number you want to find: ";
        cin >> key;
        final_location = interp_search(key, vec);
        if (final_location != -2) {
            cout << "The number " << key << " is located at "<< final_location << endl;
        }
        else {
            cout << "number not found" << endl;
        }
        

    }





    



    return 0;
}