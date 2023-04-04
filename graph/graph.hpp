#include <bits/stdc++.h>
#include <iostream>
#include <string.h>
#include "../utils/utils.hpp"

using namespace std;

struct Edge
{
    int src;
    int dest;
    int weight;

    bool operator<(const Edge &rhs) const
    {
        return weight < rhs.weight;
    }
};

struct Traits
{
    int age;
    string region;
    string name;
};

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

    void Dijkstra(int);

    void GenerateGraphFromCSV()
    {
        GenerateVerticesFromCSV();
        GenerateEdgesFromCSV();
    }

    void PrintVerticesAndEdges(){
        PrintEdges();
        PrintVertices();
    }
};
