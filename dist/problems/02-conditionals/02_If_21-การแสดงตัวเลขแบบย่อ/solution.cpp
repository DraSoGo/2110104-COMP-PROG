#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
#define B 1000000000
#define M 1000000
#define K 1000

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    double n;
    cin >> n;
    if (n > B)
    {
        if (n/B < 10)
        {
            cout << round(n/B*10)/10.0 << "B";
        }
        else
        {
            cout << round(n/B) << "B";
        }
    }
    else if (n > M)
    {
        if (n/M < 10)
        {
            cout << round(n/M*10)/10.0 << "M";
        }
        else
        {
            cout << round(n/M) << "M";
        }
    }
    else if (n > K)
    {
        if (n/K < 10)
        {
            cout << round(n/K*10)/10.0 << "K";
        }
        else
        {
            cout << round(n/K) << "K";
        }
    }
    else
    {
        cout << n;
    }
    
    return 0;
}