#include<bits/stdc++.h>
using namespace std;
int main()
{
    int freq[26];
    int n;
    cin>>n;
    char a[n],ans[n];
    for(int i=0 ; i<26 ; i++)
        freq[i] = 0;
    for(int i=0 ; i<n ; i++)
    {
        cin>>a[i];
        freq[a[i]-'a']++;
    }

    for(int i=1 ; i<26 ; i++)
        freq[i] += freq[i-1];

    for(int i=0 ; i<n; i++)
    {
        ans[freq[a[i]-'a']] = a[i];
        freq[a[i]-'a']--;
    }
    for(int i=0 ; i<n ; i++)
        cout<<ans[i]<<" ";
    return 0;
}
