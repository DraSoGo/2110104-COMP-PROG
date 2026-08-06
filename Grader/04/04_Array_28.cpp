#include <bits/stdc++.h>
using namespace std;

int ans[26];

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    getline(cin,s);
    for (int i = 0; i < s.length(); i++)
    {
        char c = tolower(s[i]);
        if (c >= 'a' && c <= 'z')
        {
            ans[c - 'a']++;
        }
    }
    for (int i = 0; i < 26; i++)
    {
        if (ans[i])
        {
            cout << char('a'+i) << " -> " << ans[i] << "\n";
        }
    }
    return 0;
}