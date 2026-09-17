#include <iostream>
using namespace std;
int main()
{
    int num, a, b, next;
    cout << " Enter the number: ";
    cin >> num;
    a = 0;
    b = 1;
    for (int i = 0; i < num; i++)
    {
        cout << a << endl;
        next = a + b;
        a = b;
        b = next;
    }
    return 0;
}
