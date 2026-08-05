#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    if (a > b)
    {
        swap(a,b);
        if (d >= a)
        {
            if (c > d)
            {
                c = c-a;
            }
        }
        else
        {
            c = c + a;
        }
        b = a+c+d;
    }
    else
    {
        if (c > a && a >= b)
        {
            d = d + a;
        }
        if (d > c)
        {
            b = b + 2;
        }
        else
        {
            b = 2 * b;
        }
    }
    cout << a << " " << b << " " << c << " " << d;
    return 0;
}