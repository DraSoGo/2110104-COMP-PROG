#include<bits/stdc++.h>
using namespace std;
long gcd(long a, long b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    string a, b, c;
    int i, j, l, h, t, d;
    cin>>a>>b>>c;
    i = stoi(a);
    if(stoi(c)!=0){
        for(int e=0; e<c.length(); ++e){
            s += '9';
        }
        for(int e=0; e<b.length(); ++e){
            s += '0';
        } 
        h = i*(stoi(s))+stoi(b+c)-stoi(b);
        t = stoi(s);
    }
    else{
        h = i*pow(10, b.length())+stoi(b);
        t = pow(10, b.length());
    }
    d= gcd(h, t);
    cout<<h/d<<" / "<<t/d;
    
    return 0;
}