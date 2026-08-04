#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a;
    cin >> a;
    a -= 543;
    a %= 100;
    int k = a+a/4+11;
    cout << k%7;
    return 0;
}