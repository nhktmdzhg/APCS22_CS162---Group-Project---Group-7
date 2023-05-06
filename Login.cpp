#include "Login.h"

void import_login_data(User_node *&users, ifstream &fin) {
    User_node *cur;
    string line;

    while (getline(fin, line)) {
        if (!users) {
            users = new User_node;
            cur = users;
        } else {
            cur->next = new User_node;
            cur = cur->next;
        }

        stringstream split(line);
        string username, password, isAdminStr;

        getline(split, username, ' ');
        getline(split, password, ' ');
        getline(split, isAdminStr);

        cur->data.username = username;
        cur->data.password = password;
        cur->data.isAdmin = (isAdminStr == "1");

        getline(fin, cur->data.adminName);
        getline(fin, cur->data.birthday);

        cur->next = nullptr;
    }
}


void login(User_node *users, User_node *&current_user) {
    while (true) {
        // Log in to system
        string username, password;
        cout << "Enter your username: ";
        cin >> username;
        cout << "Enter your password: ";
        cin >> password;
        User_node *cur = users;
        while (cur) {
            if (cur->data.username == username && cur->data.password == password) {
                cout << "Welcome " << username << endl;
                current_user = cur;
                return;
            }
            cur = cur->next;
        }
        cout << "Incorrect username or password. Please try again." << endl;
    }
}


void change_password(User_node *&current_user) {
    string current_password, new_password, check_new_password;
    cout << "Enter your current password: ";
    cin >> current_password;
    while (current_password != current_user->data.password) {
        cout << "Wrong password. Please try again." << endl;
        cout << "Enter your current password: ";
        cin >> current_password;
    }
    cout << "Enter new password: ";
    cin >> new_password;
    cout << "Enter new password again: ";
    cin >> check_new_password;
    while (new_password != check_new_password) {
        cout << "Incorrect. Please try again." << endl;
        cout << "Enter new password again: ";
        cin >> check_new_password;
    }
    current_user->data.password = new_password;
    cout << "Password changed successfully." << endl;
}

void delete_user_data(User_node *&users) {
    while (users) {
        User_node *tmp = users;
        users = users->next;
        delete tmp;
    }

}

void export_login_data(User_node *users, ofstream &fout) {
    while (users) {
        fout << users->data.username << " " << users->data.password << " " << (int) users->data.isAdmin << endl;
        fout << users->data.Name << endl;
        fout << users->data.birthday << endl;
        users = users->next;
    }
}

void view_in4(User_node *current_user) {
    cout << "Name: " << current_user->data.Name << endl;
    cout << "Birthday: " << current_user->data.birthday << endl;
}