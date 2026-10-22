#include "Labs/Labs.h"
#include <iostream>
using namespace std;

int main()
{
    int choice = -1;
    while (choice != 0)
    {
        cout << endl << "--- CENG203 Lab ---" << endl;
        cout << " 3. Week 3 - Linked lists" << endl;
        cout << " 5. Week 5 - Recursion" << endl;
        cout << " 0. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 3:  runWeek03(); break;
        case 5:  runWeek05(); break;
        case 0:  break;
        default: cout << "Invalid choice" << endl;
        }
    }
    return 0;
}
