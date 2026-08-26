#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        queue <int> A,B;
        int n,sum = 0;
        cin >> n;
        char s[n];
        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
            if (s[i] == 'A')
            {
                A.push(i);
            }
            else if(s[i] == 'B')
            {
                B.push(i);
            }
            if (A.size() >= 1 && B.size() >= 1)
            {
                sum += abs(A.front() - B.front())-1;
                A.pop();
                B.pop();
            }
        }
        cout << (sum%2 == 0?"B":"A") << "\n";
    }
    return 0;
}
