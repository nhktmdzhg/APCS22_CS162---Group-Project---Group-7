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
    int choice = 0;
    semester *current_sem = nullptr;
    SchoolYear current_sy;
    int cur_sem;
    if (current_user->data.isAdmin) {
        do {
            menuSchoolYearAndSem();
            cout << "Please input your choice: ";
            cin >> choice;
            if (choice == 1) {
                view_in4(current_user);
            } else if (choice == 2) {
                ofstream login_out;
                login_out.open("Login.txt", ofstream::out | ofstream::trunc);
                change_password(current_user);
                export_login_data(users, login_out);
                login_out.close();
            } else if (choice == 3)
                break;
            else if (choice == 4) {
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
                choose_current_sem(sy, num_of_sy, current_sem, cur_sem, current_sy);
            } else
                cout << "Wrong choice, choose again." << endl;
        } while (choice != 3 && !current_sem);
    } else {
        current_sy = sy[num_of_sy - 1];
        for (int i = 2; i >= 0; i--) {
            if (current_sy.semester[i]) {
                current_sem = current_sy.semester[i];
                cur_sem = i + 1;
                break;
            }
        }
    }
    ifstream courseToSemester;
    importCourseToSemester(current_sy, cur_sem, courseToSemester);

    course_node *added;

    if (choice != 3) {
        do {
            show_menu(current_user);
            cout << "Please input your choice: ";
            cin >> choice;
            if (choice == 1)
                //View info of account
                view_in4(current_user);
            else if (choice == 2) {
                ofstream login_out;
                login_out.open("Login.txt", ofstream::out | ofstream::trunc);
                change_password(current_user);
                export_login_data(users, login_out);//Export to file
                login_out.close();
            } else if (choice == 3)
                break;//Close the program
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
                        addStudentToClass(class_cur->data, addStudent);//add student to class
                        //create account for student
                        student_node *cur = class_cur->data.head;
                        while (cur) {
                            createNewStudentAccount(cur, users);
                            cur = cur->next;
                        }
                        //export login data
                        ofstream login_out;
                        login_out.open("Login.txt", ofstream::out | ofstream::trunc);
                        export_login_data(users, login_out);
                        login_out.close();
                        if (class_cur->next) class_cur = class_cur->next;
                        else break;
                    }
                    cout << "1st year student is added from file." << endl;
                }
            } else if (choice == 6) {
                if (current_user->data.isAdmin) {
                    addCourse(current_sem, added);
                    ofstream course_out;
                    exportCourseOfSemester(current_sy, cur_sem, course_out);
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
            } else if (choice == 9) {
                if (current_user->data.isAdmin) {
                    string course_id;
                    cout << "Input course id of course you want to update: ";
                    cin.ignore();
                    getline(cin, course_id);
                    updateCourseIn4(current_sem->head, course_id);
                }
            } else if (choice == 10) {
                if (current_user->data.isAdmin) {
                    student_node *newStudent = nullptr;
                    cout << "Input course ID: ";
                    string course_id;
                    cin.ignore();
                    getline(cin, course_id);
                    addStudentToCourse(current_sem->head, course_id, newStudent);
                }
            } else if (choice == 11) {
                if (current_user->data.isAdmin) {
                    cout << "Input student's ID you want to remove from course:";
                    string std_id, crs_id;
                    cin.ignore();
                    getline(cin, std_id);
                    cout << "Input course ID: ";
                    getline(cin, crs_id);
                    removeStudentFromCourse(current_sem->head, crs_id, std_id);
                }
            } else if (choice == 12) {
                if (current_user->data.isAdmin) {
                    cout << "Input course id:";
                    string crs_id;
                    cin.ignore();
                    getline(cin, crs_id);
                    delete_Course(current_sem, crs_id);
                    ofstream course_out;
                    exportCourseOfSemester(current_sy, cur_sem, course_out);
                }
            } else if (choice == 13) {
                if (current_user->data.isAdmin) {
                    viewListOfClass(Classes);
                }
            } else if (choice == 14) {
                if (current_user->data.isAdmin) {
                    viewStudentsInClass(Classes);
                }
            } else if (choice == 15) {
                if (current_user->data.isAdmin) {
                    viewListOfCourse(current_sem);
                }
            } else if (choice == 16) {
                if (current_user->data.isAdmin) {
                    string crs_id;
                    cout << "Input course ID: ";
                    cin.ignore();
                    getline(cin, crs_id);
                    viewListOfStudentInCourse(current_sem->head, crs_id);
                }
            } else if (choice == 17) {
                if (current_user->data.isAdmin) {
                    ofstream sb_out;
                    cout << "Input course you want to export list of student:";
                    cin.ignore();
                    string crs_id;
                    getline(cin, crs_id);
                    ExportListOfStudentInCourse(sb_out, current_sem->head, crs_id);
                }
            } else if (choice == 18) {
                if (current_user->data.isAdmin) {
                    ifstream sb_in;
                    cout << "Input course you want to import scoreboard: ";
                    cin.ignore();
                    string crs_id;
                    getline(cin, crs_id);
                    ImportScoreboard(sb_in, current_sem->head, crs_id);
                }
            } else if (choice == 19) {
                if (current_user->data.isAdmin) {
                    string crs_id;
                    cout << "Please enter the course id of the course you want to view the score board: ";
                    cin.ignore();
                    getline(cin, crs_id);
                    ViewTheScoreboardOfCourse(current_sem->head, crs_id);
                }
            } else
                cout << "Wrong choice, choose again." << endl;
        } while (true);
    }
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