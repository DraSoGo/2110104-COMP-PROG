#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string p1,p2;
    double g1,g2;
    char cp1,cp2,c11,c12,c21,c22;
    bool r1 = 0,r2 = 0;
    cin >> p1 >> g1 >> cp1 >> c11 >> c21;
    cin >> p2 >> g2 >> cp2 >> c12 >> c22;
    if (cp1 <= 'A' && c11 <= 'C' && c21 <= 'C' )
    {
        r1 = 1;
    }
    if (cp2 <= 'A' && c12 <= 'C' && c22 <= 'C' )
    {
        r2 = 1;
    }
    if (r1 == 0 && r2 == 0)
    {
        cout << "None";
    }
    else if (r1 == 1 && r2 == 0)
    {
        cout << p1;
    }
    else if (r1 == 0 && r2 == 1)
    {
        cout << p2;
    }
    else if (g1 > g2)
    {
        cout << p1;
    }
    else if (g1 < g2)
    {
        cout << p2;
    }
    else if (c11 > c12)
    {
        cout << p2;
    }
    else if (c11 < c12)
    {
        cout << p1;
    }
    else if (c21 > c22)
    {
        cout << p2;
    }
    else if (c21 < c22)
    {
        cout << p1;
    }
    else
    {
        cout << "Both";
    }
    
    return 0;
}