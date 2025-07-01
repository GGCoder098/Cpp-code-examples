#include <iostream>
#include <string>
using namespace std;

class Cipher {
    public:
    string Ceaser(string text, int shift) {
        string result;
        for (int i = 0; i < text.length(); i++) {
            if ((int)text[i] >= 97 && (int)text[i] <= 122) {
                result += static_cast<char>(((int)text[i]-97+shift)%26+97);
            }
            else if ((int)text[i] >= 65 && (int)text[i] <= 90) {
                result += static_cast<char>(((int)text[i]-65+shift)%26+65);
            }
        }
        return result;
    }
    string Atbash(string text) {
        string result;
        for (int i = 0; i < text.length(); i++) {
            if ((int)text[i] >= 97 && (int)text[i] <= 122) {
                result += static_cast<char>(26 - ((int)text[i]-97) - 1 +97);
            }
            else if ((int)text[i] >= 65 && (int)text[i] <= 90) {
                result += static_cast<char>(26 - ((int)text[i]-65) - 1 + 65);
            }
        }
        return result;
    }
    string Affine(string text, int key1, int key2) {
        if (key2 % 2 == 0 && key2 % 13 == 0) {
            cout << "key2 cannot have a common divisor of 26";
            return NULL;
        }
        string result;
        for (int i = 0; i < text.length(); i++) {
            if ((int)text[i] >= 97 && (int)text[i] <= 122) {
                result += static_cast<char>((((int)text[i]-97) * key2 + key1)%26 + 97);
            }
            else if ((int)text[i] >= 65 && (int)text[i] <= 90) {
                result += static_cast<char>((((int)text[i]-65) * key2 + key1)%26 + 65);
            }
        }
        return result;
    }
    string decrypt(string text, int key1=NULL, int key2=NULL) {
        string result;
        if (key1 == NULL && key2 == NULL) {
            for (int i = 0; i < text.length(); i++) {
                if ((int)text[i] >= 97 && (int)text[i] <= 122) {
                    result += static_cast<char>(26 - ((int)text[i]-97) - 1 +97);
                }
                else if ((int)text[i] >= 65 && (int)text[i] <= 90) {
                    result += static_cast<char>(26 - ((int)text[i]-65) - 1 + 65);
                }
            }
            return result;
        }
        if (key1 != NULL && key2 == NULL) {
            for (int i = 0; i < text.length(); i++) {
                if ((int)text[i] >= 97 && (int)text[i] <= 122) {
                    result += static_cast<char>(((int)text[i]-97-key1)%26+97);
                }
                else if ((int)text[i] >= 65 && (int)text[i] <= 90) {
                    result += static_cast<char>(((int)text[i]-65-key1)%26+65);
                }
            }
        return result;
        }
        if (key1 != NULL) {
            if (key2 % 2 == 0 && key2 % 13 == 0) {
                cout << "key2 cannot have a common divisor of 26";
                return NULL;
            }
            for (int i = 0; i < text.length(); i++) {
                if ((int)text[i] >= 97 && (int)text[i] <= 122) {
                    result += static_cast<char>((((int)text[i]-97 - key1) / key2)%26 + 97);
                }
                else if ((int)text[i] >= 65 && (int)text[i] <= 90) {
                    result += static_cast<char>((((int)text[i]-65 - key1) / key2)%26 + 65);
                }
            }
            return result;
        }
    }
};

int main() {
    Cipher cipher;
    string text = "aBcDeFg";
    int shift = 5;
    string result = cipher.Affine(text, shift,  shift);
    cout << result << endl;
    cout << cipher.decrypt(result,shift,shift) << endl;

}