#include <bits/stdc++.h>
#include "../../graph/graph.hpp"
using namespace std;

unordered_map<int, string> reverseUserIDMapping;

int NumberOfRelation(int user_id)
{
    fstream fin;
    fin.open("./data/seeds/relation.csv", ios::in);
    string line;
    vector<string> elems;
    string word;
    int count = 0;
    if (fin.is_open())
    {
        getline(fin, line);
        while (getline(fin, line))
        {
            elems.clear();
            stringstream str(line);
            while (getline(str, word, ','))
                elems.push_back(word);
            int user1_id = stoi(elems[1]);
            int user2_id = stoi(elems[2]);
            if (user1_id == user_id)
            {
                count++;
            }
            else if (user2_id == user_id)
            {
                count++;
            }
        }
    }
    return count;
}

void reverseUserMap()
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
            reverseUserIDMapping[stoi(elems[0])] = elems[1];
        }
    }
}

vector<string> celebs;

void GenerateCelebs()
{
    fstream fin;
    fin.open("./data/seeds/celebs.csv", ios::in);
    string line;
    vector<string> elems;
    string word;
    int count = 0;
    if (fin.is_open())
    {
        getline(fin, line);
        while (getline(fin, line))
        {
            elems.clear();
            stringstream str(line);
            while (getline(str, word, ','))
                elems.push_back(word);
            celebs.push_back(elems[1]);
        }
    }
}

void PrintRecommendedCelebs()
{
    system("clear");
    cout << "The recommended accounts to follow : " << endl;
    for (auto x : celebs)
    {
        cout << x << endl;
    }
    cout << endl;
    string x;
    cout << "Press any key to continue " << endl;
    cin >> x;
}

void GenerateGraphRecommendations(int userID,int count)
{
    string x;
    Graph graph;
    graph.GenerateGraphFromCSV();

    DijkstraReturn returned = graph.Dijkstra(userID);
    unordered_map<int, int> recommendationScore;
    for (auto x : returned.costToReach)
    {
        recommendationScore[x.first] = x.second;
    }
    for (auto x : returned.userVisit)
    {
        recommendationScore[x.first] -= x.second * .5;
    }

    vector<pair<int, int>> scorePairs;
    for (auto x : recommendationScore)
    {
        scorePairs.push_back({x.second, x.first});
    }
    sort(scorePairs.begin(), scorePairs.end());
    system("clear");
    cout << "the recommended accounts are : "<<endl;
    for (int i = 0; i < count; i++)
    {
        cout << reverseUserIDMapping[scorePairs[i].second] << endl;
    }

    cout << "Press any key to continue : ";
    cin >> x;
}

int ReturnRecommendations(int count, string currentUser)
{
    system("clear");
    makeUsersMap();
    reverseUserMap();
    int userID = userIDMapping[currentUser];
    if (NumberOfRelation(userID) < 15)
    {
        GenerateCelebs();
        PrintRecommendedCelebs();
    }
    else
    {
        GenerateGraphRecommendations(userID,count);
    }

    return 0;
}