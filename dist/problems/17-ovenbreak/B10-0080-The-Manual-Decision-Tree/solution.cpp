#include <bits/stdc++.h>
using namespace std;

int main()
{
    int d,s;
    cin >> d >> s;
    cout << "DT Action: ";
    if(d <= 500)
    {
        if(s<=30)
        {
            cout << "IGNORE";
        }
        else
        {
            cout << "SHOOT";
        }
    }
    else
    {
        if(s <= 100)
        {
            cout << "REFLECT";
        }
        else
        {
            cout << "WARP_EVADE";
        }
    }
    return 0;
}