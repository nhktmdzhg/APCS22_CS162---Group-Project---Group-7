#include "Semester.h"

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

void delete_Course(semester *sem, string course_id) {
    for (course_node *cur_course = sem->head; cur_course->next != nullptr; cur_course = cur_course->next) {
        if (cur_course->next->data.course_id == course_id) {
            course_node *tmp = cur_course->next;
            cur_course->next = tmp->next;
            deleteStudent(tmp->data.head);
            delete tmp;
            return;
        }
    }
    cout << "Wrong course ID." << endl;
}

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