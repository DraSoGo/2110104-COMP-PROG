#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    if(n > 0)
    {
        cout << "positive\n";
    }
    else if(n < 0)
    {
        cout << "negative\n";
    }
    else
    {
        cout << "zero\n";
    }
    if(n % 2 == 0)
    {
        cout << "even";
    }
    else
    {
        cout << "odd";
    }
    
    return 0;
}