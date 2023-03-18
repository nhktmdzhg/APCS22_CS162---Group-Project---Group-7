#include <iostream>
#include <string>

using namespace std;

struct User 

    string username;
    string password;
    bool isAdmin;
};

const int NUM_USERS = 3;
User users[NUM_USERS] = {
    {"admin", "admin", true},
    {"student1", "password1", false},
    {"student2", "password2", false}
};

bool login() {
    string username, password;
    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;

    for (int i = 0; i < NUM_USERS; i++) {
        if (users[i].username == username && users[i].password == password) {
            cout << "Welcome, " << username << endl;
            return users[i].isAdmin;
        }
    }

    cout << "Incorrect username or password. Please try again."<<endl;
    return false;
}

int main() {
    cout << "Welcome to the course management system"<<endl;

    bool isAdmin = false;
    while (!isAdmin) {
        isAdmin = login();
    }



    return 0;
}
