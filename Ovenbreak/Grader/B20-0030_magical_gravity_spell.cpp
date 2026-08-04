#include <bits/stdc++.h>
using namespace std;

int main()
{
    char a,b,x,y;
    cin >> a >> b >> x >> y;

    if(a <= b)
    {
        if(x <= y)
        {
            cout << ((x >= a && x <= b) || (y >= a && y <= b) || (a >= x && a <= y) || (b >= x && b <= y) ? "bad" : "good");
        }
        if(x > y)
        {
            cout << ((a >= x || a <= y) || (b >= x || b <= y) || (x >= a && x <= b) || (y >= a && y <= b) ? "bad" : "good");
        }
    }
    else
    {
        if(x <= y)
        {
            cout << ((x >= a || x <= b) || (y >= a || y <= b) || (a >= x && a <= y) || (b >= x && b <= y) ? "bad" : "good");
        }
        if(x > y)
        {
            cout << ((a >= x || a <= y) || (b >= x || b <= y) || (x >= a || x <= b) || (y >= a || y <= b) ? "bad" : "good");
        }
    }
    return 0;
}