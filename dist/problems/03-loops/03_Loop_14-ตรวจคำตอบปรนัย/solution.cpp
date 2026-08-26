#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string c,s;
    int ans = 0;
    // cin >> c;
    getline(cin,c);
    getline(cin,s);
    // cout << c << " " << s;
    if (c.length() != s.length())
    {
        cout << "Incomplete answer";
        return 0;
    }
    for (int i = 0; i < c.length(); i++)
    {
        if (s[i] == c[i])
        {
            ans++;
        }
    }
    cout << ans;
    return 0;
}