#include <bits/stdc++.h>
#include <iostream>
#include <string.h>

using namespace std;

class Graph
{
    unordered_map<int, vector<Edge>> adjList;
    unordered_map<int, Traits> userTraits;

private:
    vector<string> split(string &s, char delim)
    {
        vector<string> result;
        stringstream ss(s);
        string item;
        while (getline(ss, item, delim))
        {
            result.push_back(item);
        }
        return result;
    }

    void GenerateEdgesFromCSV()
    {
        fstream fin;
        fin.open("./data/seeds/relation.csv", ios::in);
        string line;
        vector<string> elems;
        string word;
        if (fin.is_open())
        {
            getline(fin, line);
            while (getline(fin, line))
            {
                elems.clear();
                stringstream str(line);
                while (getline(str, word, ','))
                    elems.push_back(word);
                int scoreRel = score();
                Edge relationEdge = {stoi(elems[2]), stoi(elems[1]), scoreRel};
                Edge relationEdgeTwo = {stoi(elems[1]), stoi(elems[2]), scoreRel};
                adjList[stoi(elems[2])].push_back(relationEdge);
                adjList[stoi(elems[1])].push_back(relationEdgeTwo);
            }
        }
    }

    void GenerateVerticesFromCSV()
    {
        fstream fin;
        fin.open("./data/seeds/user.csv", ios::in);
        string line;
        vector<string> elems;
        string word;
        if (fin.is_open())
        {
            getline(fin, line);
            while (getline(fin, line))
            {
                elems.clear();
                stringstream str(line);
                while (getline(str, word, ','))
                    elems.push_back(word);
                int index = stoi(elems[0]);
                Traits traits = {stoi(elems[2]), elems[3], elems[1]};
                userTraits[index] = traits;
            }
        }
    }

    void PrintVertices()
    {
        cout << "\n user traits \n";
        for (auto user : userTraits)
        {
            cout << user.first << " " << user.second.age << " " << user.second.name << " " << user.second.region << endl;
        }
    }

    void PrintEdges()
    {
        cout << "\n user relation \n";
        auto user = adjList[1];
        for (auto x : user)
        {
            cout << "dest : " << x.dest;
            cout << "src : " << x.src;
            cout << "score : " << x.weight;
            cout << endl;
        }
    }

public:
    Graph()
    {
    }

    void GenerateGraphFromCSV()
    {
        GenerateVerticesFromCSV();
        GenerateEdgesFromCSV();
    }

    void PrintVerticesAndEdges()
    {
        PrintEdges();
        PrintVertices();
    }

    void Dijkstra(int source)
    {
        unordered_map<int, int> costToReach;
        unordered_set<int> verticesSet;
        Fibonacci_Heap pq;
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
};
