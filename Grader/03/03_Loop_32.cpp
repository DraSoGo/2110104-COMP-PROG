#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string n;
    getline(cin,n);
    int k = stoi(n);
    while (k--)
    {
        string s,tmp = "";
        getline(cin,s);
        if (s.length() == 1)
        {
            if (s[0] == 'R')
            {
                cout << 1;
            }
            else
            {
                cout << "WRONG_INPUT";
            }
            cout << "\n";
            continue;
        }
        int sum = 0;
        for (int i = 0; i < s.length(); i+=2)
        {
            tmp += s[i];
            sum += s[i] == 'R'?1:s[i] == 'Y'?2:s[i] == 'G'?3:s[i] == 'N'?4:s[i] == 'B'?5:s[i] == 'P'?6:7;
        }
        s = tmp;
        bool c = 1;
        for (int i = 1; i < s.length(); i++)
        {
            if ((s[i] == 'R' && i%2 == 1) || (((s[i-1] != 'R' && s[i] != 'R') && (s.substr(i,s.length()-i) != "Y" && s.substr(i,s.length()-i) != "YG" && s.substr(i,s.length()-i) != "YGN" && s.substr(i,s.length()-i) != "YGNB" && s.substr(i,s.length()-i) != "YGNBP" && s.substr(i,s.length()-i) != "YGNBPK"))))
            {
                // cout << i << " " << (s[i] == 'R' && i%2 == 1) << " " << (s[i-1] != 'R' && s[i] != 'R') << " " << s.substr(i,s.length()-i) << " ";
                cout << "WRONG_INPUT";
                c = 0;
                break;
            }
            if (s[i-1] != 'R' && s[i] != 'R')
            {
                break;
            }
            
        }
        if (c)
        {
            cout << sum;
        }
        cout << "\n";
    }
    return 0;
}