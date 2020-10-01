#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a=0,b=1,c;
    cout<<1<<" ";
    for(int i=1 ; i<n ; i++)
    {
        c = a+b;
        cout<<c<<" ";
        a = b;
        b = c;
    }
    return 0;
}
