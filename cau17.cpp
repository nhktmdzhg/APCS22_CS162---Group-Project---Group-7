#include"AllStruct.h"

void viewListOfCourse(semester *current_sem) {
    if (current_sem == nullptr) {
        cout << "No current semester found." << endl;
        return;
    }

    course_node *current_course = current_sem->head;

    if (current_course == nullptr) {
        cout << "No courses found in the current semester." << endl;
        return;
    }

    cout << "List of courses in the current semester: " << endl;

    while (current_course != nullptr) {
        cout << "Course ID: " << current_course->data.course_id << endl;
        cout << "Course name: " << current_course->data.course_name << endl;
        cout << "Teacher name: " << current_course->data.teacher_name << endl;
        cout << "Number of credits: " << current_course->data.num_of_credit << endl;
        cout << "Number of students: " << getStudentCount(current_course->data.head) << endl;
        cout << endl;

        current_course = current_course->next;
    }
}
