#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    double x, y;
    cin>>x;
    y = (pow(x, sqrt(log(pow((x+1),2))))) / (10-x);
    cout<<round(y*1e6)/1e6;
    
    return 0;
}