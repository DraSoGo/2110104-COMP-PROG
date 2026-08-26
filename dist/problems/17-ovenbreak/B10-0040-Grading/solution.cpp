#include <bits/stdc++.h>
using namespace std;

int main()
{
    double x;
    cin >> x;
    // cout << x << " ";
    if (x < 0 || x > 100)
    {
        cout << "Invalid Score";
        return 0;
    }
    if(x < 50)
        cout << "F";
    else if(x < 60)
        cout << "D";
    else if(x < 70)
        cout << "C";
    else if(x < 80)
        cout << "B";
    else
        cout << "A";
    return 0;
}