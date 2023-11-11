#include <cstring>
#include <iostream>
#include <string>

using namespace std;
using st = string;

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
        stt[0][1] = 'O';
    else if (str == "2")
        stt[0][5] = 'O';
    else if (str == "3")
        stt[0][9] = 'O';
    else if (str == "4")
        stt[2][1] = 'O';
    else if (str == "5")
        stt[2][5] = 'O';
    else if (str == "6")
        stt[2][9] = 'O';
    else if (str == "7")
        stt[4][1] = 'O';
    else if (str == "8")
        stt[4][5] = 'O';
    else
        stt[4][9] = 'O';
}
void straddp2(char stt[5][11], string str)
{
    if (str == "1")
        stt[0][1] = 'X';
    else if (str == "2")
        stt[0][5] = 'X';
    else if (str == "3")
        stt[0][9] = 'X';
    else if (str == "4")
        stt[2][1] = 'X';
    else if (str == "5")
        stt[2][5] = 'X';
    else if (str == "6")
        stt[2][9] = 'X';
    else if (str == "7")
        stt[4][1] = 'X';
    else if (str == "8")
        stt[4][5] = 'X';
    else
        stt[4][9] = 'X';
}
int main()
{
    while (1)
    {
        char stt[5][11] = {' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '-', '-', '-', ' ', '-', '-', '-', ' ', '-', '-', '-', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '-', '-', '-', ' ', '-', '-', '-', ' ', '-', '-', '-', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' '};

        cout << "\n\nThis is a tic-tac-toe game.\nThe positions of the boxes are defined as 1-9, starting from the left side of the first row.You need to choose a number to put your mark. whoever makes a line of 3 boxes first, wins the game.\n\n";
        string p1, p2;
        cout << "enter player 1 name: ";
        getline(cin, p1);
        cout << "enter player 2 name: ";
        getline(cin, p2);
        st pl1, pl2, str;
        int i = 1;
        pri(stt);
        while (1)
        {

            while (1)
            {
                cout << "player 1's turn: ";
                cin >> str;
                if (stoll(str) > 9 || stoll(str) < 1)
                    cout << "\nnot a valid box number, please enter between 1-9.\n";
                else if (pl1.find(str.back()) != string ::npos || pl2.find(str.back()) != string ::npos)
                {
                    cout << "\nthis box is already taken, please choose another box.\n";
                }
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
                    cout << '\n'
                         << p1 << " wins the game !\n\n";
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
                cout << "player 2's turn: ";
                cin >> str;
                if (stoll(str) > 9 || stoll(str) < 1)
                    cout << "\nnot a valid box number, please enter between 1-9.\n";
                else if (pl1.find(str.back()) != string ::npos || pl2.find(str.back()) != string ::npos)
                {
                    cout << "\nthis box is already taken, please choose another box.\n";
                }
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
                    cout << '\n'
                         << p2 << " wins the game !\n\n";
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