#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string x,y;
    while (cin >> x,cin >> y)
    {
        string ans,pat = "";
        int co = 0;
        int a = x[x.length()-1]-'0',b = (a*a)%10,tmp = a,n = stoi(y.substr(max(int(y.length()-2),0),2));
        if (n == 0 && y.length() == 1)
        {
            cout << ">> 1" << "\n";
            continue;
        }
        pat += tmp+'0';
        tmp *= a;
        while (b+'0' != pat[0])
        {
            co++;
            pat += b+'0';
            tmp *= a;
            b = tmp%10;
        }
        pat = pat[pat.length()-1] + pat.substr(0,pat.length()-1);
        cout << ">> " << pat[n%pat.size()] << "\n";
        // cout << a << " " << n << " " << ">> " << int(pow(a,n))%10 << "\n";
    }
    return 0;
}