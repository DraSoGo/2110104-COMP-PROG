#include <bits/stdc++.h>
using namespace std;

string T[5][5];
bool M[5][5];

vector <string> ANS[4];
string big = "BINGO";

bool checkR(int r)
{
    for (int i = 0; i < 5; i++)
    {
        if (!M[r][i])
        {
            return 0;
        }
    }
    for (int i = 0; i < 5; i++)
    {
        string tmp = "";
        tmp += big[i];
        tmp += T[r][i];
        ANS[0].push_back(tmp);
    }
    return 1;
}

bool checkC(int c)
{
    for (int i = 0; i < 5; i++)
    {
        if (!M[i][c])
        {
            return 0;
        }
    }
    for (int i = 0; i < 5; i++)
    {
        string tmp = "";
        tmp += big[c];
        tmp += T[i][c];
        ANS[1].push_back(tmp);
    }
    return 1;
}

bool checkL()
{
    for (int i = 0; i < 5; i++)
    {
        if (!M[i][i])
        {
            return 0;
        }
    }
    for (int i = 0; i < 5; i++)
    {
        string tmp = "";
        tmp += big[i];
        tmp += T[i][i];
        ANS[2].push_back(tmp);
    }
    return 1;
}

bool checkR()
{
    for (int i = 0; i < 5; i++)
    {
        if (!M[4-i][i])
        {
            return 0;
        }
    }
    for (int i = 0; i < 5; i++)
    {
        string tmp = "";
        tmp += big[i];
        tmp += T[4-i][i];
        ANS[3].push_back(tmp);
    }
    return 1;
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    M[2][2] = 1;
    char x;
    for (int i = 0; i < 5; i++)
    {
        cin >> x;
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> T[i][j];
        }
    }
    string c;
    bool s = 0;
    int ans = 0;
    while (cin >> c)
    {
        if (!s)
        {
            int col = c[0] == 'B'?0:c[0] == 'I'?1:c[0] == 'N'?2:c[0] == 'G'?3:4;
            string x = c.substr(1,c.length()-1);
            for (int i = 0; i < 5; i++)
            {
                if (T[i][col] == x)
                {
                    M[i][col] = 1;
                    if (checkR(i))
                    {
                        s = 1;
                    }
                    if (checkC(col))
                    {
                        s = 1;
                    }
                    if (checkL())
                    {
                        s = 1;
                    }
                    if (checkR())
                    {
                        s = 1;
                    }
                    break;
                }
            }
            ans++;
        }
    }
    cout << ans << "\n";
    for (int i = 0; i < 4; i++)
    {
        if (ANS[i].empty())
        {
            continue;
        }
        for (int j = 0; j < ANS[i].size(); j++)
        {
            if (ANS[i][j][1] == '*')
            {
                continue;
            }
            cout << ANS[i][j];
            if (j != ANS[i].size()-1)
            {
                cout << ", ";
            }
        }
        cout << "\n";
    }
    return 0;
}