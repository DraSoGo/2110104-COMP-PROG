#include <bits/stdc++.h>
using namespace std;

struct pos
{
    double d;
    int n;
    double x,y;
    bool operator < (const pos&k)const
    {
        if (d == k.d)
        {
            if (n == k.n)
            {
                if (x == k.x)
                {
                    return y < k.y;
                }
                return x < k.x;
            }
            return n < k.n;
        }
        return d < k.d;
    }
};


int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    vector <pos> V;
    int n;
    double x,y;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x >> y;
        V.push_back({sqrt(x*x+y*y),i,x,y});
    }
    sort(V.begin(),V.end());
    // for (int i = 0; i < n; i++)
    // {
    //     cout << V[i].d << " " << V[i].n << " " << V[i].x << " " << V[i].y << "\n";
    // }
    cout << "#" << V[2].n << ": (" << V[2].x << ", " << V[2].y << ")";
    // cout << mx;
    return 0;
}