#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    double sum = 0, in, max = INT_MIN, min = INT_MAX;
    for(int i=0; i<4; ++i){
        cin>>in;
        if(in>max) max = in;
        if(in<min) min = in;
        sum += in;
    }
    cout<<round(((sum-max-min)/2.0)*100.0)/100.0;
    
    return 0;
}