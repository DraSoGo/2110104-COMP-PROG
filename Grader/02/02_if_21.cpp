#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    unsigned long long int n;
    cin>>n;
    if(n>10000000000){
        cout<<round(n/1000000000.0)<<"B";
    }
    else if(n>1000000000){
        cout<<round((n/1000000000.0)*10)/10.0<<"B";
    }
    else if(n>10000000){
        cout<<round(n/1000000.0)<<"M";
    }
    else if(n>1000000){
        cout<<round((n/1000000.0)*10)/10.0<<"M";
    }
    else if(n>10000){
        cout<<round(n/1000.0)<<"K";
    }
    else if(n>1000){
        cout<<round((n/1000.0)*10)/10.0<<"K";
    }
    else{
        cout<<n;
    }

    return 0;
}