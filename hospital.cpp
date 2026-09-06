#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

void Add_patient()
{
    string name, age, diseases;
    int id;
    ofstream obj("patient.csv", ios::app);
    char choice;
    do
    {

        cout << "Enter the patient id: ";
        cin >> id;
        cout << "Enter the patient name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter the patient age: ";
        cin >> age;
        cout << "Enter the patient diseases: ";
        cin >> diseases;
        obj << id << ", " << name << ", " << age << ", " << diseases << endl;
        cout << " THe paitent add successfully! " << endl;
        cout << "Do you want to add another patient? (y/n): ";
        cin >> choice;
    } while (choice == 'y');
    obj.close();
}

void show()
{
    ifstream obj("patient.csv");
    cout << "Id\tName\t\tAge\tDiseases" << endl;
    string line;
    while (getline(obj, line))
    {
        stringstream ss(line);
        string pid, pname, page, pdiseases;
        getline(ss, pid, ',');
        getline(ss, pname, ',');
        getline(ss, page, ',');
        getline(ss, pdiseases, ',');
        cout << pid << "\t" << pname << "\t" << page << "\t" << pdiseases << endl;
    }
    obj.close();
}

void locate_patient()
{
    int id;
    bool found = false;
    cout << " Enter the id of the patient: ";
    cin >> id;

    ifstream obj("patient.csv");
    string line;
    while (getline(obj, line))
    {
        stringstream ss(line);
        string pid, pname, page, pdiseases;
        getline(ss, pid, ',');
        getline(ss, pname, ',');
        getline(ss, page, ',');
        getline(ss, pdiseases, ',');
        if (stoi(pid) == id)
        {
            cout << "Id\tName\tAge\tDiseases" << endl;
            cout << pid << "\t" << pname << "\t" << page << "\t" << pdiseases << endl;
            found = true;
            break;
        }
    }
    obj.close();

    if (!found)
    {
        cout << " Not found! " << endl;
    }
}

void appointment()
{
    int patient_id;
    string doctor, date, time;
    char choice;
    ofstream obj("appointment.csv", ios::app);
    do
    {

        cout << " Enter the patient id: ";
        cin >> patient_id;
        cout << " Enter the doctor name: ";
        cin.ignore();
        getline(cin, doctor);
        cout << " Enter the appointment date: ";
        getline(cin, date);
        cout << " Enter the appointment time: ";
        cin >> time;
        obj << patient_id << ", " << doctor << ", " << date << ", " << time << endl;
        cout << " Your appointment is successfully booked to " << doctor << endl;
        cout << " Do you want to book another appointment: (y/n) " << endl;
        cin >> choice;
    } while (choice == 'y');
    obj.close();
}

void show_appointment()
{
    ifstream obj("appointment.csv");
    cout << "Patient Id\tDoctor\t\tDate\t\tTime" << endl;
    string line;
    while (getline(obj, line))
    {
        stringstream ss(line);
        string pid, pdoctor, pdate, ptime;
        getline(ss, pid, ',');
        getline(ss, pdoctor, ',');
        getline(ss, pdate, ',');
        getline(ss, ptime, ',');
        cout << pid << "\t\t" << pdoctor << "\t" << pdate << "\t\t" << ptime << endl;
    }
    obj.close();
}

void cancel_appointment()
{

    int patient_id;
    bool found = false;
    ifstream obj("appointment.csv");
    ofstream temp("temp.csv");
    cout << " Enter the patient id: ";
    cin >> patient_id;
    string line;
    while (getline(obj, line))
    {
        stringstream ss(line);
        string pid, pdoctor, pdate, ptime;
        getline(ss, pid, ',');
        getline(ss, pdoctor, ',');
        getline(ss, pdate, ',');
        getline(ss, ptime, ',');
        if ((stoi(pid)) == patient_id)
        {
            found = true;
        }
        else
        {
            temp << pid << "\t\t" << pdoctor << "\t" << pdate << "\t" << ptime << endl;
        }
    }
    obj.close();
    temp.close();
    if (found)
    {
        remove("appointment.csv");
        rename("temp.csv", "appointment.csv");
        cout << " The appointment is cancelled! " << endl;
    }
    else if (!found)
    {
        cout << " Not found! " << endl;
    }
}
void cancel()
{

    ofstream obj("appointment.csv");
    obj.close();
    cout << " All appointment are canceled! " << endl;
}

void discahrge()
{
    int id;
    bool found = false;
    cout << " Enter the id of the patient: ";
    cin >> id;
    ifstream obj("patient.csv");
    ofstream temp("temp.csv");
    string line;
    while (getline(obj, line))
    {
        stringstream ss(line);
        string pid, pname, page, pdiseases;
        getline(ss, pid, ',');
        getline(ss, pname, ',');
        getline(ss, page, ',');
        getline(ss, pdiseases, ',');
        if ((stoi(pid)) == id)
        {
            found = true;
        }
        else
        {
            temp << pid << "," << pname << "," << page << "," << pdiseases << endl;
        }
    }
    if (found)
    {
        remove("patient.csv");
        rename("temo.csv", "patient.csv");
        cout << " The patient is discharged! " << endl;
    }
    else if (!found)
    {
        cout << " Not found! " << endl;
    }
}

void discharge_all()
{
    ofstream obj("patient.csv", ios::trunc);
    obj.close();
    cout << " All the patients are discharged! " << endl;
}

void delete_data()
{
    remove("patient.csv");
    remove("appointment.csv");
    cout << " Your all data is deleted! " << endl;
}

int main()
{
    int passoward;
    int choice;
    cout << " Enter the passoward: ";
    cin >> passoward;
    if (passoward == 123)
    {
        cout << "==== Welcome to Hospital Management System! ==== " << endl;
    }
    else
    {
        cout << " Wrong passoward! " << endl;
        return 0;
    }
    do
    {
        cout<<"======= Options for you ======= "<<endl;
        cout << "1. Add the paitent " << endl;
        cout << "2. Show the paitent " << endl;
        cout << "3. Locate the paitent " << endl;
        cout << "4. Book an appoinment " << endl;
        cout << "5. Show the appoinment " << endl;
        cout << "6. Cancel the appoinment " << endl;
        cout << "7. Cancel all the appoinment " << endl;
        cout << "8. Discharge the paitent " << endl;
        cout << "9. Discharge all the paitents " << endl;
        cout << "10. Delete all the data " << endl;
        cout << "0. Exit! " << endl;
        cout << " Enter the yours choice from (1 to 10): ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            Add_patient();
            break;
        case 2:
            show();
            break;
        case 3:
            locate_patient();
            break;
        case 4:
            appointment();
            break;
        case 5:
            show_appointment();
            break;
        case 6:
            cancel_appointment();
            break;
        case 7:
            cancel();
            break;
        case 8:
            discahrge();
            break;
        case 9:
            discharge_all();
            break;
        case 10:
            delete_data();
            break;
        case 0:
            cout << " Exit! " << endl;
            ;
            return 0;
        default:
            cout << "Invalid choice! " << endl;
        }

    } while (choice != 11);
    return 0;
}