#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, c, x, y, z;
    cin >> a >> b >> c >> x >> y >> z;

    int diff = abs(a - x) + abs(b - y) + abs(c - z);

    if (diff >= 100)
        cout << "BANG!!!";
    else
    {
        int s = (99 - diff) / 5;
        cout << s;
    }

    return 0;
}