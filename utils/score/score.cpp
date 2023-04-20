#include<bits/stdc++.h>
using namespace std;

int cardinalityOfIntersectionMutuals(vector<int>Set1,vector<int>Set2){
    sort(Set1.begin(),Set1.end());
    sort(Set2.begin(),Set2.end());
    vector<int> v(Set1.size() + Set2.size());
    vector<int>::iterator it, st;
  
    it = set_intersection(Set1.begin(),
                          Set1.end(),
                          Set2.begin(),
                          Set2.end(),
                          v.begin());
    return v.size();
}
int cardinalityOfIntersectionHashtags(vector<string>Set1,vector<string>Set2){
    sort(Set1.begin(),Set1.end());
    sort(Set2.begin(),Set2.end());
    vector<string> v(Set1.size() + Set2.size());
    vector<string>::iterator it;
  
    it = set_intersection(Set1.begin(),
                          Set1.end(),
                          Set2.begin(),
                          Set2.end(),
                          v.begin());
    return v.size();
}
float score(vector<string>elems,unordered_map<int,Traits>userTraits)
{
    float scoreValue=0;
    int src=stoi(elems[1]);
    int dest=stoi(elems[2]);
    string srcPlace=userTraits[src].region;
    string destPlace=userTraits[dest].region;
    int commonHashtags=cardinalityOfIntersectionHashtags(userTraits[src].interests,userTraits[dest].interests);
    int commonFriends=cardinalityOfIntersectionMutuals(userTraits[src].following,userTraits[dest].following);
    scoreValue+=(100000/(commonHashtags+1));
    scoreValue+=(100000/(commonFriends+1));
    if (srcPlace.compare(destPlace)==0) 
        scoreValue-=(0.1*scoreValue);
    return scoreValue;
}