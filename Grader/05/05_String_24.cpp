#include <bits/stdc++.h>
using namespace std;

bool vow(char x)
{
    if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')
    {
        return 1;
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s,a,b,ca,cb,va,vb;
    vector <string> S;
    while (cin >> s)
    {
        S.push_back(s);
    }
    a = S[0];
    b = S[S.size()-1];
    for (int i = 0; i < a.length(); i++)
    {
        if (i != 0 && vow(a[i]))
        {
            ca = a.substr(0,i);
            va = a.substr(i,a.length()-i);
            // cout << ca << " " << va << "\n";
            break;
        }
    }
    for (int i = 0; i < b.length(); i++)
    {
        if (i != 0 && vow(b[i]))
        {
            cb = b.substr(0,i);
            vb = b.substr(i,b.length()-i);
            // cout << cb << " " << vb << "\n";
            break;
        }
    }
    S[0] = ca + vb;
    S[S.size()-1] = cb + va;
    for (int i = 0; i < S.size(); i++)
    {
        cout << S[i] << " ";
    }
    
    return 0;
}