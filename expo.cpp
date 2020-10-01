#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll power(ll a,ll n)
{
    if(n==0)
        return 1;

    if(n%2==0)
        return (power(a,n/2)*power(a,n/2));
    else
        return (a*power(a,n/2)*power(a,n/2));
}

int main()
{
    ll x,n;
    cin >> x >> n;
    cout<< power(x,n);
    return 0;
}
