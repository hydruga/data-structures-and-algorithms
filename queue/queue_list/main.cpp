#include <iostream>
#include "List_Queue.h"
using namespace std;

int main() {
    List_Queue<string> queue;
    char menu='C';
    while(menu=='C')
    {
        char entry;
        cout << "******* Welcome to Queue_Linked_List Menu *******\n\n";
        cout << "Enter [X] to Exit \n";
        cout << "Enter [I] to Insert Node\n";
        cout << "Enter [P] to Pop Front Node\n";
        cout << "Enter [D] to Display all nodes in structure\n";
        cout << "Enter [E] to check if queue is empty\n";

        cin >> entry;
        system("clear");
        switch(toupper(entry)){
            case 'X' : menu = entry;
            break;
            case 'I' : {
                cout << "Enter string value to insert"<< endl;
                string val;
                cin >> val;
                queue.push(val);
            }
            break;
            case 'P' :  {
                cout << queue.front() << " removed from queue.\n";
                queue.pop();
            }
            break;
            case 'D' : { queue.display(); }
            break;
            case 'E' : {
                (queue.empty()==true) ? cout << "Queue is empty!!\n" : cout << "NOT EMPTY!\n";
            }
        }

    }
    cout << "\nGoodbye!";
    return 0;
}
