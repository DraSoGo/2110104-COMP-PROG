#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    int A[n],idx,sum,mx = INT_MIN,ch,now,nxt;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    for (int k = 0; k <= n; k++)
    {
        vector <int> tmp;
        for (int i = 0; i < n; i++)
        {
            if (i != k)
            {
                tmp.push_back(A[i]);
                // cout << A[i] << " ";
            }
        }
        for (int i = 0; i < tmp.size(); i++)
        {
            idx = i+1,sum = tmp[i],ch = 0,now = tmp[i];
            if (idx >= tmp.size())
            {
                idx = 0;
            }
            // cout << now << " ";
            for (int j = 1; j < tmp.size(); j++)
            {
                nxt = tmp[idx];
                if (nxt < now)
                {
                    mx = max(sum,mx);
                    break;
                }
                now = nxt;
                sum += now;
                mx = max(sum,mx);
                idx++;
                if (idx >= tmp.size())
                {
                    idx = 0;
                }
            }
            // cout << "\n";
            // mx = max(sum,mx);
        }
    }
    cout << mx;
    return 0;
}