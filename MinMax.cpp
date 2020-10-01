#include<bits/stdc++.h>
using namespace std;


void MinMax(int a[],int start,int end,int& min, int& max)
{
    if(start==end)
    {
        if(min > a[start])
            min = a[start];
        if(max < a[start])
            max = a[start];

        return;
    }
    else if(start - end == 1)
    {
        if(a[start]>a[end])
        {
            if(min > a[end])
                min = a[end];

            if(max < a[start])
                max = a[start];
        }
        else
        {
            if(max < a[end])
                max = a[end];

            if(min > a[start])
                min = a[start];
        }
        return;
    }
        int mid = (start+end)/2;
        MinMax(a,start,mid,min,max);
        MinMax(a,mid+1,end,min,max);
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i=0 ; i<n ; i++)
        cin >> a[i];
    int min = INT_MAX,max = INT_MIN;
    MinMax(a,0,n-1,min,max);
    cout<<min<<" "<<max;
    return 0;
}
