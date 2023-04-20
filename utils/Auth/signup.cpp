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
int createUsers(vector<string>creds)
{
    fstream fin;
    fin.open("./data/seeds/user.csv", ios::app);
    string line;
    vector<string> elems;
    string word;
    if (fin.is_open())
    {
        int lineNum = file_line_count("./data/seeds/user.csv");
        fin << lineNum << "," << creds[0] << ","<<creds[4]<<","<<creds[2]<<","<<creds[3]<<"," << creds[1]<<"\n";
        fin.close();
    }
    return 0;
}
int signupUser(vector<string>credentials)
{
    string username = credentials[0];
    string password = credentials[1];
    makeUserVerificationMap();
    if (userVerification.find(username) != userVerification.end())
    {
        return 1;
    }
    else
    {
        int resp = createUsers(credentials);
        return resp;
    }
}