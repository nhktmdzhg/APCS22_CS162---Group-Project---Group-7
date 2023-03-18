#include "Login.h"

int main() {
    cout << "Welcome to the course management system" << endl;
    User_node *users = nullptr, *current_user;
    login (users, current_user);
    return 0;
}