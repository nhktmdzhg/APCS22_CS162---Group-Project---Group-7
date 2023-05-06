#include"AllStruct.h"

void viewListofCourse(course_node *head) {
    while (head != nullptr) {
        cout << "Course Name: " << head->data.course_name << endl;
        cout << "Course ID: " << head->data.course_id << endl;
        cout << "Teacher of the course: " << head->data.teacher_name << endl;
        cout << "Class Name: " << head->data.class_name << endl;
        cout << "Max number of student of the course is: " << head->data.max_student << endl;
        cout << "Number of course credit: " << head->data.num_of_credit << endl;
        cout << "Session: S" << head->data.session;
        switch (head->data.session) {
            case 1:
                cout << "(7:30)" << endl;
                break;
            case 2:
                cout << "9:30" << endl;
                break;
            case 3:
                cout << "13:30" << endl;
                break;
            case 4:
                cout << "15:30" << endl;
                break;
            default:
                cout << " ";
        }
        cout << "Class will study on: " << head->data.day_of_week << endl;
        head = head->next;
    }
}