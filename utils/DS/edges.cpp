#include <bits/stdc++.h>
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

    Edge(){
        weight=0;
    }
    Edge (int s , int d, int w){
        src= s;
        dest = d;
        weight= w;
    }
};

struct Traits
{
    int age;
    string region;
    string name;
    string institution;
    vector<int> following;
    vector<string> interests;
};


