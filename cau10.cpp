#include"AllStruct.h"

void updateCourseIn4(course_node *courses, string course_id) {
    course_node *cur = courses;
    while (cur != nullptr && cur->data.course_id != course_id)
        cur = cur->next;
    if (cur == nullptr) {
        cout << "Course not found." << endl;//ko tim thay va cut ngay
        return;
    }
    cout << "Enter newly updated information for course " << course_id << ":" << endl;
    cout << "Course name: ";
    cin.ignore();
    getline(cin, cur->data.course_name);
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
    cout << "Course information updated successfully." << endl;
}
