#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    map <string,vector<string>> M;
    vector <string> V;
    string idx,x;
    while (cin >> x,cin >> idx)
    {
        if (M.find(idx) == M.end())
        {
            V.push_back(idx);
        }
        M[idx].push_back(x);
        
    }
    for (auto i:V)
    {
        cout << i << ":";
        for(auto k:M[i])
        {
            cout << " " << k;
        }
        cout << "\n";
    }
    
    return 0;
}