#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n=4;
    double mn = INT_MAX,mx = INT_MIN,x = 0;
    double A[4];
    for (int i = 0; i < 4; i++)
    {
        cin >> A[i];
        if (A[i] > mx)
        {
            mx = A[i];
        }
        if (A[i] < mn)
        {
            mn = A[i];
        }
        x += A[i];
    }
    x -= mx+mn;
    cout << round(((x)/2)*100.0)/100.0;
    return 0;
}