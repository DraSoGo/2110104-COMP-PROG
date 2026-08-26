#include <bits/stdc++.h>
using namespace std;

int main()
{
    int e,w,h,m,d;
    cin >> e >> w >> h >> m >> d;
    bool j1,j2,j3;
    j1 = e>70?(w>2?1:(d>400000?1:0)):(d > 600000?1:0);
    j2 = w>3?(m>5?1:(h==1?1:0)):(h==1?(m>7?1:0):0);
    j3 = h==1?(d>300000?(m>6?1:w>2?1:0):(e>60?1:0)):(e>80?(d>500000?(w>1?1:0):0):0);
    cout << (j1+j2+j3>=2?"GUILTY":"NOT GUILTY");
    return 0;
}