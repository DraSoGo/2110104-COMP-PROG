#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

int fac(int n) {
    if (n == 0) return 1;
    return n * fac(n - 1);
}

int main()
{
    double a = M_PI * M_PI - 1.0 * pow(4.3, 2.0 / 7.0);
    double b = cbrt(11.0) + (double)fac(8) / (pow(3.0, 4) * pow(2.0, 3));

    cout << fixed << setprecision(6) << a / b;
    return 0;
}