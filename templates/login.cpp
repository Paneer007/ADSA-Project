#include<bits/stdc++.h>
using namespace std;
pair<string,string> LoginPage(){
    system("clear");
    string username,password;
    cout<<"Enter username : ";
    cin>>username;
    cout<<"Enter password : ";
    cin>>password;
    return {username,password};
}