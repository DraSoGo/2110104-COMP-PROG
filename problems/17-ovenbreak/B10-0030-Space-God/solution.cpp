#include <bits/stdc++.h>
using namespace std;

int main()
{
    double a,b;
    cin >> a >> b;
    double x = (a/b)*100.0;
    // cout << x << " ";
    if (x < 0 || x > 100)
    {
        cout << "Invalid!";
        return 0;
    }
    if(x <= 10)
        cout << "Very weak";
    else if(x <= 30)
        cout << "Normal";
    else if(x <= 50)
        cout << "Acceptable";
    else if(x <= 80)
        cout << "Interesting";
    else
        cout << "Remarkable";
    return 0;
}