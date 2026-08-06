#include <bits/stdc++.h>
using namespace std;

bool check(int A[],int B[],int n)
{
    for (int i = 0; i < n; i++)
    {
        if (A[i] != B[i])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,x = 10;
    cin >> n;
    int A[n],tmp[n],a = n;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
        cout << A[i] << " ";
        tmp[i] = A[i];
    }
    cout << "\n";
    sort(tmp,tmp+n);
    if (check(A,tmp,n))
    {
        return 0;
    }
    while (1)
    {
        int r,mx = INT_MIN;
        for (int i = 0; i < a; i++)
        {
            if (A[i] > mx)
            {
                mx = A[i];
                r = i;
            }
        }
        if (A[r] == tmp[r])
        {
            a--;
            continue;
        }
        if (r != 0)
        {
            reverse(A,A+r+1);
            if (check(A,tmp,n))
            {
                break;
            }
            for (int i = 0; i < n; i++)
            {
                cout << A[i] << " ";
            }
            cout << "\n";
        }
        // cout << a << "\n";
        reverse(A,A+a);
        a--;
        if (check(A,tmp,n))
        {
            break;
        }
        for (int i = 0; i < n; i++)
        {
            cout << A[i] << " ";
        }
        cout << "\n";
    }
    for (int i = 0; i < n; i++)
    {
        cout << tmp[i] << " ";
    }
    
    return 0;
}