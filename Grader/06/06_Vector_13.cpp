#include <bits/stdc++.h>
using namespace std;

vector<string> split(string line, char delimiter)
{
    vector <string> ans;
    string tmp = "";
    for (int i = 0; i < line.length(); i++)
    {
        if (line[i] == delimiter && tmp.size() > 0)
        {
            ans.push_back(tmp);
            tmp = "";
        }
        else if(line[i] != delimiter)
        {
            tmp += line[i];
        }
    }
    if (tmp.length() > 0)
    {
        ans.push_back(tmp);
    }
    
    return ans;
}
int main()
{
    string line;
    getline(cin, line);
    string delim;
    getline(cin, delim);
    for (string e : split(line, delim[0]))
    {
        cout << '(' << e << ')';
    }
}