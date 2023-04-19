#include <bits/stdc++.h>
using namespace std;

unordered_map<string, string> userVerification;

void makeUserVerificationMap()
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
            userVerification[elems[1]]=elems[5];
        }
    }
}
int loginUser(string username, string password)
{
    makeUserVerificationMap();
    if(userVerification.find(username)== userVerification.end()){
        return 2;
    }else{
        auto actualPassword = userVerification[username];
        cout<<actualPassword<<endl;
        if(actualPassword== password){
            return 0;
        }else{
            return 1;
        }
    }
}