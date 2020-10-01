#include<bits/stdc++.h>
using namespace std;

// function to find Optimal Parenthesization for given input
void parenthesis(int i, int j, int n, int *s, char &name) 
{ 
    if (i == j) 
    { 
        cout << name++; 
        return; 
    } 
    cout << "("; 
  
    parenthesis(i, *((s+i*n)+j), n, s, name); 
    parenthesis(*((s+i*n)+j) + 1, j, n, s, name); 
    cout << ")"; 
}

int main()
{
    int n;
    cin >> n;
    int d[n];
    for(int i=0 ; i<n ; i++)
        cin >> d[i];

    int m[n][n];  
    int s[n][n]; 
    
    for (int i = 1; i < n; i++)
        m[i][i] = 0;
    
    for(int len=2 ; len<n ; len++)
    {
        for(int i=1 ; i<n-len+1 ; i++)
        {
            int j = i+len-1;
            
            m[i][j] = INT_MAX;
            for(int k = i ; k<=j-1 ; k++)
            {
                int val = m[i][k] + m[k+1][j] + d[i-1]*d[k]*d[j];
                if(val < m[i][j])
                {
                    m[i][j] = val;
                    s[i][j] = k;
                }
            }
        }
    }
    /* display the m array
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<n ; j++)
            cout << m[i][j] << " ";
        cout << "\n";
    }*/
    cout << "Optimal cost is : " << m[1][n-1];
    char name = 'A'; 
    cout << "\nOptimal Parenthesization is : "; 
    parenthesis(1, n-1, n, (int *)s, name);
    
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
