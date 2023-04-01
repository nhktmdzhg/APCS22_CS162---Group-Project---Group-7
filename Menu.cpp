#include "Menu.h"

void showMenu(User_node *&current_user) {
    cout<<"1. View my info."<<endl;
    cout<<"2. Change my password."<<endl;
    cout<<"3. Log out."<<endl;
    if(current_user->data.isAdmin) {
    }
}