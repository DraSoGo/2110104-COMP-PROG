#include <bits/stdc++.h>
using namespace std;

int main()
{
    char c;
    double a,b;
    cin >> a >> c >> b;
    if (c=='k')
        a = a*1000.0;
    if (c=='m')
        a = a*1000000.0;
    if(a == b)
        cout << "MESSAGE RECEIVED";
    else if(b >= 0.95 * a && b <= 1.05 * a)
        cout << "PARTIAL MATCH";
    else if(b < 0.95 * a)
        cout << "SIGNAL TOO LOW";
    else
        cout << "SIGNAL TOO HIGH";
    return 0;
}