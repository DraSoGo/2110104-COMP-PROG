#include <bits/stdc++.h>
using namespace std;
int main()
{
    double xe,ye,re,rp,xm,ym;
    cin >> xe >> ye >> re >> rp >> xm >> ym;
    double a,b,c,A,B,C;
    c = re-rp;
    C = sqrt(pow(xe-xm,2.0)+pow(ye-ym,2.0));
    A = xm-xe;
    B = ym-ye;
    a = c*A/C;
    b = c*B/C;
    // cout << a << " " << b << " " << c << " " << A << " " << B << " " << C << "\n";
    cout << round(xe+a) << " " << round(ye+b);
    return 0;
}