#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    pair <int,string> NUM[] = {{0,"- "},{1,"-"},{2,"-abc"},{3,"-def"},{4,"-ghi"},{5,"-jkl"},{6,"-mno"},{7,"-pqrs"},{8,"-tuv"},{9,"-wxyz"}};
    string line;
    while (getline(cin,line))
    {
        line += " ";
        string c = line.substr(0,3);
        string tmp = "";
        // cout << line << "\n";
        cout << ">> ";
        for (int i = 4; i < line.length(); i++)
        {
            if (line[i] == ' ')
            {
                if (c == "K2T")
                {
                    cout << NUM[tmp[0]-'0'].second.at(tmp.length());
                }
                else
                {
                    if (i != line.length()-1)
                    {
                        tmp += " ";
                    }
                    for(auto ch:tmp)
                    {
                        if (!(isalpha(ch) || ch == ' '))
                        {
                            continue;
                        }
                        ch = tolower(ch);
                        // char t = tolower(ch);
                        // cout << ch << ":";
                        for (int j = 0; j < 10; j++)
                        {
                            if (NUM[j].second.find(ch) != string::npos)
                            {
                                for (int k = 0; k < NUM[j].second.find(ch); k++)
                                {
                                    cout << j;
                                }
                                cout << " ";
                                break;
                            }
                        }
                        
                    }
                }
                tmp = "";
                continue;
            }
            tmp += line[i];
        }
        
        cout << "\n";
    }
    
    return 0;
}