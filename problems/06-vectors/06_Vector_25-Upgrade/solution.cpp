#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string score[] = {"F","D","D+","C","C+","B","B+","A","A+"};
    vector <pair<string,string>> V;
    string a,b;
    while (cin >> a,a != "q")
    {
        cin >> b;
        V.push_back({a,b});
    }
    while (cin >> a)
    {
        for (int i = 0; i < V.size(); i++)
        {
            if (V[i].first == a)
            {
                for (int j = 0; j < 8; j++)
                {
                    if (V[i].second == score[j])
                    {
                        V[i].second = score[j+1];
                        break;
                    }
                }
                break;
            }
        }
    }
    for(auto[u,v]:V)
    {
        cout << u << " " << v << '\n';
    }
    
    return 0;
}