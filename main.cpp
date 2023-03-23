#include "Login.h"

int main() {
    cout << "Welcome to the course management system" << endl;
    User_node *users = nullptr, *current_user;
    ifstream fin;
    fin.open("Login.txt");
    import_login_data(users, fin);
    login (users, current_user);
    delete_user_data(users);
    fin.close();

    return 0;
}