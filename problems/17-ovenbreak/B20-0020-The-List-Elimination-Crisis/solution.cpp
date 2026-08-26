#include <bits/stdc++.h>
using namespace std;

int main()
{
    int f,s,c,state = 0;
    cin >> f >> s >> c;
    bool h1,h2,h3;
    h1 = f >= 200 && s <= 4;
    h2 = f < 300 || s == 8;
    h3 = f * s > 1200;
    h1 == c?h1 = 1:h1 = 0;
    h2 == c?h2 = 1:h2 = 0;
    h3 == c?h3 = 1:h3 = 0;
    state = h1 + h2 + h3;
    cout << "H1: " << (h1 == 1?"SURVIVED":"ELIMINATED") << "\n";
    cout << "H2: " << (h2 == 1?"SURVIVED":"ELIMINATED") << "\n";
    cout << "H3: " << (h3 == 1?"SURVIVED":"ELIMINATED") << "\n";
    cout << "VS State: " << (state >= 2?"AMBIGUOUS":state == 1?"UNIQUE":"COLLAPSE") << "\n";
    
    return 0;
}