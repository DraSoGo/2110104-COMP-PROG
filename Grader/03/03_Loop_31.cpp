#include <bits/stdc++.h>
using namespace std;

long long poww(long long x,long long y)
{
    long long tmp = x;
    for (int i = 0; i < y-1; i++)
    {
        x*=tmp;
    }
    return x;
}

int dig(long long x)
{
    if (x == 0)
    {
        return 1;
    }
    return floor(log10(x))+1;
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n,m;
    cin >> n >> m;
    long long a = n,b = m,da = dig(n),db = dig(m),sum = 0;
    if (da == db)
    {
        sum += (b-a)*da;
        a = b;
    }
    else
    {
        sum += (poww(10,da)-a)*da;
        a = poww(10,da);
    }
    // cout << a << " " << sum << "\n";
    da++;
    while (a < poww(10,db-1))
    {
        a = a*10;
        sum += (poww(10,da)-poww(10,da-1))*(da);
        da++;
        // cout << a << " " << sum << "\n";
    }
    sum += (b-a)*db;
    // cout << a << " " << sum << "\n";
    cout << sum+db;
    return 0;
}