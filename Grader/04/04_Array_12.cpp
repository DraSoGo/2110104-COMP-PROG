#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string S[10][2] = {{"Robert","Dick"},{"William","Bill"},{"James","Jim"},{"John","Jack"},{"Margaret","Peggy"},{"Edward","Ed"},{"Sarah","Sally"},{"Andrew","Andy"},{"Anthony","Tony"},{"Deborah","Debbie"}};
    int n;
    cin >> n;
    while (n--)
    {
        string s;
        bool ch = 0;
        cin >> s;
        for (int i = 0; i < 10; i++)
        {
            if (S[i][0] == s)
            {
                ch = 1;
                cout << S[i][1] << "\n";
                break;
            }
            if (S[i][1] == s)
            {
                ch = 1;
                cout << S[i][0] << "\n";
                break;
            }
        }
        if (!ch)
        {
            cout << "Not found\n";
        }
    }
    return 0;
}