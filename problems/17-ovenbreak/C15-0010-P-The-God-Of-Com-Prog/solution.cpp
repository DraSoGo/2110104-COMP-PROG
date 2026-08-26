#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b;
    char x = 'A';
    cin >> a >> b;
    char arr[a][b];
    for(int i = 0; i < a; i++)
    {
        for(int j = 0; j < b; j++)
        {
            arr[i][j] = x;
            x++;
            if(x > 'Z')
            {
                x = 'A';
            }
        }
    }
    for(int i = 0; i < a; i++)
    {
        if(i%2 == 1)
        {
            reverse(arr[i],arr[i]+b);
        }
        for(int j = 0; j < b; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}
