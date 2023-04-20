#include <bits/stdc++.h>
using namespace std;
string currentUser;
void homepage(string user)
{
    currentUser = user;
    bool flag = true;
    while (flag)
    {
        system("clear");
        cin.sync();
        int choice = HomePage();
        switch (choice)
        {
        case 1:
        {
            string userFriendName = AddAFriendPage();
            int type = AddAFriend(currentUser, userFriendName);
            switch (type)
            {
            case 1:
            {
                BlockIO("friendDoesNotExist");
                continue;
            }
            case 2:
            {
                BlockIO("AlreadyFriends");
                continue;
            }
            case 0:
            {
                BlockIO("addedFriend");
                continue;
            }
            }
            continue;
        }

        case 2:
        {
            auto choice = AddHashTagsToProfile();
            auto res = UpdateHashtag(currentUser, choice.second);
            switch (res)
            {
            case 1:
                BlockIO("hashExists");
            case 0:
                BlockIO("addedHash");
            }
            continue;
        }

        case 3:
        {
            int count = SearchForRecommendationPage();
            ReturnRecommendations(count, currentUser);
            BlockIO("displayed recommendations");
            continue;
        }

        case 4:
        {
            currentUser = "";
            BlockIO("LoggedOut");
            flag = false;
            continue;
        }

        case 5:
        {
            currentUser = "";
            exit(0);
            continue;
        }
        default:
        {
            fflush(stdin);
            cin>>ws;
            cin.sync();
            BlockIO("invalid");
        }
        }
        
    }
}