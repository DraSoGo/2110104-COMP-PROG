#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string tmp;
    int n,co = 0;
    getline(cin,tmp);
    n = stoi(tmp);
    string C[n];
    getline(cin,tmp);
    string s = "";
    for (int i = 0; i < tmp.length(); i++)
    {
        if (tmp[i] == ' ')
        {
            C[co] = s;
            s = "";
            co++;
            continue;
        }
        s += tmp[i];
    }
    C[co] = s;
    co++;
    getline(cin,tmp);
    for (int i = 0; i < tmp.length(); i++)
    {
        string A[n/2],B[n/2];
        for (int j = 0; j < n; j++)
        {
            if (j < n/2)
            {
                A[j] = C[j];
            }
            else
            {
                B[j-n/2] = C[j];
            }
        }
        // for (int j = 0; j < n/2; j++)
        // {
        //     cout << A[j] << " ";
        // }
        // cout << "\n";
        // for (int j = 0; j < n/2; j++)
        // {
        //     cout << B[j] << " ";
        // }
        
        if (tmp[i] == 'S')
        {
            for (int j = 0; j < n; j++)
            {
                if (j%2 == 0)
                {
                    C[j] = A[j/2];
                }
                else
                {
                    C[j] = B[j/2];
                }
            }
        }
        else if(tmp[i] == 'C')
        {
            for (int j = 0; j < n; j++)
            {
                if (j < n/2)
                {
                    C[j] = B[j];
                }
                else
                {
                    C[j] = A[j-n/2];
                }
            }
        }
    }
    for (int j = 0; j < n; j++)
    {
        cout << C[j] << " ";
    }
    
    
    return 0;
}