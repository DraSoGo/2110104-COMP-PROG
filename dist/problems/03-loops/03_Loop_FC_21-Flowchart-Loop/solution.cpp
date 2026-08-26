#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    float p,k = 1,t = 1;
    cin >> p;
    t = (t*(365-(k-1)))/365;
    while (!(1-t >= p))
    {
        k++;
        t = (t*(365-(k-1)))/365;
    }
    cout << k;
    return 0;
}