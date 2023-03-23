#include "Login.h"

void login(User_node *users, User_node *&current_user) {

    // Log in to system
    string username, password;
    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;
    bool true_user = false;
    // Check if the password and username are correct
    while (!true_user) {
        User_node *cur = users;
        while (cur) {
            if (cur->data.username == username && cur->data.password == password) {
                true_user = true;
                cout << "Welcome, " << username << endl;
                current_user = cur;
                break;
            }
            cur = cur->next;
        }
        if (!true_user) cout << "Incorrect username or password. Please try again." << endl;
    }
}

void delete_user_data(User_node *&users) {
    while (users)
    {
        User_node *tmp = users;
        users = users->next;
        delete tmp;
    }
    
}