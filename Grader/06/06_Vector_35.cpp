#include <bits/stdc++.h>
using namespace std;


pair <string,int> A[] = {{"soon",0}, {"neung",1}, {"song",2}, {"sam",3}, {"si",4}, {"ha",5}, {"hok",6}, {"chet",7}, {"paet",8}, {"kao",9},{"et",1}, {"yi",2}, {"sip",1e1}, {"roi",1e2}, {"phan",1e3}, {"muen",1e4}, {"saen",1e5}, {"lan",1e6}};

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string l;
    while (getline(cin,l),l != "q")
    {
        string tmp = "";
        vector <string> V;
        for (int i = 0; i < l.length(); i++)
        {
            if (l[i] == ' ')
            {
                V.push_back(tmp);
                tmp = "";
                continue;
            }
            tmp += l[i];
        }
        V.push_back(tmp);
        int tod,x,ans = 0;
        for (int i = 0; i < V.size(); i++)
        {
            // cout << V[i] << " ";
            for (int j = 0; j < 18; j++)
            {
                if (V[i] == A[j].first)
                {
                    // cout << V[i] << " " << A[j].first << " ";
                    x = A[j].second;
                    break;
                }
            }
            // cout << x << " ";
            if (x < 10 && i != V.size()-1)
            {
                tod = x;
            }
            else if (x >= 10 && i%2 == 1)
            {
                ans += tod*x;
            }
            else
            {
                ans += x;
            }
        }
        // cout << "\n";
        cout << ans << "\n";
    }
    return 0;
}