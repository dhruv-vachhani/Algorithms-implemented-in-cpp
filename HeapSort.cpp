#include<bits/stdc++.h>
using namespace std;
void maxHeap(int *a,int n,int pos)
{
    int lr,l,r;
    l=2*pos+1;
    r=2*pos+2;
    if(l<n && a[l]>a[pos])
    {
        lr=l;
    }
    else
    {
        lr=pos;
    }
    if(r<n && a[r]>a[lr])
    {
        lr=r;
    }
    if(lr!=pos)
    {
        swap(a[lr],a[pos]);
        maxHeap(a,n,lr);
    }

}
void heapSort(int *a,int n)
{
    for(int i=(n/2)-1;i>=0;i--)
    {
        maxHeap(a,n,i);
    }
    for(int i=n-1;i>0;i--)
    {
        swap(a[0],a[i]);
        maxHeap(a,i,0);
    }
}
int main()
{
    int a[10];
    for(int i=0;i<10;i++)
    {
        cin>>a[i];
    }
    heapSort(a,10);
    for(int i=0;i<10;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
