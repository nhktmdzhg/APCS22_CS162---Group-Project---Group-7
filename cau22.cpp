#include"AllStruct.h"

void updateStudentResult(string student_id, string course_id, course_node *courses) {
    course_node *cur_course = courses;
    while (cur_course != nullptr && cur_course->data.course_id != course_id)
        cur_course = cur_course->next;
    if (cur_course == nullptr) {
        cout << "Course not found." << endl;
        return;
    }
    student_node *cur_student = cur_course->data.head;
    while (cur_student != nullptr && cur_student->data.ID != student_id)
        cur_student = cur_student->next;
    if (cur_student == nullptr) {
        cout << "Student not found." << endl;
        return;
    }
    cout << "Update total mark: ";
    cin.ignore();
    cin >> cur_student->data.s.total;
    cout << "Update final mark: ";
    cin >> cur_student->data.s.final;
    cout << "Update midterm mark: ";
    cin >> cur_student->data.s.midterm;
    cout << "Update other mark: ";
    cin >> cur_student->data.s.other;
}