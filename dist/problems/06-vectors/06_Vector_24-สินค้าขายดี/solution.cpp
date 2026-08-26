#include <bits/stdc++.h>
using namespace std;

struct good
{
    string p;
    double c,sum;
    bool operator < (const good&k)const
    {
        if (sum == k.sum)
        {
            return p < k.p;
        }
        return sum > k.sum;
    }
};


int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    vector <good> V;
    string l;
    double x;
    while (cin >> l,l != "END")
    {
        cin >> x;
        V.push_back({l,x,0});
    }
    while (cin >> l)
    {
        for (int i = 0; i < V.size(); i++)
        {
            if (V[i].p == l)
            {
                V[i].sum += V[i].c;
            }
        }
    }
    sort(V.begin(),V.end());
    for (int i = 0; i < min(3,int(V.size())); i++)
    {
        if (V[i].sum == 0)
        {
            if (i == 0)
            {
                cout << "No Sales";
            }
            
            break;
        }
        cout << V[i].p << " " << V[i].sum << "\n";
    }
    
    return 0;
}