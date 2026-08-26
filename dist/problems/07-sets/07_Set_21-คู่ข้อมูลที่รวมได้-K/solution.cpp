#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    set <int> S;
    int k,x,ans = 0;
    cin >> k;
    while (cin >> x)
    {
        if (x > k)
        {
            continue;
        }
        S.insert(x);
    }
    for(auto i:S)
    {
        if (S.find(k-i) != S.end())
        {
            ans++;
        }
    }
    cout << ans/2;
    return 0;
}