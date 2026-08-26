#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    if (n <= 100)
    {
        cout << 18;
    }
    else if (n <= 250)
    {
        cout << 22;
    }
    else if (n <= 500)
    {
        cout << 28;
    }
    else if (n <= 1000)
    {
        cout << 38;
    }
    else if (n <= 2000)
    {
        cout << 58;
    }
    else
    {
        cout << "Reject";
    }
    
    
    return 0;
}