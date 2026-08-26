#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    double x,sum = 0,n = 0;
    while (1)
    {
        cin >> x;
        if (x == -1)
        {
            break;
        }
        sum += x;
        n++;
    }
    if (n == 0)
    {
        cout << "No Data";
        return 0;
    }
    cout << round((sum/n)*100.0)/100.0;
    return 0;
}