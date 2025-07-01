#include <iostream>
#include <string>
using namespace std;

class Language {
public:
    virtual string getLanguage() {
        return "Generic Language";
    }
    virtual string print(){
        return "test";
    }
};

class English : public Language {
public:
    string getLanguage() override {
        return "English Langauge";
    }
};

class German : public Language {
public:
    string getLanguage() override {
        return "Deutsche Sprache";
    }
};

class Spanish : public Language {
public:
    string getLanguage() override {
        return "Idioma Espanol";
    }
};

int main() {
    English eng;
    German ger;
    Spanish spa;

    Language& l1 = eng;
    Language& l2 = ger;
    Language& l3 = spa;

    cout << l1.getLanguage() << endl;
    cout << l2.getLanguage() << endl;
    cout << l3.getLanguage() << endl;
    cout << l3.print() << endl;

    return 0;
}