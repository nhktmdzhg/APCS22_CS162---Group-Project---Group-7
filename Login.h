#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct User {
    string username;
    string password;
    bool isAdmin;
    User() : username(), password(), isAdmin(false) {}
};

struct User_node {
    User data;
    User_node *next;
    User_node() : data(), next(nullptr) {}
};

void import_login_data (User_node *&users, ifstream &fin);

void login(User_node *users, User_node *&current_user);

void change_password(User_node *&current_user);

void delete_user_data(User_node *&users);

void export_login_data(User_node *users, ofstream &fout);