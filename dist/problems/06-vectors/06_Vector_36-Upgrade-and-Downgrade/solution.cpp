#include <bits/stdc++.h>
using namespace std;

struct sc
{
    string s,g;
    int x;
    bool operator < (const sc&a)const
    {
        if (x == a.x)
        {
            return s > a.s;
        }
        return x > a.x;
    }
};


int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string score[] = {"F","D","D+","C","C+","B","B+","A"};
    vector <sc> V;
    string a,b;
    int n;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> a >> b;
        for (int i = 0; i < 8; i++)
        {
            if (b == score[i])
            {
                x = i;
            }
        }
        V.push_back({a,b,x});
    }
    while (cin >> a)
    {
        b = a[a.length()-1];
        a = a.substr(0,a.length()-1);
        for (int i = 0; i < V.size(); i++)
        {
            if (V[i].s == a)
            {
                if (b == "+" && V[i].x < 7)
                {
                    V[i].x++;
                    V[i].g = score[V[i].x];
                }
                else if (b == "-" && V[i].x > 0)
                {
                    V[i].x--;
                    V[i].g = score[V[i].x];
                }
                break;
            }
        }
    }
    sort(V.begin(),V.end());
    for(auto[u,v,l]:V)
    {
        cout << u << " " << v << '\n';
    }
    
    return 0;
}