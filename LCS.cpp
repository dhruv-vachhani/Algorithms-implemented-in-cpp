#include<bits/stdc++.h>
using namespace std;

int main()
{
    char a[] = "AGGTAB";
    char b[] = "GXTXAYB";

    int s1 = strlen(a);
    int s2 = strlen(b);
    int x[s1+1][s2+1];
    int ans = 0;

    for(int i=0 ; i<=s1 ; i++)
    {
        for(int j=0 ; j<=s2 ; j++)
        {
            if(i==0 || j==0)
                x[i][j] = 0;
            else if(a[i-1] == b[j-1])
                x[i][j] = 1 + x[i-1][j-1];
            else
                x[i][j] = max( x[i-1][j],x[i][j-1] );
        }
    }

    ans = x[s1][s2];
    cout << ans;
    return 0;
}










/* using recursion
int lcs(char x[], char y[], int n1, int n2)
{
    if(n1==0 || n2==0)
        return 0;
    else if(x[n1-1] == y[n2-1])
        return (1+lcs(x,y,n1-1,n2-1));
    else
        return max( lcs(x,y,n1-1,n2) , lcs(x,y,n1,n2-1) );
}
int main()
{
    char a[] = "AGGTAB";
    char b[] = "GXTXAYB";

    int s1 = strlen(a);
    int s2 = strlen(b);

    int ans = lcs(a,b,s1,s2);
    cout << ans;
    return 0;
}
*/
