#include <bits/stdc++.h>
using namespace std;

string one[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
                 "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
string ten[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
string big[] = {"", "thousand", "million", "billion", "trillion"};

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n;
    string ans;
    cin >> n;
    if (n == 0)
    {
        cout << "zero";
        return 0;
    }
    vector <int> G;
    while (n > 0)
    {
        G.push_back(n%1000);
        // cout << n%1000 << " ";
        n/=1000;
    }
    for (int i = G.size()-1; i >= 0; i--)
    {
        if (G[i] == 0)
        {
            continue;
        }
        if (!ans.empty())
        {
            ans += " ";
        }
        if (G[i] >= 100)
        {
            ans += one[G[i]/100] + " hundred";
            G[i]%=100;
            if (G[i] > 0)
            {
                ans += " ";
            }
            
        }
        if (G[i] >= 20)
        {
            ans += ten[G[i]/10];
            G[i] = G[i] % 10;
            if (G[i] % 10 > 0)
            {
                ans += " " + one[G[i] % 10];
            }
        }
        else if (G[i] > 0)
        {
            ans += one[G[i]];
        }
        if (i > 0)
        {
            ans += " " + big[i];
        }
        
    }
    cout << ans;
    return 0;
}