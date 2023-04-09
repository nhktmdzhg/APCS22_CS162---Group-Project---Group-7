#include "AllStruct.h"

using namespace std;

void addCourse(semester *&current_sem, course_node *&added) {
    course_node *cur;
    if (!current_sem->head) {
        current_sem->head = new course_node;
        cur = current_sem->head;
    } else {
        cur = current_sem->head;
        while (cur->next) cur = cur->next;
        cur->next = new course_node;
        cur = cur->next;
    }
    added = cur;
    cout << "Enter course information:" << endl;
    cout << "Course name: ";
    cin.ignore();
    getline(cin, cur->data.course_name);
    cout << "Course ID: ";
    getline(cin, cur->data.course_id);
    cout << "Teacher of the course: ";
    getline(cin, cur->data.teacher_name);
    cout << "Class name: ";
    getline(cin, cur->data.class_name);
    cout << "Number of course credits: ";
    cin >> cur->data.num_of_credit;
    cout << "Maximum number of students: ";
    cin >> cur->data.max_student;
    cout << "Session: S";
    cin >> cur->data.session;
    cout << "Day of the week (Monday-Saturday): ";
    cin.ignore();
    getline(cin, cur->data.day_of_week);
    cout << "Course has been added." << endl;
    cur->next = nullptr;
}

void createSemester(SchoolYear *&sy, semester *&current_sem, int numOfSchoolYear) {
    cout << "Input semester you want to create: ";
    int z;
    cin >> z;
    int sd_d, sd_m, sd_y;
    cout << "Input start date of semester (day month year): ";
    cin >> sd_d >> sd_m >> sd_y;
    int ed_d, ed_m, ed_y;
    cout << "Input end date of semester (day month year): ";
    cin >> ed_d >> ed_m >> ed_y;
    cout << "Input school year: ";
    string sy_name;
    cin.ignore();
    getline(cin, sy_name);
    for (int i = 0; i < numOfSchoolYear; i++) {
        if (sy[i].SchoolYearName == sy_name) {
            switch (z) {
                case 1:
                    if (sy[i].semester1)
                        cout << "Semester 1 is created before." << endl;
                    else {
                        sy[i].semester1 = new semester;
                        sy[i].semester1->sd_day = sd_d;
                        sy[i].semester1->sd_month = sd_m;
                        sy[i].semester1->sd_year = sd_y;
                        sy[i].semester1->ed_day = ed_d;
                        sy[i].semester1->ed_month = ed_m;
                        sy[i].semester1->ed_year = ed_y;
                        current_sem = sy[i].semester1;
                        cout << "Semester 1 is created." << endl;
                    }
                    break;
                case 2:
                    if (sy[i].semester2)
                        cout << "Semester 2 is created before." << endl;
                    else {
                        sy[i].semester2 = new semester;
                        sy[i].semester2->sd_day = sd_d;
                        sy[i].semester2->sd_month = sd_m;
                        sy[i].semester2->sd_year = sd_y;
                        sy[i].semester2->ed_day = ed_d;
                        sy[i].semester2->ed_month = ed_m;
                        sy[i].semester2->ed_year = ed_y;
                        current_sem = sy[i].semester2;
                        cout << "Semester 2 is created." << endl;
                    }
                    break;
                case 3:
                    if (sy[i].semester3)
                        cout << "Semester 3 is created before." << endl;
                    else {
                        sy[i].semester3 = new semester;
                        sy[i].semester3->sd_day = sd_d;
                        sy[i].semester3->sd_month = sd_m;
                        sy[i].semester3->sd_year = sd_y;
                        sy[i].semester3->ed_day = ed_d;
                        sy[i].semester3->ed_month = ed_m;
                        sy[i].semester3->ed_year = ed_y;
                        current_sem = sy[i].semester3;
                        cout << "Semester 3 is created." << endl;
                    }
                    break;
                default:
                    cout << "Invalid semester." << endl;
            }
            return;
        }
    }
    cout << "Invalid school year." << endl;
}