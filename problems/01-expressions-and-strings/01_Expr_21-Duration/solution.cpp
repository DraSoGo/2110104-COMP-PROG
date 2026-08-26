#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int h1, m1, s1, h2, m2, s2;
    cin >> h1 >> m1 >> s1;
    cin >> h2 >> m2 >> s2;
    int t1 = h1 * 60 * 60 + m1 * 60 + s1;
    int t2 = h2 * 60 * 60 + m2 * 60 + s2;
    int dh, dm, ds;
    ds = t2 - t1;
    ds >= 0 ? ds : ds = ds + 24 * 60 * 60;
    dh = ds / (60 * 60);
    ds -= dh * 60 * 60;
    dm = ds / 60;
    ds -= dm * 60;
    cout << dh << ':' << dm << ':' << ds;
    return 0;
}