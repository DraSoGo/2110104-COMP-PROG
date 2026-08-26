#include <bits/stdc++.h>
using namespace std;

bool sp(char c)
{
    if ((c >= '!' && c <= '/') || (c >= ':' && c <= '@') || (c >= '[' && c <= '`') || (c >= '{' && c <= '~'))
    {
        return 1;
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    while (getline(cin,s))
    {
        int co = 0;
        string ans = "";
        for (int i = 0; i < s.length(); i++)
        {
            if (sp(s[i]) && co == 0)
            {
                co++;
            }
            else if (sp(s[i]) && co == 1)
            {
                co = 0;
            }
            else if (co == 1)
            {
                ans += s[i];
            }
        }
        cout << ans << "\n";
    }
    return 0;
}