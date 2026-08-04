#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s,h1,h2,m1,m2;
    cin >> s >> h1 >> m1 >> h2 >> m2;
    int t1 = stoi(h1) * 60 + stoi(m1);
    int t2 = stoi(h2) * 60 + stoi(m2);
    cout << t1 << " " << t2 << endl;
    int m = (720-t1) + t2;
    int h = m / 60;
    m %= 60;
    cout << "Croissant " << s << " is out for " << h << " hr " << m << " min";
    return 0;
}