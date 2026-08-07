#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    cin >> s;
    s += "$";
    vector <string> V;
    V.push_back(s);
    for (int i = 0; i < s.size()-1; i++)
    {
        s = s.substr(1,s.length()-1)+s[0];
        // cout << s << "\n";
        V.push_back(s);
    }
    sort(V.begin(),V.end());
    for (int i = 0; i < V.size(); i++)
    {
        cout << V[i][V[i].length()-1];
    }
    
    return 0;
}