#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string x;
    cin >> x;
    for (int i = 0; i < x.length(); i++)
    {
        if (i != 0 && (isupper(x[i]) || (isdigit(x[i]) && !isdigit(x[i-1])) || (islower(x[i]) && isdigit(x[i-1]))))
        {
            cout << ", ";
        }
        cout << x[i];
    }
    return 0;
}