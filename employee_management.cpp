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
void addemployee()
{
    company temporary;
    cout << "enter employee name: ";
    cin >> temporary.name;
    cout << "enter employee id: ";
    cin >> temporary.id;
    cout << "enter employee age: ";
    cin >> temporary.age;
    cout << "enter employee salary: ";
    cin >> temporary.salary;
    cin.ignore();
    cout << "enter employee post: ";
    getline(cin, temporary.post);
    cout << "\nemployee id " << temporary.id << " has been hired!\n\n";
    employee.push_back(temporary);
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
        cout << "\nemployee id " << tem << " not found!\n";
}
void viewallemployee()
{
    for (auto &a : employee)
        cout << "\nname: " << a.name << "\n"
             << "id: " << a.id << "\n"
             << "age: " << a.age << "\n"
             << "post: " << a.post << "\n"
             << "salary: " << a.salary << "\n";
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
            f = 1;
            break;
        }
    }
    if (!f)
        cout << "employee id " << tem << " not found!\n";
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
            f = 1;
            break;
        }
    }
    if (!f)
        cout << "\nemployee " << tem << " not found!\n";
}
int main()
{
    cout << "Assalamu alaikum wa rohmatulloh!\nWelcome to your employee management system !\nChoose any of the options given below:\n1. Add employee\n2. View employee\n3. Remove employee\n4. Update employee post\n5. Update employee salary\nChoose: ";
    int i;
    cin >> i;
    while (i != 6)
    {
        if (i == 1)
            addemployee();
        if (i == 2)
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
                cout << "wrong entry !\n";
                goto here;
            }
        }
        }
        if (i == 3)
            removeemployee();
        if (i == 4)
            update_post();
        cout << "1. Add employee\n2. View employee\n3. Remove employee\n4. Update employee post\n5. Update employee salary\n6.exit\nChoose: ";
        cin >> i;
    }
    cout << "Thanks for using the employee management system !";
}
