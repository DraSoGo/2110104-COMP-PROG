#include <bits/stdc++.h>
using namespace std;

struct GP
{
    int v,w;
    bool operator < (const GP&a)const
    {
        return a.w < w;
    }
};

const int sz = 1e4+10;
int n,e,u,v,w,a,b,x;
vector <GP> G[sz];
priority_queue <GP> PQ;
bool vis[sz];
int dis[sz];

int DJ(int st,int ed)
{
    dis[st] = 0;
    PQ.push({st,0});
    while (!PQ.empty())
    {
        auto [node,w] = PQ.top();
        PQ.pop();
        if (vis[node])
        {
            continue;
        }
        vis[node] = 1;
        // cout << node << " " << w << "\n";
        for (auto [nxt,nw]:G[node])
        {
            if (dis[nxt] > dis[node] + nw)
            {
                dis[nxt] = dis[node] + nw;
                PQ.push({nxt,dis[nxt]});
            }
        }
    }
    return dis[ed];
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    fill(dis,dis+sz,INT_MAX);
    cin >> n >> e;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < e; j++)
        {
            cin >> x;
            G[i].push_back({x,1});
        }
    }
    int ans = DJ(0,n-1),co = 0;
    if (ans == INT_MAX)
    {
        for (int i = 0; i < sz; i++)
        {
            if(dis[i] != INT_MAX)
            {
                co++;
            }
        }
        cout << "No " << co;
    }
    else
    {
        cout << "Yes " << ans+1;
    }
    
    return 0;
}
