#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,x,p = 2;
    cin >> n;
    x = n;
    bool ch1 = 1;
    for (int i = 2; i*i <= x; i++)
    {
        if (x % i == 0)
        {
            ch1 = 0;
        }
    }
    if (ch1)
    {
        cout << x;
        return 0;
    }
    while (n != 1)
    {
        // cout << p << "\n";
        if (n % p == 0)
        {
            n/=p;
            cout << p;
            if (n != 1)
            {
                cout << '*';
            }
        }
        else
        {
            for (int i = p+1; i < x; i++)
            {
                // cout << i;
                bool s = 1;
                for (int j = 2; j*j <= i; j++)
                {
                    if (i % j == 0)
                    {
                        s = 0;
                        break;
                    }
                }
                if (s)
                {
                    p = i;
                    break;
                }
            }
        }
    }
    return 0;
}