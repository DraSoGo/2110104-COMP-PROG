#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long s,k,d,e,ns,i = 0;
    cin >> s >> k >> d >> e;
    if(s >= e)
    {
        cout << 0;
        return 0;
    }
    while(1)
    {
        ns = k-i*d;
        if(ns <= 0)
        {
            cout << "Give Up";
            break;
        }
        s += ns;
        i++;
        // cout << ns << " " << s << " " << i << "\n";
        if(s >= e)
        {
            cout << i;
            break;
        }
    }
    return 0;
}
