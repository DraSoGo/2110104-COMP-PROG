#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,x,co = 0;
    deque <int> DQ;
    cin >> n;
    while (cin >> x,x != -1)
    {
        co % 2 == 0?DQ.push_back(x):DQ.push_front(x);
        co++;
    }
    cout << "[";
    while(!(DQ.empty()))
    {
        cout << DQ.front();
        DQ.pop_front();
        if (!DQ.empty())
        {
            cout << ", ";
        }
    }
    cout << "]";
    return 0;
}