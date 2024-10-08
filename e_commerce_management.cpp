#include <bits/stdc++.h>
using namespace std;
class Rshop;
vector<class purchase> purchase_hstry;
vector<class customer> customer_list;
vector<class products> all_prod;
vector<class seller> seller_list;
map<string, vector<pair<int, int>>> cart_list;
long long validate()
{
    string s;
here:
{
    getline(cin, s);
    if (s.size() == 1 && s[0] == '-')
    {
        cout << "invalid integer input. please input again: ";
        goto here;
    }
    for (int i = 1; i < s.size(); i++)
        if (!isdigit(s[i]))
        {
            cout << "invalid integer input. please input again: ";
            goto here;
        }
    if (s.size() == 0)
        goto here;
    return stoll(s);
}
}
void save_cart()
{
    ofstream file6("cart.txt");
    if (file6.is_open())
    {
        for (auto &[a, b] : cart_list)
            for (auto &[c, d] : b)
                file6 << c << " " << d << " " << a << ",\n";
    }
    file6.close();
}
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
    friend class file_handle;

public:
    void save_purchase()
    {
        ofstream file("purchase.txt");
        if (file.is_open())
        {
            for (auto &a : purchase_hstry)
                file << a.id << " " << a.quantity << " " << a.cost << " " << a.name << ", " << a.user_name << ", " << a.p_time << "*\n";
        }
        file.close();
    }
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
    friend class file_handle;
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
    friend class file_handle;

