#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
        double x = A[i];
        for (int j = i-1; j >= 0; j--)
        {
            x = A[j]+(1/x);
        }
        cout << setprecision(10) << x << "\n";
    }
    return 0;
}