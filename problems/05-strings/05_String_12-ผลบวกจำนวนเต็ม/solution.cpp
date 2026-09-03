#include <bits/stdc++.h>
using namespace std;

string add(string a,string b)
{
    string sum = "",mx,mn;
    bool t = 0;
    if (a.length() > b.length())
    {
        mx = a;
        mn = b;
    }
    else
    {
        mx = b;
        mn = a;
    }
    // cout << mx.length()-mn.length() << "\n";
    int k = mx.length()-mn.length();
    mn = string(k, '0') + mn;
    // cout << mx << " " << mn << "\n";
    for (int i = mx.length()-1; i >= 0; i--)
    {
        int cal;
        cal = (mx[i]-'0')+(mn[i]-'0')+t;
        t = cal/10;
        cal %= 10;
        // cout << mx[i]-'0' << " " << mn[i]-'0' << " " << cal << "\n";
        sum += char(cal+'0');
    }
    sum = t?sum + "1":sum;
    reverse(sum.begin(),sum.end());
    // cout << sum << "\n";
    return sum;
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string sum,x;
    cin >> sum;
    while (x != "END")
    {
        cin >> x;
        if (x == "END")
        {
            break;
        }
        sum = add(sum,x);
    }
    // reverse(sum.begin(),sum.end());
    cout << sum;
    return 0;
}