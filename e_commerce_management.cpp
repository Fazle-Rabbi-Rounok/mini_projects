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
    string user_name;
    int id;
    string name;
    int quantity;
    string p_time;
    int cost;
    friend customer;
    friend Rshop;
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
        cout << "\n1.log in\n2.sign up\n3.return\nchoose: ";
        cin >> choose;
        while (choose != 3)
        {
            switch (choose)
            {
            case 1:
                seller_log_in();
                break;
            case 2:
                seller_reg();
                break;
            default:
                cout << "\ninvalid input.\n";
                break;
            }
            cout << "\n1.log in\n2.sign up\n3.return\nchoose: ";
            cin >> choose;
        }
    }
    void seller_reg()
    {
        seller tem;
        cin.ignore();
        cout << "\nenter your name: ";
        getline(cin, tem.name);
        cout << "enter your age: ";
        cin >> tem.age;
        cin.ignore();
        cout << "enter your contact number: ";
        getline(cin, tem.contact);
        cout << "enter your address: ";
        getline(cin, tem.address);
        cout << "enter your username: ";
        getline(cin, tem.user_name);
        int f;
        while (f)
        {
            f = 0;
            for (auto &a : seller_list)
                if (a.user_name == tem.user_name)
                {
                    cout << "\nusername already taken. please enter a new username: ";
                    getline(cin, tem.user_name);
                    f = 1;
                    break;
                }
        }
        cout << "enter your password: ";
        getline(cin, tem.log_pass);
        cout << "\nthanks for signing up to our website. use your username and password to log into our website.\n";
        seller_list.push_back(tem);
    }
    void seller_log_in()
    {
        int f = 0;
        cin.ignore();
        if (!seller_list.size())
        {
            cout << "\nno seller registered. Please sign up\n";
            return;
        }
        seller tem;
        cout << "\nenter your username: ";
        getline(cin, tem.user_name);
        cout << "enter your password: ";
        getline(cin, tem.log_pass);
        for (auto &a : seller_list)
            if (tem.user_name == a.user_name && tem.log_pass == a.log_pass)
            {
                cout << "\nlogin successfull.\n";
                seldashboard(a);
                f = 1;
                break;
            }
        if (!f)
            cout << "\nusername or password doesnt match, please try again\n";
    }
    void seldashboard(seller &tem)
    {
        cout << "           welcome to your dashboard " << tem.name << " \n\n";
        cout << "1. view poducts\n2. add products\n3. remove products\n4. update stock\n5. update price\n6. return\nchoose: ";
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
            cout << "\n1. view poducts\n2. add products\n3. remove products\n4. update stock\n5. update price\n6. return\nchoose: ";
            cin >> choose;
        }
    }
    void add_product(seller &t)
    {
        products tem;
        tem.owner_name = t.user_name;
        cout << "\nenter product id: ";
        cin >> tem.id;
        while (tem.id < 1)
            cout << "\nid must be greater than 0.\nenter id again: ", cin >> tem.id;
        int f;
        while (f)
        {
            f = 0;
            for (auto &a : all_prod)
                if (a.id == tem.id)
                {
                    cout << "\nproduct id already taken. Enter a new id: ";
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
        cout << "\nproduct added successfully.\n";
    }
    void stock_manage(seller &t)
    {
        cout << "\nenter product id: ";
        int iid, f = 0;
        cin >> iid;
        for (auto &a : all_prod)
            if (a.id == iid && t.user_name == a.owner_name)
            {
                cout << "enter re stock amount: ";
                cin >> a.quantity;
                cout << "\nstock updated successfull.\n";
                f = 1;
                break;
            }
        if (!f)
            cout << "\nproduct not found\n";
    }
    void price_update(seller &t)
    {
        cout << "\nenter product id: ";
        int pric, f = 0;
        cin >> pric;
        for (auto &a : all_prod)
            if (a.id == pric && t.user_name == a.owner_name)
            {
                cout << "enter new price: ";
                cin >> a.price;
                cout << "\nprice updated successfully.\n";
                f = 1;
                break;
            }
        if (!f)
            cout << "\nproduct not found\n";
    }
    void view_products(seller &t)
    {
        int choose;
        cout << "\n1. single product\n2. all products\n3.return\nchoose: ";
        cin >> choose;
        while (choose != 3)
        {
            switch (choose)
            {
            case 1:
                view_single_prod(t);
                break;
            case 2:
                view_all_prod(t);
                break;
            default:
                cout << "\ninvalid input.\n";
                break;
            }
            cout << "\n1. single product\n2. all products\n3.return\nchoose: ";
            cin >> choose;
        }
    }
    void view_single_prod(seller &t)
    {
        cout << "\nenter product id: ";
        int i, f = 0;
        cin >> i;
        cout << "\n";
        for (auto &a : all_prod)
        {
            if (a.id == i && a.owner_name == t.user_name)
                cout << "name: " << a.name << "\nid: " << a.id << "\nprice: " << a.price << "\nstock available: " << a.quantity << "\n";
            f = 1;
            break;
        }
        if (!f)
            cout << "product not found.\n";
    }
    void view_all_prod(seller &t)
    {
        int f = 0;
        cout << "\n";
        for (auto &a : all_prod)
        {
            if (a.owner_name == t.user_name)
                cout << "name: " << a.name << "\nid: " << a.id << "\nprice: " << a.price << "\nstock available: " << a.quantity << "\n"
                     << "- - -\n";
            f = 1;
        }
        if (!f)
            cout << "no products were found\n";
    }
    void remove_product(seller &t)
    {
        cout << "\nenter product id: ";
        int i, f = 0, cnt = 0;
        cin >> i;
        for (auto &a : all_prod)
        {
            if (a.id == i && a.owner_name == t.user_name)
            {
                all_prod.erase(all_prod.begin() + cnt);
                cout << "\nproduct removed successfully\n";
                f = 1;
                break;
            }
            else
                cnt++;
        }
        if (!f)
            cout << "\nproduct not found.\n";
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
        cout << "\n1.log in\n2.sign up\n3.return\nchoose: ";
        cin >> choose;
        while (choose != 3)
        {
            switch (choose)
            {
            case 1:
                customer_log_in();
                break;
            case 2:
                customer_reg();
                break;
            default:
                cout << "\ninvalid input.\n";
                break;
            }
            cout << "\n1.log in\n2.sign up\n3.return\nchoose: ";
            cin >> choose;
        }
    }
    void customer_log_in()
    {
        customer tem;
        cin.ignore();
        if (!customer_list.size())
        {
            cout << "\nno customer found. Please sign up.\n";
            return;
        }
        cout << "\nenter your username: ";
        getline(cin, tem.user_name);
        cout << "enter your password: ";
        getline(cin, tem.pass);
        for (auto &a : customer_list)
            if (tem.user_name == a.user_name && tem.pass == a.pass)
            {
                cout << "\nlogin successfull.\n";
                customer_dash(a);
                break;
            }
            else
            {
                cout << "\nusername or password doesnt match, please try again\n";
                customer_dashboard();
            }
    }
    void customer_dash(customer &tem)
    {
        cout << "           welcome to your dashboard " << tem.name << " \n\n";
        cout << "1. search poducts\n2. go to cart\n3. purchase history\n4. return\nchoose: ";
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
                pur_hstry(tem);
                break;
            default:
                cout << "invalid input.\n ";
                break;
            }
            cout << "\n1. search poducts\n2. go to cart\n3. purchase history\n4. return\nchoose: ";
            cin >> choose;
        }
    }
    void customer_reg()
    {
        customer tem;
        cin.ignore();
        cout << "\nenter your name: ";
        getline(cin, tem.name);
        cout << "enter your age: ";
        cin >> tem.age;
        cin.ignore();
        cout << "enter your contact number: ";
        getline(cin, tem.contact);
        cout << "enter your address: ";
        getline(cin, tem.address);
        cout << "enter your username: ";
        getline(cin, tem.user_name);
        int f;
        while (f)
        {
            f = 0;
            for (auto &a : customer_list)
                if (a.user_name == tem.user_name)
                {
                    cout << "\nusername already taken. please enter a new username: ";
                    getline(cin, tem.user_name);
                    f = 1;
                    break;
                }
        }
        cout << "enter your password: ";
        getline(cin, tem.pass);
        cout << "\nthanks for signing up to our website. use your username and password to log into our website.\n";
        customer_list.push_back(tem);
    }
    void search_product(customer &t)
    {
        string tem;
        int f = 0;
        cout << "\nsearch for your desired product by their name or by some part of their name: ";
        cin.ignore();
        getline(cin, tem);
        cout << "\n";
        for (auto &a : all_prod)
        {
            if ((a.name).find(tem) != string::npos)
                cout << "id: " << a.id << "    name: " << a.name << "    price: " << a.price << "    available: " << a.quantity << endl;
            f = 1;
        }
        if (!f)
            cout << "\nno products found having \"" << tem << "\" in it\n";
        cout << "\nenter 0 to search again\nenter -1 to return or\nenter product id to add to cart\nenter: ";
        int choose;
        cin >> choose;
        while (1)
        {
            switch (choose)
            {
            case 1:
                search_product(t);
                break;
            case -1:
                break;
            default:
                int quan;
                cout << "\nenter quantity: ";
                cin >> quan;
                for (auto &a : all_prod)
                {
                    if (a.id == choose)
                        if (quan > a.quantity)
                            while (quan > a.quantity)
                                cout << "\nnot enough products available, please lower the quantity.\nenter quantity: ", cin >> quan;
                    break;
                }
                add_to_cart(choose, t, quan);
                cout << "\nproduct added to your cart.\n";
                break;
            }
            if (choose == -1)
                break;
            cout << "\nenter 0 to search again\nenter -1 to return or\nenter product id to add to cart\nenter: ";
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
        int f = 0;
        cout << "\nyour purchase history\n\n";
        for (auto &a : purchase_hstry)
        {
            if (t.user_name == a.user_name)
                cout << "name: " << a.name << "    id: " << a.id << "    quantity: " << a.quantity << "    cost: " << a.cost << "    time: " << a.p_time << endl;
            f = 1;
        }
        if (!f)
            cout << "no purchase history found.\n";
    }
    void cart(customer &t)
    {
        show_cart(t);
        cout << "\n1.remove from cart\n2.add more product\n3. confirm buy\n4.return\nchoose: ";
        int chose;
        cin >> chose;
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
                cout << "\ninvalid input.\n";
                break;
            }
            cout << "\n1.remove from cart\n2.add more product\n3. confirm buy\n4.return\nchoose: ";
            cin >> chose;
        }
    }
    void show_cart(customer &t)
    {
        int f = 0;
        cout << "\nyour cart list\n\n";
        for (auto &[a, b] : cart_list)
            if (a == t.user_name)
            {
                for (auto &c : b)
                {
                    for (auto &d : all_prod)
                    {
                        if (d.id == c.first)
                            cout << "id: " << d.id << "    name: " << d.name << "    price: " << d.price << "    quantity: " << c.second << endl;
                        f = 1;
                    }
                }
            }
        if (!f)
            cout << "\nno products were found in your cart.\n";
    }
    void remove_from_cart(customer &t)
    {
        int iid;
        cout << "\nenter product id from your cart: ";
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
                        cout << "\nproduct removed from your cart.\n";
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
                    cout << "\nproduct was not found in your cart.\n";
                    break;
                }
            }
    }
    void buy(customer &t)
    {
        long long cost = 0;
        cout << "\n         you are buying \n\n";
        for (auto &[a, b] : cart_list)
            if (a == t.user_name)
            {
                purchase temp;
                for (auto &c : b)
                {
                    cost += c.second * c.first;
                    cout << c.second << " ";
                    for (auto &st : all_prod)
                        if (c.first == st.id)
                        {
                            time_t ti;
                            time(&ti);
                            cout << st.name << endl;
                            temp.user_name = t.user_name;
                            temp.id = c.first;
                            temp.cost = c.second * c.first;
                            temp.name = st.name;
                            temp.quantity = c.second;
                            temp.p_time = ctime(&ti);
                            st.quantity -= c.second;
                            purchase_hstry.push_back(temp);
                            break;
                        }
                }
                break;
            }
        cout << "\ntotal bill: " << cost << " taka." << endl
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
    string log_pass = "admin";

public:
    void view_seller()
    {
        if (!seller_list.size())
        {
            cout << "\nno seller found yet.\n";
            return;
        }
        cout << "\n";
        for (auto &a : seller_list)
        {
            cout << "name: " << a.name << "\nage: " << a.age << "\ncontact number: " << a.contact << "\naddress: " << a.address << endl;
        }
    }
    void view_customers()
    {
        if (!customer_list.size())
        {
            cout << "\nno customer found yet.\n";
            return;
        }
        cout << "\n";
        for (auto &a : customer_list)
            cout << "name: " << a.name << "\nage: " << a.age << "\ncontact info: " << a.contact << "\naddress: " << a.address << endl;
    }
    void admin_dashboard()
    {
        string user, logpass;
        cin.ignore();
        cout << "\nplease log in:  (admin,admin)\nenter username: ";
        getline(cin, user);
        cout << "enter password: ";
        getline(cin, logpass);
        if (user_name == user && log_pass == logpass)
            admdashboard();
        else
            cout << "\nwrong username or password\n";
    }
    void admdashboard()
    {
        cout << "\n             welcome to admin dashboard  \n\nplease choose any option given below: \n1.view sellers\n2.view customers\n3. ban someone\n4. view products\n5. view purchase history\n6.return\nchoose: ";
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
                cout << "\ninvalid input\n";
                break;
            }
            cout << "\n1.view sellers\n2.view customers\n3. ban someone\n4. view products\n5. view purchase history\n6.return\nchoose: ";
            cin >> choose;
        }
    }
    void ban_seller()
    {
        cout << "\nenter seller username: ";
        cin.ignore();
        string s;
        getline(cin, s);
        int f = 0, cnt = 0;
        for (auto &a : seller_list)
            if (s == a.user_name)
            {
                seller_list.erase(seller_list.begin() + cnt);
                cout << "\nseller banned sucessfully\n";
                f = 1;
                break;
            }
            else
                cnt++;
        if (!f)
            cout << "\nseller not found.\n";
        else
        {
            for (int i = 0; i < all_prod.size(); i++)
                if (all_prod[i].owner_name == s)
                    all_prod.erase(all_prod.begin() + i), i--;
        }
    }
    void ban_()
    {
        cout << "\n1.ban a seller\n2.ban a customer\n3.return\nchoose: ";
        int choose;
        cin >> choose;
        while (choose != 3)
        {
            switch (choose)
            {
            case 1:
                ban_seller();
                break;
            case 2:
                ban_customer();
                break;
            default:
                cout << "\ninvalid input.\n";
                break;
            }
            cout << "\n1.ban a seller\n2.ban a customer\n3.return\nchoose: ";
            cin >> choose;
        }
    }
    void ban_customer()
    {
        cout << "\nenter customer username: ";
        cin.ignore();
        string s;
        getline(cin, s);
        int f = 0, cnt = 0;
        for (auto &a : customer_list)
            if (s == a.user_name)
            {
                customer_list.erase(customer_list.begin() + cnt);
                cout << "\ncustomer banned sucessfully\n";
                f = 1;
                break;
            }
            else
                cnt++;
        if (!f)
            cout << "\ncustomer not found.\n";
    }
    void view_products()
    {
        cout << "\n1. all products\n2.single product\n3.seller specified products\n4.return\nchoose: ";
        int choose;
        cin >> choose;
        while (choose != 4)
        {
            switch (choose)
            {
            case 2:
                view_single_prod();
                break;
            case 1:
                view_all_prod();
                break;
            case 3:
                view_seller_prod();
                break;
            default:
                cout << "\ninvalid input.\n";
                break;
            }
            cout << "\n1. all products\n2.single product\n3.seller specified products\n4.return\nchoose: ";
            cin >> choose;
        }
    }
    void view_history()
    {
        cout << "\n1.all history\n2. customer specified.\n3.return\nchoose: ";
        int choose;
        cin >> choose;
        while (choose != 3)
        {
            switch (choose)
            {
            case 2:
                single_history();
                break;
            case 1:
                show_all_history();
                break;
            default:
                cout << "\ninvalid input.\n";
                break;
            }
            cout << "\n1.all history\n2. customer specified.\n3.return\nchoose: ";
            cin >> choose;
        }
    }
    void show_all_history()
    {
        if (!purchase_hstry.size())
        {
            cout << "\nno purchase history found yet.\n";
            return;
        }
        cout << "\npurchase history\n\n";
        for (auto &a : purchase_hstry)
        {
            cout << "name: " << a.name << "    id: " << a.id << "    quantity: " << a.quantity << "    cost: " << a.cost << "    time: " << a.p_time << endl;
        }
    }
    void single_history()
    {
        if (!purchase_hstry.size())
        {
            cout << "\nno purchase history found yet.\n";
            return;
        }
        cout << "\nenter customer username: ";
        string s;
        cin.ignore();
        getline(cin, s);
        int f = 0;
        cout << "\ncustomer's purchase history\n\n";
        for (auto &a : purchase_hstry)
        {
            if (s == a.user_name)
                cout << "name: " << a.name << "    id: " << a.id << "    quantity: " << a.quantity << "    cost: " << a.cost << "    time: " << a.p_time << endl;
            f = 1;
        }
        if (!f)
            cout << "\nno purchase history found for the username.\n";
    }
    void view_all_prod()
    {
        if (!all_prod.size())
        {
            cout << "\nno products found yet.\n";
            return;
        }
        cout << "\n";
        for (auto &a : all_prod)
        {
            cout << "owner: " << a.owner_name << "\nname: " << a.name << "\nid: " << a.id << "\nprice: " << a.price << "\nstock available: " << a.quantity << "\n";
        }
    }
    void view_single_prod()
    {
        if (!all_prod.size())
        {
            cout << "\nno products found yet.\n";
            return;
        }
        cout << "\nenter product id: ";
        int i, f = 0;
        cin >> i;
        cout << "\n";
        for (auto &a : all_prod)
        {
            if (a.id == i)
                cout << "owner: " << a.owner_name << "\nname: " << a.name << "\nid: " << a.id << "\nprice: " << a.price << "\nstock available: " << a.quantity << "\n";
            f = 1;
            break;
        }
        if (!f)
            cout << "\nproduct not found.\n";
    }
    void view_seller_prod()
    {
        if (!all_prod.size())
        {
            cout << "\nno products found yet.\n";
            return;
        }
        cout << "\nenter seller username: ";
        int f = 0;
        string tem;
        cin.ignore();
        getline(cin, tem);
        cout << "\n";
        for (auto &a : all_prod)
        {
            if (a.owner_name == tem)
                cout << "name: " << a.name << "\nid: " << a.id << "\nprice: " << a.price << "\nstock available: " << a.quantity << "\n";
            f = 1;
        }
        if (!f)
            cout << "\nno products found for the seller username.\n";
    }
};

int main()
{
    Rshop obj;
    seller sobj;
    customer cobj;
    cout << "           Welcome to my mini E-commerce site.\n\n1.enter as admin\n2.enter as a seller\n3.enter as customer\nchoose: ";
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
            cout << "\ninvalid input\n ";
            break;
        }
        cout << "\n1.enter as admin\n2.enter as a seller\n3.enter as customer\n4. return\nchoose: ";
        cin >> choose;
    }
}