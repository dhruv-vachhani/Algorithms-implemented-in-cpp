#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int d[n];
    for(int i=0 ; i<n ; i++)
        cin >> d[i];

    int c[n][n];
    for (int i = 0; i < n; i++)
        c[i][i] = 0;
    for(int len=2 ; len<n ; len++)
    {
        for(int i=0 ; i<n-len+1 ; i++)
        {
            int j = i+len-1;
            if(j==n)continue;
            c[i][j] = INT_MAX;
            for(int k = i ; k<j ; k++)
            {
                int temp = c[i][k] + c[k+1][j] + d[i-1]*d[k]*d[j];
                if(temp<c[i][j])
                    c[i][j] = temp;
            }
        }
    }
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<n ; j++)
            cout << c[i][j] << " ";
        cout << "\n";
    }
    cout << c[0][n-1];
    return 0;
}
/*
 j    0 1 2 3 4
    0 0
 i  1   0
    2     0
    3       0
    4         0
*/
