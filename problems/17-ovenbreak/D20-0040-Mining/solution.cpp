#include <bits/stdc++.h>
using namespace std;

vector <int> V;
int l = 3,sum = 0;
char A[30][30][30];


int mine(char x)
{
    if (x == '-')
    {
        return 0;
    }
    if (x == 'C')
    {
        return 1;
    }
    if (x == 'G')
    {
        return 2;
    }
    return 5;
}

void genb(int a,int b,int c)
{
    if (V.size() == l)
    {
        for(auto i:V)
        {
            // cout << i << " ";
        }
        sum += mine(A[a+V[0]][b+V[1]][c+V[2]]);
        A[a+V[0]][b+V[1]][c+V[2]] = '-';
        return;
        // cout << "\n";
    }
    for (int i = -1; i <= 1; i++)
    {
        V.push_back(i);
        genb(a,b,c);
        V.pop_back();
    }
}

int main()
{
    int x,y,z,n,s,a,b,c;
    cin >> x >> y >> z >> n;
    for (int i = 0; i < x+2; i++)
    {
        for (int j = 0; j < y+2; j++)
        {
            for (int k = 0; k < z+2; k++)
            {
                A[i][j][k] = '-';
            }
        }
    }
    for (int i = 1; i <= x; i++)
    {
        for (int j = 1; j <= y; j++)
        {
            for (int k = 1; k <= z; k++)
            {
                cin >> A[i][j][k];
            }
        }
    }
    while (n--)
    {
        cin >> s >> a >> b >> c;
        // cout << a << b << c;
        if(s == 0)
        {
            // cout << A[a+1][b+1][c+1] << "\n";
            sum += mine(A[a+1][b+1][c+1]);
            A[a+1][b+1][c+1] = '-';
        }
        else
        {
            genb(a+1,b+1,c+1);
        }
    }
    cout << sum;
    
    return 0;
}
