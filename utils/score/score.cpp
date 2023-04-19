#include<bits/stdc++.h>
using namespace std;

int cardinalityOfIntersection(vector<int>Set1,vector<int>Set2){
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

int score()
{
    return rand() % 10000;
}