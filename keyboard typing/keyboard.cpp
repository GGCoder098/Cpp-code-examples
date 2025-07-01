#include <iostream>  
#include <ctime>  
#include <vector>  
#include <string>
#include <array>
#include <fstream>
#include <algorithm>
#include <random>
#include <sstream>
#include <regex>
#include <iomanip>

using namespace std;



class Record_table
{
    public:
    void write_score(string user, double result){
        file.open("record_table.txt", std::ios::app);
        file << user << "↔" << result << endl;
        file.close();
    }
    void load_table(){
        calculate();
        for (int n = 0; n < username.size(); n++){
            string x = username[n];
            string y = record[n];
            cout << "User: " << x << " Time: " << y << endl;
        }
    }

    void find_record(){
        calculate();
        string user_temp;
        string record_temp = record[0];
        string record_comp;
        for (int n = 0; n < username.size(); n++){
            record_comp = record[n];
            if (stod(record_temp) > stod(record_comp)){
                user_temp = username[n];
                record_temp = record[n];
                
            } 
        }
        cout << "All time record:" << endl <<"|User: " << user_temp << "|Time: " << record_temp << "|" << endl;
    }



    private:
    void calculate(){
        username.clear();
        record.clear();
        read.open("record_table.txt");
        while (getline(read, str)){
            regex del("↔");
            sregex_token_iterator it(str.begin(), str.end(), del, -1);
            sregex_token_iterator end;
            int count = 0;
            while (it != end){
                
                if (count == 0){
                    count++;
                    username.push_back(*it);
                }
                else{
                    count = 0;
                    record.push_back(*it);
                }
                ++it;
            }
        }
    }



    ofstream file;
    ifstream read;
    string str;
    vector <string> username;
    vector <string> record;

};


class KeyboardRace
{
    public:
    



    void game(){
        timer();
        show_phrase();
        start = clock();
        bool check = input();
        finish = clock();
        result = check_time();
        cout << "You finished in " << fixed << setprecision(2) << result << " seconds!" << endl;
        if (check == false){
            cout << "Your phrase didn't match the one you were given, better luck next time!" << endl;
        }
        else{
            cout << "enter your name for the record table: ";
            getline(cin, user);
            record.write_score(user, result);
        }
    }


    

    private:
    void timer(){
        cout << "3" << endl;
        _sleep(1000);
        cout << "2" << endl;
        _sleep(1000);
        cout << "1" << endl;
        _sleep(1000);
        cout << "GO!" << endl;
    }

    void generate_phrase(){
        file.open("phrases.txt");
        int lines = 0;
        while (getline(file, phrase)){
            lines++;
        }
        file.clear();
        file.seekg(0);
        srand(time(0));
        int randomLine = rand() % lines;
        lines = 0;
        while (getline(file, phrase)){
            lines++;
            if (lines == randomLine){
                break;
            }
        }
        
    }

    void show_phrase(){
        generate_phrase();
        cout << phrase << endl;
    }
    double check_time(){
        float time = (finish - start) / 1000.0;
        return time;
    }
    bool input(){
        getline(cin, user_phrase);
        if (user_phrase == phrase){
            return true;
        }
        else{
            return false;
        }

    }


    ifstream file;
    string phrase;
    string user_phrase;
    float result;
    clock_t start, finish;
    string user;
    Record_table record;
};


int main(){
    KeyboardRace x;
    Record_table y;
    x.game();
    y.load_table();
    y.find_record();
}