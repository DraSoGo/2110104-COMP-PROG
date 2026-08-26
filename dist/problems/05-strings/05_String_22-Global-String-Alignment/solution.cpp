#include <bits/stdc++.h>
using namespace std;

int cal(string x,string y)
{
    int co = 0;
    for (int i = 0; i < x.length(); i++)
    {
        if (x[i] == y[i])
        {
            co++;
        }
    }
    return co;
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string a,b,x,y;
    int mx = INT_MIN,s,idx,c;
    cin >> a >> b;
    for (int i = 0; i < b.length(); i++)
    {
        x = a.substr(0,min(a.length(),b.length()-i));
        y = b.substr(i,min(b.length()-i,x.length()));
        c = cal(x,y);
        if (c > mx)
        {
            mx = c;
            s = 1;
            idx = i;
        }
        // cout << y << " " << x << "\n";
    }
    for (int i = 0; i < a.length(); i++)
    {
        x = b.substr(0,min(b.length(),a.length()-i));
        y = a.substr(i,min(a.length()-i,x.length()));
        c = cal(x,y);
        if (c > mx)
        {
            mx = c;
            s = 2;
            idx = i;
        }
        else if (c == mx && i < idx)
        {
            s = 2;
            idx = i;
        }
        // cout << y << " " << x << " " << c << "\n";
    }
    if (s == 1)
    {
        for (int i = 0; i < idx; i++)
        {
            cout << '-';
        }
    }
    cout << a << "\n";
    if (s == 2)
    {
        for (int i = 0; i < idx; i++)
        {
            cout << '-';
        }
    }
cout << b << "\n" << mx;
    
    return 0;
}