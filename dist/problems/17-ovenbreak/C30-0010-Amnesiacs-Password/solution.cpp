#include <bits/stdc++.h>
using namespace std;

vector <string> V;
string S = "";
bool vis[26];

void gen_pass(int n)
{
    if (S.size() == n)
    {
        V.push_back(S);
        // cout << S << "\n";
        return;
    }
    for (int i = 0; i < 26; i++)
    {
        vis[i] = 1;
        S += char(i+'A');
        gen_pass(n);
        vis[i] = 0;
        S.pop_back();
    }
    
}

int main()
{
    gen_pass(4);
    pair<char,char> c[4];
    int n,sum = 0;
    cin >> c[0].first >> c[0].second >> c[1].first >> c[1].second >> c[2].first >> c[2].second >> c[3].first >> c[3].second >> n;
    for (int i = 0; i < V.size(); i++)
    {
        bool check = 1;
        int chars = 0;
        
        for (int j = 0; j < 4; j++)
        {
            if ((j > 0 && V[i][j]-V[i][j-1] == 0) || (!(V[i][j] >= c[j].first && V[i][j] <= c[j].second)))
            {
                // cout << c[j].first << " " << V[i][j] << " " << c[j].second << "\n";
                check = 0;
                break;
            }
            
            chars += V[i][j]-'A';
        }
        // cout << V[i] << " " << chars << "\n";
        if (!check || chars%10 != n)
        {
            continue;
        }
        cout << V[i] << "\n";
        sum++;
    }
    cout << sum;
    return 0;
}
