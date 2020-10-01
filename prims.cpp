#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a[5][5] = { { 0, 2, 0, 6, 0 },
                    { 2, 0, 3, 8, 5 },
                    { 0, 3, 0, 0, 7 },
                    { 6, 8, 0, 0, 9 },
                    { 0, 5, 7, 9, 0 } };


    int key[5],mst[5],parent[5];
    for(int i=0 ; i<5 ; i++)
    {
        key[i] = INT_MAX;
        mst[i] = 0;
        parent[i]=0;
    }

    key[0] = 0;
    //mst[i] = 1;

    for(int edge=1 ; edge<5 ; edge++)
    {
        int minVal = INT_MAX,index=0;
        for(int i=0 ; i<5 ; i++)
        {
            if(mst[i]==0 && key[i]<minVal)
            {
                minVal = key[i];
                index = i;
            }
        }
        mst[index] = 1;
        for(int j=0 ; j<5 ; j++)
        {
            if(a[index][j]!=0 && mst[j]==0 && key[j]>a[index][j])
            {
                key[j] = a[index][j];
                parent[j]=index;
            }
        }
    }
    int cost=0;
    for(int i=1 ; i<5 ; i++)
    {
        cout << "Edge-" << i << " :(" << parent[i] << "," << i << ") cost->" << key[i] << endl;
        cost += key[i];
    }
    cout << endl << "Minimum cost -> " << cost << endl;
    return 0;
}
    /*
    Algorithm
    1) Create a set mstSet that keeps track of vertices already included in MST.
    2) Assign a key value to all vertices in the input graph.
       Initialize all key values as INFINITE. Assign key value as 0 for the first vertex so that it is picked first.
    3) While mstSet doesn’t include all vertices
    ….a) Pick a vertex u which is not there in mstSet and has minimum key value.
    ….b) Include u to mstSet.
    ….c) Update key value of all adjacent vertices of u. To update the key values, iterate through all adjacent vertices.
       For every adjacent vertex v, if weight of edge u-v is less than the previous key value of v, update the key value as weight of u-v
       The idea of using key values is to pick the minimum weight edge from cut.
       The key values are used only for vertices which are not yet included in MST,
       the key value for these vertices indicate the minimum weight edges connecting them to the set of vertices included in MST.
    */
