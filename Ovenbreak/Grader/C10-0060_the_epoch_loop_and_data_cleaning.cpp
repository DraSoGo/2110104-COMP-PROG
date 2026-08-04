#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    double sum = 0,a,co = 0;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a;
        if(a > 0)
        {
            co++;
            sum += a;
        }
    }
    cout << "Cleaned ML Mean: " << fixed << setprecision(2) << sum/co;
    return 0;
}
