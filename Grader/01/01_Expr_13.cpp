#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    double x1,x2;
    double a, b, c;
    cin>>a>>b>>c;
    x1 = (-b-sqrt(pow(b, 2)-(4*a*c)))/(2*a);
    x2 = (-b+sqrt(pow(b, 2)-(4*a*c)))/(2*a);
    cout<<round(x1*1e3)/1e3<<' '<<round(x2*1e3)/1e3;
    return 0;
}