
#include <bits/stdc++.h>
using namespace std;
vector<string> SignupPage()
{
    system("clear");
    string username, password, region, institution, age;
    cout << "Enter username : ";
    cin >> username;
    cout << "Enter password : ";
    cin >> password;
    cout << "Enter Region : ";
    cin >> region;
    cout << "Enter Institution : ";
    cin >> institution;
    cout << "Enter Age : ";
    cin >> age;
    return {username, password, region, institution, age};
}