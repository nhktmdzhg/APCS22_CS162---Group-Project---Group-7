

#include"login.h"
#include"AllStruct.h"
void addStudentToCourse(course_node *courses, int course_id, student_node *new_student) {
    course_node *cur_course = courses;
 
    while (cur_course) {
        if (cur_course->data.course_id == course_id) {

            if (getStudentCount(cur_course->data.head) == cur_course->data.max_student) {
                cout << "Error: The course has reached its maximum student limit." << endl;
                return;
            }
          
            student_node *cur_student = cur_course->data.head;
            if (cur_student == nullptr) {
                cur_course->data.head = new_student;
            } else {
                while (cur_student->next != nullptr) {
                    cur_student = cur_student->next;
                }
                cur_student->next = new_student;
            }
            cout << "Student added to the course successfully." << endl;
            return;
        }
        cur_course = cur_course->next;
    }
    
    cout << "Error: Course not found." << endl;
}

int getStudentCount(student_node *head) 
{
    int count = 0;
    student_node *cur_student = head;
    while (cur_student != nullptr) 
	{
        count++;
        cur_student = cur_student->next;
    }
    return count;
}
