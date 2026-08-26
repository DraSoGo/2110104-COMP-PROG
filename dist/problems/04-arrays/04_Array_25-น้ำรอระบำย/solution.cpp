#include <bits/stdc++.h>
using namespace std;

const int sz = 1e6+1;
int A[sz];

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];

    }
    for (int i = 0; i < n-1; i++)
    {
        if (A[i] >= A[i+1])
        {
            int idx = i+1,idxmx = i+1;
            while (idx < n)
            {
                if (A[idx] > A[idxmx])
                {
                    idxmx = idx;
                }
                if (A[idxmx] > A[i])
                {
                    break;
                }
                idx++;
            }
            for (int j = i+1; j < idxmx; j++)
            {
                // cout << j << " " << min(A[idx],A[i]) << " " << A[i] << " " << idx << ":" << A[idx] << "\n";
                sum += min(A[idxmx],A[i])-A[j];
            }
            // cout << i << " " << idx << " " << idxmx << "\n";
            i = idxmx-1;
        }
    }
    cout << sum;
    return 0;
}