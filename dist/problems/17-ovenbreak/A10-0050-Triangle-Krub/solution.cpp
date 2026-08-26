#include <bits/stdc++.h>
#include <cmath>
using namespace std;
int main()
{
    double a,b,c;
    cin >> a >> b >> c;
    double S = (a+b+c)/2;
    cout << fixed << setprecision(4) << a + b + c << '\n';
    cout << fixed << setprecision(4) << sqrt(S*(S-a)*(S-b)*(S-c)) << '\n';
    double A = acos((b*b+c*c-a*a)/(2*b*c));
    double B = acos((a*a+c*c-b*b)/(2*a*c));
    double C = acos((a*a+b*b-c*c)/(2*a*b));
    cout << fixed << setprecision(4) << (min(A,min(B,C)))*180/M_PI;
    return 0;
}