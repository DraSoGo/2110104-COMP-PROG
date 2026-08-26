#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b,c;
    cin >> a >> b >> c;
    if (a >= 30 && b >= 50 && c < 70)
        cout << "ALL SYSTEMS STABLE";
    else
        if(a < 30)
            cout << "LOW OXYGEN\n";
        if(b < 50)
            cout << "ENGINE ERROR\n";
        if(c >= 70)
            cout << "HULL DAMAGE\n";
    return 0;
}