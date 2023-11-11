#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using st = string;
using d = double;
using ld = long double;
void toss_()
{
    srand(time(0));
    st team1, team2;
    cout << "This is a cricket simulator game.\n\nEnter your team name: ";
    cin >> team1;
    cout << "Enter opponents team name: ";
    cin >> team2;
    int toss = rand() % 2;
    char tos;
    cout << "It's time for toss.\n\nChoose 'H' or 'T': ";
    cin >> tos;
    if (toss == 0)
    {
        cout << "You have won the toss !\nWhat would you like to do?\nCoose 0 to bat & 1 to ball: ";
        cin >> toss;
    }
    else
    {
        toss = rand() % 2;
        cout << "Opponent has won the toss !";
        if (rand == 0)
            cout << "They have decided to bat first.";
        else
            cout << "They have decided to bowl first.";
    }
}
int main()
{
}