#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,p;
    cin >> n;
    double A[n];
    for(int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    cin >> p;
    for(int i = n-1; i >= 1; i--)
    {
        double x = A[i]*p/100.0;
        A[i] -= x;
        A[i-1] += x;
    }
    for(int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    return 0;
}
