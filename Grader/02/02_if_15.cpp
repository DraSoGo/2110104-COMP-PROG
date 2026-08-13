#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    string ss = s.substr(0, 2);   
    if(s.length() == 10 &&(ss == "06" || ss == "09" || ss == "08")){
        cout<<"Mobile number";
    }
    else cout<<"Not a mobile number";
    return 0;
}