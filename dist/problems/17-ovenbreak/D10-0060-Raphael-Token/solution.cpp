#include <bits/stdc++.h>
using namespace std;

int main()
{
    double x,co = 0;
    string s;
    cin >> s >> x;
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == '-' || s[i] == '_' || s[i] == ',' || s[i] == '.')
        {
            co++;
        }
    }
    cout << co+1 << " " << (co+1)*x;
    return 0;
}