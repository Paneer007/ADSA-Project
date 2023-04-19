#include <bits/stdc++.h>
#include "./homepage.cpp"
using namespace std;
int landingpage()
{
    int x;
    bool flag = true;
    while (flag)
    {
        system("clear");
        int choice = LandingPage();
        int authStatus;
        switch (choice)
        {
        case 1:
        {
            auto creds = LoginPage();
            authStatus = loginUser(creds.first, creds.second);
            switch (authStatus)
            {
            case 0:
                cout << "logged in" << endl;
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
        }

        case 2:
        {
            auto creds = SignupPage();
            authStatus = signupUser(creds);
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
        }

        case 3:
        {
            flag = false;
            break;
        }

        default:
        {
            exit(1);
            break;
        }
        }
    }
    return 0;
}