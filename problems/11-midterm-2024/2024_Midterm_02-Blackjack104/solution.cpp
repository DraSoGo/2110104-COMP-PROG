#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int a,b,suma= 0,sumb = 0,ansa,ansb;
    cin >> a >> b;
    string A[a],B[b];
    for (int i = 0; i < a; i++)
    {
        cin >> A[i];
        suma += isdigit(A[i][0])?stoi(A[i]):A[i] == "A"?11:10;
    }
    for (int i = 0; i < b; i++)
    {
        cin >> B[i];
        sumb += isdigit(B[i][0])?stoi(B[i]):B[i] == "A"?11:10;
    }
    for (int i = 0; i < a; i++)
    {
        if (A[i] == "A" && suma > 21)
        {
            suma-=10;
        }
    }
    for (int i = 0; i < a; i++)
    {
        if (B[i] == "A" && sumb > 21)
        {
            sumb-=10;
        }
    }
    ansa = suma > 21?0:suma;
    ansb = sumb > 21?0:sumb;
    cout << (ansa == ansb?"Draw":ansa > ansb?"A":"B") << "\n" << suma << " " << sumb;
    return 0;
}