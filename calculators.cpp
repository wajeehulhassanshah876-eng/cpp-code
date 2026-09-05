#include <iostream>
using namespace std;
int main()
{
    long long num1, num2;
    int choice;
    cout << "==========Your Console Calculator=============" << endl;
    do
    {
        cout << " The operations are: " << endl;
        cout << "1. Addition + " << endl;
        cout << "2. Subtraction - " << endl;
        cout << "3. Multiplication * " << endl;
        cout << "4. Division / " << endl;
        cout << "5. Exit " << endl;
        cin >> choice;

        cout << " Enter the two numbers: ";
        cin >> num1 >> num2;
        switch (choice)
        {
        case 1:
            cout << " Result: " << num1 << "+" << num2 << "=" << num1 + num2 << endl;
            break;
        case 2:
            cout << "Result:" << num1 << "-" << num2 << "=" << num1 - num2 << endl;
            break;
        case 3:
            cout << "Result:" << num1 << "*" << num2 << "=" << num1 * num2 << endl;
            break;
        case 4:
            if (num2 == 0)
            {
                cout << " Error! Can't divide in zero! " << endl;
            }
            else
            {
                cout << "Result:" << num1 << "/" << num2 << "=" << num1 / num2 << endl;
                break;
            }
        case 5:
            cout << " You Exit! the calcuulator " << endl;
        default:
            cout << " You enter the Invalid operation " << endl;
        }
    } while (choice != 6);

    return 0;
}