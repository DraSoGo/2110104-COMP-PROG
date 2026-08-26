#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int x,y,i = 0,n;
    string s;
    int mnsi = INT_MAX,mnsa = INT_MAX,mxsi = INT_MIN,mxsa = INT_MIN;
    cin >> n;
    while (n--)
    {
        cin >> x >> y;
        if (i % 2 == 0)
        {
            mnsi = min(x,mnsi);
            mnsa = min(y,mnsa);
            mxsi = max(y,mxsi);
            mxsa = max(x,mxsa);
        }
        else
        {
            mnsi = min(y,mnsi);
            mnsa = min(x,mnsa);
            mxsi = max(x,mxsi);
            mxsa = max(y,mxsa);
        }
        // cout << mnsi << " " << mxsi << " " << mnsa << " " << mxsa << "\n";

        i++;
    }
    cin >> s;
    if (s == "Zig-Zag")
    {
        cout << mnsi << " " << mxsi;
    }
    else
    {
        cout << mnsa << " " << mxsa;
    }
    
    return 0;
}