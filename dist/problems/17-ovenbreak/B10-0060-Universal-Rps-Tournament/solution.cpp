#include <bits/stdc++.h>
using namespace std;

int rps(string a, string b)
{
    if(a=="scissors")
    {
        if(b=="paper") return 1;
        if(b=="rock") return 0;
        if(b=="lizard") return 1;
        if(b=="spock") return 0;
    }
    else if(a=="paper")
    {
        if(b=="scissors") return 0;
        if(b=="rock") return 1;
        if(b=="lizard") return 0;
        if(b=="spock") return 1;
    }
    else if(a=="rock")
    {
        if(b=="scissors") return 1;
        if(b=="paper") return 0;
        if(b=="lizard") return 1;
        if(b=="spock") return 0;
    }
    else if(a=="lizard")
    {
        if(b=="scissors") return 0;
        if(b=="paper") return 1;
        if(b=="rock") return 0;
        if(b=="spock") return 1;
    }
    else if(a=="spock")
    {
        if(b=="scissors") return 1;
        if(b=="paper") return 0;
        if(b=="rock") return 1;
        if(b=="lizard") return 0;
    }
    return 2;
}

int main()
{
    string a,b,xa,xb;
    cin >> a >> xa >> b >> xb;
    if(rps(xa, xb) == 2)
    {
        cout << "Tie!";
        return 0;
    }
    else cout << (rps(xa, xb) == 1 ? a : b) << " wins!";
    return 0;
}