#include<bits/stdc++.h>
#include "../../graph/graph.hpp"
using namespace std;

// void makeUsersMap()
// {
//     fstream fin;
//     fin.open("./data/seeds/user.csv", ios::in);
//     string line;
//     vector<string> elems;
//     string word;
//     if (fin.is_open())
//     {
//         getline(fin, line);
//         while (getline(fin, line))
//         {
//             elems.clear();
//             stringstream str(line);
//             while (getline(str, word, ','))
//                 elems.push_back(word);
//             userIDMapping[elems[1]]=stoi(elems[0]);
//         }
//     }
// }

bool cmp(pair<int,int>a,pair<int,int>b)
{
    return a.second<b.second;
}
void ReturnRecommendations(int count,string currentUser){
    int userID=userIDMapping[currentUser];
    int wait;

    Graph graph;
    graph.GenerateGraphFromCSV();
    cout<<userID<<endl;

    DijkstraReturn returned=graph.Dijkstra(userID);
    unordered_map<int,int>recommendationScore;
    for (auto x:returned.costToReach)
    {
        cout<<x.first<<" "<<x.second<<endl;
        recommendationScore[x.first]=x.second;
    }
    cout<<"this is the gap"<<endl;
    for (auto x:returned.userVisit){
cout<<x.first<<" "<<x.second<<endl;
        recommendationScore[x.first]-=x.second;
    }
        
    vector<pair<int,int>>scorePairs;
    for (auto x:recommendationScore)
    {
        scorePairs.push_back({x.second,x.first});
    }
    sort(scorePairs.begin(),scorePairs.end(),cmp);
    for (int i=0;i<count;i++)
    {
        cout<<scorePairs[i].first<<" "<<scorePairs[i].second<<endl;
    }
    cin>>wait;
    return;
}