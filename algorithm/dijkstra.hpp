#include <bits/stdc++.h>
#include "../graph/graph.hpp"
using namespace std;
void Graph::Dijkstra(int source)
{
    unordered_map<int, int> costToReach;
    unordered_set<int> verticesSet;
    priority_queue<Edge> pq;
    pq.push({source, source, 0});
    costToReach[source] = 0;
    while (!pq.empty())
    {
        auto currVertex = pq.top();
        pq.pop();
        verticesSet.insert(currVertex.src);
        auto edges = adjList[currVertex.dest];
        for (auto edge : edges)
        {
            if (costToReach.find(edge.dest) == costToReach.end())
            {
                costToReach[edge.dest] = costToReach[currVertex.src] + edge.weight;
            }
            else
            {
                costToReach[edge.dest] = min(costToReach[currVertex.src] + edge.weight, costToReach[edge.dest]);
            }
            if (verticesSet.find(edge.dest) == verticesSet.end())
            {
                pq.push(edge);
            }
        }
    }

    cout << "cost" << endl;

    for (auto x : costToReach)
    {
        cout << x.first << " : " << x.second << endl;
    }
    return;
}