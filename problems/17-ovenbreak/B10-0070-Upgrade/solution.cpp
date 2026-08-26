#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,x,y;
    cin >> a;
    x = a/5;
    y = a%5;
    if (y == 1)
        cout << "+";
    else if (y == 2)
        cout << "-";
    else if (y == 3)
        cout << "*";
    else if (y == 4)
        cout << "/";
    else if (y == 0)
    {
        while(x > 26)
        {
            x -= 26;
        }
        cout << char(x+'A'-1);
    }
    return 0;
}