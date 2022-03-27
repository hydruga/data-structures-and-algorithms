#include <iostream>
using namespace std;

// Variables
const int asize = 10;
int num_arry[asize] = { 1,3,5,7,9,11,13,15,17,19 };
int x = 0;
int recursiveCount = 0;
int loopCount = 0;

// Function prototype
bool isMemberRecursive(int ar[], int e, int ix);
bool isMember(int ar[], int e, int ix);


int main() {
    cout << "Enter an integer to search for: ";
    cin >> x;
    //Recursive version

    cout << "\nRecursive- ";

    if (isMemberRecursive(num_arry, asize, x) == false) {
        cout << "Not a Member\n" << "Recursive calls: " << recursiveCount;
    }
    else if (isMemberRecursive(num_arry, asize, x) == true) {
        cout << "Is Member\n" << "Recursive calls: " << recursiveCount;
    }


    // For loop search

    cout << "\n\n\nFor loop search- ";

    if (isMember(num_arry, asize, x) == false) {
        cout << "Not a Member" << "\nFor loop count: " << loopCount;
    }
    else {
        cout << "Is Member" << "\nFor loop count: " << loopCount;
    }
    cout << endl;
    return 0;
}

// Function to search an array for a member using recursion.
bool isMemberRecursive(int ar[], int e, int ix) {
    static int i = 0;
    if (e <= 0) // Base case end of array
        {
        return false;
        }
    else if (ar[i] == ix) {
        return true;
    }
    else
    {
        i++;
        recursiveCount++;
        return isMemberRecursive(ar, e - 1, ix);
    }
}

// Function to search an array for a member using a for loop.
bool isMember(int ar[], int e, int ix) {
    for (int i = 0; i < e; i++) {
        if (ar[i] == ix) {
            return true;
        }
    loopCount++;
    }
    return false;
}
