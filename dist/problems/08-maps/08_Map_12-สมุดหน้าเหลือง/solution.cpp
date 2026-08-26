#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    string a,b;
    map <string,string> M;
    getline(cin,a);
    n = stoi(a);
    while (n--)
    {
        getline(cin,a);
        for (int i = 0; i < a.length(); i++)
        {
            if (isdigit(a[i]))
            {
                b = a.substr(i,a.length()-i);
                a = a.substr(0,i-1);
                break;
            }
        }
        // cout << a << " " << b << "\n";
        M[a] = b;
    }
    getline(cin,a);
    m = stoi(a);
    while (m--)
    {
        getline(cin,a);
        bool ch = 1;
        for(auto[i,j]:M)
        {
            if (a == i)
            {
                cout << i << " --> " << j << "\n";
                ch = 0;
                break;
            }
            else if (a == j)
            {
                cout << j << " --> " << i << "\n";
                ch = 0;
                break;
            }
        }
        if(ch)
        {
            cout << a << " --> " << "Not found\n";
        }
    }
    return 0;
}