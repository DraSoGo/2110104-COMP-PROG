#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b;
    cin >> a >> b;
    int A[a][b];
    for(int i = 0; i < a; i++)
    {
        for(int j = 0; j < b; j++)
        {
            cin >> A[i][j];
        }
        reverse(A[i],A[i]+b);
    }
    for(int i = 0; i < a; i++)
    {
        for(int j = 0; j < b; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
