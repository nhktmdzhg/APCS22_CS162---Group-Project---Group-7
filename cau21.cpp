#include"AllStruct.h"

void ViewTheScoreboardOfCourse(course_node *courses, string course_id) {
    while (courses != nullptr) {
        if (courses->data.course_id == course_id)
            break;
        courses = courses->next;
    }
    if (courses == nullptr) {
        cout << "Can't find course ID." << endl;
        return;
    }
    cout << "This is the score board of this course: " << endl;
    int i = 1;
    cout << "Course name: " << courses->data.course_name << endl;
    cout << "Teacher: " << courses->data.teacher_name << endl;
    cout << "Class name: " << courses->data.class_name << endl;
    student_node *cur = courses->data.head;
    while (cur != nullptr) {
        cout << i++ << ". " << cur->data.first_name << " " << cur->data.last_name << endl;
        cout << "ID: " << cur->data.ID << endl;
        cout << "Midterm mark: " << cur->data.s.midterm << endl;
        cout << "Final mark: " << cur->data.s.final << endl;
        cout << "Other mark: " << cur->data.s.other << endl;
        cout << "Total mark:" << cur->data.s.total << endl;
        cur = cur->next;
    }
}