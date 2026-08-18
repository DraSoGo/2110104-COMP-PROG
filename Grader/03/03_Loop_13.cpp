#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string pat,s;
    int ans = 0;
    // cin >> pat;
    getline(cin,pat);
    getline(cin,s);
    s += "-";
    // cout << pat << " " << s;
    for (int i = 0; i < s.length()-pat.length()+1; i++)
    {
        string tmp = s.substr(i,pat.length());
        // cout << tmp << "\n";
        if (pat == tmp)
        {
            cout << i << "\n";
            ans++;
            // i += pat.length();
        }
    }
    cout << ans;
    return 0;
}