#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a,b,c;
    cin >> a >> b >> c;
    int x = stoi(b+c)-stoi(b);
    string tmp;
    for(int i=0;i<c.length();i++)
    {
        tmp += '9';
    }
    for(int i=0;i<b.length();i++)
    {
        tmp += '0';
    }
    // cout << tmp;
    int y = stoi(tmp);
    x += y*stoi(a);
    int k = __gcd(x,y);
    x/=k;
    y/=k;
    cout << x << " / " << y;
    return 0;
}