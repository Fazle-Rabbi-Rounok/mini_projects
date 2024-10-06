#include <bits/stdc++.h>
using namespace std;
class Rshop;
vector<class purchase> purchase_hstry;
vector<class customer> customer_list;
vector<class products> all_prod;
vector<class seller> seller_list;
vector<pair<string, vector<pair<int, int>>>> cart_list;
class purchase
{
};
class products
{
    int id;
    string name;
    int price;
    int quantity;
    string owner_name;
    friend seller;
    friend Rshop;
    friend customer;
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
        cout << "enter your user name: ";
        getline(cin, tem.user_name);
        int f;
        while (f)
        {
            f = 0;
            for (auto &a : seller_list)
                if (a.user_name == tem.user_name)
                {
                    cout << "user name already taken. please enter a new user name: ";
                    getline(cin, tem.user_name);
                    f = 1;
                    break;
                }
        }
        cout << "enter your password: ";
        getline(cin, tem.log_pass);
        cout << "thanks for signing up to our website. use your user name and password to log into our website.\n";
        seller_list.push_back(tem);
    }
    void seller_log_in()
    {
        seller tem;
        cin.ignore();
        cout << "enter your user name: ";
        getline(cin, tem.user_name);
        cout << "enter your password: ";
        getline(cin, tem.log_pass);
        for (auto &a : seller_list)
            if (tem.user_name == a.user_name && tem.log_pass == a.log_pass)
            {
                cout << "login successfull.\n";
                seldashboard(a);
                break;
            }
            else
            {
                cout << "username or password doesnt match, please try again\n";
                seller_dashboard();
            }
    }
    void seldashboard(seller &tem)
    {
        cout << "welcome " << tem.name << " \n";
        cout << "1. view poducts\n2. add products\n3. remove products\n4. update stock\n5. update price\n6. exit\nchoose: ";
        int choose;
        cin >> choose;
        while (choose != 6)
        {
            switch (choose)
            {
            case 1:
                view_products(tem);
                break;
            case 2:
                add_product(tem);
                break;
            case 3:
                remove_product(tem);
                break;
            case 4:
                stock_manage(tem);
                break;
            case 5:
                price_update(tem);
                break;
            default:
                cout << "invalid input\n ";
                break;
            }
            cout << "1. view poducts\n2. add products\n3. remove products\n4.update stock\n5. update price\n6. exit\nchoose: ";
            cin >> choose;
        }
    }
    void add_product(seller &t)
    {
        products tem;
        tem.owner_name = t.user_name;
        cout << "enter product id: ";
        cin >> tem.id;
        while (tem.id < 1)
            cout << "id must be greater than 0.\nenter id again: ", cin >> tem.id;
        int f;
        while (f)
        {
            f = 0;
            for (auto &a : all_prod)
                if (a.id == tem.id)
                {
                    cout << "product id not available. Enter a new id: ";
                    cin >> tem.id;
                    f = 1;
                    break;
                }
        }
        cin.ignore();
        cout << "enter product name: ";
        getline(cin, tem.name);
        cout << "enter product price: ";
        cin >> tem.price;
        cout << "enter product quantity: ";
        cin >> tem.quantity;
        all_prod.push_back(tem);
        cout << "product added successfully.\n";
    }
    void stock_manage(seller &t)
    {
        cout << "enter product id: ";
        int iid, f = 0;
        cin >> iid;
        for (auto &a : all_prod)
            if (a.id == iid && t.user_name == a.owner_name)
            {
                cout << "enter re stock amount: ";
                cin >> a.quantity;
                cout << "stock updated successfull.\n";
                f = 1;
                break;
            }
        if (!f)
            cout << "product id not found or the the product doesnt belong to you\n";
    }
    void price_update(seller &t)
    {
        cout << "enter product id: ";
        int pric, f = 0;
        cin >> pric;
        for (auto &a : all_prod)
            if (a.id == pric && t.user_name == a.owner_name)
            {
                cout << "enter new price: ";
                cin >> a.price;
                cout << "price updated successfull.\n";
                f = 1;
                break;
            }
        if (!f)
            cout << "product id not found or the the product doesnt belong to you\n";
    }
    void view_products(seller &t)
    {
        int choose;
        cout << "1. single product\n2. all products\n3.exit\nchoose: ";
        cin >> choose;
        while (choose < 1 || choose > 3)
            cout << "invlid input, please try again.\nchoose: ", cin >> choose;
        if (choose == 1)
            view_single_prod(t);
        else if (choose == 2)
            view_all_prod(t);
    }
    void view_single_prod(seller &t)
    {
        cout << "enter product id: ";
        int i, f = 0;
        cin >> i;
        for (auto &a : all_prod)
        {
            if (a.id == i && a.owner_name == t.user_name)
                cout << "name: " << a.name << "\nid: " << a.id << "\nprice: " << a.price << "\nstock available: " << a.quantity << "\n";
            f = 1;
            break;
        }
        if (!f)
            cout << "product id not found or the the product doesnt belong to you\n";
    }
    void view_all_prod(seller &t)
    {
        int f = 0;
        for (auto &a : all_prod)
        {
            if (a.owner_name == t.user_name)
                cout << "name: " << a.name << "\nid: " << a.id << "\nprice: " << a.price << "\nstock available: " << a.quantity << "\n";
            f = 1;
        }
        if (!f)
            cout << "no products were found\n";
    }
    void remove_product(seller &t)
    {
        cout << "enter product id: ";
        int i, f = 0, cnt = 0;
        cin >> i;
        for (auto &a : all_prod)
        {
            if (a.id == i && a.owner_name == t.user_name)
            {
                all_prod.erase(all_prod.begin() + cnt);
                cout << "product removed successfully\n";
                f = 1;
                break;
            }
            else
                cnt++;
        }
        if (!f)
            cout << "product id not found or the the product doesnt belong to you\n";
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
    void customer_log_in()
    {
        customer tem;
        cin.ignore();
        cout << "enter your user name: ";
        getline(cin, tem.user_name);
        cout << "enter your password: ";
        getline(cin, tem.pass);
        for (auto &a : customer_list)
            if (tem.user_name == a.user_name && tem.pass == a.pass)
            {
                cout << "login successfull.\n";
                customer_dash(a);
                break;
            }
        cout << "username or password doesnt match, please try again\n";
        customer_dashboard();
    }
    void customer_dash(customer &tem)
    {
        cout << "welcome " << tem.name << " \n";
        cout << "1. search poducts\n2. go to cart\n3. purchase history\n4. exit\nchoose: ";
        int choose;
        cin >> choose;
        while (choose != 4)
        {
            switch (choose)
            {
            case 1:
                search_product(tem);
                break;
            case 2:
                cart(tem);
                break;
            case 3:
                // pur_histry(tem);
                break;
            default:
                cout << "invalid input\n ";
                break;
            }
            cout << "1. view poducts\n2. add products\n3. remove products\n4.update stock\n5. update price\n6. exit\nchoose: ";
            cin >> choose;
        }
    }
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
        cout << "enter your user name: ";
        getline(cin, tem.user_name);
        int f;
        while (f)
        {
            f = 0;
            for (auto &a : customer_list)
                if (a.user_name == tem.user_name)
                {
                    cout << "user name already taken. please enter a new user name: ";
                    getline(cin, tem.user_name);
                    f = 1;
                    break;
                }
        }
        cout << "enter your password: ";
        getline(cin, tem.pass);
        cout << "thanks for signing up to our website. use your user name and password to log into our website.\n";
        customer_list.push_back(tem);
    }
    void search_product(customer &t)
    {
        string tem;
        int f = 0;
        cout << "search for your desired product by their name: ";
        cin.ignore();
        getline(cin, tem);
        for (auto &a : all_prod)
        {
            if ((a.name).find(tem) != string::npos)
                cout << "id: " << a.id << "    name: " << a.name << "    price: " << a.price << "    available: " << a.quantity << endl;
            f = 1;
        }
        if (!f)
            cout << "no products found having \"" << tem << "\" in it\n";
        cout << "enter 0 to search again\nenter -1 to exit or\nenter product id to add to cart\nenter: ";
        int choose;
        cin >> choose;
        while (choose != -1)
        {
            if (choose == 0)
                search_product(t);
            else if (choose == -1)
                customer_dash(t);
            else
            {
                int quan;
                cout << "enter quantity: ";
                cin >> quan;
                add_to_cart(choose, t, quan);
                cout << "product added to your cart.\n";
            }
            cout << "enter 0 to search again\nenter -1 to exit or\nenter product id to add to cart\nenter: ";
            cin >> choose;
        }
    }
    void add_to_cart(int ch, customer &t, int q)
    {
        int f = 0;
        for (auto &[a, b] : cart_list)
        {
            if (a == t.user_name)
                b.push_back({ch, q});
            f = 1;
            break;
        }
        if (!f)
            cart_list.push_back({t.user_name, {{ch, q}}});
    }
    void pur_hstry(customer &t)
    {
    }
    void cart(customer &t)
    {
        show_cart(t);
        cout << "1.remove from cart\n2.add more product\n3. confirm buy\n4.exit\nchoose: ";
        int chose;
        cin >> chose;
        while (chose < 1 || chose > 4)
        {
            cout << "invalid input, choose again: ";
            cin >> chose;
        }
        while (chose != 4)
        {
            switch (chose)
            {
            case 1:
                remove_from_cart(t);
                show_cart(t);
                break;
            case 2:
                search_product(t);
                show_cart(t);
                break;
            case 3:
                buy(t);
                break;
            default:
                cout << "invalid input.\n1.remove from cart\n2.add more product\n3. confirm buy\n4.exit\nchoose: ";
            }
        }
    }
    void show_cart(customer &t)
    {
        cout << "your cart list\n\n";
        for (auto &[a, b] : cart_list)
            if (a == t.user_name)
            {
                for (auto &c : b)
                {
                    for (auto &d : all_prod)
                    {
                        if (d.id == c.first)
                            cout << "id: " << d.id << "    name: " << d.name << "    price: " << d.price << "    quantity: " << c.second << endl;
                    }
                }
            }
    }
    void remove_from_cart(customer &t)
    {
        int iid;
        cout << "enter product id from your cart: ";
        cin >> iid;
        int f = 0;
        for (auto &[a, b] : cart_list)

            if (t.user_name == a)
            {
                int cnt = 0;
                for (auto &c : b)
                {
                    if (c.first == iid)
                    {
                        b.erase(b.begin() + cnt);
                        cout << "product removed from your cart.\n";
                        f = 1;
                        break;
                    }
                    else
                        cnt++;
                }
                if (f)
                    break;
                else
                {
                    cout << "product was not found in your cart.\n";
                    break;
                }
            }
    }
    void buy(customer &t)
    {
        long long cost = 0;
        cout << "you are buying \n";
        for (auto &[a, b] : cart_list)
            if (a == t.user_name)
            {
                for (auto &c : b)
                {
                    cost += c.second * c.first;
                    cout << c.second << " ";
                    for (auto &q : all_prod)
                        if (c.first == q.id)
                        {
                            cout << q.name << endl;
                            break;
                        }
                }
                break;
            }
        cout << "total bill: " << cost << " taka" << endl
             << "thanks for purchasing.\n";
        int cnt = 0;
        for (auto &[a, b] : cart_list)
            if (a == t.user_name)
            {
                cart_list.erase(cart_list.begin() + cnt);
                break;
            }
            else
                cnt++;
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
        cout << "welcome to admin dashboar:  \n\nplease choose any option given below: \n1.view sellers\n2.view customers\n3. ban someone\n4. view products\n5. view purchase history\n6.exit\nchoose: ";
        int choose;
        cin >> choose;
        while (choose != 6)
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
            case 4:
                view_products();
                break;
            case 5:
                view_history();
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
        cout << "enter seller user name: ";
        cin.ignore();
        string s;
        getline(cin, s);
        int f = 0, cnt = 0;
        for (auto &a : seller_list)
            if (s == a.user_name)
            {
                seller_list.erase(seller_list.begin() + cnt);
                cout << "seller banned sucessfully\n";
                f = 1;
                break;
            }
            else
                cnt++;
        if (!f)
            cout << "seller not found.\n";
        else
        {
            for (int i = 0; i < all_prod.size(); i++)
                if (all_prod[i].owner_name == s)
                    all_prod.erase(all_prod.begin() + i), i--;
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
    void view_products()
    {
        cout << "1. all products\n2.single product\n3.seller specified products\n4.exit\nchoose: ";
        int choose;
        cin >> choose;
        while (choose < 1 || choose > 4)
            cout << "invalid input\nchoose: ", cin >> choose;
        if (choose == 1)
            view_all_prod();
        else if (choose == 2)
            view_single_prod();
        else if (choose == 3)
            view_seller_prod();
    }
    void view_history() {}
    void view_all_prod()
    {
        int f = 0;
        for (auto &a : all_prod)
        {
            cout << "owner: " << a.owner_name << "\nname: " << a.name << "\nid: " << a.id << "\nprice: " << a.price << "\nstock available: " << a.quantity << "\n";
            f = 1;
        }
        if (!f)
            cout << "no products were found.\n";
    }
    void view_single_prod()
    {
        cout << "enter product id: ";
        int i, f = 0;
        cin >> i;
        for (auto &a : all_prod)
        {
            if (a.id == i)
                cout << "owner: " << a.owner_name << "\nname: " << a.name << "\nid: " << a.id << "\nprice: " << a.price << "\nstock available: " << a.quantity << "\n";
            f = 1;
            break;
        }
        if (!f)
            cout << "product id not found.\n";
    }
    void view_seller_prod()
    {
        cout << "enter seller user name: ";
        int f = 0;
        string tem;
        cin.ignore();
        getline(cin, tem);
        for (auto &a : all_prod)
        {
            if (a.owner_name == tem)
                cout << "\nname: " << a.name << "\nid: " << a.id << "\nprice: " << a.price << "\nstock available: " << a.quantity << "\n";
            f = 1;
        }
        if (!f)
            cout << "no products found for the seller user name.\n";
    }
};

int main()
{
    Rshop obj;
    seller sobj;
    customer cobj;
    cout << "1.enter as admin\n2.enter as a seller\n3.enter as customer\nchoose: ";
    int choose;
    cin >> choose;
    while (choose < 1 || choose > 3)
    {
        cout << "invalid input.\n"
             << "1.enter as admin\n2.enter as a seller\n3.enter as customer\nchoose: ";
        cin >> choose;
    }
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
        cout << "1.enter as admin\n2.enter as a seller\n3.enter as customer\n4. exit\nchoose: ";
        cin >> choose;
    }
}