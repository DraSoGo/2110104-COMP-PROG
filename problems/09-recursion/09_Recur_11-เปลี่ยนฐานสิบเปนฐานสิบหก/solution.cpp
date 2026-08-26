#include <bits/stdc++.h>
using namespace std;

string dec2hex(int d)
{
    if (d < 16)
    {
        string tmp = "";
        tmp += d <= 9 ? d+'0': d-10+'A';
        return tmp;
    }
    return dec2hex(d/16) + dec2hex(d%16);
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int d;
    while (cin >> d)
    {
        cout << d << " -> " << dec2hex(d) << endl;
    }
    return 0;
}