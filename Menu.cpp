#include "Menu.h"

void show_menu(User_node *current_user) {
    cout << "1. View my info." << endl;
    cout << "2. Change my password." << endl;
    cout << "3. Log out." << endl;
    if (current_user->data.isAdmin) {
        cout << "4. Create new school year." << endl;
        cout << "5. Create new class for 1-year student." << endl;
        cout << "6. Add student to class." << endl;
        cout << "7. Create new semester." << endl;
        cout << "8. Add a course." << endl;
        cout << "9. Upload student enrolled in the course." << endl;
        cout << "10. View the list of course." << endl;
        cout << "11. Quit the program." << endl;
    }
}