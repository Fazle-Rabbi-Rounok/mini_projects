#include <bits/stdc++.h>
using namespace std;
vector<seller> seller_list;
vector<customer> customer_list;
vector<purchase> purchase_hstry;
vector<products> all_prod;

class Rshop
{
    string user_name = "admin";
    string log_pass = "admin123";

public:
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
        Rshop obj;
        cout << "welcome to admin dashboar:  \n\nplease choose any option given below: \n1.view sellers\n2.view customers\n3. ban someone\n4.exit\nchoose: ";
        int choose;
        cin >> choose;
        while (choose != 4)
        {
            switch (choose)
            {
            case 1:
                obj.view_seller();
                break;
            case 2:
                obj.view_customers();
                break;
            case 3:
                obj.ban_();
                break;
            default:
                cout << "invalid input\n ";
                break;
            }
            cout << "1.view sellers\n2.view customers\n3. ban someone\n4.exit\nchoose: ";
            cin >> choose;
        }
    }
    void view_seller()
    {
        for (auto &a : seller_list)
        {
        }
    }
    void view_customers() {}
    void ban_() {}
    void ban_seller()
    {
    }
    void ban_customer() {}
};
class seller : public Rshop
{

    string log_in;
    string log_pass;

public:
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
    string log_in;
    string log_pass;

public:
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
            admin_obj.admin_dashboard();
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
