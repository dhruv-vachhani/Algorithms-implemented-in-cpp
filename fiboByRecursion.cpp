#include<bits/stdc++.h>
using namespace std;

int fibo(int n)
{
    if(n<=1)
        return n;
    else
        return (fibo(n-1) +fibo(n-2));
}

int main()
{
    int t;
    cin >> t;
    cout << fibo(t);
    return 0;
}
