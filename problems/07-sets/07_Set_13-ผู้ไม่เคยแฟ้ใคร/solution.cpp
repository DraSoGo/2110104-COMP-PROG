#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    set <string> W,L;
    string w,l;
    bool one = 0;
    while (cin >> w,cin >> l)
    {
        W.insert(w);
        L.insert(l);
    }
    for(auto x:W)
    {
        bool ch = 1;
        if (L.find(x) != L.end())
        {
            ch = 0;
        }
        if (ch)
        {
            one = 1;
            cout << x << " ";
        }
    }
    if (!one)
    {
        cout << "None";
    }
    return 0;
}