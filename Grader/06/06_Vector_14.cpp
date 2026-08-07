#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    set <int> S;
    int x,co = 0;
    while (cin >> x)
    {
        S.insert(x);
    }
    cout << S.size() << "\n";
    for(auto i:S)
    {
        cout << i << " ";
        if (co == 9)
        {
            break;
        }
        co++;
    }
    return 0;
}