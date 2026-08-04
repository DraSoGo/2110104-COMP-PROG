#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a,b;
    cin >> a >> b;
    char A[10];
    for(int i = 0; i < 10; i++)
    {
        cin >> A[i];
    }
    for(int i = 0; i < a.length(); i++)
    {
        a[i] = A[a[i]-'0'];
    }
    for(int i = 0; i < b.length(); i++)
    {
        b[i] = A[b[i]-'0'];
    }
    cout << stoi(a)+stoi(b);
    return 0;
}
