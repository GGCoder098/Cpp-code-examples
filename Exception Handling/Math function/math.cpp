#include <iostream>
#include <cmath>
using namespace std;

class LessThanZero : public exception
{
    public:
    virtual const char* what() const noexcept
    {
        return "Logarithm undefined";
    }
};
class TooLarge : public exception
{
    public:
    virtual const char* what() const noexcept
    {
        return "Square root undefined";
    }
};


double math_func(int x){

    if(x<0){
        throw LessThanZero();
    }
    else if(x > pow(exp(1.0) , 10.0)){
        throw TooLarge();
    }
    else{
        double final = sqrt(10-log(x));
        return final;
    }

    
}

int main(){
    double x;
    cin >> x;
    try{
        cout << math_func(x) << endl;
    }
    catch(LessThanZero& e){
        cout << "Error: " << e.what() << endl;
    }
    catch(TooLarge& e){

    }
}