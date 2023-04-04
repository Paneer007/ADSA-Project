#include <bits/stdc++.h>
#include "./queue/priority_queue.hpp"
#include "./algorithm/dijkstra.hpp"
using namespace std;
int main()
{
    custom_pq();
    auto tempGraph = Graph();
    tempGraph.GenerateGraphFromCSV();
    tempGraph.PrintVerticesAndEdges();
    tempGraph.Dijkstra(1);
    return 0;
}