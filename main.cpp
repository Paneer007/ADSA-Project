#include <bits/stdc++.h>
#include "./utils/utils.hpp"
// #include "./graph/graph.hpp"
#include "./templates/templates.hpp"
#include "./pages/pages.hpp"
using namespace std;
int main()
{
    // while (true)
    // {
    //     system("clear");
    //     landingpage();
    // }

//      FibonacciHeap pq;
//     // pq.push(1,2,10);
//     // pq.push(3,4,12);
//     // pq.push(2,7,4);
//     // pq.push(1,4,5);
//     // pq.push(5,6,11);
//     // // pq.display();
//     // pq.pop();
//     // cout<<1<<endl;
//     // // pq.display();
//     // pq.push(1,41,17);
//     // pq.pop();
//     // cout<<122<<endl;

//     // // pq.display();
//     // pq.pop();
//     // cout<<1222<<endl;

//     // // pq.display();
//     // pq.pop();
//     // cout<<1322<<endl;

//     // // pq.display();
//     // pq.pop();
//     // cout<<14222<<endl;
//     // // pq.display();
//     // pq.pop();
//     // cout<<1522<<endl;
//     // // pq.display();
//     // pq.pop();
//     // cout<<1622<<endl;
//     // // pq.display();
//     // pq.pop();
//     // cout<<17222<<endl;
//     // // pq.display();
//     // pq.pop();
//     // cout<<18222<<endl;
//     // // pq.display();
//     // pq.pop();
//     // cout<<1922<<endl;
//     // // pq.display();

//     pq.push(1,2,10);
//     pq.push(3,4,12);
//     pq.push(2,7,4);
//     pq.push(1,4,5);
//     pq.push(5,6,11);// pq.push(1,2,10);
//     pq.push(3,4,121);
//     //pq.push(2,7,41);
//    // pq.push(1,4,52);
//     pq.push(5,6,113);// pq.push(1,2,10);
//     pq.push(3,4,124);
//     pq.push(2,7,45);
//     pq.push(1,4,56);
//     pq.push(5,6,171);// pq.push(1,2,10);
//   //  pq.push(3,4,129);
//     //pq.push(2,7,410);
//     pq.push(1,4,523);
//   //  pq.push(5,6,1441);// pq.push(1,2,10);
//     // pq.push(3,4,1122);
//     //pq.push(2,7,4214);
//     pq.push(1,4,422);
//     // pq.push(5,6,12121);// pq.push(1,2,10);
//     pq.push(3,4,1223);
//     //pq.push(2,7,4423);
//     // pq.push(1,4,1935);
//     // pq.push(5,6,12891);// pq.push(1,2,10);
//     // pq.push(3,4,18322);
//     // pq.push(2,7,418921);
//     // pq.push(1,4,192015);
//     // pq.push(5,6,12191);// pq.push(1,2,10);
//     // pq.push(3,4,1292);
//     // pq.push(2,7,4292);
//     // pq.push(1,4,19125);
//     // pq.push(5,6,148491);// pq.push(1,2,10);
//     // pq.push(3,4,122023);
//     // pq.push(2,7,45893);
//     // pq.push(1,4,10205);
//     // pq.push(5,6,13201);// pq.push(1,2,10);
//     // pq.push(3,4,148322);
//     // pq.push(2,7,439012);
//     // pq.push(1,4,53902);
//     // pq.push(5,6,1490491);

//     // pq.display();
//     pq.pop();
//     cout<<1<<endl;
//     // pq.display();
//     pq.push(1,41,17);
//     // pq.display();

//     cout<<12<<endl;
//     pq.pop();
//     cout<<122<<endl;

//     // pq.display();
//     pq.pop();
//     cout<<1222<<endl;

//     // pq.display();
//     pq.pop();
//     cout<<1322<<endl;

//     // pq.display();
//     pq.pop();
//     cout<<14222<<endl;
//     // pq.display();
//     pq.pop();
//     cout<<1522<<endl;
//     // pq.display();
//     pq.pop();
//     cout<<1622<<endl;
//     // pq.display();
//     pq.pop();
//     cout<<17222<<endl;
//     // pq.display();
//     pq.pop();
//     cout<<18222<<endl;
//     // pq.display();
//     pq.pop();
//     cout<<1922<<endl;
//     // pq.display();
    Edge pq;
    cout<<pq.weight<<endl;
    auto tempGraph = Graph();
    tempGraph.GenerateGraphFromCSV();
    tempGraph.PrintVerticesAndEdges();
    tempGraph.Dijkstra(1);    return 0;
}