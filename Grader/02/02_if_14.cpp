#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s1, s2;
    bool b1 = false, b2 = false;
    double d1, d2;
    char com_a, com_b, cal1_a, cal2_a, cal1_b, cal2_b;
    cin>>s1>>d1>>com_a>>cal1_a>>cal2_a;
    cin>>s2>>d2>>com_b>>cal1_b>>cal2_b;
    if(com_a == 'A' && cal1_a <= 'C' && cal2_a <= 'C'){
        b1 = true;
    }
    if(com_b == 'A' && cal1_b <= 'C' && cal2_b <= 'C'){
        b2 = true;
    }
    if(!(b1||b2)){
        cout<<"None";
    }
    else if(!b1&&b2){
        cout<<s2;
    }
    else if(b1&&!b2){
        cout<<s1;
    }
    else{
        if(d1 != d2){
            if(d1 > d2){
                cout<<s1;
            }
            else cout<<s2;
        }
        else if (cal1_a != cal1_b){
            if(cal1_a < cal1_b){
                cout<<s1;
            }
            else cout<<s2;
        }
        else if(cal2_a != cal2_b){
            if(cal2_a < cal2_b){
                cout<<s1;
            }
            else cout<<s2;
        }
        else cout<<"Both";
    }
    
    return 0;
}