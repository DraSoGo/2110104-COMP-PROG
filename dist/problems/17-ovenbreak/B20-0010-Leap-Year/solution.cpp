#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    c = c - 543;
    int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(c % 4 == 0 && (c % 100 != 0 || c % 400 == 0))
    {
        month[1] += 1;
    }
    int day = 0;
    day += month[b-1]-a;
    // cout << day << " ";
    for (int i = b; i < 12; i++)
    {
        day += month[i];
        // cout << month[i] << " ";
    }
    // cout << "\n";
    cout << day << endl;
    return 0;
}