#include <bits/stdc++.h>
using namespace std;

void print_s(set <int> S)
{
    for(auto x:S)
    {
        cout << x << " ";
    }
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    set <int> U,I,D;
    string line;
    getline(cin,line);
    string s = "";
    for (int i = 0; i < line.length(); i++)
    {
        if (line[i] == ' ')
        {
            U.insert(stoi(s));
            I.insert(stoi(s));
            D.insert(stoi(s));
            s = "";
            continue;
        }
        s += line[i];
    }
    while (getline(cin,line))
    {
        set <int> tmpI;
        line += " ";
        string s = "";
        for (int i = 0; i < line.length(); i++)
        {
            if (line[i] == ' ')
            {
                if (!I.empty() && I.find(stoi(s)) != I.end())
                {
                    tmpI.insert(stoi(s));
                }
                D.erase(stoi(s));
                U.insert(stoi(s));
                s = "";
                continue;
            }
            s += line[i];
        }
        // print_s(tmpI);
        // print_s(tmpD);
        I = tmpI;
    }
    cout << "U: ";
    if (!U.empty())
    {
        print_s(U);
    }
    else
    {
        cout << "empty set\n";
    }
    cout << "I: ";
    if (!I.empty())
    {
        print_s(I);
    }
    else
    {
        cout << "empty set\n";
    }
    cout << "D: ";
    if (!D.empty())
    {
        print_s(D);
    }
    else
    {
        cout << "empty set";
    }
    
    return 0;
}