#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int sum = 0;
    for(int i=0;i<s.length();i++)
    {
        sum += (s[i]-'0')*(13-i);
        // cout << i << " " << 13-i << "\n";
    }
    int n12 = (11-(sum)%11)%10;
    for(int i=0;i<s.length();i++)
    {
        cout << s[i];
        if(i==0 || i==4 || i==9)
        {
            cout << "-";
        }
    }
    cout << "-" << n12;
    return 0;
}