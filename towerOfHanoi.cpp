#include<bits/stdc++.h>
using namespace std;

void toh(int n,char source,char aux,char destination)
{
    if(n == 1)
    {
        cout<<"1 move from "<<source<<"-"<<destination<<"\n";
        return;
    }
    else
    {
        toh(n - 1, source, aux, destination);
        cout<<n<<" move from "<<source<<"-"<<destination<<"\n";
        toh(n - 1, destination, aux, source);
    }
}

int main()
{
    int n;
    cin >> n;
    char a='A',b='B',c='C';
    toh(n,a,b,c);
    return 0;
}
