#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,co = 0;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    for (int i = 1; i < n-1; i++)
    {
        if (A[i] > A[i-1] && A[i] > A[i+1])
        {
            co++;
        }
    }
    cout << co;
    return 0;
}