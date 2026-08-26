#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    int a,b,g,x,y;
    cin >> s >> a >> b;
    x = pow((2*(b+1))-1,2);
    y = pow((2*(a))-1,2);
    g = x - y;
    cout << s << " has " << g << " attackable grids";
    return 0;
}