#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    vector <int> V;
    cin >> n;
    V.push_back(n);
    while (n!=1)
    {
        if (n %2 == 0)
        {
            n /= 2;
        }
        else
        {
            n = 3*n+1;
        }
        V.push_back(n);
    }
    for (int i = max(0,int(V.size()-15)); i < V.size(); i++)
    {
        cout << V[i];
        if (V[i] != 1)
        {
            cout << "->";
        }
    }
    return 0;
}