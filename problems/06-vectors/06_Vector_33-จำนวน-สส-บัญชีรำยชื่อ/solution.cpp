#include <bits/stdc++.h>
using namespace std;

struct pak
{
    string c;
    double s,p,t;
    bool operator < (const pak&x)const
    {
        return t > x.t;
    }
};

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    vector <pair<int,pair<int,string>>> ANS;
    vector <pak> A;
    string s;
    double x,sum = 0;
    int co = 100;
    while (cin >> s,s != "END")
    {
        cin >> x;
        sum += x;
        A.push_back({s,x,0,0});
    }
    sum /= 100;
    for (int i = 0; i < A.size(); i++)
    {
        A[i].p = A[i].s/sum;
        A[i].t = A[i].p-floor(A[i].p);
        co -= int(A[i].p);
    }
    sort(A.begin(),A.end());
    int idx = 0;
    while (co--)
    {
        A[idx].p++;
        idx++;
    }
    for (int i = 0; i < A.size(); i++)
    {
        if (int(A[i].p) <= 0)
        {
            continue;
        }
        ANS.push_back({int(A[i].p),{int(A[i].s),A[i].c}});
    }
    sort(ANS.begin(),ANS.end());
    reverse(ANS.begin(),ANS.end());
    for (int i = 0; i < ANS.size(); i++)
    {
        cout << ANS[i].second.second << " " << ANS[i].first << " " << ANS[i].second.first << "\n";
    }
    
    return 0;
}