#include <iostream>  
#include <ctime>  
#include <vector>  
#include <string>
#include <array>
#include <fstream>
#include <algorithm>
using namespace std;









void quick_sort(vector<int> &sort, int left, int right) {
    if (left >= right) {
        return;
    }
    bool loop = true;
    int dif = sort[(left + right) / 2];

    int l = left;
    int r = right;


    while (l <= r) {
        
        while(sort[l] < dif) {
            l++;
        }
        while(sort[r] > dif) {
            r--;
        }
        
        if (l <= r) {
            swap(sort[l], sort[r]);
            l++;
            r--;
        }
    }
    quick_sort(sort, left, r);
    quick_sort(sort, l, right);
}


int main() {
    vector<int> sort = {3,5,2,6,8,7,4,9};
    int left = 0;
    int right = sort.size() - 1;
    quick_sort(sort, left, right);
    for (int i = 0; i < sort.size(); i++) {
        cout << sort[i];
    }
}