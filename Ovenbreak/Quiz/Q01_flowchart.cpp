#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int a,b,c;
    cin >> a >> b >> c;
    if (a > 100)
    {
        while (1)
        {
            if (b > c)
            {
                if (b%2 == 0)
                {
                    a = a+b;
                    c = c+2;
                }
                else
                {
                    a = a-c;
                    b = b+3;
                }
            }
            else
            {
                c = c+10;
                a = a-5;
            }
            if (a % 5 == 0)
            {
                b = b-1;
            }
            else
            {
                c = c+1;
            }
            if (!(a <= 3*abs(b+c)))
            {
                break;
            }
        }
    }
    else
    {
        if (a < b)
        {
            if (c % 3 == 0)
            {
                a = a*2;
                b = b-1;
            }
            else
            {
                a = a+b;
                c = c*2;
            }
        }
        else
        {
            a = a+b;
            c = c*2;
        }
        if (b < c)
        {
            b = b+c;
            a = a+1;
        }
        else
        {
            c = c-b;
            a = a-2;
        }
        
    }
    cout << a << "\n" << b << "\n" << c;
    return 0;
}