#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int x,y,i = 0;
    int mnsi = INT_MAX,mnsa = INT_MAX,mxsi = INT_MIN,mxsa = INT_MIN;
    while (1)
    {
        cin >> x;
        if (x == -999)
        {
            cout << mnsa << " " << mxsa;
            break;
        }
        if (x == -998)
        {
            cout << mnsi << " " << mxsi;
            break;
        }
        cin >> y;
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
    
    return 0;
}