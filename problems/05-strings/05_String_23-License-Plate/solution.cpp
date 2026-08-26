#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s,n;
    int x,k,ans2;
    cin >> s >> x;
    n = s.substr(4,3);
    k = stoi(n)+x;
    ans2 = k%1000;
    k /= 1000;
    for (int i = 2; i >= 1; i--)
    {
        k += (s[i]-'A');
        s[i] = k%26+'A';
        k /= 26;
    }
    k += (s[0]-'0');
    s[0] = k+'0';
    cout << s.substr(0,4) << ans2;
    return 0;
}