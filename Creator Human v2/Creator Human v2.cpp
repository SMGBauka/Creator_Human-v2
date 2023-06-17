#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

#define GOT  goto ret_f; 
#define TRC system("cls");

class Human {
    short int size;
    string* name;
public:

    Human() {
        size = 0;
        name = new string[10];
    }

    ~Human() {
        cout << "ADD HUMAN COUNT:" << size;
    }
    void add(string namer) {
        name[size] = namer;
        size++;
    }
    void about() {
        cout << "Hello! My name is Bauka, and I like a writing programs in the language C++.\nI begin learning C++ at 12yo. \nThank you for reading the text! :)\n";
    }
    void remove(short int s) {
        for (short int i = s; i < size; i++) {
            name[i-1] = name[i];
        }
        size--;
    }

    void printer() {
        if (size == 0) {
            cout << "NULL\n";
        }
        else {
            for (short int i = 0; i < size; i++) {
                cout << "NUM:" << (i + 1) << "\t NAME:" << name[i] << endl;
            }
        }
    }

    void edit(short int i) {
        string namer;

        if (i <= size) {
            cout << "NEW NAME:";
            cin >> namer;
            name[i - 1] = namer;
            cout << "HIM NEW NAME IS:" << namer;
            cout << endl;
        }
        else { cout << "ERROR!"; }
        
    }

};

void menu_list() {

    cout << "What are u want?\n";
    cout << "1.ADD HUMAN\n";
    cout << "2.PRINT HUMAN LIST\n";
    cout << "3.EDIT HUMAN\n";
    cout << "4.REMOVE HUMAN\n";
    cout << "5.ABOUT ME\n";
    cout << "6.EXIT\n";


}



int main() {

    Human Menu;
    string name;
    short int num;
    string namer;

ret_f:
    menu_list();
    cout << "PLS SELECT:";


    while (!(cin >> num) || (cin.peek() != '\n'))
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "\nERROR!\n";
        cout << "INCORRECT INPUTE!\n";
        GOT;
    }
    TRC;

    switch (num) {
    case 1://ADD Human Menu
        cout << "HUMAN NAME:";
        cin >> name;

        if (name.size() > 0) {
            Menu.add(name);
        }

        TRC;
        GOT;
        
        break;

    case 2://Print Human

        Menu.printer();
        cout << endl;
        GOT;

        break;

    case 3:
        short int sj;
        Menu.printer();
        cout << endl;
        cout << "PLS SELECT HUMAN, WHO DO YOU WANT REMAKE:";
        cin >> sj;

        if (sj > -1) {
            TRC;
            Menu.edit(sj);
            cout << endl;
        }
        else { cout << "ERROR!"; }
        GOT;
        break;


    case 4://Remove human
        short int i;
        Menu.printer();
        cout << endl;
        cout << "PLS SELECT HUMAN:";
        cin >> i;
        Menu.remove(i);
        TRC;

        GOT;

        break;

    case 5://About myself
        
        Menu.about();
        cout << endl;
        GOT;

        break;


    case 6:// exit
        return 0;
        break;
    default://Anymore select

        cout << "ERROR!\n";
        cout << endl;
        GOT;

        break;
    }
}