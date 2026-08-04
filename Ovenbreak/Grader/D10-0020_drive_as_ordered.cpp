#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    int x = 0;
    cin >> s;
    for(int i = 0; i < s.length(); i++)
    {
        if(i % 4 == 0)
        {
            x += s[i]-'0';
        }
        else if(i % 4 == 1)
        {
            x -= s[i]-'0';
        }
        else if(i % 4 == 2)
        {
            x *= s[i]-'0';
        }
        else
        {
            x /= s[i]-'0';
        }
    }
    cout << x;
    return 0;
}
