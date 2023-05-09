#include "AllStruct.h"

void viewScoreboardOfClass(string class_name, course_node *courses, classes_node *classes) {
    classes_node *cur_class = classes;
    while (cur_class != nullptr && cur_class->data.class_name != class_name)
        cur_class = cur_class->next;
    if (cur_class == nullptr) {
        cout << "Can't find class." << endl;
        return;
    }
    student_node *cur_student = cur_class->data.head;
    if (cur_student == nullptr) {
        cout << "There's no student in this class." << endl;
        return;
    }
    cout << "This is scoreboard of class " << class_name << ":" << endl;
    while (cur_student != nullptr) {
        double overall_gpa = 0;
        int num_of_all_credit = 0;
        cout << cur_student->data.No << ". " << cur_student->data.first_name << " " << cur_student->data.last_name
             << ":" << endl;
        cout << "- ID: " << cur_student->data.ID << endl;
        course_node *cur_course = courses;
        while (cur_course != nullptr) {
            student_node *std = cur_course->data.head;
            while (std != nullptr && std->data.ID != cur_student->data.ID)
                std = std->next;
            if (std != nullptr) {
                cout << "- Course: " << cur_course->data.course_name << " (" << cur_course->data.course_id << ")"
                     << endl;
                cout << "  Final mark: " << std->data.s.final << "; GPA: " << std->data.s.total << endl;
                overall_gpa += std->data.s.total * cur_course->data.num_of_credit;
                num_of_all_credit += cur_course->data.num_of_credit;
            }
            cur_course = cur_course->next;
        }
        cout << "Overall GPA: " << overall_gpa / num_of_all_credit;
        cur_student = cur_student->next;
    }
}

void viewStudentScoreboard(string student_id, course_node *courses) {
    course_node *cur = courses;
    double overall_gpa = 0;
    int num_of_all_credit = 0;
    cout << "This student's scoreboard: " << endl;
    while (cur) {
        student_node *stu = cur->data.head;
        while (stu) {
            if (stu->data.ID != student_id) stu = stu->next;
            else {
                cout << cur->data.course_name << ":" << endl;
                cout << "Total: " << stu->data.s.total << endl;
                cout << "Final: " << stu->data.s.final << endl;
                cout << "Midterm: " << stu->data.s.midterm << endl;
                cout << "Others: " << stu->data.s.other << endl;
                overall_gpa += stu->data.s.total * cur->data.num_of_credit;
                num_of_all_credit += cur->data.num_of_credit;
                break;
            }
        }
        cur = cur->next;
    }
    cout << "Overall GPA: " << overall_gpa / num_of_all_credit;
}