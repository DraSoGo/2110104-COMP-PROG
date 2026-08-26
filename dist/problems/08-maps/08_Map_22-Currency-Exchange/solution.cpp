#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    map <string,double> M;
    M["THB"] = 1;
    int m,n;
    string s,now,nxt;
    double c;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s >> c;
        M[s] = c;
    }
    cin >> m >> now;
    while (cin >> nxt)
    {
        cout << m << " " << now << " -> ";
        m = int(m*M[now]/M[nxt]);
        now = nxt;
    }
    cout << m << " " << now;
    return 0;
}