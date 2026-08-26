#include <bits/stdc++.h>
using namespace std;

struct ran
{
    int n,a,b;
    bool operator < (const ran&x)const
    {
        if (n == x.n)
        {
            return a < x.a;
        }
        return n < x.n;
    }
};


int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    vector <int> V;
    vector <ran> ans;
    int x,idx = 0,co = 1,mx = INT_MIN;
    while (cin >> x)
    {
        V.push_back(x);
        if (idx > 0 && V[idx] == V[idx-1])
        {
            co++;
        }
        else
        {
            mx = max(co,mx);
            co = 1;
        }
        idx++;
    }
    mx = max(co,mx);
    V.push_back(-1);
    for (int l = 0; l < V.size(); l++)
    {
        co = 1;
        for (int r = l+1; r < V.size(); r++)
        {
            // cout << l << ":" << V[l] << " " << r << ":" << V[r] << "\n";
            if (V[l] == V[r])
            {
                co++;
            }
            else
            {
                if (co == mx)
                {
                    ans.push_back({V[l],l,r});
                    // cout << tmp << "\n";
                }
                l = r-1;
                co = 1;
                break;
            }
            
        }
    }
    sort(ans.begin(),ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i].n << " --> x[ " << ans[i].a << " : " << ans[i].b << " ]\n";
    }
    
    // cout << mx;
    return 0;
}