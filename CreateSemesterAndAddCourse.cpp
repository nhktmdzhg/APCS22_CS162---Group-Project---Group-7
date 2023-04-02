#include "AllStruct.h"
#include "Login.h"
#include <string>

using namespace std;

void addCourse(semester* sem) {
    cout << "Enter the start date (day month year): ";
    cin >> sem->sd_day >> sem->sd_month >> sem->sd_year;
    cout << "Enter the end date (day month year): ";
    cin >> sem->ed_day >> sem->ed_month >> sem->ed_year;
    cout << "Total courses: ";
    int n;
    cin >> n;
    cout << endl;
    course_node *cur = new course_node;
    sem->head = cur;
    for(int i = 0; i < n; i++) {
        cout << "Enter course information:" << endl;
        cout << "Course name: ";
        cin.ignore(); 
        getline(cin, cur->data.course_name);
        cout << "Course ID: ";
        cin >> cur->data.course_id;
        cin.ignore();
        cout << "Teacher of the course: ";
        getline(cin, cur->data.teacher_name);
        cout << "Class name: ";
        getline(cin, cur->data.class_name);
        cout << "Number of course credits: ";
        cin >> cur->data.num_of_credit;
        cout << "Maximum number of students: ";
        cin >> cur->data.max_student;
        cout << "Session: ";
        cin >> cur->data.session;
        cout << "Day of the week (Monday-Saturday): ";
        string day;
        cin.ignore();
        getline(cin, day);
        if (day == "Monday") cur->data.day_of_week = 1;
        else if (day == "Tuesday") cur->data.day_of_week = 2;
        else if (day == "Wednesday") cur->data.day_of_week = 3;
        else if (day == "Thursday") cur->data.day_of_week = 4;
        else if (day == "Friday") cur->data.day_of_week = 5;
        else if (day == "Saturday") cur->data.day_of_week = 6;        
        cout << "Course has been added." << endl;
        cur->next = nullptr; 
        if(i != n - 1) {
            course_node *next_course = new course_node;
            cur->next = next_course;
            cur = next_course;
        }
    }
}

void createSemester(SchoolYear*& sy, semester*& current_sem, bool isAdmin) {
    if (!isAdmin) {
        cout << "Access denied. Only admins can create a new school year." << endl;
        return;
    }
    sy = new SchoolYear;
    cout << "Enter the school year name: ";
    getline(cin, sy->SchoolYearName);
    int i = 0;
    while (i < 4) {
        if (i == 0) cout << "First year:" << endl;
        else if (i == 1) cout << "Second year:" << endl;
        else if (i == 2) cout << "Third year:" << endl;
        else if (i == 3) cout << "Fourth year:" << endl;
        sy->semester1 = new semester;
        sy->semester2 = new semester;
        sy->semester3 = new semester;
        cout << "Creating Semester 1..." << endl;
        addCourse(&sy->semester1[i]);
        cout << "Creating Semester 2..." << endl;
        addCourse(&sy->semester2[i]);
        cout << "Creating Semester 3..." << endl;
        addCourse(&sy->semester3[i]);
        i++;
    }
    cout << "New school year created successfully." << endl;
}