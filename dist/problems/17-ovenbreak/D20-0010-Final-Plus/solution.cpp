#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a,b;
    cin >> a >> b;
    char A[10];
    long long B[10];
    memset(B,0,sizeof(B));
    for(long long i = 0; i < 10; i++)
    {
        cin >> A[i];
    }
    for(long long i = 0; i < a.length(); i++)
    {
        a[i] = A[a[i]-'0'];
    }
    for(long long i = 0; i < b.length(); i++)
    {
        b[i] = A[b[i]-'0'];
    }
    // cout << a << " " << b << "\n";
    string c;
    long long mx = INT_MIN,co = 1,d;
    string tmp = "";
    bool fg = 0;
    for(int i = 0; i < a.length(); i++)
    {
        if(a[i] != '0' || fg)
        {
            tmp += a[i];
            fg = 1;
        }
    }
    a = tmp == ""?"0":tmp;
    tmp = "";
    fg = 0;
    for(int i = 0; i < b.length(); i++)
    {
        if(b[i] != '0' || fg)
        {
            tmp += b[i];
            fg = 1;
        }
    }
    b = tmp == ""?"0":tmp;
    // cout << a << " " << b << "\n";
    int mxl = max(a.length(), b.length());
    while(a.length() < mxl) a = "0" + a;
    while(b.length() < mxl) b = "0" + b;
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    for(long long i = 0;i < b.length(); i++)
    {
        long long x = (a[i]-'0')+(b[i]-'0');
        if(x >= 10)
        {
            c += to_string(x%10);
            B[x%10]++;
            if(i != b.length()-1)
            {
                a[i+1] = (a[i+1]-'0')+1+'0';
            }
            else
            {
                c += "1";
                B[1]++;
            }
        }
        else
        {
            c += to_string(x);
            B[x]++;
        }
    }
    sort(B,B+10);
    reverse(c.begin(),c.end());
    unordered_map<long long,long long> mp;
    cout << c << "\n";
    for(long long i = 0; i < 10; i++)
    {
        cout << B[i] << " ";
        mp[B[i]]++;
    }
    for(auto i : mp)
    {
        if(i.second > co)
        {
            co = i.second;
            d = i.first;
        }
    }
    cout << "\n" << d;
    return 0;
}
