#include "Login.h"

void login(User_node *users, User_node *&current_user) {

    // Log in to system
    string username, password;
    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;

    // Check if the password and username are correct
    while (true) {
        User_node *cur = users;
        while (cur) {
            if (cur->data.username == username && cur->data.password == password) {
                cout << "Welcome, " << username << endl;
                current_user = cur;
                break;
            }
            cur = cur->next;
        }
        cout << "Incorrect username or password. Please try again." << endl;
    }
}