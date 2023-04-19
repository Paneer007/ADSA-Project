#include <bits/stdc++.h>

unordered_map<string,int> userIDMapping;

set<pair<int,int>>RelationEdges;

void makeRelationMap()
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
                RelationEdges.insert({stoi(elems[2]), stoi(elems[1])});
                RelationEdges.insert({stoi(elems[1]), stoi(elems[2])});
            }
        }
    }

void makeUsersMap()
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
            userIDMapping[elems[1]]=stoi(elems[0]);
        }
    }
}
int createRelation(int user_id, int friend_id)
{
    fstream fin;
    fin.open("./data/seeds/relation.csv", ios::app);
    string line;
    vector<string> elems;
    string word;
    if (fin.is_open())
    {
        int lineNum = file_line_count("./data/seeds/relation.csv");
        fin << lineNum<<","<<user_id<<","<<friend_id<<"\n";
        fin.close();
    }
    return 0;
}

int AddAFriend(string user, string friendname)
{
    makeUsersMap();
    makeRelationMap();

    auto user_id = userIDMapping[user];
    if(userIDMapping.find(friendname)==userIDMapping.end()){
        return 1;
    }
    auto friend_id = userIDMapping[friendname];
    if (RelationEdges.find({user_id,friend_id})!= RelationEdges.end()){
        return 2;
    }

    createRelation(user_id,friend_id);

    return 0;

}
