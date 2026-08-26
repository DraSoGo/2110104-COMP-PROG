#include <bits/stdc++.h>
using namespace std;

int main()
{
    double s,d,e,k;
    cin >> s >> d >> e >> k;
    for(int i = 0; i < d; i++)
    {
        s += s*(i+1);
        s *= e;
    }
    cout << fixed << setprecision(3) << s << "\n" << (s == k?"Just enough":s > k?"More than enough":s < k/2?"We're cooked":"Not enough");
    return 0;
}