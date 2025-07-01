#include <iostream>    
#include <string>
using namespace std;


class DivByZero : public exception
{
    virtual const char* what() const noexcept
    {
        return "Division by zero";
    }
};

void division(int x, int y){
    if (y == 0){
        throw DivByZero();
    }
    else{
        cout << x / y << endl;
    }
}

int main(){
    int x;
    int y;
    cout << "Enter x value: ";
    cin >> x;
    cout << "Enter y value: ";
    cin >> y;
    try
    {
        division(x, y);
    }
    catch (exception& e)
    {   
        cout << "Exception Caught: " << e.what() << endl;
    }



    return 0;
}