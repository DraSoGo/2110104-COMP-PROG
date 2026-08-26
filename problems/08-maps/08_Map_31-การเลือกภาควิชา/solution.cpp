#include <bits/stdc++.h>
using namespace std;

struct student
{
    string id;
    double s;
    string O[4];
    bool operator < (const student&a)const
    {
        return s > a.s;
    }
};


int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m,co;
    map <string,int> M;
    vector <pair<string,string>> ANS;
    string s;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s >> co;
        M[s] = co;
    }
    cin >> m;
    student A[m];
    for (int i = 0; i < m; i++)
    {
        cin >> A[i].id >> A[i].s >> A[i].O[0] >> A[i].O[1] >> A[i].O[2] >> A[i].O[3];
    }
    sort(A,A+n);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (M[A[i].O[j]] > 0)
            {
                // cout << A[i].id << " " << A[i].O[j] << "\n"
                ANS.push_back({A[i].id,A[i].O[j]});
                M[A[i].O[j]]--;
                break;
            }
        }
    }
    sort(ANS.begin(),ANS.end());
    for(auto [a,b]:ANS)
    {
        cout << a << " " << b << "\n";
    }
    return 0;
}