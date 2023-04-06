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
};

struct Traits
{
    int age;
    string region;
    string name;
};
