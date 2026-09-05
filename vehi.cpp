#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

void Add()
{
    ofstream obj("vehicle.csv", ios::app);
    string name, brand;
    int id, model_No;
    char choice;
    do
    {

        cout << " Enter the vehicle name: ";
        cin.ignore();
        getline(cin, name);
        cout << " Enter the brand name: ";

        getline(cin, brand);
        cout << " Enter your id also: ";
        cin >> id;
        cout << " Enter the model number: ";
        cin >> model_No;
        obj << name << "," << brand << "," << id << "," << model_No << endl;
        cout << " Your " << name << " add successfully! " << endl;
        cout << " Do you want to add more vehicle: (y/n) " << endl;
        cin >> choice;
    } while (choice == 'y');
    obj.close();
}

void show_vehicle()
{
    ifstream obj("vehicle.csv");
    cout << "Name\tBrand\tId\tModel number " << endl;
    string line;
    while (getline(obj, line))
    {
        stringstream ss(line);
        string vname, vbrand, vid, vmodel_No;
        getline(ss, vname, ',');
        getline(ss, vbrand, ',');
        getline(ss, vid, ',');
        getline(ss, vmodel_No, ',');
        cout << vname << "\t" << vbrand << "\t" << vid << "\t" << vmodel_No << endl;
    }
    obj.close();
}

void locate_vehicle()
{
    int id;
    bool found = false;
    ifstream obj("vehicle.csv");
    cout << " Enter the id of your vehicle: ";
    cin >> id;
    string line;
    while (getline(obj, line))
    {
        stringstream ss(line);
        string vname, vbrand, vid, vmodel_No;
        getline(ss, vname, ',');
        getline(ss, vbrand, ',');
        getline(ss, vid, ',');
        getline(ss, vmodel_No, ',');
        if ((stoi(vid)) == id)
        {
            cout << vname << "\t" << vbrand << "\t" << vid << "\t" << vmodel_No << endl;
            found = true;
        }

        if (!found)
        {
            cout << " Not found! " << endl;
        }
    }
    obj.close();
}

void edit_vehicle()
{
    bool found = false;
    string name, brand;
    int id;
    ifstream obj("vehicle.csv");
    ofstream temp("temp.csv");
    cout << " Enter the id of your vehicle:  ";
    cin >> id;
    cout << " Enter the new vehicle name: ";
    cin.ignore();
    cin >> name;
    cout << " Enter the new vehicle brand: ";
    cin >> brand;
    string line;
    while (getline(obj, line))
    {

        stringstream ss(line);
        string vname, vbrand, vid, vmodel_No;
        getline(ss, vname, ',');
        getline(ss, vbrand, ',');
        getline(ss, vid, ',');
        getline(ss, vmodel_No, ',');
        if ((stoi(vid)) == id)
        {
            vname = name;
            vbrand = brand;
            found = true;
            temp << vname << "," << vbrand << "," << vid << "," << vmodel_No << endl;
        }
    }
    obj.close();
    temp.close();
    if (found)
    {
        remove("vehicle.csv");
        rename("temp.csv", "vehicle.csv");
        cout << " Your new requirments is updated! " << endl;
    }
    else if (!found)
    {
        cout << " Not found! " << endl;
    }
}

void service(){

    char service_choice;
    ofstream obj("vehicle.csv");
    do{
        cout<<" Enter the services you want: (1-> for wash 2-> for body change 3-> for repairing) "<<endl;
        cin>>service_choice;
        if(service_choice=='1'){
            cout<<" You have to paid 90$. "<<endl;
            obj<<" For wash service, Paid 90$. "<<endl;
        }else if(service_choice==2){
             cout<<" You have to paid 150$$. "<<endl;
            obj<<" For body change service, Paid 150$. "<<endl;
        }else if(service_choice==3){
             cout<<" You have to paid 250$$. "<<endl;
            obj<<" For wash service, Paid 250$$. "<<endl;
        }else{
            cout<<" Invalid choice! "<<endl;
        }
        cout<<" Do you want to continue this services: (y/n) ";
        cin>>service_choice;

    }while(service_choice=='y');
    obj.close();

}



void remove_vehicle()
{
    int id;
    bool found = false;
    cout << " Enter the id of your vehicle: " << endl;
    cin >> id;
    ifstream obj("vehicle.csv");
    ofstream temp("temp.csv");
    string line;
    while (getline(obj, line))
    {
        stringstream ss(line);
        string vname, vbrand, vid, vmodel_No;
        getline(ss, vname, ',');
        getline(ss, vbrand, ',');
        getline(ss, vid, ',');
        getline(ss, vmodel_No, ',');
        if ((stoi(vid)) == id)
        {
            found = true;
        }
        else
        {
            temp << vname << "," << vbrand << "," << vid << "," << vmodel_No << endl;
        }
    }
    obj.close();
    temp.close();
    if (found)
    {
        remove("vehicle.csv");
        rename("temp.csv", "vehicle.csv");
        cout << " THe vehicle is removed! " << endl;
    }
    else if (!found)
    {
        cout << " Not found! " << endl;
    }
}

void delete_all()
{
    ofstream obj("vehicle.csv", ios::trunc);
    obj.close();
    cout << " The data is deleted! " << endl;
}

void delete_file()
{
    remove("vehicle.csv");
    cout << " Your file is removed! " << endl;
}

int main()
{
    int passoward;
    int choice;
    cout << " Enter the passoward: ";
    cin >> passoward;
    if (passoward == 123)
    {
        cout << "Welcome to Vehicle shop! " << endl;
    }
    else
    {
        cout << " Wrong passoward! " << endl;
        return 0;
    }

    do
    {
        cout << "======Menue of vehicles=========" << endl;
        cout << "1. Add your vehicle " << endl;
        cout << "2. Show the vehicle " << endl;
        cout << "3. Locate the vehicle " << endl;
        cout << "4. Update the vehicle " << endl;
        cout << "5. Service providing " << endl;
        cout << "6. Remove the vehicle " << endl;
        cout << "7. Remove all the vehicles " << endl;
        cout << "8. Delete the file" << endl;
        cout << "9. Exit! " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            Add();
            break;
        case 2:
            show_vehicle();
            break;
        case 3:
            locate_vehicle();
            break;
        case 4:
            edit_vehicle();
            break;
        case 5:
            service();
            break;
        case 6:
            remove_vehicle();
            break;
        case 7:
            delete_all();
            break;
        case 8:
            delete_file();
            break;
        case 9:
            cout << " Exit! " << endl;
            return 0;
        }

    } while (choice != 10);
}
