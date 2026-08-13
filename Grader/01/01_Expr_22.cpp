#include<bits/stdc++.h>
using namespace std;
int main(){
    double Xe, Ye, Re, Rp, Xm, Ym, A, a, B, b, C, c, ratio;
    cin>>Xe>>Ye>>Re>>Rp>>Xm>>Ym;
    C = sqrt(pow(Xm-Xe, 2)+pow(Ym-Ye, 2));
    c = Re - Rp;
    ratio = c/C;
    A = Xm - Xe;
    B = Ym - Ye;
    a = A*ratio;
    b = B*ratio;
    cout<<Xe+round(a)<<' '<<Ye+round(b);
    return 0;
}