#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

void Add()
{
    ofstream obj("execc.csv", ios::app);
    string name, age, marks;
    int id;
    char choice;
    do{
    cout << " Enter the name of the student: ";
    cin.ignore();
    getline(cin, name);
    cout << " Enter the id of the student: ";
    cin >> id;
    cout << " Enter the age of the student: ";
    cin >> age;
    cout << " Enter the marks of the student: ";
    cin >> marks;
    obj << name << "," << id << "," << age << "," << marks << endl;
    cout << " Student add successfully! " << endl;
    cout<<" Do you to add more data: (y/n) "<<endl;
    cin>>choice;
}while(choice == 'y' );
    obj.close();
}

void show()
{
    ifstream obj("execc.csv");
    string line;
    cout << "Name\tId\tAge\tMarks" << endl;
    while (getline(obj, line))
    {
        stringstream ss(line);
        string Name, Id, Age, Marks;
        getline(ss, Name, ',');
        getline(ss, Id, ',');
        getline(ss, Age, ',');
        getline(ss, Marks, ',');
        cout << Name << "\t" << Id << "\t" << Age << "\t" << Marks << endl;
    }
    obj.close();
}

void locate()
{
    int id;
    cout << " Enter the id: " << endl;
    cin >> id;
    ifstream obj("execc.csv");
    string line;
    bool found = false;

    while (getline(obj, line))
    {

        stringstream ss(line);
        string Name, Id, Age, Marks;
        getline(ss, Name, ',');
        getline(ss, Id, ',');
        getline(ss, Age, ',');
        getline(ss, Marks, ',');
        if ((stoi(Id)) == id)
        {
            cout << Name << "\t" << Id << "\t" << Age << "\t" << Marks << endl;
            cout << "found" << endl;
            found = true;
            break;
        }
        if (!found)
        {
            cout << " not found " << endl;
        }
    }
    obj.close();
}

void edit_marks()
{
    int marks, id;
    bool found = false;
    cout << " Enter the marks you want to change: " << endl;
    cin >> marks;
    cout << " Enter the id: " << endl;
    cin >> id;
    ifstream obj("execc.csv");
    ofstream temp("temp.csv");
    string line;
    while (getline(obj, line))
    {
        
        stringstream ss(line);
        string Name, Id, Age, Marks;
        getline(ss, Name, ',');
        getline(ss, Id, ',');
        getline(ss, Age, ',');
        getline(ss, Marks, ',');
        if (stoi(Id) == id)
        {
            Marks = to_string(marks);
            found = true;
        }
        temp << Name << "," << Age << "," << Marks << "," << Id << endl;
    }
    obj.close();
    temp.close();
    if(found){
        remove("excess.csv");
        rename("temp.csv","excess.csv");
        cout<<" Marks is updated "<<endl;

    }else if(!found){
        remove("temp.excess");
        cout<<"Not found! "<<endl;
    }
    
}

void Daily_test()
{
    int s1, s2, s3;
    int Avg, sum;
    cout << " Enter the English marks: " << endl;
    cin>>s1;
    cout << " Enter the Urdu marks: " << endl;
    cin>>s2;
    cout << " Enter the Math marks: " << endl;
    cin>>s3;
    sum = s1 + s2 + s3;
    Avg = sum / 3;
    if (Avg >= 50)
    {
        cout << " Your daily performance is good " << endl;
    }
    else
    {
        cout << " Your performance is not well! " << endl;
    }
}


void remove()
{
    int id;
    bool found = false;
    cout << " Enter the id: " << endl;
    cin >> id;
    ifstream obj("execc.csv");
    ofstream temp("temp.csv");
    string line;
    while (getline(obj, line))
    {
        stringstream ss(line);
        string Name, Age, Marks, Id;
        getline(ss, Name, ',');
        getline(ss, Age, ',');
        getline(ss, Marks, ',');
        getline(ss, Id, ',');
        if (stoi(Id) == id)
        {
            temp << Name << "," << Age << "," << Marks << "," << Id << endl;
        }
        found = true;
    }
    obj.close();
    temp.close();
    remove("execc.csv");
    rename("temp.csv", "execc.csv");
    if (found)
    {
        cout << " Student Remove! " << endl;
    }
    else
    {
        cout << " Not found! " << endl;
    }
}

void remove_all()
{
    ofstream obj("excecc.csv, ios::trunc");
    obj.close();
    cout << " Record is deleted! " << endl;
}

void file()
{
    remove("execc.csv");
}

int main()
{
    string passoward;
    int choice;
    cout << " Enter the passoward: ";
    cin >> passoward;
    if (passoward == "123")
    {
        cout << "==== WElcome to Student system!==== " << endl;
    }
    else
    {
        cout << " Invalid passoward! " << endl;
        return 0;
    }
    do
    {
        cout << "1. Add the student " << endl;
        cout << "2. Show the student " << endl;
        cout << "3. Locate the student " << endl;
        cout << "4. Enter the edit student marks " << endl;
        cout << "5. Daily test performance " << endl;
        cout << "6. Remove the student " << endl;
        cout << "7. Remove all the record " << endl;
        cout << "8. Delete the file " << endl;
        cout << "9. Exit!" << endl;

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
            edit_marks();
            break;
        case 5:
            Daily_test();
            break;
        case 6:
            remove();
            break;
        case 7:
            remove_all();
            break;
        case 8:
            file();
            cout << " Delete the file " << endl;
            break;
        case 9:
            cout << "Exit the programme! " << endl;
            return 0;
        default:
            cout << " Invalid choice! " << endl;
        }

    } while (choice != 10);
}