#include <iostream>
#include "LinkedList.h"
#include <string>

//#include <ctype.h>
using namespace std;

int main() {
    LinkedList<string> list;
    char menu='C';
    while(menu=='C')
    {
        char entry;
        cout << "******* Welcome to LinkedList Menu *******\n\n";
        cout << "Enter [X] to Exit \n";
        cout << "Enter [I] to Insert Node\n";
        cout << "Enter [D] to Delete Node\n";
        cout << "Enter [P] to Print all nodes in structure\n";
        cout << "Enter [F] to Find a node\n";
        cin >> entry;
        system("clear");
        switch(toupper(entry)){
            case 'X' : menu = entry;
            break;
            case 'I' : {
                cout << "Enter string value to insert \n"<< endl;
                string val;
                cin >> val;
                list.insert(val);
            }
            break;
            case 'D' :  {
                cout << "Enter string value to delete \n"<< endl;
                string val;
                cin >> val;
                list.deleteNode(val);
            }
            break;
            case 'P' : { list.display(); }
            break;
            case 'F' : {
                cout << "Enter string value to find \n"<< endl;
                string val;
                cin >> val;
                if (list.find(val) == -1){
                    cout << "Node not found in list\n";
                }
                else { cout << "Node " << val << " found at position " << list.find(val) << endl; }
            }

        }

    }
    return 0;
}
