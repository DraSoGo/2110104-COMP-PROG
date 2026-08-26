#include <bits/stdc++.h>
using namespace std;

char ANS[8][8];
int add(int x)
{
    if (x == 0)
    {
        return 0;
    }
    return x/(abs(x));
}

bool check(int x,int y)
{
    if (x < 0 || x >= 8 || y < 0 || y >= 8 || ANS[x][y] != '.')
    {
        return 0;
    }
    return 1;
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T[8][8],n;
    char c;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            ANS[i][j] = '.';
        }
    }
    string p;
    memset(T,0,sizeof(T));
    cin >> n;
    vector <pair<int,string>> V;
    while (n--)
    {
        cin >> c >> p;
        V.push_back({c,p});
        if (c == 'B')
        {
            int x = 8-(p[1]-'0'),y = p[0]-'A',idx = 0;
            ANS[x][y] = 'B';
        }
        else if (c == 'K')
        {
            int x = 8-(p[1]-'0'),y = p[0]-'A',idx = 0;
            ANS[x][y] = 'K';
        }
        else if (c == 'Q')
        {
            int x = 8-(p[1]-'0'),y = p[0]-'A',idx = 0;
            ANS[x][y] = 'Q';
        }
        else if (c == 'R')
        {
            int x = 8-(p[1]-'0'),y = p[0]-'A',idx = 0;
            ANS[x][y] = 'R';
        }
        else if (c == 'P')
        {
            int x = 8-(p[1]-'0'),y = p[0]-'A',idx = 0;
            ANS[x][y] = 'P';
        }
        else if (c == 'N')
        {
            int x = 8-(p[1]-'0'),y = p[0]-'A',idx = 0;
            ANS[x][y] = 'N';
        }
    }
    for (int k = 0; k < V.size(); k++)
    {
        c = V[k].first;
        p = V[k].second;
        if (c == 'B')
        {
            int disx[4] = {-1,-1,1,1};
            int disy[4] = {-1,1,-1,1};
            int x = 8-(p[1]-'0'),y = p[0]-'A',idx = 0;
            ANS[x][y] = 'B';
            for (int i = 0; i < 4; i++)
            {
                // cout << x << " " << y << "\n";
                int nx = x+disx[i],ny = y+disy[i];
                // cout << i << " " << nx << " " << ny << "\n";
                while (check(nx,ny))
                {
                    T[nx][ny]++;
                    nx += add(disx[i]);
                    ny += add(disy[i]);
                    // cout << i << " " << nx << " " << ny << " " << add(disx[i]) << " " << add(disy[i]) << "\n";
                }
            }
        }
        else if (c == 'K')
        {
            int disx[8] = {-1,-1,1,1,0,0,1,-1};
            int disy[8] = {-1,1,-1,1,1,-1,0,0};
            int x = 8-(p[1]-'0'),y = p[0]-'A',idx = 0;
            ANS[x][y] = 'K';
            for (int i = 0; i < 8; i++)
            {
                // cout << x << " " << y << "\n";
                int nx = x+disx[i],ny = y+disy[i];
                // cout << i << " " << nx << " " << ny << "\n";
                if(check(nx,ny))
                {
                    T[nx][ny]++;
                    // cout << i << " " << nx << " " << ny << " " << add(disx[i]) << " " << add(disy[i]) << "\n";
                }
            }
        }
        else if (c == 'Q')
        {
            int disx[8] = {-1,-1,1,1,0,0,1,-1};
            int disy[8] = {-1,1,-1,1,1,-1,0,0};
            int x = 8-(p[1]-'0'),y = p[0]-'A',idx = 0;
            ANS[x][y] = 'Q';
            for (int i = 0; i < 8; i++)
            {
                // cout << x << " " << y << "\n";
                int nx = x+disx[i],ny = y+disy[i];
                // cout << i << " " << nx << " " << ny << "\n";
                while (check(nx,ny))
                {
                    T[nx][ny]++;
                    nx += add(disx[i]);
                    ny += add(disy[i]);
                    // cout << i << " " << nx << " " << ny << " " << add(disx[i]) << " " << add(disy[i]) << "\n";
                }
            }
        }
        else if (c == 'R')
        {
            int disx[4] = {0,0,1,-1};
            int disy[4] = {1,-1,0,0};
            int x = 8-(p[1]-'0'),y = p[0]-'A',idx = 0;
            ANS[x][y] = 'R';
            for (int i = 0; i < 4; i++)
            {
                // cout << x << " " << y << "\n";
                int nx = x+disx[i],ny = y+disy[i];
                // cout << i << " " << nx << " " << ny << "\n";
                while (check(nx,ny))
                {
                    T[nx][ny]++;
                    nx += add(disx[i]);
                    ny += add(disy[i]);
                    // cout << i << " " << nx << " " << ny << " " << add(disx[i]) << " " << add(disy[i]) << "\n";
                }
            }
        }
        else if (c == 'P')
        {
            int disx[2] = {-1,-1};
            int disy[2] = {-1,1};
            int x = 8-(p[1]-'0'),y = p[0]-'A',idx = 0;
            ANS[x][y] = 'P';
            for (int i = 0; i < 2; i++)
            {
                // cout << x << " " << y << "\n";
                int nx = x+disx[i],ny = y+disy[i];
                // cout << i << " " << nx << " " << ny << "\n";
                if(check(nx,ny))
                {
                    T[nx][ny]++;
                    // cout << i << " " << nx << " " << ny << " " << add(disx[i]) << " " << add(disy[i]) << "\n";
                }
            }
        }
        else
        {
            int disx[8] = {-1,-2,-1,-2,1,2,1,2};
            int disy[8] = {-2,-1,2,1,-2,-1,2,1};
            int x = 8-(p[1]-'0'),y = p[0]-'A',idx = 0;
            ANS[x][y] = 'N';
            for (int i = 0; i < 8; i++)
            {
                // cout << x << " " << y << "\n";
                int nx = x+disx[i],ny = y+disy[i];
                // cout << i << " " << nx << " " << ny << "\n";
                if(check(nx,ny))
                {
                    T[nx][ny]++;
                    // cout << i << " " << nx << " " << ny << " " << add(disx[i]) << " " << add(disy[i]) << "\n";
                }
            }
        }
        
    }
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (T[i][j] > 0 && ANS[i][j] == '.')
            {
                cout << T[i][j] << " ";
                continue;
            }
            cout << ANS[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}