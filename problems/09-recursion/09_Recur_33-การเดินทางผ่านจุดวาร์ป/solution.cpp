#include <bits/stdc++.h>
using namespace std;

vector <int> G[1000];
int n,s,e,u,v;
stack <int> S;
bool vis[1000];

bool dfs()
{
    S.push(s);
    while (!S.empty())
    {
        int u = S.top();
        S.pop();
        if (vis[u])
        {
            continue;
        }
        if (u == e)
        {
            return 1;
        }
        for (int i = 0; i < G[u].size(); i++)
        {
            S.push(G[u][i]);
        }
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> s >> e;
    for (int i = 0; i < n; i++)
    {
        cin >> u >> v;
        G[u].push_back(v);
    }
    cout << (dfs()?"yes":"no");
    return 0;
}