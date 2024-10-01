#include <bits/stdc++.h>
using namespace std;
class company
{
public:
    string name;
    int age;
    int salary;
    int id;
    string post;
};
vector<company> employee;
void load_from_file()
{
    ifstream data_file("employees.txt");
    if (data_file.is_open())
    {
        company tem;
        string s;
        while (getline(data_file, s))
        {
            stringstream s1(s);
            s1 >> tem.id >> tem.age >> tem.salary;
            s1.ignore();
            getline(s1, tem.name, ',');
            s1.ignore();
            getline(s1, tem.post, ',');
            employee.push_back(tem);
        }
    }
    else
        cout << "file opening error!\n";
    data_file.close();
}
void save_to_file()
{
    ofstream data_file("employees.txt");
    if (data_file.is_open())
    {
        for (auto &a : employee)
            data_file << a.id << " " << a.age << " " << a.salary << " " << a.name << ", " << a.post << ",\n";
    }
    else
        cout << "file opening error!\n";
    data_file.close();
}
void addemployee()
{
    company temporary;
    cin.ignore();
    cout << "\nenter employee name: ";
    getline(cin, temporary.name);
    cout << "enter employee id: ";
    cin >> temporary.id;
    while (temporary.id < 0)
    {
        cout << "\nid must be grater than equal 0.\nenter employee id: ";
        cin >> temporary.id;
    }
    while (1)
    {
        int f = 1;
        for (auto &a : employee)
            if (temporary.id == a.id)
            {
                cout << "\nid must be unique.\nenter employee id: ";
                cin >> temporary.id;
                f = 0;
                break;
            }
        if (f)
            break;
    }
    cout << "enter employee age: ";
    cin >> temporary.age;
    while (temporary.age < 1)
    {
        cout << "\nage must be grater than 0.\nenter employee age: ";
        cin >> temporary.age;
    }
    cout << "enter employee salary: ";
    cin >> temporary.salary;
    while (temporary.salary < 1)
    {
        cout << "\nsalary must be grater than 0.\nenter employee salary: ";
        cin >> temporary.salary;
    }
    cin.ignore();
    cout << "enter employee post: ";
    getline(cin, temporary.post);
    cout << "\nemployee id " << temporary.id << " has been hired!\n\n";
    employee.push_back(temporary);
    save_to_file();
}
void viewemployee()
{
    cout << "\nenter employee id: ";
    int tem, f = 0;
    cin >> tem;
    for (auto &a : employee)
    {
        if (tem == a.id)
        {
            cout << "\nname: " << a.name << "\n"
                 << "id: " << a.id << "\n"
                 << "age: " << a.age << "\n"
                 << "post: " << a.post << "\n"
                 << "salary: " << a.salary << "\n\n";
            f = 1;
            break;
        }
    }
    if (!f)
        cout << "\nemployee id " << tem << " not found!\n";
}
void removeemployee()
{
    cout << "\nenter employee id: ";
    int tem;
    cin >> tem;
    int cnt = 0, f = 0;
    for (auto &a : employee)
    {
        if (tem == a.id)
        {
            cout << "\nemployee id " << a.id << " has been fired!\n\n";
            employee.erase(employee.begin() + cnt);
            f = 1;
            break;
        }
        else
            cnt++;
    }
    if (!f)
        cout << "\nemployee id " << tem << " not found!\n\n";
    else
        save_to_file();
}
void viewallemployee()
{
    if (employee.size() == 0)
        cout << "\nNo employees found !\n\n";
    else
        for (auto &a : employee)
            cout << "name: " << a.name << "\n"
                 << "id: " << a.id << "\n"
                 << "age: " << a.age << "\n"
                 << "post: " << a.post << "\n"
                 << "salary: " << a.salary << "\n\n";
}
void update_post()
{
    cout << "\nenter employee id: ";
    int tem;
    cin >> tem;
    cin.ignore();
    int f = 0;
    for (auto &a : employee)
    {
        if (tem == a.id)
        {
            cout << "enter new post: ";
            getline(cin, a.post);
            cout << "employee id " << tem << " is now " << a.post << "\n\n";
            f = 1;
            break;
        }
    }
    if (!f)
        cout << "\nemployee id " << tem << " not found!\n\n";
    else
        save_to_file();
}
void update_salary()
{
    cout << "\nenter employee id: ";
    int tem;
    cin >> tem;
    int f = 0;
    for (auto &a : employee)
    {
        if (tem == a.id)
        {
            cout << "enter new salary: ";
            cin >> a.salary;
            while (a.salary < 1)
            {
                cout << "\nsalary must be grater than 0.\nenter employee salary: ";
                cin >> a.salary;
            }
            cout << "employee id " << tem << "'s salary has been updated !\n\n";
            f = 1;
            break;
        }
    }
    if (!f)
        cout << "\nemployee id " << tem << " not found!\n\n";
    else
        save_to_file();
}

int main()
{
    load_from_file();
    cout << "Assalamu alaikum wa rohmatulloh!\nWelcome to your employee management system !\nChoose any of the options given below:\n1. Add employee\n2. View employee\n3. Remove employee\n4. Update employee post\n5. Update employee salary\nChoose: ";
    int i;
    cin >> i;
    while (i < 1 || i > 5)
    {
        cout << "invalid option chosen !\nchoose: ";
        cin >> i;
    }
    while (i != 6)
    {
        if (i == 1)
            addemployee();
        else if (i == 2)
        {
        here:
        {
            cout << "single employee (1)\nall employee (2)\nchoose: ";
            cin >> i;
            if (i == 1)
                viewemployee();
            else if (i == 2)
                viewallemployee();
            else
            {
                cout << "invalid option !\n";
                goto here;
            }
        }
        }
        else if (i == 3)
            removeemployee();
        else if (i == 4)
            update_post();
        else if (i == 5)
            update_salary();
        else
            cout << "\ninvalid option !\n\n";
        cout << "1. Add employee\n2. View employee\n3. Remove employee\n4. Update employee post\n5. Update employee salary\n6.exit\nChoose: ";
        cin >> i;
    }
    cout << "\nThanks for using the employee management system !";
}
