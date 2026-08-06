#include <bits/stdc++.h>
using namespace std;

bool c[10];

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    int n = 10;
    getline(cin,s);
    
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            if (!c[s[i]-'0'])
            {
                n--;
                // cout << n << "\n";
            }
            c[s[i]-'0'] = 1;
        }
    }
    if (n == 0)
    {
        cout << "None";
        return 0;
    }
    // for (int i = 0; i < 10; i++)
    // {
    //     cout << c[i];
    // }
    for (int i = 0; i < 10; i++)
    {
        if (!c[i])
        {
            cout << i;
            n--;
            if (n > 0)
            {
                cout << ',';
            }
        }
    }
    return 0;
}