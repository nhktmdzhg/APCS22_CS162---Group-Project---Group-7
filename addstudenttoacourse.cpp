
#include"AllStruct.h"

void addStudentToCourse(course_node *courses, string course_id, student_node *new_student) {
    course_node *cur_course = courses;

    while (cur_course) {
        if (cur_course->data.course_id == course_id) {

            if (getStudentCount(cur_course->data.head) == cur_course->data.max_student) {
                cout << "Error: The course has reached its maximum student limit." << endl;
                return;
            }
            student_node *cur_student = cur_course->data.head;
            cout << "Input student ID: ";
            cin.ignore();
            getline(cin, new_student->data.ID);

            cout << "Input first name: ";
            getline(cin, new_student->data.first_name);

            cout << "Input last name: ";
            getline(cin, new_student->data.last_name);

            cout << "Input date of birth (dd/mm/yyyy): ";
            string dob;
            getline(cin, dob);
            new_student->data.date_of_birth = dob.substr(0, 2) + dob.substr(3, 2) + dob.substr(6, 4);

            cout << "Input gender (Male/Female): ";
            string genderStr;
            getline(cin, genderStr);
            new_student->data.isMale = (genderStr == "Male");

            cout << "Input social ID: ";
            getline(cin, new_student->data.social_id);

            new_student->next = nullptr;

            if (cur_student == nullptr) {
                new_student->data.No = "1";
                cur_course->data.head = new_student;
            } else {
                while (cur_student->next != nullptr) {
                    cur_student = cur_student->next;
                }
                new_student->data.No = to_string(stoi(cur_student->data.No) + 1);
                cur_student->next = new_student;
            }
            ofstream course_out;
            exportStudentOfCourse(cur_course->data, course_out);
            cout << "Student added to the course successfully." << endl;
            return;
        }
        cur_course = cur_course->next;
    }

    cout << "Error: Course not found." << endl;
}

int getStudentCount(student_node *head) {
    int count = 0;
    student_node *cur_student = head;
    while (cur_student != nullptr) {
        count++;
        cur_student = cur_student->next;
    }
    return count;
}
