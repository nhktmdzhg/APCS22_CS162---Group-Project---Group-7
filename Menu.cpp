#include "Menu.h"

void show_menu(User_node *current_user) {
    cout << "1. View my info." << endl;
    cout << "2. Change my password." << endl;
    cout << "3. Log out and close the program." << endl;
    if (current_user->data.isAdmin) {
        cout << "4. Create new class for 1-year student." << endl;
        cout << "5. Add student to the recently added class." << endl;
        cout << "6. Add a course." << endl;
        cout << "7. Upload student enrolled in the course." << endl;
        cout << "8. View the list of course." << endl;
        cout << "9. Update course information." << endl;
        cout << "10. Add student to the course." << endl;
        cout << "11. Remove a student from the course." << endl;
        cout << "12. Delete a course." << endl;
        cout << "13. View a list of classes." << endl;
        cout << "14. View a list of student in class." << endl;
        cout << "15. View a list of courses." << endl;
        cout << "16. View a list of student in courses." << endl;
        cout << "17. Export a list of student in a course to CSV file." << endl;
        cout << "18. Import the scoreboard of a course." << endl;
        cout << "19. View the scoreboard of a course." << endl;
        cout << "20. Update a student's result." << endl;
        cout << "21. View the scoreboard of a class." << endl;
    } else {
        cout << "4. View list of my course." << endl;
        cout << "5. View my scoreboard." << endl;
    }
}

void menuSchoolYearAndSem() {
    cout << "1. View my info." << endl;
    cout << "2. Change my password." << endl;
    cout << "3. Log out and close the program." << endl;
    cout << "4. Create new school year." << endl;
    cout << "5. Create new semester." << endl;
    cout << "6. Choose current semester." << endl;
}