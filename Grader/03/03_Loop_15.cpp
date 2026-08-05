#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    getline(cin,s);
    // cout << c << " " << s;
    for (int i = 0; i < s.length(); i++)
    {
        cout << (s[i] == '('?'[':s[i] == ')'?'[':s[i] == '['?'(':s[i] == ']'?')':s[i]);
    }
    return 0;
}