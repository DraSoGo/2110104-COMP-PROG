#include <bits/stdc++.h>
using namespace std;

const int R = 7, C = 7;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
void floodfill(int x[][C], int r, int c, int e)
{
    if (r < 0 || r > R-1 || c < 0 || c > C-1 || x[r][c] == 1 || x[r][c] == e)
    {
        // cout << r << " " << c << "\n";
        return;
    }
    x[r][c] = e;
    for (int i = 0; i < 4; i++)
    {
        floodfill(x,r+dx[i],c+dy[i],e);
    }
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int x[][C] = {{0}, {0}, {0}, {0}, {0}, {0}, {0}};
    for (int r = 0; r < R; ++r)
        for (int c = 0; c < C; ++c)
            cin >> x[r][c];
    int row, col, e;
    cin >> row >> col >> e;
    floodfill(x, row, col, e);
    for (int r = 0; r < R; ++r)
    {
        for (int c = 0; c < C; ++c)
            cout << x[r][c] << ' ';
        cout << endl;
    }
    return 0;
}