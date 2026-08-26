#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a;
    cin >> a;
    if(a <= 30)
        cout << "NOT GUILTY";
    else if(a <= 60)
        cout << "UNDER INVESTIGATION";
    else if(a <= 80)
        cout << "GUILTY";
    else
        cout << "GUILTY (SEVERE)";
    
    return 0;
}