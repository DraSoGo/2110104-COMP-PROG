#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    if(n>2000){
        cout<<"Reject";
    }   
    else if(n>1000){
        cout<<58;
    }
    else if(n>500){
        cout<<38;
    }
    else if(n>250){
        cout<<28;
    }
    else if(n>100){
        cout<<22;
    }
    else cout<<18;
    
    return 0;
}