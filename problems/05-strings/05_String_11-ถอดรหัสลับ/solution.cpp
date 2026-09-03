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
        char c = s[s.length()-1];
        string ans = "";
        for (int i = 0; i < s.length(); i++)
        {
            // cout << i << " " << s[i] << " " << co << " : ";
            if (s[i] == c)
            {
                i++;
                while (1 && i < s.length())
                {
                    if (s[i] == c)
                    {
                        break;
                    }
                    ans += s[i];
                    i++;
                }
            }
            // cout << '\n';
        }
        cout << ans << "\n";
        k++;
    }
    return 0;
}