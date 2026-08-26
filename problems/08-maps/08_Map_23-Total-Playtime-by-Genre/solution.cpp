#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    map <string,int> M;
    string m,a,c,t;
    while (cin >> m >> a >> c >> t)
    {
        // cout << t.substr(0,t.find(':')) << " " << t.substr(t.find(':')+1,2) << "\n";
        M[c] += stoi(t.substr(0,t.find(':')))*60+stoi(t.substr(t.find(':')+1,2));
    }
    vector <pair<int,string>> V;
    for(auto[i,j] : M)
    {
        V.push_back({j,i});
    }
    sort(V.begin(),V.end());
    for (int i = V.size()-1; i >= max(int(V.size()-3),0); i--)
    {
        cout << V[i].second << " --> " << V[i].first/60 << ":" << V[i].first%60 << "\n"; 
    }
    
    return 0;
}