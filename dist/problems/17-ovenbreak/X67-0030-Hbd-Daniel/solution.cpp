#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,s = 1,i,x;
    bool check = 0;
    string c;
    cin >> n >> m;
    i = m;
    while(1)
    {
        cin >> c;
        if(c == "PRINT")
        {
            // cout << s << " " << n << "\n";
            if(s > n)
            {
                cout << "Happy Birthday Daniel\nP\n";
                for(int j = 0;j < n;j++)
                {
                    for(int k = 0;k < j+1;k++)
                    {
                        cout << "S";
                    }
                    cout << "\n";
                }
                return 0;
            }
            s = n-s;
            for(int j = 0;j < n;j++)
            {
                for(int k = 0;k < j+1;k++)
                {
                    cout << "S";
                }
                if(j == s)
                {
                    cout << "P";
                }
                cout << "\n";
            }
            return 0;
        }
        else if(c == "UP")
        {
            cin >> x;
            if(check)
            {
                continue;
            }
            for (int j = s; x > 0; x--)
            {
                i -= j;
                if (i <= 0)
                {
                    i = m+5;
                    m = i;
                    s = 1;
                    j = s;
                }
                else
                {
                    j++;
                    s++;
                }
                if (s > n)
                {
                    check = 1;
                    break;
                }
                // cout << i << " " << s << "\n";
            }
        }
        else if(c == "REST")
        {
            cin >> x;
            if(check)
            {
                continue;
            }
            i = min((i+5*x),m);
            // cout << i << " " << s << "\n";
        }
    }
    return 0;
}
