#include <bits/stdc++.h>
using namespace std;

int main()
{
    int d,r,l,co = 0;
    cin >> d >> r >> l;
    if((d+r)%2 != 0 || d < 4)
    {
        co++;
    }
    if(r*15 < d)
    {
        co++;
    }
    if(!(l >= 1 && l <= d+4))
    {
        co++;
    }
    if(co > 0)
    {
        cout << "No " << co;
    }
    else
    {
        cout << "Yes " << floor((d+r)/4.0)+1 << " " << ceil((d+r)/4.0)+1;
    }
    return 0;
}