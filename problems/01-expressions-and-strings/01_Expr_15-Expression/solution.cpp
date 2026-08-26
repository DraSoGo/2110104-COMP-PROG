#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    double x;
    cin >> x;
    double y = (pow(x,sqrt(log((x+1)*(x+1)))))/(10.0-x);
    cout << round(y*1e6)/1e6;
    return 0;
}