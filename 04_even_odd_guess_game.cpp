#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
    cout << "\n\nThis is a even odd gussing game.Your opponent is the computer.\nThis game consists of five rounds.In each round you need to choose any of the following \"even\" or \"odd\".\nIf you guess the correct one, you win the round.Highest point after 5 rounds wins.Good luck.\n\n";
    int a = 5;
    srand(time(0));
    string str, s2;
    int yp = 0, cp = 0;
    while (a--)
    {
        int ra = rand() % 2;
        if (ra == 0)
            str = "even";
        else
            str = "odd";

        cout << "Enter your choice: ";
        cin >> s2;
        cout << "computer chossed: " << str << "\nYon chossed: " << s2 << "\n";
        if (str == s2)
        {
            cout << "You guessed right ! \n\n";
            yp++;
        }
        else
        {
            cout << "You guessed wrong ! \n\n";
            cp++;
        }
    }
    cout << "Coumputer's point: " << cp << "\nYour point: " << yp << endl;

    if (yp > cp)
        cout << "Hurrah ! You won the game !\n\n";
    else
        cout << "OOPS ! You lost the game !\n\n";
    return 0;
}
