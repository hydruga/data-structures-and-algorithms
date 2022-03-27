#include <iostream>
#include "Double_List.h"
#include <string>
using namespace std;

int main() {
    Double_List<string> list;
    char menu='C';
    while(menu=='C')
    {
        char entry;
        cout << "******* Welcome to Queue_Linked_List Menu *******\n\n";
        cout << "Enter [X] to Exit \n";
        cout << "Enter [I] to Insert Front Node\n";
        cout << "Enter [J] to Insert Back Node\n";
        cout << "Enter [P] to Pop Front Node\n";
        cout << "Enter [Q] to Pop Back Node\n";
        cout << "Enter [D] to Display all nodes in structure from first to last\n";
        cout << "Enter [B] to Display all nodes in structure from last to first\n";


        cin >> entry;
        system("clear");
        switch(toupper(entry)){
            case 'X' : menu = entry;
            break;
            case 'I' : {
                cout << "Enter string value to insert to front"<< endl;
                string val;
                cin >> val;
                list.push_front(val);
            }
            break;
            case 'J' : {
                    cout << "Enter string value to insert to back"<< endl;
                    string val;
                    cin >> val;
                    list.push_back(val);
                }
                break;
            case 'P' :  {
                cout << list.front() << " removed from queue.\n";
                list.pop_front();
            }
            break;
            case 'Q' :  {
                cout << list.back() << " removed from queue.\n";
                list.pop_back();
            }
            break;
            case 'D' : { list.display_forward(); }
            break;
            case 'B' : { list.display_backward();}
        }

    }
    cout << "\nGoodbye!";
}
