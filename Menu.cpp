#include "Menu.h"

void show_menu(User_node *current_user) {
    cout << "1. View my info." << endl;
    cout << "2. Change my password." << endl;
    cout << "3. Log out." << endl;
    if (current_user->data.isAdmin) {
        cout << "4. Create new class for 1-year student." << endl;
        cout << "5. Add student to class." << endl;
        cout << "6. Add a course." << endl;
        cout << "7. Upload student enrolled in the course." << endl;
        cout << "8. View the list of course." << endl;
    }
}

void menuSchoolYearAndSem() {
    cout << "4. Create new school year."<<endl;
    cout << "5. Create new semester." <<endl;
    cout << "6. Choose current semester." <<endl;
}