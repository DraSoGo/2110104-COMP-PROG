#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int d1, m1, y1, d2, m2, y2, all = 0, black = 0, blue = 0, red = 0;
    cin>>d1>>m1>>y1;
    cin>>d2>>m2>>y2;   
    if(y2-y1-1 > 0){
        black = 365*(y2-y1-1);
    }
    if(m1==1) red = 31-d1+28+31+30+31+30+31+31+30+31+30+31;
    if(m1==2) red = 28-d1+31+30+31+30+31+31+30+31+30+31;
    if(m1==3) red = 31-d1+30+31+30+31+31+30+31+30+31;
    if(m1==4) red = 30-d1+31+30+31+31+30+31+30+31;
    if(m1==5) red = 31-d1+30+31+31+30+31+30+31;
    if(m1==6) red = 30-d1+31+31+30+31+30+31;
    if(m1==7) red = 31-d1+31+30+31+30+31;
    if(m1==8) red = 31-d1+30+31+30+31;
    if(m1==9) red = 30-d1+31+30+31;
    if(m1==10) red = 31-d1+30+31;
    if(m1==11) red = 30-d1+31;
    if(m1==12) red = 31-d1;
    red += 1;
    if(m2 == 1) blue = d2;
    if(m2 == 2) blue = 31+d2;
    if(m2 == 3) blue = 31+28+d2;
    if(m2 == 4) blue = 31+28+31+d2;
    if(m2 == 5) blue = 31+28+31+30+d2;
    if(m2 == 6) blue = 31+28+31+30+31+d2;
    if(m2 == 7) blue = 31+28+31+30+31+30+d2;
    if(m2 == 8) blue = 31+28+31+30+31+30+31+d2;
    if(m2 == 9) blue = 31+28+31+30+31+30+31+31+d2;
    if(m2 == 10) blue = 31+28+31+30+31+30+31+31+30+d2;
    if(m2 == 11) blue = 31+28+31+30+31+30+31+31+30+31+d2;
    if(m2 == 12) blue = 31+28+31+30+31+30+31+31+30+31+30+d2;
    blue -= 1;
    if(m1<=2)
        if((y1-543)%400 == 0){
            red += 1;
        }
        else if((y1-543)%4==0 && ((y1-543)%100 != 0)){
            red += 1;
        }
    if(m2 > 2){
        if((y2-543)%400 == 0){
            blue += 1;
        }
        else if((y2-543)%4==0 && ((y1-543)%100 != 0)){
            blue += 1;
        }
    }
    all = red+blue+black;
    double phys = sin(2*M_PI*all/23.0), emo = sin(2*M_PI*all/28.0), intel = sin(2*M_PI*all/33.0);
    cout<<all<<' '<<round(phys*100.0)/100.0<<' '<<round(emo*100.0)/100.0<<' '<<round(intel*100.0)/100.0;
    return 0;
}