#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    /*if(s.length() > 2 || !(s[0] >= '0' && s[0]<= '9')|| !(s[1] >= '0' && s[1] <= '9')){
        cout<<"Error";
        return 0;
    }
    else if(!(s == "01" || s == "02" ||s == "51" || s == "53" || s == "55" || s == "58" || (stoi(s)>=20 && stoi(s)<=40))){
        cout<<"Error";
        return 0;
    }
    cout<<"OK";*/
    if(s.length() > 2 || !isdigit(s[0]) || !isdigit(s[1])){
        cout<<"Error"; return 0;
    }
    int n = stoi(s);
    if(n == 1 || n==2 || n >= 20 || n <= 40 || n == 51 || n == 53 || n == 55 || n == 58){
        cout<<"OK";
    }
    else cout<<"Error";
    
    return 0;
}