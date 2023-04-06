#include <bits/stdc++.h>
#include "./utils/utils.hpp"
#include "./queue/priority_queue.hpp"
#include "./graph/graph.hpp"
using namespace std;
int main()
{
    auto tempGraph = Graph();
    tempGraph.GenerateGraphFromCSV();
    tempGraph.PrintVerticesAndEdges();
    tempGraph.Dijkstra(1);
    return 0;
}