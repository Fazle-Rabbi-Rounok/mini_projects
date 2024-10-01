#include <bits/stdc++.h>
using namespace std;
class seller
{
public:
    int id;
    string name;
    string log_in;
    string log_pass;

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
vector<seller> seller_list;

class customer
{
public:
    int id;
    string name;
    string log_in;
    string login_pass;

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
vector<customer> customer_list;

class purchase
{
};
vector<purchase> purchase_hstry;

class products
{
};
vector<products> all_prod;
class Rshop
{
    string user_name = "admin";
    string log_pass = "admin123";

public:
    void view_seller()
    {
        for (auto &a : seller_list)
        {
            cout << "name: " << a.name << "\nid: " << a.id << "\n";
        }
    }
    void view_customers()
    {
        for (auto &a : customer_list)
            cout << "name: " << a.name << "\nid: " << a.id << "\n";
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
            dashboard();
        else
            cout << "wrong username or password\n";
    }
    void dashboard()
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
            // seller_dashboard();
            break;
        case 3:
            //  customer_dashboard();
            break;
        default:
            cout << "invalid input\n ";
            break;
        }
        cout << "1.log in as admin\n2.log in as a seller\n3.log in as customer\nchoose: ";
        cin >> choose;
    }
}