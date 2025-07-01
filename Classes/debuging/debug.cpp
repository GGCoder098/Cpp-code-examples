#include <iostream>  
#include <ctime>  
#include <vector>  
#include <string>
#include <array>
#include <fstream>
#include <algorithm>
#include <random>
using namespace std;


class A
{
public:
    virtual const char* getName() { return "A" ; };

};

class B : public A
{
public:
    virtual const char* getName() { return "B" ; };
};

class C : public B
{
public:
    virtual const char* getName() { return "C" ; };
};

class D : public C
{
public:
    virtual const char* getName() { return "D" ; };
};

int main(){
    C c;
    A &a = c;
    cout << a.getName() << endl;


    return 0;
}