#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 10,k,a,b,sum = 0,mn = INT_MAX,mx = INT_MIN;
    int A[n];
    for(int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    cin >> k;
    while(k--)
    {
        cin >> a >> b;
        for(int i = a; i <= b; i++)
        {
            if(A[i] != 0)
            {
                A[i]--;
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        mn = min(mn,A[i]);
        mx = max(mx,A[i]);
        sum += A[i];
    }
    cout << mn << " " << mx << fixed << setprecision(1) << " " << sum/10.0;
    return 0;
}