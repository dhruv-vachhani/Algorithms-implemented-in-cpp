#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int s[n],f[n];
    for(int i=0 ; i<n ; i++)
        cin >> s[i];

    for(int i=0 ; i<n ; i++)
        cin >> f[i];

    cout << s[0] <<"-"<< f[0]<<"\n";
    int finish = f[0];
    for(int i=1 ; i<n ; i++)
    {
        if(s[i] >= finish)
        {
            cout << s[i] <<"-"<< f[i]<<"\n";
            finish = f[i];
        }
    }
    return 0;
}
