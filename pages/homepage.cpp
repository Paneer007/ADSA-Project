#include <bits/stdc++.h>
using namespace std;
string currentUser;
void homepage(string user)
{
    currentUser = user;
    while (true)
    {
        system("clear");
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
            BlockIO("addedFriend");
            continue;
        }

        case 2:
        {
            int choice = UpdateProfilePage();
            switch(choice){
                case 1:
                    {
                        continue;
                    }
                case 2:
                case 3:
                case 4:
                    cout<<"WIP"<<endl;
            }
            BlockIO("updatedProfile");
            continue;
        }

        case 3:
        {
            int count = SearchForRecommendationPage();
            // ReturnRecommendations();
            BlockIO("Recommended");
            continue;
        }

        case 4:
        {
            currentUser = "";
            BlockIO("LoggedOut");
            continue;
        }

        case 5:
        {
            currentUser = "";
            exit(0);
            continue;
        }
        }
    }
}