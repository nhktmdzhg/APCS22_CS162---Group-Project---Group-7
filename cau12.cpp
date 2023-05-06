#include "AllStruct.h"

void removeStudentFromCourse(course_node *courses, string course_id, string student_id) {
    // Find the course
    course_node *course_ptr = courses;
    while (course_ptr != nullptr && course_ptr->data.course_id != course_id) {
        course_ptr = course_ptr->next;
    }
    if (course_ptr == nullptr) {
        cout << "Error: Cannot find the course with id " << course_id << endl;
        return;
    }

    // Find the student in the course
    student_node *prev = nullptr;
    student_node *current = course_ptr->data.head;
    // keeping track of the prev and next student inorder to delete
    while (current != nullptr && current->data.ID != student_id) {
        prev = current;
        current = current->next;
    }
    if (current == nullptr) {
        cout << "Error: Cannot find the student with id " << student_id << " in the course "
             << course_ptr->data.course_name << endl;
        return;
    }

    // Remove the student from the course
    if (prev == nullptr) {

        // The first student is the one to be removed
        course_ptr->data.head = current->next;
    } else {
        prev->next = current->next;
    }
    delete current;
    prev = prev->next;
    while (prev != nullptr) {
        prev->data.No = to_string(stoi(prev->data.No) - 1);
        prev = prev->next;
    }
    ofstream course_out;
    exportStudentOfCourse(course_ptr->data, course_out);

    cout << "Successfully removed student with id " << student_id << " from the course " << course_ptr->data.course_name
         << endl;
}

