#include <iostream>  
#include <ctime>  
#include <vector>  
#include <string>
#include <array>
#include <algorithm>
#include <random>
using namespace std;


class Field
 {
    public:
    bool set_field(int x, int y, string type){
        if (field[y][x] == "+"){
            field[y][x] = type;
            return true;
        }
        else{
            return false;
        }
    }

    void print_field(){
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << "|";
                cout << field[i][j];
            }
            cout << "|" << "\n" << "" << "\n";
        }
    }
    bool check_won(string type){
        if (field[0][0] == field[1][0] && field[0][0] == field[2][0] && field[0][0] == type){
            return true;
        }
        else if (field[0][1] == field[1][1] && field[0][1] == field[2][1] && field[0][1] == type){
            return true;
        }
        else if (field[0][2] == field[1][2] && field[0][2] == field[2][2] && field[0][2] == type){
            return true;
        }
        else if (field[0][0] == field[0][1] && field[0][0] == field[0][2] && field[0][0] == type){
            return true;
        }
        else if (field[1][0] == field[1][1] && field[1][0] == field[1][2] && field[1][0]== type){
            return true;
        }
        else if (field[2][0] == field[2][1] && field[2][0] == field[2][2] && field[2][0]== type){
            return true;
        }
        else if (field[0][0] == field[1][1] && field[0][0] == field[2][2] && field[0][0] == type){
            return true;
        }
        else if (field[0][2] == field[1][1] && field[0][2]== field[2][0] && field[0][2] == type){
            return true;
        }
        else{
            return false;
        }
    }


    private:
    string field[3][3] = {{"+","+","+"},{"+","+","+"},{"+","+","+"}};

 };

 class game
 {
    public:

    void game_loop(){
        game = true;
        while (game == true){
            
            cout << "Your Turn, enter x, y" << endl;
            cin >> x;
            cin >> y;
            cout << "\n";
            while (control.set_field(x - 1,y- 1,"x") == false){
                cin >> x;
                cin >> y;
                cout << "\n";
            }

            control.print_field();

            if (control.check_won("x")){
                cout << "x won" << endl;
                game = false;
                break;
            }
            if (control.check_won("o")){
                cout << "o won" << endl;
                game = false;
                break;
            }

            cout << "Computer Turn" << endl;
            while (control.set_field(rand() % (2 - 0 + 1) + 0,rand() % (2 - 0 + 1) + 0,"o") == false){
            }
            control.print_field();
            if (control.check_won("x")){
                cout << "x won" << endl;
                game = false;
                break;
            }
            if (control.check_won("o")){
                cout << "o won" << endl;
                game = false;
                break;
            }
            cout << "\n";

        }
        
    }
    private:
    bool game;;
    int x;
    int y;
    Field control;
 };

 



 void main(){
    srand(time(0));
    game x;
    x.game_loop();
 };