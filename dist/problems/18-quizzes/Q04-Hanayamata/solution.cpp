#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,ans = 0;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
        A[i]--;
    }
    for (int i = 0; i < n; i++)
    {
        while (A[i] != i)
        {
            // cout << A[i] << " " << A[A[i]] << "\n";
            int tmp = A[A[i]];
            A[A[i]] = A[i];
            A[i] = tmp;
            ans++;
            // for (int k = 0; k < n; k++)
            // {
            //     cout << A[k] << " ";
            // }
            // cout << "\n";
        }
    }
    cout << ans;
    return 0;
}