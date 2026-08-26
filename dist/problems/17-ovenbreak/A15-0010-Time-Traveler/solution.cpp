#include <bits/stdc++.h>
using namespace std;

int main()
{
    double a,b,c;
    cin >> a >> b >> c;
    double x1 = max((-b + sqrt(pow(b,2) - 4*a*c)) / (2*a),(-b - sqrt(pow(b,2) - 4*a*c)) / (2*a));
    double x2 = min((-b + sqrt(pow(b,2) - 4*a*c)) / (2*a),(-b - sqrt(pow(b,2) - 4*a*c)) / (2*a));
    cout << x1 << " " << x2 << "\n";
    long long F = (x1+5*x2)*(x1+5*x2);
    long long E = (7*x1+x2)*(3*x1+x2);
    long long S = (F%100001*E%100001)%100001;
    cout << F << "\n" << E << "\n" << S;
    return 0;
}