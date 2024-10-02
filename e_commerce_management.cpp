#include <bits/stdc++.h>
using namespace std;
class Rshop;
vector<class purchase> purchase_hstry;
vector<class customer> customer_list;
vector<class products> all_prod;
vector<class seller> seller_list;
class purchase
{
};
class products
{
};

class seller
{
    string name;
    int age;
    string contact;
    string address;
    string user_name;
    string log_pass;
    friend class Rshop;

public:
    void seller_dashboard()
    {
        int choose;
        cout << "1.log in\n2.sign up\n3.exit\nchoose: ";
        cin >> choose;
        while (choose < 1 || choose > 3)
            cout << "invlid input, please try again.\nchoose: ", cin >> choose;
        if (choose == 1)
            seller_log_in();
        else if (choose == 2)
            seller_reg();
    }
    void seller_reg()
    {
        seller tem;
        cin.ignore();
        cout << "enter your name: ";
        getline(cin, tem.name);
        cout << "enter your age: ";
        cin >> tem.age;
        cin.ignore();
        cout << "enter your contact number: ";
        getline(cin, tem.contact);
        cout << "enter your address: ";
        getline(cin, tem.address);
        cout << "enter your email: ";
        getline(cin, tem.user_name);
        cout << "enter your password: ";
        getline(cin, tem.log_pass);
        cout << "thanks for signing up to our website. use your email and password to log into our website.\n";
        seller_list.push_back(tem);
    }
    void seller_log_in()
    {
        seller tem;
        cin.ignore();
        cout << "enter your email: ";
        getline(cin, tem.user_name);
        cout << "enter your password: ";
        getline(cin, tem.log_pass);
        for (auto &a : seller_list)
            if (tem.user_name == a.user_name && tem.log_pass == a.log_pass)
            {
                cout << "you have logged in\n";
                seldashboard(a);
                break;
            }
        cout << "username or password doesnt match, please try again\n";
        seller_dashboard();
    }
    void seldashboard(seller &tem)
    {
        cout << "welcome " << tem.name << " \n";
    }
    void add_product()
    {
    }
    void stock_manage()
    {
    }
    void price_update()
    {
    }
    void profit()
    {
    }
    void remove_product()
    {
    }
};

class customer
{

    string name;
    int age;
    string contact;
    string address;
    string user_name;
    string pass;
    friend class Rshop;

public:
    void customer_dashboard()
    {
        int choose;
        cout << "1.log in\n2.sign up\n3.exit\nchoose: ";
        cin >> choose;
        while (choose < 1 || choose > 3)
            cout << "invlid input, please try again.\nchoose: ", cin >> choose;
        if (choose == 1)
            customer_log_in();
        else if (choose == 2)
            customer_reg();
    }
    void customer_log_in() {}
    void customer_reg()
    {
        customer tem;
        cin.ignore();
        cout << "enter your name: ";
        getline(cin, tem.name);
        cout << "enter your age: ";
        cin >> tem.age;
        cin.ignore();
        cout << "enter your contact number: ";
        getline(cin, tem.contact);
        cout << "enter your address: ";
        getline(cin, tem.address);
        cout << "enter your email: ";
        getline(cin, tem.user_name);
        cout << "enter your password: ";
        getline(cin, tem.pass);
        cout << "thanks for signing up to our website. use your email and password to log into our website.\n";
        customer_list.push_back(tem);
    }
    void search_product()
    {
    }
    void buy_product()
    {
    }
    void add_to_cart()
    {
    }
    void payment()
    {
    }
    void order_details()
    {
    }
};

class Rshop
{
    string user_name = "admin";
    string log_pass = "admin123";

public:
    void view_seller()
    {
        for (auto &a : seller_list)
        {
            cout << "name: " << a.name << "\nage: " << a.age << "\ncontact number: " << a.contact << "\naddress: " << a.address << endl
                 << endl;
        }
    }
    void view_customers()
    {
        for (auto &a : customer_list)
            cout << "name: " << a.name << "\nid: " << a.age << "\n";
    }
    void admin_dashboard()
    {
        string user, logpass;
        cin.ignore();
        cout << "please log in:\nenter user name: ";
        getline(cin, user);
        cout << "enter password: ";
        getline(cin, logpass);
        if (user_name == user && log_pass == logpass)
            admdashboard();
        else
            cout << "wrong username or password\n";
    }
    void admdashboard()
    {
        cout << "welcome to admin dashboar:  \n\nplease choose any option given below: \n1.view sellers\n2.view customers\n3. ban someone\n4.exit\nchoose: ";
        int choose;
        cin >> choose;
        while (choose != 4)
        {
            switch (choose)
            {
            case 1:
                view_seller();
                break;
            case 2:
                view_customers();
                break;
            case 3:
                ban_();
                break;
            default:
                cout << "invalid input\n ";
                break;
            }
            cout << "1.view sellers\n2.view customers\n3. ban someone\n4.exit\nchoose: ";
            cin >> choose;
        }
    }
    void ban_seller()
    {
        cout << "es\n";
    }
    void ban_()
    {
        cout << "1.ban a seller\n2.ban a customer\n3.return\nchoose: ";
        int choose;
        cin >> choose;
        while (choose < 1 || choose > 3)
        {
            cout << "invalid input\nchoose: ";
            cin >> choose;
        }
        if (choose == 1)
            ban_seller();
        else if (choose == 2)
            ban_customer();
    }
    void ban_customer()
    {
    }
};

int main()
{
    Rshop obj;
    seller sobj;
    customer cobj;
    cout << "1.log in as admin\n2.log in as a seller\n3.log in as customer\nchoose: ";
    int choose;
    cin >> choose;
    while (choose != 4)
    {
        switch (choose)
        {
        case 1:
            obj.admin_dashboard();
            break;
        case 2:
            sobj.seller_dashboard();
            break;
        case 3:
            cobj.customer_dashboard();
            break;
        default:
            cout << "invalid input\n ";
            break;
        }
        cout << "1.log in as admin\n2.log in as a seller\n3.log in as customer\nchoose: ";
        cin >> choose;
    }
}