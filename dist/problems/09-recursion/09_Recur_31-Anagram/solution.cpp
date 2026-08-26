#include <bits/stdc++.h>
using namespace std;

string pat,s = "";
set <string> ANS;
bool vis[100000];

void gen(int n)
{
    if (s.size() == n)
    {
        ANS.insert(s);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            vis[i] = 1;
            s.push_back(pat[i]);
            gen(n);
            vis[i] = 0;
            s.pop_back();
        }
    }
    
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> pat;
    gen(pat.length());
    for(auto x:ANS)
    {
        cout << x << " ";
    }
    return 0;
}