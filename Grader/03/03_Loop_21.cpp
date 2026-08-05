#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    while (getline(cin,s))
    {
        bool c = 0,C = 0,n = 0,sp = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] >= '!' && s[i] <= '/')
            {
                sp = 1;
            }
            else if (s[i] >= 'a' && s[i] <= 'z')
            {
                c = 1;
            }
            else if (s[i] >= 'A' && s[i] <= 'Z')
            {
                C = 1;
            }
            else if (s[i] >= '0' && s[i] <= '9')
            {
                n = 1;
            }
        }
        if (s.length() >= 12 && c && C && n && sp)
        {
            cout << ">> strong\n";
        }
        else if (s.length() >= 8 && c && C && n)
        {
            cout << ">> weak\n";
        }
        else
        {
            cout << ">> invalid\n";
        }
    }
    return 0;
}