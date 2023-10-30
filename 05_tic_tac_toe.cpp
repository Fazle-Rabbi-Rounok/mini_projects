#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cstdint>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <cctype>
#include <ctime>

using namespace std;
using ll = long long;
using st = string;
using d = double;
using ld = long double;

int com(const void *aa, const void *bb)
{
    return *(const int *)aa - *(const int *)bb;
}
void pri(char st[5][11])
{
    printf("\n");
    int aa = 0, bb = 0;
    while (aa < 5)
    {
        bb = 0;
        while (bb < 11)
        {
            printf("%c", st[aa][bb]);
            bb++;
        }
        printf("\n");
        aa++;
    }
    printf("\n");
}
void straddp1(char stt[5][11], string str)
{
    if (str == "1")
        stt[0][1] = 'o';
    else if (str == "2")
        stt[0][5] = 'o';
    else if (str == "3")
        stt[0][9] = 'o';
    else if (str == "4")
        stt[2][1] = 'o';
    else if (str == "5")
        stt[2][5] = 'o';
    else if (str == "6")
        stt[2][9] = 'o';
    else if (str == "7")
        stt[4][1] = 'o';
    else if (str == "8")
        stt[4][5] = 'o';
    else
        stt[4][9] = 'o';
}
void straddp2(char stt[5][11], string str)
{
    if (str == "1")
        stt[0][1] = '*';
    else if (str == "2")
        stt[0][5] = '*';
    else if (str == "3")
        stt[0][9] = '*';
    else if (str == "4")
        stt[2][1] = '*';
    else if (str == "5")
        stt[2][5] = '*';
    else if (str == "6")
        stt[2][9] = '*';
    else if (str == "7")
        stt[4][1] = '*';
    else if (str == "8")
        stt[4][5] = '*';
    else
        stt[4][9] = '*';
}
int main()
{
    while (1)
    {
        char stt[5][11] = {' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '-', '-', '-', ' ', '-', '-', '-', ' ', '-', '-', '-', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '-', '-', '-', ' ', '-', '-', '-', ' ', '-', '-', '-', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' '};

        cout << "\n\nThis is a tic-tac-toe game.\nThe positions of the boxes are defined as 1-9, starting from the left side of the first row.You need to choose a number to put your mark. whoever makes a line of 3 boxes first, wins the game.\n\n";
        st pl1, pl2, str;
        int i = 1;
        pri(stt);
        while (1)
        {

            while (1)
            {
                cout << "player 1's choice: ";
                cin >> str;
                if (pl1.find(str.back()) != string ::npos || pl2.find(str.back()) != string ::npos)
                {
                    cout << "\nthis box is already taken, please choose another box.\n";
                }
                else if (stoll(str) > 9 || stoll(str) < 1)
                    cout << "\nnot a valid box number, please enter between 1-9.\n";
                else
                    break;
            }
            straddp1(stt, str);
            pri(stt);
            pl1 += str;
            if (i > 2)
            {
                if ((pl1.find("1") != st ::npos && pl1.find("2") != st ::npos && pl1.find("3") != st ::npos) || (pl1.find("4") != st ::npos && pl1.find("5") != st ::npos && pl1.find("6") != st ::npos) || (pl1.find("7") != st ::npos && pl1.find("9") != st ::npos && pl1.find("8") != st ::npos) || (pl1.find("1") != st ::npos && pl1.find("4") != st ::npos && pl1.find("7") != st ::npos) || (pl1.find("2") != st ::npos && pl1.find("5") != st ::npos && pl1.find("8") != st ::npos) || (pl1.find("3") != st ::npos && pl1.find("6") != st ::npos && pl1.find("9") != st ::npos) || (pl1.find("1") != st ::npos && pl1.find("5") != st ::npos && pl1.find("9") != st ::npos) || (pl1.find("3") != st ::npos && pl1.find("5") != st ::npos && pl1.find("7") != st ::npos))
                {
                    cout << "\nplayer 1 wins !\n\n";
                    break;
                }
            }
            if (i == 9)
            {
                cout << "\ngame over ! No one wins this round.\n\n";
                break;
            }
            i++;
            while (1)
            {
                cout << "player 2's choice: ";
                cin >> str;
                if (pl1.find(str.back()) != string ::npos || pl2.find(str.back()) != string ::npos)
                {
                    cout << "\nthis box is already taken, please choose another box.\n";
                }
                else if (stoll(str) > 9 || stoll(str) < 1)
                    cout << "\nnot a valid box number, please enter between 1-9.\n";
                else
                    break;
            }
            straddp2(stt, str);
            pri(stt);
            pl2 += str;
            if (i > 2)
            {
                if ((pl2.find("1") != st ::npos && pl2.find("2") != st ::npos && pl2.find("3") != st ::npos) || (pl2.find("4") != st ::npos && pl2.find("5") != st ::npos && pl2.find("6") != st ::npos) || (pl2.find("7") != st ::npos && pl2.find("9") != st ::npos && pl2.find("8") != st ::npos) || (pl2.find("1") != st ::npos && pl2.find("4") != st ::npos && pl2.find("7") != st ::npos) || (pl2.find("2") != st ::npos && pl2.find("5") != st ::npos && pl2.find("8") != st ::npos) || (pl2.find("3") != st ::npos && pl2.find("6") != st ::npos && pl2.find("9") != st ::npos) || (pl2.find("1") != st ::npos && pl2.find("5") != st ::npos && pl2.find("9") != st ::npos) || (pl2.find("3") != st ::npos && pl2.find("5") != st ::npos && pl2.find("7") != st ::npos))
                {
                    cout << "\nplayer 2 wins !\n\n";
                    break;
                }
            }
            i++;
        }
        cout << "want to play again?\npress y to play again, n to end the program.\n";
        getchar();
        char a = getchar();
        if (a == 'n')
        {
            cout << "\nThanks for playing my game.\n\n";
            break;
        }
    }
    return 0;
}