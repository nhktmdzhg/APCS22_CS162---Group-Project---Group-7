#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

struct User {
    string username;
    string password;
    bool isAdmin;
    string Name;
    string birthday;
};

struct User_node {
    User data;
    User_node *next;
};

void import_login_data (User_node *&users, ifstream &fin);

void login(User_node *users, User_node *&current_user);

void change_password(User_node *&current_user);

void delete_user_data(User_node *&users);

void export_login_data(User_node *users, ofstream &fout);

void view_in4(User_node *current_user);