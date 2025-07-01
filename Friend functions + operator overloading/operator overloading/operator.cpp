#include <iostream>  
using namespace std;  
class Array {  
    friend Array operator& (Array arr1, Array arr2);  
public:  
    Array(int m, int n) {  
        this->m = m;  
        this->n = n;  
        this->a = new int*[m];  
        for (int i = 0; i < m; i++) {  
            this->a[i] = new int[n];  
        }  
    }  
    ~Array() {  
        for (int r = 0; r < m; r++) {  
        delete[] a[r];  
    }  
    delete[] a;  
    }  
    void init(int c) {  
        for (int r = 0; r < m; r++) {  
            for (int j = 0; j < n; j++) {  
                a[r][j] = c;  
                c++;  
            }  
        }  
    }  
    int** a;  
    int m;  
    int n;  
};  
Array operator& (Array arr1, Array arr2) {  
    int rows = arr1\.m;  
    int cols = arr1\.n;  
    Array new_arr(rows, cols);  
    for (int r = 0; r < rows; r++) {  
        for (int j = 0; j < cols; j++) {  
            new_arr.a[r][j] = arr1\.a[r][j] * arr2\.a[r][j];  
        }  
    }  
    return new_arr;  
}  
int main() {  
    int c = 0;  
    Array arr1(5, 7);  
    Array arr2(5, 7);  
    arr1\.init(1);  
    arr2\.init(1);  
    Array arr3 = arr1 & arr2;  
    for (int r = 0; r < 5; r++) {  
        for (int j = 0; j < 7; j++) {  
            cout << arr3\.a[r][j] << " ";  
        }  
        cout << endl;  
    }  
    return 0;  
}  