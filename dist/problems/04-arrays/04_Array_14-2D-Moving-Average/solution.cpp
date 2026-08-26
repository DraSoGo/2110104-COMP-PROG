#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin >> n >> m;
    double A[n+1][m+1],QS[n+1][m+1];
    memset(A,0,sizeof(A));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> A[i][j];
            QS[i][j] = A[i][j] + QS[i-1][j] + QS[i][j-1] - QS[i-1][j-1];
        }
    }
    for (int i = 3; i <= n; i++)
    {
        for (int j = 3; j <= m; j++)
        {
            cout << round(((QS[i][j] - QS[i-3][j] - QS[i][j-3] + QS[i-3][j-3])/9)*100)/100.0 << " ";
        }
        cout << "\n";
    }
    return 0;
}