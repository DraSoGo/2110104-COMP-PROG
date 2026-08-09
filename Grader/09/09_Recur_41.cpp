#include <bits/stdc++.h>
using namespace std;

vector <int> G[10000];
int n,s,e,u,v;
set <vector<int>> ANS;

bool bfs()
{
    queue <vector<int>> Q;
    Q.push({s});
    bool ch = 0;
    while (!Q.empty())
    {
        vector <int> tmp = Q.front();
        int u = tmp.back();
        Q.pop();
        if (u == e)
        {
            ANS.insert(tmp);
            ch = 1;
        }
        int idx = ANS.size()-1;
        for (int i = 0; i < G[u].size(); i++)
        {
            vector <int> next = tmp;
            next.push_back(G[u][i]);
            Q.push(next);
        }
    }
    return ch;
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
    if (!bfs())
    {
        cout << "no";
    }
    for(auto x:ANS)
    {
        for (auto y:x)
        {
            cout << y;
            if (y != x.back())
            {
                cout << " -> ";
            }
        }
        cout << "\n";
        // if (x[x.size()-1] == e)
        // {
        // }
    }
    return 0;
}