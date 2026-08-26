#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    double a,b,c;
    cin >> a >> b >> c;
    double x1 = (-b - sqrt(pow(b,2.0) - 4.0*a*c))/(2*a);
    double x2 = (-b + sqrt(pow(b,2.0) - 4.0*a*c))/(2*a);
    cout << round(x1*1e3)/1e3 << " " << round(x2*1e3)/1e3;
    return 0;
}