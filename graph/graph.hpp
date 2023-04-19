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
                userTraits[stoi(elems[1])].following.push_back(stoi(elems[2]));
                userTraits[stoi(elems[2])].following.push_back(stoi(elems[1]));
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
                Traits traits = {stoi(elems[2]), elems[3], elems[1], elems[4]};
                userTraits[index] = traits;
            }
        }
    }

    void PrintVertices()
    {
        cout << "\n user traits \n";
        for (auto user : userTraits)
        {
            cout << user.first << " " << user.second.age << " " << user.second.name << " " << user.second.region << user.second.institution << endl;
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

    void PrintHashtags()
    {
        cout << "\n user hash tags \n";
        for (auto user : userTraits)
        {
            for (auto tags : user.second.interests)
            {
                cout << tags << " ";
            }
            cout << endl;
        }
    }

    void GenerateHashtagsFromCSV()
    {
        fstream fin;
        fin.open("./data/seeds/hashtags.csv", ios::in);
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
                int index = stoi(elems[2]);
                userTraits[index].interests.push_back(elems[1]);
            }
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
        GenerateHashtagsFromCSV();
    }

    void PrintVerticesAndEdges()
    {
        PrintEdges();
        PrintVertices();
        PrintHashtags();
    }

    void Dijkstra(int source)
    {
        unordered_map<int,int>userVisit;
        unordered_map<int, int> costToReach;
        unordered_set<int> verticesSet;
        FibonacciHeap pq;
        pq.push(source, source, 0);
        costToReach[source] = 0;
        while (!pq.isEmpty())
        {
            auto currVertex = pq.top();
            pq.pop();
            verticesSet.insert(currVertex.src);
            auto edges = adjList[currVertex.dest];
            for (auto edge : edges)
            {
                if(userVisit.find(edge.dest)== userVisit.end()){
                    userVisit[edge.dest]=0;
                }else{
                    userVisit[edge.dest]=userVisit[edge.dest]+1;
                }
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
                    cout<<edge.src<<" "<<edge.dest<<" "<<edge.weight<<endl;
                    pq.push(edge.src,edge.dest,edge.weight);
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
