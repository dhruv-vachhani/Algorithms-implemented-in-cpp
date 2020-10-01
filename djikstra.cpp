#include<bits/stdc++.h>
using namespace std;

void dijkstra(int graph[9][9],int src)
{
    int dist[9],found[9];

    for(int i=0 ; i<9 ; i++)
    {
        dist[i] = INT_MAX;
        found[i] = 0;
    }

    dist[src] = 0;
    for(int i=0 ; i<9-1 ; i++)
    {
        int min=INT_MAX,min_index=0;
        for(int j=0 ; j<9 ; j++)
        {
            if(found[j]==0 && dist[j]<=min)
            {
                min = dist[j];
                min_index = j;
            }
        }
        found[min_index] = 1;
        for(int k=0 ; k<9 ; k++)
        {
            if(found[k]==0 && graph[min_index][k] && dist[min_index] != INT_MAX && dist[min_index]+graph[min_index][k] < dist[k])
                dist[k] = dist[min_index]+graph[min_index][k];
        }
    }
    for(int i=0 ; i<9 ; i++)
        cout << i+1 <<" ->" << dist[i]<<"\n";
}

int main()
{
    int graph[9][9] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    dijkstra(graph,0);

    return 0;
}
