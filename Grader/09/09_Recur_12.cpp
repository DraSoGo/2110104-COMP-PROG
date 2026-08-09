#include <bits/stdc++.h>
using namespace std;

long long solve(long long a,long long k,long long m)
{
    if (k == 0)
    {
        return 1;
    }
    long long h = solve(a,k/2,m);
    long long hs = h*h%m;
    if (k % 2 == 0)
    {
        return hs;
    }
    return a*hs%m;
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long a,b,c;
    cin >> a >> b >> c;
    cout << solve(a,b,c);
    return 0;
}