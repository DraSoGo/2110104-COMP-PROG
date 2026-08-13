#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    if(n==0){
        cout<<"zero \n";
    }
    else if(n>0){
        cout<<"positive \n";
    }
    else{
        cout<<"negative \n";
    }
    if(n%2 == 0){
        cout<<"even";
    }
    else{
        cout<<"odd";
    }
    
    return 0;
}