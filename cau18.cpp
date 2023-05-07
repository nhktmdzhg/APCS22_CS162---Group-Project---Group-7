#include"AllStruct.h"

void viewListOfStudentInCourse(course_node *courses, string course_id) {
    bool found_course = false;
    int count = 1;
    while (courses != nullptr) {
        if (courses->data.course_id == course_id) {
            found_course = true;
            student_node *students = courses->data.head;
            while (students != nullptr) {
                cout << " the number" << " " << count << " student  : " << endl;
                // Print out the student information
                cout << "Student ID: " << students->data.ID << endl;
                cout << "Name: " << students->data.first_name << " " << students->data.last_name << endl;
                cout << "Date of Birth: " << students->data.date_of_birth << endl;
                cout << "Gender: " << (students->data.isMale ? "Male" : "Female") << endl;
                cout << "Social ID: " << students->data.social_id << endl;
                students = students->next;
                cout << endl;
            }
            break;
        }
        courses = courses->next;
    }
    if (!found_course) {
        cout << "Course ID " << course_id << " not found" << endl;
    }
}
