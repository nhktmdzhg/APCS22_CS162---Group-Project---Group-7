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
    //Import school year
    auto *sy = new SchoolYear[20];
    int num_of_sy;
    ifstream schoolYear_in;
    schoolYear_in.open("School year.txt");
    importSchoolYear(sy, schoolYear_in, num_of_sy);
    schoolYear_in.close();
    //Import class
    classes_node *Classes = nullptr;
    ifstream class_in;
    class_in.open("Class.txt");
    importClass(Classes, class_in);
    class_in.close();
    //Import student to class
    classes_node *class_cur = Classes;
    while (true) {
        ifstream addStudent;
        addStudentToClass(class_cur->data, addStudent);
        if (class_cur->next) class_cur = class_cur->next;
        else break;
    }
    int choice;
    semester *current_sem = nullptr;
    if (current_user->data.isAdmin) {
        do {
            menuSchoolYearAndSem();
            cout << "Please input your choice: ";
            cin >> choice;
            if (choice == 4) {
                ofstream schoolYear_out;
                schoolYear_out.open("School year.txt", ofstream::out | ofstream::trunc);
                createNewSchoolYear(sy, num_of_sy);
                exportSchoolYear(sy, num_of_sy, schoolYear_out);
                schoolYear_out.close();
            } else if (choice == 5) {
                createSemester(sy, current_sem, num_of_sy);
                ofstream schoolYear_out;
                schoolYear_out.open("School year.txt", ofstream::out | ofstream::trunc);
                exportSchoolYear(sy, num_of_sy, schoolYear_out);
                schoolYear_out.close();
            } else if (choice == 6) {
                choose_current_sem(sy, num_of_sy, current_sem);
            } else
                cout << "Wrong choice, choose again." << endl;
        } while (choice != 3 && !current_sem);
    }


    course_node *added;


    do {
        show_menu(current_user);
        cout << "Please input your choice: ";
        cin >> choice;
        if (choice == 1) {
            cout << "This function isn't programed." << endl;
        } else if (choice == 2) {
            ofstream login_out;
            login_out.open("Login.txt", ofstream::out | ofstream::trunc);
            change_password(current_user);
            export_login_data(users, login_out);
            login_out.close();
        } else if (choice == 3)
            break;
        else if (choice == 4) {
            if (current_user->data.isAdmin) {
                ofstream class_out;
                class_out.open("Class.txt", ofstream::out | ofstream::trunc);
                addNewClass(Classes);
                exportClass(Classes, class_out);
                class_out.close();
            }
        } else if (choice == 5) {
            if (current_user->data.isAdmin) {
                class_cur = class_cur->next;
                while (true) {
                    ifstream addStudent;
                    addStudentToClass(class_cur->data, addStudent);
                    if (class_cur->next) class_cur = class_cur->next;
                    else break;
                }
                cout << "1st year student is added from file." << endl;
            }
        } else if (choice == 6) {
            if (current_user->data.isAdmin) {
                addCourse(current_sem, added);
            }
        } else if (choice == 7) {
            if (current_user->data.isAdmin) {
                ifstream course_in;
                importStudenttoCourse(added->data, course_in);
                course_in.close();
            }
        } else if (choice == 8) {
            if (current_user->data.isAdmin) {
                viewListofCourse(current_sem->head);
            }
        } else
            cout << "Wrong choice, choose again." << endl;
    } while (choice != 3);
    delete_user_data(users);
    class_cur = Classes;
    while (class_cur) {
        deleteStudent(class_cur->data.head);
        class_cur = class_cur->next;
    }
    deleteClass(Classes);
    for (int i = 0; i < num_of_sy; i++)
        deleteSemester(sy[i]);
    delete[] sy;
    return 0;
}