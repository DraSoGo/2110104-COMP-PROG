#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    int n;
    cin >> s;
    s += '-';
    for (int i = 0; i < s.length(); i++)
    {
        int co = 1;
        for (int j = i+1; j < s.length(); j++)
        {
            if (s[i] == s[j])
            {
                co++;
                // cout << s[i] << " " << s[j] << " " << co << "\n";
            }
            else
            {
                cout << s[i] << " " << co << " ";
                // cout << co << " " << n << "\n";
                i = j-1;
                break;
            }
        }
    }
    
    return 0;
}