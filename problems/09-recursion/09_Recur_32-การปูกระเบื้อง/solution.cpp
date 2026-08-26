#include <bits/stdc++.h>
using namespace std;

string pat = "RGB",s = "";
set <string> ANS;

bool check(string k)
{
    for (int i = 0; i < k.length()-1; i++)
    {
        if (k[i] == 'G' && k[i+1] == 'G')
        {
            return 0;
        }
    }
    return 1;
}

void gen(int n)
{
    if (s.size() == n)
    {
        if (check(s))
        {
            ANS.insert(s);
        }
        return;
    }
    for (int i = 0; i < 3; i++)
    {
        s.push_back(pat[i]);
        gen(n);
        s.pop_back();
    }
    
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,co = 0;
    cin >> n;
    gen(n);
    cout << ANS.size() << "\n";
    for(auto x:ANS)
    {
        cout << x << " ";
        co++;
        if (co == 20)
        {
            break;
        }
    }
    return 0;
}