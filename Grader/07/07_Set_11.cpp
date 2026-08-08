#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    multiset <char> S1,S2;
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    for (int i = 0; i < s1.size(); i++)
    {
        if (s1[i] != ' ')
        {
            S1.insert(tolower(s1[i]));
        }
    }
    for (int i = 0; i < s2.size(); i++)
    {
        if (s2[i] != ' ')
        {
            S2.insert(tolower(s2[i]));
        }
    }
    if (S1 == S2)
    {
        cout << "YES";
        return 0;
    }
    cout << "NO";
    
    return 0;
}