#include<bits/stdc++.h>
using namespace std;
long gcd(long a, long b) {
 if (b == 0) return a;
 return gcd(b, a%b);
}
int main(){
    string a ,b, c;
    cin>>a>>b>>c;
    long long valABC = stoll(a+b+c);
    long long valAB = stoll(a+b);
    long long q = 1, m=1;
    for(int i=0; i<b.length(); ++i) q*=10;
    for(int i=0; i<c.length(); ++i) m*=10;
    long long bot = q*(m-1);
    long long top = valABC - valAB;
    long long d = gcd(top, bot);
    cout<<top/d<<" / "<<bot/d;
}