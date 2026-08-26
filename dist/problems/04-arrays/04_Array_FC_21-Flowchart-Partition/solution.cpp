#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    int d[n];
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
    }
    int p = d[n-1],i = -1,j = 0;
    while (j < n-1)
    {
        if (d[j] <= p)
        {
            i++;
            swap(d[i],d[j]);
        }
        j++;
    }
    swap(d[i+1],d[n-1]);
    cout << "[";
    for (int i = 0; i < n; i++)
    {
        cout << d[i];
        if (i != n-1)
        {
            cout << ", ";
        }
    }
    cout << "]";
    return 0;
}