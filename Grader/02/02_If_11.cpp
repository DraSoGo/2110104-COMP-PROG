#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    cin >> s;
    if(s.length() > 2 || !(s[0] >= '0' && s[0] <= '9') || !(s[1] >= '0' && s[1] <= '9'))
    {
        cout << "Error";
        return 0;
    }
    if(!(s == "01" || s == "02" || s == "51" || s == "53" || s == "55" || s == "58" || (stoi(s) >= 20 && stoi(s) <= 40)))
    {
        cout << "Error";
        return 0;
    }
    cout << "OK";
    return 0;
}