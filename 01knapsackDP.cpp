#include<bits/stdc++.h>

using namespace std;
int main()
{
    int nCoins,capacity;
    cin >> nCoins;
    int weights[nCoins+1],val[nCoins+1];
    cin >> capacity;
    for(int i=1 ; i<=nCoins ; i++)
        cin >> weights[i] >> val[i];

    int dp[nCoins+1][capacity+1];

    for(int i=0 ; i<=nCoins ; i++)
    {
        for(int j=0 ; j<=capacity ; j++)
        {
            if(i==0 || j==0)
                dp[i][j] = 0;
            else if(weights[i]<=j)
                dp[i][j] = max(dp[i-1][j],val[i]+dp[i-1][j-weights[i]]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    cout << dp[nCoins][capacity];
    return 0;
}

