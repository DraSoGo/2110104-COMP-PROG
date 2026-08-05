#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

bool lp_y(int y)
{
    y -= 543;
    // cout << y << "\n";
    if (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0))
    {
        return 1;
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int d,m,y,sum = 0;
    int M[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    cin >> d >> m >> y;
    if (lp_y(y))
    {
        M[1]++;
    }
    d += 15;
    if (d > M[m-1])
    {
        d -= M[m-1];
        m++;
    }
    if (m > 12)
    {
        y++;
        m = 1;
    }
    cout << d << "/" << m << "/" << y;
    return 0;
}