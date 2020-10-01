#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n],maxval=0;
    for(int i=0 ;i<n ; i++)
    {
        cin >>a[i];
        if(maxval < a[i])
            maxval = a[i];
    }


    for(int exp=1 ; maxval/exp > 0 ; exp *= 10)
    {
        int output[n];
        int count[10] = {0};

        for (int i = 0; i < n; i++)
            count[ (a[i]/exp)%10 ]++;
        for (int i = 1; i < 10; i++)
            count[i] += count[i - 1];
        for (int i = n - 1; i >= 0; i--)
        {
            output[count[ (a[i]/exp)%10 ] - 1] = a[i];
            count[ (a[i]/exp)%10 ]--;
        }

        for (int k = 0; k < n; k++)
            a[k] = output[k];
    }
    for(int i=0 ; i<n ; i++)
        cout<<a[i]<<" ";
    return 0;
}
