#include <bits/stdc++.h>
using namespace std;

void BlockIO(string inputType)
{
    system("clear");
    string x;
    if (inputType == "invalid")
    {
        cout << "invalid response. Press a key to return ";
        cin >> x;
    }
    else if (inputType == "incorrect")
    {
        cout << "incorrect response. Press a key to return ";
        cin >> x;
    }
    else if (inputType == "userNotFound")
    {
        cout << "account not found. Press a key to return ";
        cin >> x;
    }
    else if (inputType == "accountExists")
    {
        cout << "account found. Please try another credentials. Press a key to return ";
        cin >> x;
    }
    else if (inputType == "addedFriend")
    {
        cout << "Successfully added a friend. Press a key to return ";
        cin >> x;
    }
    else if (inputType == "friendDoesNotExist")
    {
        cout << "The given user doesn't exists. Press a key to return ";
        cin >> x;
    }
    else if (inputType == "AlreadyFriends")
    {
        cout << "You are already friends with given user. Press a key to return ";
        cin >> x;
    }
    else if (inputType == "hashExists")
    {
        cout << "HashTag already exists. Press a key to return ";
        cin >> x;
    }
    else if (inputType == "displayed recommendations")
    {
        cout << "Successfully displayed recommendation. Press a key to exit ";
        cin >> x;
    }else if(inputType == "LoggedOut"){
        cout << "Successfully logged out. Press a key to exit ";
        cin >> x;
    }else if (inputType == "accountMade"){
        cout<<"Account successfully created. Press a key to continue ";
        cin>>x;
    }else if (inputType=="addedHash"){
        cout<<"Hashtag added successfully. Press a key to continue ";
        cin>>x;
    }
}