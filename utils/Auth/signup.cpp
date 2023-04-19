#include <bits/stdc++.h>
using namespace std;
int file_line_count(string file_name){
    ifstream aFile (file_name);   
   std::size_t lines_count =0;
   std::string line;
   while (std::getline(aFile , line))
        ++lines_count;
    return lines_count;
}
int createUsers(string username, string password)
{
    fstream fin;
    fin.open("./data/seeds/user.csv", ios::app);
    string line;
    vector<string> elems;
    string word;
    if (fin.is_open())
    {
        int lineNum = file_line_count("./data/seeds/user.csv");
        fin << lineNum << "," << username << ",,,," << password<<"\n";
        fin.close();
    }
    return 0;
}
int signupUser(string username, string password)
{
    makeUserVerificationMap();
    if (userVerification.find(username) != userVerification.end())
    {
        return 1;
    }
    else
    {
        int resp = createUsers(username, password);
        return resp;
    }
}