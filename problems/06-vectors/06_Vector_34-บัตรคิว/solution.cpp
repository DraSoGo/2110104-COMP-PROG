#include <bits/stdc++.h>
using namespace std;

struct que
{
    int q,t;
};


int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,idx = 0,q;
    double sum = 0,k = 0;
    vector <que> Q;
    cin >> n;
    while (n--)
    {
        string c;
        int x;
        cin >> c;
        if (c == "reset")
        {
            cin >> x;
            q = x;
        }
        else if (c == "new")
        {
            cin >> x;
            cout << "ticket " << q << "\n";
            Q.push_back({q,x});
            q++;
        }
        else if (c == "next")
        {
            cout << "call " << Q[idx].q << "\n";
            idx++;
        }
        else if (c == "order")
        {
            cin >> x;
            // cout << x << " " << Q[idx-1].t << "\n";
            cout << "qtime " << Q[idx-1].q << " " << x-Q[idx-1].t << "\n";
            sum += x-Q[idx-1].t;
            k++;
        }
        else
        {
            cout << "avg_qtime " << round((sum/k)*100)/100.0 << "\n";
        }
        
    }
    return 0;
}