#include<bits/stdc++.h>
using namespace std;

int main()
{
    int c[] = {100,25,10,5,1};
    int n,sum=0,ptr=0;
    cin >> n;

    while(sum != n)
    {
        int x = c[ptr];
        if(sum+x <= n)
        {
            cout<<x<<" ";
            sum += x;
        }
        else if(ptr<5)
            ptr++;
    }
    return 0;
}
