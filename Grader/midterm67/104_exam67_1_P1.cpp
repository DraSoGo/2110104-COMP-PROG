#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long N,d = 2;
    cin >> N;
    if (N < 2)
    {
        cout << "No prime factors for numbers less than 2.";
        return 0;
    }
    while (N > 1)
    {
        if (d*d > N)
        {
            cout << N;
            return 0;
        }
        while(N % d == 0)
        {
            N/=d;
            cout << d << " ";
        }
        d+=1;
        
    }
    
    return 0;
}