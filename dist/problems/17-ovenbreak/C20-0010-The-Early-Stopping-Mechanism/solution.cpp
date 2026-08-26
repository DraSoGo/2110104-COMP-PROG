#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    double a,mn = INT_MAX,idx,s = -1;
    cin >> n;
    double A[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a;
        A[i] = a;
        if(i != 0 && A[i] > A[i-1] && s == -1)
        {
            s = i+1;
        }
        if(a < mn)
        {
            mn = a;
            idx = i+1;
        }
    }
    cout << "Best Epoch: " << idx << "\n";
    cout << "Min Loss: " << fixed << setprecision(4) << mn << "\n";
    if(s == -1)
    {
        cout << "Stop Epoch: NONE";
        return 0;
    }
    cout << "Stop Epoch: " << fixed << setprecision(0) << s;
    return 0;
}
