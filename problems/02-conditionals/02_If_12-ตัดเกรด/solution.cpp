#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    double x;
    cin >> x;
    if (x >= 80)
    {
        cout << "A";
    }
    else if (x >= 70)
    {
        cout << "B";
    }
    else if (x >= 60)
    {
        cout << "C";
    }
    else if (x >= 50)
    {
        cout << "D";
    }
    else
    {
        cout << "F";
    }
        
    return 0;
}