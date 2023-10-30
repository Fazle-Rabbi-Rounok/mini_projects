#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
    cout << "\n\nThis is a rock paper scissor game.Your opponent is the computer.\nThis game consists of five rounds.In each round you need to choose any of the following \"rock\" \"paper\" or \"scissor\".Highest point after 5 rounds wins.Good luck.\n\n";
    int a = 5;
    srand(time(0));
    string str, s2;
    int yp = 0, cp = 0;
    while (a--)
    {
        int ra = rand() % 3;
        if (ra == 0)
            str = "rock";
        else if (ra == 1)
            str = "paper";
        else
            str = "scissor";
        cout << "Enter your choice: ";
        cin >> s2;
        cout << "computer chossed: " << str << "\nYon chossed: " << s2<<"\n";
        if (str == s2)
            cout << "This round was a draw\n";
        else if (ra == 0 && s2 == "paper")
        {
            cout << "You won this round!\n\n";
            yp++;
        }
        else if (ra == 0 && s2 == "scissor")
        {
            cout << "You lost this round!\n\n";
            cp++;
        }
        else if (ra == 1 && s2 == "scissor")
        {
            cout << "You won this round!\n\n";
            yp++;
        }
        else if (ra == 1 && s2 == "rock")
        {
            cout << "You lost this round!\n\n";
            cp++;
        }
        else if (ra == 2 && s2 == "rock")
        {
            cout << "You won this round!\n\n";
            yp++;
        }
        else if (ra == 2 && s2 == "paper")
        {
            cout << "You lost this round!\n\n";
            cp++;
        }
    }
    cout << "Coumputer's point: " << cp << "\nYour point: " << yp << endl;
    if (yp == cp)
        cout << "Game draw !";
    else if (yp > cp)
        cout << "Hurrah ! You won the game !\n\n";
    else
        cout << "OOPS ! You lost the game !\n\n";
    return 0;
}