public:
    void seller_dashboard()
    {
        int choose;
        cout << "\n         seller dashboard\n1.log in\n2.sign up\n3.return\nchoose: ";
        choose = validate();
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
            cout << "\n         seller dashboard\n1.log in\n2.sign up\n3.return\nchoose: ";
            choose = validate();
        }
    }
    void seller_reg()
    {
        seller tem;
        cout << "\nenter your name: ";
        getline(cin, tem.name);
        cout << "enter your age: ";
        tem.age = validate();
        while (tem.age < 1 || tem.age > 150)
        {
            cout << "age must be in the range 1-150, please input again: ", tem.age = validate();
        }
        cout << "enter your contact number: ";
        tem.contact = to_string(validate());
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
        save_seller();
    }
    void seller_log_in()
    {
        int f = 0;
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
        choose = validate();
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
            choose = validate();
        }
    }
    void add_product(seller &t)
    {
        products tem;
        tem.owner_name = t.user_name;
        cout << "\nenter product id: ";
        tem.id = validate();
        while (tem.id < 1)
            cout << "\nid must be greater than 0.\nenter id again: ", tem.id = validate();
        int f;
        while (f)
        {
            f = 0;
            for (auto &a : all_prod)
                if (a.id == tem.id)
                {
                    cout << "\nproduct id already taken. Enter a new id: ";
                    tem.id = validate();
                    while (tem.id < 1)
                        cout << "\nid must be greater than 0.\nenter id again: ", tem.id = validate();
                    f = 1;
                    break;
                }
        }
        cout << "enter product name: ";
        getline(cin, tem.name);
        cout << "enter product price: ";
        tem.price = validate();
        while (tem.price < 1)
            cout << "\nprice must be greater than 0.\nenter price again: ", tem.price = validate();
        cout << "enter product quantity: ";
        tem.quantity = validate();
        while (tem.quantity < 1)
            cout << "\nquantity must be greater than 0.\nenter quantity again: ", tem.quantity = validate();
        all_prod.push_back(tem);
        cout << "\nproduct added successfully.\n";
        save_product();
    }
    void stock_manage(seller &t)
    {
        cout << "\nenter product id: ";
        int iid, f = 0;
        iid = validate();
        while (iid < 1)
            cout << "\nid must be greater than 0.\nenter id again: ", iid = validate();
        for (auto &a : all_prod)
            if (a.id == iid && t.user_name == a.owner_name)
            {
                cout << "enter re stock amount: ";
                a.quantity = validate();
                while (a.quantity < 1)
                    cout << "\nquantity must be greater than 0.\nenter quantity again: ", a.quantity = validate();
                cout << "\nstock updated successfull.\n";
                save_product();
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
        pric = validate();
        while (pric < 1)
            cout << "\nid must be greater than 0.\nenter id again: ", pric = validate();
        for (auto &a : all_prod)
            if (a.id == pric && t.user_name == a.owner_name)
            {
                cout << "enter new price: ";
                a.price = validate();
                while (a.price < 1)
                    cout << "\nprice must be greater than 0.\nenter price again: ", a.price = validate();
                cout << "\nprice updated successfully.\n";
                save_product();
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
        choose = validate();
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
            choose = validate();
        }
    }
    void view_single_prod(seller &t)
    {
        cout << "\nenter product id: ";
        int i, f = 0;
        i = validate();
        while (i < 1)
            cout << "\nid must be greater than 0.\nenter id again: ", i = validate();
        cout << "\n";
        for (auto &a : all_prod)
        {
            if (a.id == i && a.owner_name == t.user_name)
            {
                cout << "name: " << a.name << "\nid: " << a.id << "\nprice: " << a.price << "\nstock available: " << a.quantity << "\n";
                f = 1;
                break;
            }
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
            {
                cout << "name: " << a.name << "\nid: " << a.id << "\nprice: " << a.price << "\nstock available: " << a.quantity << "\n"
                     << "- - -\n";
                f = 1;
            }
        }
        if (!f)
            cout << "no products were found\n";
    }
    void remove_product(seller &t)
    {
        cout << "\nenter product id: ";
        int i, f = 0, cnt = 0;
        i = validate();
        while (i < 1)
            cout << "\nid must be greater than 0.\nenter id again: ", i = validate();
        for (auto &a : all_prod)
        {
            if (a.id == i && a.owner_name == t.user_name)
            {
                all_prod.erase(all_prod.begin() + cnt);
                cout << "\nproduct removed successfully\n";
                save_product();
                f = 1;
                break;
            }
            else
                cnt++;
        }
        if (!f)
            cout << "\nproduct not found.\n";
    }
    void save_seller()
    {
        ofstream file("seller.txt");
        if (file.is_open())
        {
            for (auto &a : seller_list)
                file << a.user_name << ", " << a.age << " " << a.name << ", " << a.contact << ", " << a.address << "* " << a.log_pass << ",\n";
        }
        file.close();
    }
    void save_product()
    {
        ofstream file("product.txt");
        if (file.is_open())
        {
            for (auto &a : all_prod)
                file << a.id << " " << a.price << " " << a.quantity << " " << a.name << ", " << a.owner_name << ",\n";
        }
        file.close();
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
    friend class file_handle;

public:
    void save_purchase()
    {
        ofstream file("purchase.txt");
        if (file.is_open())
        {
            for (auto &a : purchase_hstry)
                file << a.id << " " << a.quantity << " " << a.cost << " " << a.name << ", " << a.user_name << ", " << a.p_time << "*\n";
        }
        file.close();
    }

    void customer_dashboard()
    {
        int choose;
        cout << "\n         customer dashboard\n1.log in\n2.sign up\n3.return\nchoose: ";
        choose = validate();
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
            cout << "\n         customer dashboard\n1.log in\n2.sign up\n3.return\nchoose: ";
            choose = validate();
        }
    }
    void customer_log_in()
    {
        int f = 0;
        customer tem;
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
                f = 1;
                customer_dash(a);
                break;
            }
        if (!f)
            cout << "\nusername or password doesnt match, please try again\n";
    }
    void customer_dash(customer &tem)
    {
        cout << "           welcome to your dashboard " << tem.name << " \n\n";
        cout << "1. search poducts\n2. go to cart\n3. purchase history\n4. return\nchoose: ";
        int choose;
        choose = validate();
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
            choose = validate();
        }
    }
    void customer_reg()
    {
        customer tem;
        cout << "\nenter your name: ";
        getline(cin, tem.name);
        cout << "enter your age: ";
        tem.age = validate();
        while (tem.age < 1 || tem.age > 150)
            cout << "\nage must be in the range 1-150.\nenter age again: ", tem.age = validate();
        cout << "enter your contact number: ";
        tem.contact = to_string(validate());
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
        save_customer();
    }
    void search_product(customer &t)
    {
    here:
    {
        string tem;
        int f = 0;
        cout << "\nsearch by name or part of a name: ";
        getline(cin, tem);
        cout << "\n";
        for (auto &a : all_prod)
        {
            if ((a.name).find(tem) != string::npos)
            {
                cout << "id: " << a.id << "    name: " << a.name << "    price: " << a.price << "    available: " << a.quantity << endl;
                f = 1;
            }
        }
        if (!f)
            cout << "\nno products found having \"" << tem << "\" in it\n";
    }
        cout << "\nenter 0 to search again\nenter -1 to return or\nenter product id to add to cart\nenter: ";
        int choose;
        choose = validate();
    th:
    {
    }
        while (1)
        {
            switch (choose)
            {
            case 0:
                goto here;
                break;
            case -1:
                break;
            default:
            h:
            {
                if (choose == 0)
                    goto th;
                int fl = 0;
                for (auto &a : all_prod)
                    if (a.id == choose)
                    {
                        fl = 1;
                        break;
                    }
                if (!fl)
                {
                    cout << "\nproduct id invalid.\nenter 0 to return or enter id again: ";
                    choose = validate();
                    goto h;
                }
            }
                int quan;
                cout << "\nenter quantity: ";
                quan = validate();
                for (auto &a : all_prod)
                {
                    if (a.id == choose)
                    {
                        if (quan > a.quantity)
                            while (quan > a.quantity)
                                cout << "\nnot enough products available, please lower the quantity.\nenter quantity: ", quan = validate();
                        break;
                    }
                }
                add_to_cart(choose, t, quan);
                save_cart();
                cout << "\nproduct added to your cart.\n";
                break;
            }
            if (choose == -1)
                break;
            cout << "\nenter 0 to search again\nenter -1 to return or\nenter product id to add to cart\nenter: ";
            choose = validate();
        }
    }
    void add_to_cart(int ch, customer &t, int q)
    {
        int f = 0;
        for (auto &[a, b] : cart_list)
        {
            if (a == t.user_name)
            {
                b.push_back({ch, q});
                f = 1;
                break;
            }
        }
        if (!f)
            cart_list.insert({t.user_name, {{ch, q}}});
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
        chose = validate();
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
            chose = validate();
        }
    }
    void show_cart(customer &t)
    {
        int f = 0;
        cout << "\nyour cart list\n\n";
        for (auto &[a, b] : cart_list)
        {
            if (a == t.user_name)
            {
                for (auto &c : b)
                {
                    for (auto &d : all_prod)
                    {
                        if (d.id == c.first)
                        {
                            cout << "id: " << d.id << "    name: " << d.name << "    price: " << d.price << "    quantity: " << c.second << endl;
                            f = 1;
                        }
                    }
                }
                break;
            }
        }
        if (!f)
            cout << "no products were found in your cart.\n";
    }
    void remove_from_cart(customer &t)
    {
        int iid;
        cout << "\nenter product id from your cart: ";
        iid = validate();
        while (iid < 1)
            cout << "\nid must be greater than 0.\nenter id again: ", iid = validate();
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
                        save_cart();
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
                            if (cost)
                                purchase_hstry.push_back(temp), save_purchase();
                            break;
                        }
                }
                break;
            }
        if (cost)
        {
            cout << "\ntotal bill: " << cost << " taka." << endl
                 << "thanks for purchasing.\n";
            cart_list.erase(t.user_name);
            save_product(), save_cart();
        }
        else
            cout << "\nnothing to buy in your cart.\n";
    }
    void save_product()
    {
        ofstream file("product.txt");
        if (file.is_open())
        {
            for (auto &a : all_prod)
                file << a.id << " " << a.price << " " << a.quantity << " " << a.name << ", " << a.owner_name << ",\n";
        }
        file.close();
    }
    void save_customer()
    {
        ofstream file("customer.txt");
        if (file.is_open())
        {
            for (auto &a : customer_list)
                file << a.user_name << ", " << a.age << " " << a.name << ", " << a.contact << ", " << a.address << "* " << a.pass << ",\n";
        }
        file.close();
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
        cout << "\n             welcome to admin dashboard  \n\nplease choose any option given below: \n1. view sellers\n2. view customers\n3. ban someone\n4. view products\n5. view purchase history\n6. return\nchoose: ";
        int choose;
        choose = validate();
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
            cout << "\n1. view sellers\n2. view customers\n3. ban someone\n4. view products\n5. view purchase history\n6. return\nchoose: ";
            choose = validate();
        }
    }
    void ban_seller()
    {
        cout << "\nenter seller username: ";
        string s;
        getline(cin, s);
        int f = 0, cnt = 0;
        for (auto &a : seller_list)
            if (s == a.user_name)
            {
                seller_list.erase(seller_list.begin() + cnt);
                cout << "\nseller banned sucessfully\n";
                save_seller();
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
            save_product();
        }
    }
    void save_seller()
    {
        ofstream file("seller.txt");
        if (file.is_open())
        {
            for (auto &a : seller_list)
                file << a.user_name << ", " << a.age << " " << a.name << ", " << a.contact << ", " << a.address << "* " << a.log_pass << ",\n";
        }
        file.close();
    }
    void save_product()
    {
        ofstream file("product.txt");
        if (file.is_open())
        {
            for (auto &a : all_prod)
                file << a.id << " " << a.price << " " << a.quantity << " " << a.name << ", " << a.owner_name << ",\n";
        }
        file.close();
    }

    void ban_()
    {
        cout << "\n1.ban a seller\n2.ban a customer\n3.return\nchoose: ";
        int choose;
        choose = validate();
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
            choose = validate();
        }
    }
    void ban_customer()
    {
        cout << "\nenter customer username: ";
        string s;
        getline(cin, s);
        int f = 0, cnt = 0;
        for (auto &a : customer_list)
            if (s == a.user_name)
            {
                customer_list.erase(customer_list.begin() + cnt);
                cout << "\ncustomer banned sucessfully\n";
                save_customer();
                f = 1;
                break;
            }
            else
                cnt++;
        if (!f)
            cout << "\ncustomer not found.\n";
    }
    void save_customer()
    {
        ofstream file("customer.txt");
        if (file.is_open())
        {
            for (auto &a : customer_list)
                file << a.user_name << ", " << a.age << " " << a.name << ", " << a.contact << ", " << a.address << "* " << a.pass << ",\n";
        }
        file.close();
    }

    void view_products()
    {
        cout << "\n1. all products\n2.single product\n3.seller specified products\n4.return\nchoose: ";
        int choose;
        choose = validate();
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
            choose = validate();
        }
    }
    void view_history()
    {
        cout << "\n1. all history\n2. customer specified.\n3. return\nchoose: ";
        int choose;
        choose = validate();
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
            cout << "\n1. all history\n2. customer specified.\n3. return\nchoose: ";
            choose = validate();
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
        getline(cin, s);
        int f = 0;
        cout << "\ncustomer's purchase history\n\n";
        for (auto &a : purchase_hstry)
        {
            if (s == a.user_name)
            {
                cout << "name: " << a.name << "    id: " << a.id << "    quantity: " << a.quantity << "    cost: " << a.cost << "    time: " << a.p_time << endl;
                f = 1;
            }
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
        i = validate();
        while (i < 1)
            cout << "\nid must be greater than 0.\nenter id again: ", i = validate();
        cout << "\n";
        for (auto &a : all_prod)
        {
            if (a.id == i)
            {
                cout << "owner: " << a.owner_name << "\nname: " << a.name << "\nid: " << a.id << "\nprice: " << a.price << "\nstock available: " << a.quantity << "\n";
                f = 1;
                break;
            }
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
        getline(cin, tem);
        cout << "\n";
        for (auto &a : all_prod)
        {
            if (a.owner_name == tem)
            {
                cout << "name: " << a.name << "\nid: " << a.id << "\nprice: " << a.price << "\nstock available: " << a.quantity << "\n";
                f = 1;
            }
        }
        if (!f)
            cout << "\nno products found for the seller username.\n";
    }
};

class file_handle
{
public:
    void load_files()
    {
        ifstream file("customer.txt");
        if (file.is_open())
        {
            customer t;
            string s;
            while (getline(file, s))
            {
                stringstream s1(s);
                getline(s1, t.user_name, ',');
                s1.ignore();
                s1 >> t.age;
                s1.ignore();
                getline(s1, t.name, ',');
                s1.ignore();
                getline(s1, t.contact, ',');
                s1.ignore();
                getline(s1, t.address, '*');
                s1.ignore();
                getline(s1, t.pass, ',');
                customer_list.push_back(t);
            }
        }
        file.close();
        ifstream file2("seller.txt");
        if (file2.is_open())
        {
            seller t;
            string s;
            while (getline(file2, s))
            {
                stringstream s1(s);
                getline(s1, t.user_name, ',');
                s1.ignore();
                s1 >> t.age;
                s1.ignore();
                getline(s1, t.name, ',');
                s1.ignore();
                getline(s1, t.contact, ',');
                s1.ignore();
                getline(s1, t.address, '*');
                s1.ignore();
                getline(s1, t.log_pass, ',');
                seller_list.push_back(t);
            }
        }
        file2.close();
        ifstream file3("purchase.txt");
        if (file3.is_open())
        {
            purchase t;
            string s;
            while (getline(file3, s))
            {
                stringstream s1(s);
                s1 >> t.id >> t.quantity >> t.cost;
                s1.ignore();
                getline(s1, t.name, ',');
                s1.ignore();
                getline(s1, t.user_name, ',');
                s1.ignore();
                getline(s1, t.p_time, '*');
                purchase_hstry.push_back(t);
            }
        }
        file3.close();
        ifstream file4("product.txt");
        if (file4.is_open())
        {
            products t;
            string s;
            while (getline(file4, s))
            {
                stringstream s1(s);
                s1 >> t.id >> t.price >> t.quantity;
                s1.ignore();
                getline(s1, t.name, ',');
                s1.ignore();
                getline(s1, t.owner_name, ',');
                all_prod.push_back(t);
            }
        }
        file4.close();
        ifstream file5("cart.txt");
        if (file5.is_open())
        {
            int a, b;
            string n;
            string s;
            while (getline(file5, s))
            {
                stringstream s1(s);
                s1 >> a >> b;
                s1.ignore();
                getline(s1, n, ',');
                int f = 0;
                for (auto &[p, q] : cart_list)
                {
                    if (p == n)
                    {
                        q.push_back({a, b});
                        f = 1;
                        break;
                    }
                }
                if (!f)
                    cart_list.insert({n, {{a, b}}});
            }
        }
        file5.close();
    }
};

int main()
{
    Rshop obj;
    seller sobj;
    customer cobj;
    file_handle fobj;

    fobj.load_files();
    cout << "           Welcome to my mini E-commerce site.\n\n1.enter as admin\n2.enter as a seller\n3.enter as customer\nchoose: ";
    int choose;
    choose = validate();
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
        choose = validate();
    }
}