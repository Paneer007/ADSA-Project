#include <bits/stdc++.h>
using namespace std;
set<pair<int, string>> HashtagsMap;
void makeHashtagMap()
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
            HashtagsMap.insert({stoi(elems[2]), elems[1]});
        }
    }
}

void AddHashTagToCSV(int user_id, string hashtag){
     fstream fin;
    fin.open("./data/seeds/hashtags.csv", ios::app);
    string line;
    vector<string> elems;
    string word;
    if (fin.is_open())
    {
        int lineNum = file_line_count("./data/seeds/hashtags.csv");
        fin << lineNum<<","<<hashtag<<","<<user_id<<"\n";
        fin.close();
    }
}

int UpdateHashtag(string currentUser, string hashtag)
{
    makeUsersMap();
    makeHashtagMap();
    int user_id = userIDMapping[currentUser];
    if(HashtagsMap.find({ user_id,hashtag})!= HashtagsMap.end()){
        return 1;
    }else{
        AddHashTagToCSV(user_id,hashtag);
        return 0;
    }
}