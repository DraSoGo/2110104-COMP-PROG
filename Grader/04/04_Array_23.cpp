#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string tmp;
    getline(cin,tmp);
    int n = stoi(tmp),co = 0,sum = 0;
    string A[n][2],L[100000];
    for (int i = 0; i < n; i++)
    {
        getline(cin,tmp);
        A[i][0] = tmp.substr(0,tmp.find(' '));
        A[i][1] = tmp.substr(tmp.find(' ')+1,tmp.length()-tmp.find(' '));
        // cout << A[i][0] << " " << A[i][1] << "\n";
    }
    getline(cin,tmp);
    tmp += ' ';
    for (int i = 0; i < tmp.length(); i++)
    {
        if (tmp[i] == '-')
        {
            L[co] = tmp.substr(i+1,tmp.find(' ',i)-i-1);
            co++;
            // cout << i << " " << tmp.find(' ',i)-i-1 << " " << tmp.substr(i+1,tmp.find(' ',i)-i-1) << "\n";
        }
    }
    for (int i = 1; i < co; i++)
    {
        if (L[i] != L[i-1])
        {
            for (int j = 0; j < n; j++)
            {
                if (A[j][0] == L[i])
                {
                    sum += stoi(A[j][1]);
                    break;
                }
            }
        }
    }
    cout << sum;
    return 0;
}