#include<bits/stdc++.h>
using namespace std;

int main()
{
    int change,ncoins;
    cin >> change >> ncoins;
    int coins[ncoins];
    for(int i=0 ; i<ncoins ; i++)
        cin >> coins[i];

    int table[ncoins][change+1];
    for(int col=0 ; col <= change ; col++)
    {
        for(int row=0 ; row < ncoins ; row++)
        {
            if(col == 0)
                table[row][col] = 1;
            else
            {
                int useit = col-coins[row]>=0 ? table[row][col-coins[row]]:0 ;
                int dontuse = row>=1 ? table[row-1][col]:0;
                table[row][col] = useit + dontuse;
            }
        }
    }
    cout << table[ncoins-1][change];
    return 0;
}
