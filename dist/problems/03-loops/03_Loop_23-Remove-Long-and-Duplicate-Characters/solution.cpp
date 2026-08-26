#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    int n;
    cin >> s >> n;
    s += '-';
    for (int i = 0; i < s.length(); i++)
    {
        // cout << i << "\n";
        int co = 1;
        for (int j = i+1; j < s.length(); j++)
        {
            // cout << s[i] << " " << s[j] << " " << co << "\n";
            if (s[i] == s[j])
            {
                co++;
                // cout << s[i] << " " << s[j] << " " << co << "\n";
            }
            else
            {
                // cout << co << " " << n << "\n";
                if (co < n)
                {
                    cout << s.substr(i,co);
                }
                i = j-1;
                break;
            }
        }
    }
    
    return 0;
}