#include<bits/stdc++.h>
using namespace std;
vector<pair<int , pair<int,int> > > g;
int parent[10];

int findParent(int x)
{
    while(parent[x]!=x)
        x = parent[x];

    return x;
}

void makeUnion(int x,int y)
{
    int parent1 = findParent(x);
    int parent2 = findParent(y);
    parent[parent1] = parent[parent2];
}

int kruskalsMST(vector<pair<int , pair<int,int> > > g, int nodes)
{
    for(int i=0 ; i<nodes ; i++)
        parent[i] = i;

    int edge=1,minCost=0,i=0;
    while(edge<g.size())
    {
        int node1 = g[i].second.first;
        int node2 = g[i].second.second;
        int cost = g[i].first;
        i++;
        if(findParent(node1) != findParent(node2))
        {
            edge++;
            makeUnion(node1,node2);
            minCost += cost;
        }

    }
    return minCost;
}



int main()
{
    int nodes;
    cin >> nodes;

    for(int i=0 ; i<nodes ; i++)
    {
        int weight,node1,node2;
        cin >> weight >> node1 >> node2;
        g.push_back(make_pair(weight,make_pair(node1,node2)));
    }
    sort(g.begin(),g.end());
    cout << kruskalsMST(g,nodes);
    return 0;
}
