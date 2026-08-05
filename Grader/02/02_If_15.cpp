#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    cin >> s;
    string f = s.substr(0,2);
    if (!(s.length() == 10 && (f == "06" || f == "08" || f == "09")))
    {
        cout << "Not a mobile number";
        return 0;
    }
    cout << "Mobile number";
    
    return 0;
}