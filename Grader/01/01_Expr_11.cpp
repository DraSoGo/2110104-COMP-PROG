#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

int fac(int n) {
    if (n == 0) return 1;
    return n * fac(n - 1);
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    double a = M_PI - (fac(10.0)/pow(8.0,8.0)) + pow(log(9.7),7.0/sqrt(71.0)-sin(40.0*M_PI/180.0));
    double b = pow(1.2,pow(2.3,1.0/3.0));
    cout << a / b;
    return 0;
}