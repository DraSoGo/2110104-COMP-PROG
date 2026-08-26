#include <bits/stdc++.h>
using namespace std;

int F[26];
int main()
{
    string s,ans2 = "";
    char mc;
    int o = 0;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        F[s[i]-'a']++;
    }
    for (int i = 0; i < 26; i++)
    {
        if(F[i]%2 == 1)
        {
            o++;
            mc = i+'a';
        }
    }
    if (o > 1)
    {
        cout << -1;
        return 0;
    }
    for (int i = 0; i < 26; i++)
    {
        if((F[i]%2 == 0 && F[i] != 0) || F[i] > 1)
        {
             for (int j = 0; j < F[i]/2; j++)
             {
                ans2 += i+'a';
             }
        }
    }
    // cout << mc << "\n";
    string ans2_2 = ans2;
    if (o == 1)
    {
        ans2+=mc;
    }
    reverse(ans2_2.begin(),ans2_2.end());
    ans2 += ans2_2;
    int l = 0,r = s.length()-1,ans1 = 0;
    while (l < r)
    {
        if (s[l] == s[r])
        {
            l++;
            r--;
        }
        else
        {
            int k = r;
            while (k > l && s[k] != s[l])
            {
                k--;
            }
            if (k == l)
            {
                swap(s[l],s[l+1]);
                ans1++;
            }
            else
            {
                for (int i = k; i < r; i++)
                {
                    swap(s[i],s[i+1]);
                    ans1++;
                }
                l++;
                r--;
            }
        }
        // cout << l << " " << r << "\n";
    }
    
    cout << ans1 << "\n" << ans2;
    return 0;
}
