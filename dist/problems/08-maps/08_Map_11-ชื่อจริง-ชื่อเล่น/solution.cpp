#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    string a,b;
    map <string,string> M;
    cin >> n;
    while (n--)
    {
        cin >> a >> b;
        M[a] = b;
    }
    cin >> m;
    while (m--)
    {
        cin >> a;
        bool ch = 1;
        for(auto[i,j]:M)
        {
            if (a == i)
            {
                cout << j << "\n";
                ch = 0;
                break;
            }
            else if (a == j)
            {
                cout << i << "\n";
                ch = 0;
                break;
            }
        }
        if(ch)
        {
            cout << "Not found\n";
        }
    }
    return 0;
}