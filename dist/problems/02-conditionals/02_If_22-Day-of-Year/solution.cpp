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
    for (int i = 0; i < m-1; i++)
    {
        sum += M[i];
        if (i == 1 && lp_y(y))
        {
            sum++;
        }
    }
    sum += d;
    cout << sum;
    return 0;
}