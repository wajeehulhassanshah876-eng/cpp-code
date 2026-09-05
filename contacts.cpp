#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

void Add()
{
    string name;
    long long number;
    char choice;
    ofstream obj("contact.csv");
    do
    {

        cout << " Enter the contact name: ";
        cin.ignore();
        getline(cin, name);
        cout << " Enter the contact number: ";
        cin >> number;
        obj << name << "," << number << endl;
        cout << " The contact is sved successfully! " << endl;
        cout << " Do you want to add more contacts: (y/n) " << endl;
        cin >> choice;
    } while (choice == 'y');
    obj.close();
}

void show()
{

    ifstream obj("contact.csv");
    string line;
    cout << " contact name\tcontact number " << endl;
    while (getline(obj, line))
    {
        stringstream ss(line);
        string name, number;
        getline(ss, name, ',');
        getline(ss, number, ',');
        cout << name << "\t\t" << number << endl;
    }
    obj.close();
}

void locate()
{
    string name;
    cout << " Enter the contact name: " << endl;
    cin >> name;
    ifstream obj("contact.csv");
    string line;
    bool found = false;
    while (getline(obj, line))
    {
        stringstream ss(line);
        string Name, Number;
        getline(ss, Name, ',');
        getline(ss, Number, ',');
        if (Name == name)
        {
            cout << Name << "\t" << Number << endl;
            found = true;
            break;
        }
        if (!found)
        {
            cout << "Not found " << endl;
        }
    }

    obj.close();
}

void edit_contact()
{

    long long number;
    cout << " Enter the number: " << endl;
    cin >> number;

    cin.ignore();

    string name;
    cout << " Enter the name you want to change: " << endl;
    getline(cin, name);

    ifstream obj("contact.csv");
    ofstream temp("temp.csv");

    string line;
    bool found = false;

    while (getline(obj, line))
    {

        stringstream ss(line);
        string Name, Number;

        getline(ss, Name, ',');
        getline(ss, Number, ',');

        if ((stoll(Number)) == number)
        {
            Name = name;
            found = true;

            temp << name << "," << number << endl;
        }
    }

    obj.close();
    temp.close();

    if (found)
    {
        remove("contact.csv");
        rename("temp.csv", "contact.csv");
        cout << " The contact name is changed! " << endl;
    }
    else
    {
        remove("temp.csv");
        cout << "Not found!" << endl;
    }
}

void remove_con()
{
    long long number;
    ifstream obj("contact.csv");
    ofstream temp("temp.csv");
    cout << " Enter the contact number: " << endl;
    cin >> number;
    bool found = false;
    string line;
    while (getline(obj, line))
    {
        stringstream ss(line);
        string Name, Number;
        getline(ss, Name, ',');
        getline(ss, Number, ',');
        if ((stoll(Number)) == number)
        {
            found = true;
        }
        else
        {
            temp << Name << "," << Number << endl;
        }
    }
    obj.close();
    temp.close();
    remove("contact.csv");
    rename("temp.csv", "contact.csv");
    if (found)
    {
        cout << " The contact is removed! " << endl;
    }
    else
    {
        cout << " Not found! " << endl;
    }
}

void delete_contact()
{
    ofstream obj("contact.csv", ios::trunc);
    if (obj.is_open())
    {

        cout << " Contatct is delete! " << endl;
        obj.close();
    }
    else
    {
        cout << " Error! " << endl;
    }
}

void remove()
{
    remove("contact.csv");
    cout << " File is delete! " << endl;
}

int main()
{
    cout << " Welcome to Contacts ! " << endl;
    int choice;
    do
    {
        cout << "1. Add the contact " << endl;
        cout << "2. Show the contact " << endl;
        cout << "3. Locate the contact " << endl;
        cout << "4. Edit the contact name " << endl;
        cout << "5. Remove the contact  " << endl;
        cout << "6. Delete all the contact " << endl;
        cout << "7. Delete file" << endl;
        cout << "8. Exit! The contact " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            Add();
            break;
        case 2:
            show();
            break;
        case 3:
            locate();
            break;
        case 4:
            edit_contact();
            break;
        case 5:
            remove_con();
            break;
        case 6:
            delete_contact();
            break;
        case 7:
            remove();
        case 8:
            cout << " Exit! " << endl;
            break;
        default:
            cout << " Invalid Choice! " << endl;
        }

    } while (choice != 9);
}
