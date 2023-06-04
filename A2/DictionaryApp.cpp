#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string filename;
    string seperators;
    cout << "Enter the name of an input text file: ";
    cin >> filename;
    cout << "Enter the seperator chracters: ";
    cin >> seperators;

    while (true)
    {
        int choice{mainMenu()};
    }
    return 0;
}

int mainMenu()
{
    while (true)
    {
        cout << "Choose of the following options: " << endl;
        cout << " 1 - Print the input lines" << endl;
        cout << " 2 - Print original unsorted tokens" << endl;
        cout << " 3 - Print tokens sorted by text" << endl;
        cout << " 4 - Print tokens sorted by frequency" << endl;
        cout << " 5 - Print tokens sorted by length" << endl;
        cout << " 0 - Exit" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        if (choice < 0 || choice > 5)
        {
            cout << "Invalid choice. Please try again." << endl;
        }
        else
        {
            return choice;
        }
    }
}