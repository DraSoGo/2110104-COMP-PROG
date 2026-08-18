#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string pat,s = "-",x;
    int ans = 0;
    // cin >> pat;
    getline(cin,pat);
    getline(cin,x);
    s += x;
    s += "-";
    // cout << pat << " " << s;
    for (int i = 1; i < s.length()-pat.length()+1; i++)
    {
        string tmp = s.substr(i,pat.length());
        // cout << tmp << "\n";
        if (pat == tmp && !isalpha(s[i-1]) && !isalpha(s[i+pat.length()]))
        {
            // cout << i << "\n";
            ans++;
            // i += pat.length();
        }
    }
    cout << ans;
    return 0;
}