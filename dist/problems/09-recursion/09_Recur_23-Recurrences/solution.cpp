#include <bits/stdc++.h>
using namespace std;

int F(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    if (n % 2 == 0)
    {
        n = n/2;
        return (2*F(n-1) + F(n))*F(n);
    }
    n = (n+1)/2;
    return F(n)*F(n)+F(n-1)*F(n-1);
}

int M(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    int sum = M(n-1);
    for (int k = 0; k <= n-2; k++)
    {
        sum += M(k)*M(n-2-k);
    }
    return sum;
    
}

int S(int n)
{
    if (n == 1 || n == 2)
    {
        return 1;
    }
    return 1.0/n*((6*n-9)*S(n-1)-(n-3)*S(n-2));
}

int D(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return n*D(n-1)+pow(-1,n);
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    map<string, int (*)(int)> func = {{"F", F}, {"M", M}, {"S", S}, {"D", D}};
    string fn;
    int p;
    while (cin >> fn >> p)
    {
        if (func.find(fn) != func.end())
            cout << fn << '(' << p << ") = " << func[fn](p) << endl;
    }
    return 0;
}