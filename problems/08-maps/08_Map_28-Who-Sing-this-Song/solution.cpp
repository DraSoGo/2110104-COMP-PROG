#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    map <string,vector <string>> M;
    string line;
    getline(cin,line);
    int n = stoi(line);
    while (n--)
    {
        getline(cin,line);
        string a = line.substr(0,line.find(',')),b = line.substr(line.find(',')+2,line.length()-line.find(','));
        // cout << a << " " << b << "\n";
        M[a].push_back(b);
    }
    getline(cin,line);
    line += ",";
    string tmp = "";
    for (int i = 0; i < line.length(); i++)
    {
        if (line[i] == ',')
        {
            cout << tmp << " -> ";
            if (M[tmp].empty())
            {
                cout << "Not found\n";
            }
            else
            {
                for (int i = 0; i < M[tmp].size(); i++)
                {
                    cout << M[tmp][i] << (i != M[tmp].size()-1?", ":"\n");
                }
            }
            tmp = "";
            i ++;
            continue;
        }
        
        tmp += line[i];
    }
    
    return 0;
}