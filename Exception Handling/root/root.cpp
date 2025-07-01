#include <iostream>    
#include <string>
#include <cmath>
using namespace std;


class NegRoot : public exception
{
    virtual const char* what() const noexcept
    {
        return "Num is negative when trying to root!";
    }
};

double root_calc(int a, int x, int b){
    double num = (a*x) + b;
    if (num < 0){
        throw NegRoot();
    }
    else{
        num = sqrt(num);
        return num;
    }

};

int main(){
    try{
        cout << root_calc(1,2,-3);
    }
    catch(exception& e)
    {
        cout << "Exception found: " << e.what() << endl;
    }
}