#include <bits/stdc++.h>
#include "./queue/priority_queue.hpp"
#include "./algorithm/dijkstra.hpp"
#include "./graph/graph.hpp"
using namespace std;
int main()
{
    dijkstra();
    custom_pq();
    auto tempGraph = Graph();
    tempGraph.GenerateGraphFromCSV();
    return 0;
}