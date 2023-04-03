#include "AllStruct.h"

int main() {
    cout << "Welcome to the course management system." << endl;

    User_node *users = nullptr, *current_user;
    //Import login data
    ifstream login_in;
    login_in.open("Login.txt");
    import_login_data(users, login_in);
    login_in.close();

    login(users, current_user);

    ofstream login_out;
    login_out.open("Login.txt");
    //Import school year
    auto *sy = new SchoolYear[20];
    int num_of_sy;
    ifstream schoolYear_in;
    schoolYear_in.open("School year.txt");
    importSchoolYear(sy, schoolYear_in, num_of_sy);

    ofstream schoolYear_out;
    schoolYear_out.open("School year.txt");
    //Import class
    classes_node *Classes = nullptr;
    ifstream class_in;
    class_in.open("Class.txt");
    importClass(Classes, class_in);
    //Import student to class
    classes_node *class_cur = Classes;
    while(class_cur) {
        ifstream addStudent;
        addStudentToClass(class_cur->data, addStudent);
        class_cur = class_cur->next;
    }

    ofstream class_out;
    class_out.open("Class.txt");


    int choice;
    do {
        show_menu(current_user);
        cout << "Please input your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "This function isn't programed." << endl;
                break;
            case 2:
                change_password(current_user);
                export_login_data(users, login_out);
                break;
            case 3:
                break;
            case 4:
                createNewSchoolYear(sy, num_of_sy);
                exportSchoolYear(sy, num_of_sy, schoolYear_out);
                break;
            case 5:
                addNewClass(Classes);
                exportClass(Classes, class_out);
                break;
        }
    } while (choice != 11);
    delete_user_data(users);
    return 0;
}