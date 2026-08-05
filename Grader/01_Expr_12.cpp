#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    double w,h;
    cin>>w>>h;
    double m, hay, b;
    m = sqrt(w*h)/60.0;
    hay = 0.024265*pow(w, 0.5378)*pow(h, 0.3964);
    b = 0.0333 * pow(w, 0.6157-0.0188*log10(w))*pow(h, 3.0/10.0);
    cout<<setprecision(15)<<m<<'\n';
    cout<<setprecision(15)<<hay<<'\n';
    cout<<setprecision(15)<<b;
    return 0;
}