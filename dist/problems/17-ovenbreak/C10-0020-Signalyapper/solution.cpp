#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,mx = INT_MIN,co = 0;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        if(a > mx)
        {
            mx = a;
            co = 1;
        }
        else if(mx == a)
        {
            co++;
        }
    }
    cout << mx << "-" << co;
    return 0;
}