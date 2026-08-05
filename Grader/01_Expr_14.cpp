#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,y;
    cin>>n;
    n -= 543;
    y = n%100;
    cout<<(y+(y/4)+11)%7;
    
    return 0;
}