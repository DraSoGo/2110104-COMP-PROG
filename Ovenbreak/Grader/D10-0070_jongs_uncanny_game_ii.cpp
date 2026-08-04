#include <bits/stdc++.h>
using namespace std;

int A[1000000];

int main()
{
    int n,x,c1=0,c2=0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        A[x]++;
    }
    for (int i = 0; i < 1000000; i++)
    {
        if(A[i] == 1)
        {
            c1++;
        }
        else if(A[i] > 1)
        {
            c2++;
        }
    }
    cout << ceil(c1/2.0)+c2;
    return 0;
}