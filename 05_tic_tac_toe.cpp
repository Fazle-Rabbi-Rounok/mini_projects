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

int main()
{
    cout << "\n\nThis is a tic-tac-toe game.\nThe positions of the boxes are defined as 1-9, starting from the left side of the first row.You need to choose a number to put your mark. whoever makes a line of 3 boxes first, wins the game.\n\n";
    st pl1, pl2, str;
    int i = 1;
    while (1)
    {
        cout << "player 1's choice: ";
        cin >> str;
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
        cout << "player 2's choice: ";
        cin >> str;
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
    return 0;
}