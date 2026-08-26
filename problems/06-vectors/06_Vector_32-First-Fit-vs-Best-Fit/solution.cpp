#include <bits/stdc++.h>
using namespace std;

bool op(pair <int,vector <int>> a,pair <int,vector <int>> b)
{
    if (a.first == b.first)
    {
        if (a.second.size() == b.second.size())
        {
            return a.second < b.second;
        }
        return a.second.size() < b.second.size();
    }
    return a.first > b.first;
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    vector <int> V;
    string c;
    cin >> c;
    int x;
    while (cin >> x)
    {
        V.push_back(x);
    }
    vector <vector<int>> ANS;
    if (c == "first")
    {
        for (int i = 0; i < V.size(); i++)
        {
            ANS.push_back({V[i]});
        }
        for (int i = 0; i < V.size(); i++)
        {
            for (int j = i+1; j < V.size(); j++)
            {
                int sumi = 0,sumj = 0;
                for(auto x:ANS[i])
                {
                    sumi += x;
                }
                for(auto x:ANS[j])
                {
                    sumj += x;
                }
                if (sumi + sumj <= 100)
                {
                    for(auto x:ANS[i])
                    {
                        ANS[j].push_back(x);
                    }
                    ANS[i].clear();
                    break;
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < V.size(); i++)
        {
            int mx = INT_MIN,b = -1;
            for (int j = 0; j < ANS.size(); j++)
            {
                int sumi = 0;
                for(auto x:ANS[j])
                {
                    sumi += x;
                }
                if (sumi + V[i] <= 100 && mx < sumi + V[i])
                {
                    mx = sumi + V[i],b = j;
                }
            }
            if (b != -1)
            {
                ANS[b].push_back(V[i]);
            }
            else
            {
                ANS.push_back({V[i]});
            }
            
        }
    }
    vector <pair <int,vector <int>>> FA;
    int idx = 0;
    for (int i = 0; i < ANS.size(); i++)
    {
        int sum = 0;
        if (ANS[i].empty())
        {
            continue;
        }
        sort(ANS[i].begin(),ANS[i].end());
        pair<int, vector<int>> tmp;
        for(auto x:ANS[i])
        {
            sum += x;
            tmp.second.push_back(x);
            // cout << x << " ";
        }
        tmp.first = sum;
        // cout << "\n";
        FA.push_back(tmp);
        idx++;
    }
    FA.shrink_to_fit();
    sort(FA.begin(),FA.end(),op);
    for (int i = 0; i < FA.size(); i++)
    {
        for(auto x:FA[i].second)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}