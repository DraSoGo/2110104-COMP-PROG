#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    bool ch = 1;
    map <string,set <string>> M;
    vector <string> V;
    string idx,x;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> idx;
        V.push_back(idx);
        while (cin >> x,x != "*")
        {
            M[idx].insert(x);
        }
    }
    cin >> idx;
    for(auto i:V)
    {
        if (i == idx)
        {
            continue;
        }
        for(auto j:M[i])
        {
            if (M[idx].find(j) != M[idx].end())
            {
                cout << ">> " << i << "\n";
                ch = 0;
                break;
            }
        }
    }
    if (ch)
    {
        cout << ">> Not Found";
    }
    return 0;
}