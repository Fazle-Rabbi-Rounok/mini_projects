#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <ctime>
using namespace std;

double sum_()
{
    cout << "\nTo get the sum of n numbers.\nenter in the following formate: a+b+c+...n\n\n";
    string a;
    getline(cin, a);
    double sum = 0;
    while (1)
    {
        if (a.find("+") == string::npos)
        {
            sum += stod(a);
            break;
        }
        else
        {
            long found = a.find("+");
            sum += stod(a.substr(0, found));
            a.erase(0, found + 1);
        }
    }
    cout << "Total sum: " << sum << endl;
}
double subs_()
{
    cout << "\nTo get the substraction of n numbers.\nenter in the following formate: a-b-c- ...n\n\n";
    string a;
    getline(cin, a);
    double sum = 0;

    while (1)
    {
        if (a.find("--") == string ::npos)
            break;
        else
        {
            if ((a.find("-", a.find("--") + 2)) == string::npos)
            {
                sum += stod(a.substr((a.find("--")) + 2));
                a.erase(a.find("--"), (a.substr(a.find("--"))).length());
                break;
            }
            sum += stod(a.substr((a.find("--")) + 2, a.find("-", a.find("--") + 2) - a.find("--") - 2));
            a.erase(a.find("--"), a.find("-", a.find("--") + 2) - a.find("--"));
        }
    }

    if (a.find("-") == string ::npos)
    {
        cout << "substraction value: " << sum + stod(a) << endl;
        return 0;
    }
    else if ((a.find("-") == a.rfind("-")) && a.front() == '-')
    {
        a.erase(0, 1);
        cout << "substraction value: " << sum - stod(a) << endl;
        return 0;
    }

    if (a.front() != '-')
    {
        sum += stod(a.substr(0, a.find("-")));
        a.erase(0, a.find("-") + 1);
    }
    else if (a.front() == '-')
        a.erase(0, 1);

    while (1)
    {

        if (a.find("-") == string ::npos)
        {
            sum -= stod(a);
            cout << "substraction value: " << sum << endl;
            return 0;
        }
        else
        {
            long found = a.find("-");
            sum -= stod(a.substr(0, found));
            a.erase(0, found + 1);
        }
    }
}
double div_()
{
    string a;
    cout << "\nTo divide a by b.\nenter in the following formate: a/b\n\n";
    getline(cin, a);
    long long div = a.find("/");
    cout << "Quotient: " << stod(a.substr(0, div)) / stod(a.substr(div + 1)) << endl;
}
double multi_()
{
    cout << "\nTo get the multiplication of n numbers.\nenter in the following formate: a*b*c*...n\n\n";
    string a;
    getline(cin, a);
    double sum = 1;
    while (1)
    {
        long found = a.find("*");
        sum *= stod(a.substr(0, found));
        if (found == (a.rfind("*")))
        {
            a.erase(0, found + 1);
            sum *= stod(a);
            break;
        }
        a.erase(0, found + 1);
    }
    cout << "Total multiplied value: " << sum << endl;
}
double rem_()
{
    string a;
    cout << "\nTo get the reminder of a by b.\nenter in the following formate: a%b\n\n";
    getline(cin, a);
    long long div = a.find("%");
    cout << "Reminder :" << fmod(stod(a.substr(0, div)), stod(a.substr(div + 1))) << endl;
}
double power()
{
    string a;
    cout << "\nTo get a to the power b.\nenter in the following formate: a^b\n\n";
    getline(cin, a);
    long long div = a.find("^");
    cout << stod(a.substr(0, div)) << " to the power " << stod(a.substr(div + 1)) << " is: " << pow(stod(a.substr(0, div)), stod(a.substr(div + 1))) << endl;
}
double rut()
{
    string a;
    cout << "\nTo get nth root of x.\nenter in the following formate: x,n\n\n";
    getline(cin, a);
    long long div = a.find(",");
    cout << stod(a.substr(div + 1)) << "th root of " << stod(a.substr(0, div)) << " is: " << pow(stod(a.substr(0, div)), (1 / stod(a.substr(div + 1)))) << endl;
}
double fact()
{
    cout << "\nTo get factorial of x.\nenter x: ";
    long long a;
    cin >> a;
    long long c = a;
    long long fact = 1;
    while (a != 1)
    {
        fact *= a;
        a--;
    }
    cout << "factorial of " << c << " is: " << fact << endl;
}
double log_()
{
    string a;
    cout << "\nTo get logarithm of x, where x is the argument & b is base.\nenter in the following formate: x,b\n\n";
    getline(cin, a);
    long long div = a.find(",");
    cout << "logarithm of " << stod(a.substr(0, div)) << " base " << stod(a.substr(div + 1)) << " is: " << log(stod(a.substr(0, div))) / (log(stod(a.substr(div + 1)))) << endl;
}
double eq_solve()
{
    cout << "\nTo get the roots for aX^2+bX+c=0.\nenter a,b,c in the following formate: a b c\n\n";
    double a, b, c;
    cin >> a >> b >> c;
    if (((b * b) - (4 * a * c)) >= 0)
        cout << "roots are: " << ((-b + sqrt(b * b - 4 * a * c)) / (2 * a)) << "," << ((-b - sqrt(b * b - 4 * a * c)) / (2 * a)) << endl;
    else
        cout << "roots are: " << -b / (2 * a) << "+" << sqrt(fabs(b * b - 4 * a * c)) / (2 * a) << "i , " << -b / (2 * a) << "-" << sqrt(fabs(b * b - 4 * a * c)) / (2 * a) << "i" << endl;
}
int main()
{

    cout << "\n\nWelcome to Rounok's Calculator\nType any character from the given list, for your desired operation:";
    while (true)
    {
        cout << "\n\n\'+\'  to sum \n\'-\'  to substract\n\'*\'  to multiply\n\'/\'  to divide\n\'%\'  to get reminder\n\'^\'  to get power\n\'r\'  to get root\n\'!\'  to get factorial\n\'l\'  to get logarithm\n\'e\'  to solve a quadretic equation\n\nenter your character: ";
        char a = getchar();
        getchar();
        if (a == '/')
            div_();
        else if (a == '%')
            rem_();
        else if (a == '^')
            power();
        else if (a == 'r')
            rut();
        else if (a == 'l')
            log_();
        else if (a == '!')
            fact();
        else if (a == 'e')
            eq_solve();
        else if (a == '+')
            sum_();
        else if (a == '-')
            subs_();
        else if (a == '*')
            multi_();
        else if (a == 'e')
            eq_solve();

        cout << "\npress y to continue, n to end the program" << endl;
        char end;
        cin >> end;
        getchar();
        if (end == 'n')
            break;
    }
    cout << "\nThanks for using my calculator.\n"
         << endl;

}
