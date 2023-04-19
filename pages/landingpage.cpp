#include <bits/stdc++.h>
#include "./homepage.cpp"
using namespace std;
int landingpage()
{
    int x;
    while (true)
    {
        system("clear");
        int choice = LandingPage();
        pair<string, string> creds;
        int authStatus;
        switch (choice)
        {
        case 1:
            creds = LoginPage();
            authStatus = loginUser(creds.first, creds.second);
            switch (authStatus)
            {
            case 0:
                cout<<"logged in"<<endl;
                homepage(creds.first);
                continue;
            case 1:
                BlockIO("invalid");
                cout << "Incorrect username and password. Try again" << endl;
                continue;
            case 2:
                BlockIO("userNotFound");
                cout << "Account does not exist. Please sign up" << endl;
                continue;
            }
            continue;
        case 2:
            creds = SignupPage();
            authStatus = signupUser(creds.first, creds.second);
            switch (authStatus)
            {
            case 0:
                BlockIO("accountMade");
                continue;
            case 1:
                BlockIO("accountExists");
                continue;
            }
            continue;
        case 3:
            exit(0);
            continue;
        default:
            exit(1);
            continue;
        }
    }
}