#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

int main()
{
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