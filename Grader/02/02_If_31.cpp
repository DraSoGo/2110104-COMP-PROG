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
    int d,m,y,ed,em,ey;
    double sum = 0;
    int M[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    cin >> d >> m >> y >> ed >> em >> ey;
    for (int i = m-1; i < 12; i++)
    {
        sum += M[i];
        if (i == 1 && lp_y(y))
        {
            // cout << "+1\n";
            sum++;
        }
    }
    sum -= d-1;
    // cout << sum << "\n";
    sum += (ey-y-1)*365;
    // cout << sum << "\n";
    for (int i = 0; i < em-1; i++)
    {
        sum += M[i];
        if (i == 1 && lp_y(ey))
        {
            sum++;
        }
    }
    sum += ed-1;
    cout << sum << " " << round(sin((2.0*M_PI*sum)/23.0)*100.0)/100.0 << " " << round(sin((2.0*M_PI*sum)/28.0)*100.0)/100.0 << " " << round(sin((2.0*M_PI*sum)/33.0)*100.0)/100.0;
    return 0;
}