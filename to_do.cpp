#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

void add_task()
{
    int n;
    string add, time;
    char choice;
    ofstream obj("task.csv");
    do
    {
        cout << " Enter the task number: " << endl;
        cin >> n;
        cout << " Enter the task: ";
        cin.ignore();
        getline(cin, add);
        cout << " Set the time: ";
        getline(cin, time);
        obj << n << "," << add << "," << time << endl;
        cout << " Do you want to add more task: (y/n) ";
        cin >> choice;
        cout << " Your task is save! " << endl;
    } while (choice == 'y');
    obj.close();
}

void show()
{
    ifstream obj("task.csv");

    string line;
    while (getline(obj, line))
    {
        stringstream ss(line);
        string tnumber, ttask, ttime;
        getline(ss, tnumber, ',');
        getline(ss, ttask, ',');
        getline(ss, ttime, ',');
        cout << "Task number: " << tnumber << endl;
        cout << "Task: " << ttask << endl;
        cout << "Time: " << ttime << endl;
    }
    obj.close();
}

void edit_task()
{
    int n;
    string task, time;
    bool found = false;
    ifstream obj("task.csv");
    ofstream temp("temp.csv");
    cout << " Enter the task number: ";
    cin >> n;
    cout << " Enter the updated task: ";
    cin.ignore();
    getline(cin, task);
    cout << " Enter the new time: ";
    getline(cin, time);
    string line;
    while (getline(obj, line))
    {
        stringstream ss(line);
        string tnumber, ttask, ttime;
        getline(ss, tnumber, ',');
        getline(ss, ttask, ',');
        getline(ss, ttime, ',');
        if ((stoi(tnumber)) == n)
        {
            ttask = task;
            ttime = time;
            found = true;
            temp << tnumber << "," << ttask << "," << ttime << "," << endl;
        }
    }

    obj.close();
    temp.close();
    if (found)
    {
        remove("task.csv");
        rename("temp.csv", "task.csv");
        cout << " Your task is updated! " << endl;
    }
    else if (!found)
    {
        cout << " Not found! " << endl;
    }
}

void remove_task()
{
    int n;
    bool found = false;
    ifstream obj("task.csv");
    ofstream temp("temp.csv");
    cout << " Enter the task number you want to remove: " << endl;
    cin >> n;
    string line;
    while (getline(obj, line))
    {
        stringstream ss(line);
        string tnumber, ttask, ttime;
        getline(ss, tnumber, ',');
        getline(ss, ttask, ',');
        getline(ss, ttime, ',');
        if ((stoi(tnumber)) == n)
        {
            found = true;
        }
        else
        {
            temp << tnumber << "," << ttask << "," << ttime << endl;
        }
    }

    obj.close();
    temp.close();
    if (found)
    {
        remove("task.csv");
        rename("temp.csv", "task.csv");
        cout << " Your task is removed! " << endl;
    }
    else if (!found)
    {
        cout << "Not found! " << endl;
    }
}

void remove_all()
{
    ofstream obj("task.csv", ios::trunc);
    obj.close();
    cout << " All task are removed! " << endl;
}

void del_file()
{
    remove("task.csv");
    cout << " You task file is deleted! " << endl;
}

int main()
{
    int choice;
    cout << "=== Welcome to To-Do List ===" << endl;
    do
    {
        cout << "=== Task menue ===" << endl;
        cout << "1. Add the task " << endl;
        cout << "2. Show the task " << endl;
        cout << "3. Update the task " << endl;
        cout << "4. Remove the task " << endl;
        cout << "5. Remove all the task " << endl;
        cout << "6. Delete the task file " << endl;
        cout << "7. Exit! " << endl;
        cout << " Enter the number from (1 to 6): ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            add_task();
            break;
        case 2:
            show();
            break;
        case 3:
            edit_task();
            break;
        case 4:
            remove_task();
            break;
        case 5:
            remove_all();
            break;
        case 6:
            del_file();
            break;
        case 7:
            cout << " Exit! " << endl;
            return 0;
        default:
            cout << " Invalid choice! " << endl;
        }
    } while (choice != 8);

    return 0;
}
