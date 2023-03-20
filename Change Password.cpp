#include "Login.h"

void change_password(User_node *&current_user) {
    string current_password, new_password, check_new_password;
    cout << "Enter your current password: ";
    cin >> current_password;
    while(current_password != current_user->data.password) {
        cout << "Wrong password. Please try again." << endl;
        cout << "Enter your current password: ";
        cin >> current_password;
    }
    cout << "Enter new password: ";
    cin >> new_password;
    cout << "Enter new password again: ";
    cin >> check_new_password;
    while(new_password != check_new_password) {
        cout << "Incorrect. Please try again." << endl;
        cout << "Enter new password again: ";
        cin >> check_new_password;
    }
    current_user->data.password = new_password;
    cout << "Password changed successfully.";
}