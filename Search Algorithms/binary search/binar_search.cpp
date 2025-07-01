#include <iostream>
using namespace std;


int main() {
    const int arr[10] ={1,2,3,4,5,6,7,8,9,10};
    int max = std::size(arr);
    constexpr int size = std::size(arr);
    int min = 0;
    int s_num;
    int n = 0;

    cout << "enter a number to search: ";
    cin >> s_num;
    int middle = max / 2;

    while (n == 0 && min < size && max > 0) {
        if (s_num > arr[middle]) {
            min = middle;
            middle = (max + min) / 2;

        }
        else if (s_num < arr[middle]) {
            max = middle;
            middle = (max + min) / 2;
        }
        else {
            cout << s_num << " is at point: " << middle;
            n = 1;
        }
    }
}