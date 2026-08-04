#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    double x1,y1,r1,x2,y2,r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    double d = sqrt(pow(x1-x2,2)+pow(y1-y2,2)),r = r2+r1;
    if (d == 0 && r1 == r2)
    {
        cout << "infinity" << "\n" << "yes";
        return 0;
    }
    if (d+r1 < r2 || d+r2 < r1)
    {
        cout << 0 << "\n" << "yes";
        return 0;
    }
    if (d+r1 == r2 || d+r2 == r1)
    {
        cout << 1 << "\n" << "yes";
        return 0;
    }
    if (d > r)
    {
        cout << 0 << "\n" << "no";
        return 0;
    }
    if (d == r)
    {
        cout << 1 << "\n" << "no";
        return 0;
    }
    if (d < r)
    {
        cout << 2 << "\n" << "yes";
        return 0;
    }
    // cout << 1 << "\n" << "no";
    
    
    return 0;
}