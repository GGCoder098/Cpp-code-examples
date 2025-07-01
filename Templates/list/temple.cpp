#include <iostream>  
#include <vector>
#include <algorithm>
using namespace std;  


template <class T>
class VectorTools {
    public:
    T *arr;
    VectorTools(int size){
        this -> arr = new T [size];
    }
    private:
    int partition(int low, int high) {
        int pivot = arr[high];
        int i = (low - 1);

        for (int j = low; j <= high - 1; j++) {
            if (arr[j] <= pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return (i + 1);
    }
    public:
    void sort(int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);
            sort(arr, low, pi - 1);
            sort(arr, pi + 1, high);
        }
    }
    int search(vector<T> arr, T n){
        for (int i = 0; i < arr.size(); i++){
            if (arr[i] == n){
                return i;
            }
        }
        return -1;
    }
    void del(int index){
        arr.splice(index, 1);
    }
    int max(vector<T> arr){
        int max = arr[0];
        for (auto i: arr){
            if (i > max){max = i;}
        }
        return max;
    }
    int min(vector<T> arr){
        int min = arr[0];
        for (auto i: arr){
            if (i < min){min = i;}
        }
        return min;
    }

};
int main(){
    VectorTools<int> arr(10);
    

}