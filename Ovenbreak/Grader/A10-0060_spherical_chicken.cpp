#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    double par = 6+7*log(pow(n+1.0,1.2));
    double rad = par/2;
    double vol = 4.0/3.0*M_PI*pow(rad,3);
    cout << fixed << setprecision(2) << vol;
    return 0;
}