#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int n12;
    cin>>s;
    n12 = (11-(13*(s[0]-'0')+12*(s[1]-'0')+11*(s[2]-'0')+10*(s[3]-'0')+9*(s[4]-'0')+8*(s[5]-'0')+7*(s[6]-'0')+6*(s[7]-'0')+5*(s[8]-'0')+4*(s[9]-'0')+3*(s[10]-'0')+2*(s[11]-'0'))%11)%10;
    s.insert(s.begin()+1, '-');
    s.insert(s.begin()+6, '-');
    s.insert(s.begin()+12, '-');
    cout<<s<<'-'<<n12;
    return 0;
}