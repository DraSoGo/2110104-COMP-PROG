#include <bits/stdc++.h>
using namespace std;

struct rec
{
    int idx,x1,y1,x2,y2;
};

int ovl(int x1a,int y1a,int x2a,int y2a,int x1b,int y1b,int x2b,int y2b)
{
    int xl = max(x1a, x1b);
    int xr = min(x2a, x2b);
    int yd = max(y1a, y1b);
    int yt = min(y2a, y2b);

    int w = xr - xl;
    int h = yt - yd;

    if (w > 0 && h > 0)
    {
        return w * h;
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,x1,y1,x2,y2,mx = 0,o;
    vector <pair<int,int>> V;
    cin >> n;
    rec A[n];
    for (int i = 0; i < n; i++)
    {
        A[i].idx = i+1;
        cin >> A[i].x1 >> A[i].y1 >> A[i].x2 >> A[i].y2;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            o = ovl(A[i].x1,A[i].y1,A[i].x2,A[i].y2,A[j].x1,A[j].y1,A[j].x2,A[j].y2);
            if (o)
            {
                if (o > mx)
                {
                    V.clear();
                    mx = o;
                    V.push_back({i,j});
                }
                else if(o == mx)
                {
                    V.push_back({i,j});
                }
            }
        }
    }
    if (V.empty())
    {
        cout << "No overlaps";
        return 0;
    }
    cout << "Max overlapping area = " << mx << "\n";
    for (int i = 0; i < V.size(); i++)
    {
        cout << "rectangles " << V[i].first << " and " << V[i].second << "\n";
    }
    return 0;
}