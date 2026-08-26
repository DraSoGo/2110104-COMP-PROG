#include <bits/stdc++.h>
using namespace std;

int n;

double IRR(double A[],double x)
{
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += (A[i]/pow(1+x,i));
    }
    return sum;
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    n++;
    double L = -0.9999999999999999,U = 1,a,x,A[n];
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    while (L <= U)
    {
        x = (U+L)/2.0;
        double k = IRR(A,x);
        if (abs(k) <= 1e-8)
        {
            cout << setprecision(8) << x;
            return 0;
        }
        else if (k < 0)
        {
            // cout << 1 << "\n";
            U = x;
        }
        else
        {
            // cout << 2 << "\n";
            L = x;
        }
        // cout << L << " " << U << " = " << x << "\n";
    }
    return 0;
}