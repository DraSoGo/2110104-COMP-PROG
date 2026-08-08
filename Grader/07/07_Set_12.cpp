#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    set <int> S;
    int n,idx = 0;
    bool ch = 0;
    while (cin >> n)
    {
        S.insert(n);
        if (S.size() == idx && !ch)
        {
            cout << idx+1;
            ch = 1;
        }
        idx++;
    }
    if (!ch)
    {
        cout << -1;
    }
    
    return 0;
}