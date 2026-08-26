#include <bits/stdc++.h>
using namespace std;

struct ice
{
    double c,sum;
};


int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    map <string,ice> M;
    pair <string,double> mx = {"-",0};
    int n;
    string s;
    double c,sum = 0;
    cin >> n;
    while (n--)
    {
        cin >> s >> c;
        M[s] = {c,0};
    }
    cin >> n;
    while (n--)
    {
        cin >> s >> c;
        M[s].sum += c*M[s].c;
        sum += c*M[s].c;
        if (M[s].sum > mx.second)
        {
            mx.first = s;
            mx.second = M[s].sum;
        }
    }
    if (mx.second == 0)
    {
        cout << "No ice cream sales";
    }
    else
    {
        cout << "Total ice cream sales: " << sum << "\nTop sales: " << mx.first;
    }
    
    return 0;
}