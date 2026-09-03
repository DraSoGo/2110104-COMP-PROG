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
    int k = 0;
    while (getline(cin,s))
    {
        // cout << k << "\n";
        int co = 0,ch = 0;
        string ans = "";
        for (int i = 0; i < s.length(); i++)
        {
            // cout << i << " " << s[i] << " " << co << " : ";
            if (sp(s[i]) && co == 0)
            {
                // cout << 0;
                co = 1;
            }
            else if (sp(s[i]) && co == 1 && ch == 1)
            {
                // cout << 1;
                co = 0;
                ch = 0;
            }
            else if (co == 1 && !sp(s[i]))
            {
                // cout << 2;
                ans += s[i];
                ch = 1;
            }
            // cout << '\n';
        }
        cout << ans << "\n";
        k++;
    }
    return 0;
}