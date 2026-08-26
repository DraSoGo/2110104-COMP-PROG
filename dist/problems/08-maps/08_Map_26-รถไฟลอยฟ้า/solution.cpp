#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    map <string,vector<string>> G;
    set <string> ANS;
    string u,v,line;
    while (getline(cin,line))
    {
        if (line.find(' ') == string::npos)
        {
            u = line;
            ANS.insert(u);
            for(auto uv:G[u])
            {
                ANS.insert(uv);
                for(auto uvv:G[uv])
                {
                    ANS.insert(uvv);

                }
            }
        }
        else
        {
            u = line.substr(0,line.find(" "));
            v = line.substr(line.find(" ")+1,line.length()-line.find(" "));
            G[u].push_back(v);
            G[v].push_back(u);
            // cout << u << " " << v << "\n";
        }
    }
    for(auto x:ANS)
    {
        cout << x << "\n";
    }
    return 0;
}