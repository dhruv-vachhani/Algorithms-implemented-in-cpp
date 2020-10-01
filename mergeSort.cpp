#include<bits/stdc++.h>
using namespace std;

void mergeSort(int a[] , int l, int m , int r)
{
    int n1 = m-l+1, n2=r-m;

    int left[n1],right[n2];

    for(int i=0 ; i<n1 ; i++)
        left[i] = a[l+i];

    for(int i=0 ; i<n2 ; i++)
        right[i] = a[m+1+i];

    int ptr=l,i=0,j=0;
    while(i<n1 && j<n2)
    {
        if(left[i]<right[j])
            a[ptr++] = left[i++];
        else
            a[ptr++] = right[j++];
    }

    while(i<n1)
        a[ptr++] = left[i++];
    while(j<n2)
        a[ptr++] = right[j++];
}

void partion(int a[],int l,int r)
{
    if(l<r)
    {
        int m = (l+r)/2;
        partion(a,l,m);
        partion(a,m+1,r);

        mergeSort(a,l,m,r);
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i=0 ; i<n ; i++)
        cin >> a[i];

    partion(a,0,n-1);

    for(int i=0 ; i<n ; i++)
        cout<<a[i]<<" ";
    return 0;
}
