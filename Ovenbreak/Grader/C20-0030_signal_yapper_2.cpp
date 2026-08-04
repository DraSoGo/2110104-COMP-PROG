#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c,x;
    cin >> a >> b >> c;
    // cin >> x;
    int sum = 0;
    // sum -= 1;
    while(1)
    {
        cin >> x;
        if(x == -1)
        {
            break;
        }
        if(x == c)
        {
            cout << sum << " ";
            sum = 0;
            // cout << "c" << ": " << x << " " << sum << "\n";
            continue;
        }
        if(x == b)
        {
            // cout << "b" << ": " << x << " " << sum << "\n";
            cout << sum << " ";
            sum = x;
            sum -= 1;
            continue;
        }
        sum += x;
        if(sum > a)
        {
            // cout << "a" << ": " << x << " " << sum << " " << sum-x << "\n";
            cout << sum-x << " ";
            sum = x;
        }
        sum -= 1;
    }
    cout << sum;
    return 0;
}
