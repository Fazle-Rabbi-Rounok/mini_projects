#include <bits/stdc++.h>
using namespace std;

class Rshop
{
public:
    string user_name = "admin";
    string log_pass = "admin123";
};
class seller : public Rshop
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
class purchase;
class products;
vector<seller> seller_list;
vector<customer> customer_list;
vector<purchase> purchase_hstry;
vector<products> all_prod;
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
void ban_seller()
{
    cout << "es";
}
void dashboard()
{
    Rshop obj;
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
void admin_dashboard()
{
    Rshop obj;
    string user, logpass;
    cin.ignore();
    cout << "please log in:\nenter user name: ";
    getline(cin, user);
    cout << "enter password: ";
    getline(cin, logpass);
    if (obj.user_name == user && obj.log_pass == logpass)
        dashboard();
    else
        cout << "wrong username or password\n";
}
int main()
{
    Rshop admin_obj;
    cout << "1.log in as admin\n2.log in as a seller\n3.log in as customer\nchoose: ";
    int choose;
    cin >> choose;
    while (choose != 4)
    {
        switch (choose)
        {
        case 1:
            admin_dashboard();
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