#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    double L = 0,U,a,x;
    cin >> a;
    U = 10;
    while (L <= U)
    {
        x = (U+L)/2.0;
        if (abs(a-pow(10,x)) <= 10e-10*(max(a,pow(10,x))))
        {
            cout << x;
            return 0;
        }
        else if (pow(10,x) > a)
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