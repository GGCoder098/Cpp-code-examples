#include <iostream>
#include <string>
using namespace std;



struct Person
{
    string name;
    int age;
    string education;
    int experience;
};

class Student   
{
    protected:
    Person p1;

    public:
    Student(string s_name, int s_age, string s_edu){
        p1.experience = 0;
        p1.name = s_name;
        p1.age = s_age;
    };
};

class Intern : public Student
{
    public:
    Intern(){
        p1.experience++;
    };
};

class Junior : public Intern
{
    public:
    Junior(){
        p1.experience++;
    };
};


class Senior : public Junior
{  
    public:
    Senior(){
        p1.experience++;
    };
};


void main(){

}

