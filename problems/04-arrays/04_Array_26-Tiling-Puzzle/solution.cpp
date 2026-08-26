#include <bits/stdc++.h>
using namespace std;

const int sz = 1e6+1;
int A[sz];

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    int A[n*n],r,in = 0;
    for (int i = 0; i < n*n; i++)
    {
        cin >> A[i];
        if (A[i] == 0)
        {
            r = i / n;
        }
    }
    for (int i = 0; i < n*n; i++)
    {
        for (int j = i+1; j < n*n; j++)
        {
            if (A[i] > A[j] && A[j] != 0)
            {
                // cout << A[i] << " " << A[j] << "\n";
                in++;
            }
        }
    }
    cout << r << " " << in << " " << n << "\n";
    if ((n % 2 == 1 && in % 2 == 0) || ((n % 2 == 0 && in % 2 == 1 && r % 2 == 0) || (n % 2 == 0 && in % 2 == 0 && r % 2 == 1)))
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}