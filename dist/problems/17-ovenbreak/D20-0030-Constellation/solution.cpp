#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s[3][5] = {{"k\\=/k","k/k\\k","k=k=k","/kkk\\","\\k=k/"},{"k=k=k","=k=k=","k=k=k","kkkkk","k=k=k"},{"k/=\\k","k\\k/k","k=k=k","\\kkk/","/=k=\\"}};
    int n,a,x;
    cin >> n >> x;
    int A[x];
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < x;j++)
        {
            cin >> a;
            A[j] = a;
        }
        for(int j = 0;j < 3;j++)
        {
            for(int k = 0;k < x;k++)
            {
                // cout << j << " " << A[k]-1 << "|";
                cout << s[j][A[k]-1];
                if(k != x-1)
                {
                    cout << "|";
                }
            }
            cout << "\n";
        }
        if(i != n-1)
        {
            for(int j = 0;j < x;j++)
            {
                cout << "=====";
                if(j != x-1)
                {
                    cout << "|";
                }
            }
            cout << "\n";
        }
    }
    return 0;
}
