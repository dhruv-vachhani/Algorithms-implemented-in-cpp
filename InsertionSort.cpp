#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i=0 ; i<n ; i++)
        cin >> a[i];

    int key=0;
    for(int j=0 ; j<n ; j++)
    {
        key = a[j];
        int i = j;
        while(i>0 && a[i-1]>key)
        {
            a[i] = a[i-1];
            i--;
        }
        a[i] = key;
    }
    for(int i=0 ; i<n ; i++)
        cout << a[i];

    return 0;
}
