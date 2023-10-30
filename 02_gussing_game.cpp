#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
    cout << "\n\nThis is a gussing  game.\nThere will be a secret number randomly generated between 0 to 9\nYou have 3 guesses to guess it. good luck !\nfirst guess: ";
    int a = 1;
    srand(time(0));
    int ra = rand() % 10;
    while (a--)
    {
        int a;
        cin >> a;
        if (a == ra)
        {
            cout << "you guessed it!, you win";
            break;
        }
        cout << "Wrong! 2 guesses remaining\n";
        cin >> a;
        if (a == ra)
        {
            cout << "you guessed it!, you win";
            break;
        }
        cout << "Wrong! 1 guess remaining\n";
        cin >> a;
        if (a == ra)
        {
            cout << "you guessed it!, you win";
            break;
        }
        cout << "oops! guesses over! you lost! \nThe secret number was: " << ra;
    }
    return 0;
}
