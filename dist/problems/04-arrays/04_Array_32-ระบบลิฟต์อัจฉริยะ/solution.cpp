#include <bits/stdc++.h>
using namespace std;

int cal(int A[],int B[])
{
    // for (int i = 0; i < 2; i++)
    // {
    //     cout << A[i] << " ";
    // }
    // cout << ", ";
    // for (int i = 0; i < 2; i++)
    // {
    //     cout << B[i] << " ";
    // }
    // cout << "\n";
    bool sa,sb;
    sa = A[0] >= A[1]?1:0;
    sb = B[0] > B[1]?1:0;
    if (sa != sb || !(B[0] >= A[0] && B[0] <= A[1]) && !(B[0] <= A[0] && B[0] >= A[1]))
    {
        // cout << 1 << ":" << abs(A[1]-B[0]) + abs(B[0]-B[1]) << "\n";
        return abs(A[1]-B[0]) + abs(B[0]-B[1]);
    }
    // cout << 2 << ":" << abs(B[1]-A[1]) << "\n";
    return abs(B[1]-A[1]);
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin >> n;
    int A[n][3];
    for (int i = 0; i < n; i++)
    {
        cin >> A[i][2] >> A[i][0] >> A[i][1];
    }
    cin >> m;
    int B[m][2];
    for (int i = 0; i < m; i++)
    {
        cin >> B[i][0] >> B[i][1];
    }
    for (int i = 0; i < m; i++)
    {
        int mn = INT_MAX,idx;
        for (int j = 0; j < n; j++)
        {
            int dis = cal(A[j],B[i]);
            // cout << dis << " ";
            if (dis < mn)
            {
                mn = dis;
                idx = A[j][2];
            }
            else if (dis == mn)
            {
                idx = min(idx,A[j][2]);
            }
        }
        // cout << "\n";
        cout << ">> " << idx << "\n";
    }
    
    return 0;
}