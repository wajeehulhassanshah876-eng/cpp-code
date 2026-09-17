#include <iostream>
using namespace std;
int main()
{

    int n, num, rev = 0, digit;
    cout << "Enter the number: ";
    cin >> num;
    n = num;
    while (n != 0)
    {
        digit = n % 10;
        rev = (rev * 10) + digit;
        n = n / 10;
    }
    cout << "The reverse of the  " << num << " is " << rev << endl;
    if (num == rev && num > 0)
    {
        cout << num << " is plaindrome number! " << endl;
    }
    else
    {
        cout << num << " is not plaindrome number! " << endl;
    }
    return 0;
}
