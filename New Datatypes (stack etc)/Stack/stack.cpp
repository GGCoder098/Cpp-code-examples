#include <iostream>
#include <string>
using namespace std;

class Book{
    public:
    string author;
    string title;
    int unique_key;
};

class Stack{
    public:
    Book data;
    Stack *next;

};

class Stack_library
{
    public:
    void add(Stack*& top, Book book) {    
        Stack* temp = new Stack;  
        temp->data = book;  
        temp->next = top;  
        top = temp;  
        
    }    
    void print(Stack* top) {    
        Stack* temp = top;  
        int count = 0;
        if (temp == nullptr) {    
            cout << "Empty" << endl;    
            return;  
        }    
        while (temp != nullptr) {  
            cout << "Index: " << count << "\nAuthor: " << temp->data.author << "\nTitle: " << temp->data.title << "\nUnique Key: " << temp->data.unique_key << "\n" << endl;
            temp = temp->next;  
            count++;
        }    
    }
    Stack* top(Stack* top) {    
        Stack* temp = top;
        if (temp == nullptr) {    
            cout << "Empty" << endl;    
            return NULL;  
        }    
        return temp;   
    }
    void pop(Stack* top) {    
        Stack* temp = top;
        if (temp == nullptr) {    
            cout << "Empty" << endl; 
        }
        delete top;
        *top = *temp->next;
           
    }
};

void printstack(Stack* x){
    cout << "Author: " << x->data.author << "\nTitle: " << x->data.title << "\nUnique Key: " << x->data.unique_key << "\n" << endl;
}

int main(){
    Book book1;
    book1.author = "1";
    book1.title = "1";
    book1.unique_key = 1;

    Book book2;
    book2.author = "2";
    book2.title = "2";
    book2.unique_key = 2;

    Book book3;
    book3.author = "3";
    book3.title = "3";
    book3.unique_key = 3;

    Stack *stack1 = nullptr;

    Stack_library x;
    x.add(stack1, book1);
    x.add(stack1, book2);
    x.add(stack1, book3);
    x.print(stack1);
    x.pop(stack1);
    x.print(stack1);
    return 0;
}