#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s,a,b,l;
    getline(cin,s);
    while (getline(cin,l))
    {
        a = l[0];
        b = l.substr(2,l.length()-2);
        if (a == "E")
        {
            int n = b.length()*4,co = 0,idx = 0,ID[4];
            for (int i = 0; i < s.length(); i++)
            {
                if (isalpha(s[i]))
                {
                    co++;
                }
            }
            string tmp = s;
            while (co < n)
            {
                tmp += s[idx];
                if (isalpha(s[idx]))
                {
                    co++;
                }
                idx++;
                idx %= s.length();
            }
            string k = "";
            idx = 0;
            for (int i = 0; i < tmp.length(); i++)
            {
                if (isalpha(tmp[i]))
                {
                    k += tmp[i];
                    ID[k.size()-1] = i;
                    if (k.size() == 4)
                    {
                        int x = isdigit(b[idx])?b[idx]-'0':b[idx] == '-'?10:11;
                        // cout << x << " ";
                        for (int j = 3; j >= 0; j--)
                        {
                            x & 1 == 1?k[j] = tolower(k[j]):k[j] = toupper(k[j]);
                            x>>=1;
                        }
                        for (int j = 0; j < 4; j++)
                        {
                            tmp[ID[j]] = k[j];
                        }
                        idx++; 
                        k = "";
                    }
                }
            }
            cout << tmp;
        }
        else
        {
            string k = "";
            for (int i = 0; i < b.length(); i++)
            {
                if (isalpha(b[i]))
                {
                    k += b[i];
                    if (k.size() == 4)
                    {
                        int ans = 0;
                        char d;
                        for (int j = 0; j < 4; j++)
                        {
                            ans = (ans << 1) | (islower(k[j])?1:0);
                        }
                        d = ans < 10?(ans+'0') : ans == 10?('-'):',';
                        cout << d;
                        k = "";
                    }
                    
                }
            }
        }
        cout << "\n";
    }
    return 0;
}