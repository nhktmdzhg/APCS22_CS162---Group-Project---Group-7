#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

struct User {
    string username;
    string password;
    bool isAdmin;
};

struct User_node {
    User data;
    User_node *next;
};

void import_login_data (User_node *&users, ifstream fin);

void login(User_node *users, User_node *&current_user);

void show_menu();

void change_password(User_node *&current_user);

void delete_user_data(User_node *&users);