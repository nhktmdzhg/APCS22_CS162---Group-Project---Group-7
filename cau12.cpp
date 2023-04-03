#include "AllStruct.h"
void removeStudentFromCourse(course_node *courses, int course_id, int student_id) {
    // Find the course with the given ID by looping through the whole list
    course_node *current_course = courses;
    while (current_course != nullptr && current_course->data.course_id != course_id) 
	{
        current_course = current_course->next;
    }
    if (current_course == nullptr) 
	{
        // Course not found
        return;
    }

    // Find the student with the given ID in the course's student list
    student_node *current_student = current_course->data.head;
    student_node *previous_student = nullptr;
    while (current_student != nullptr && current_student->data.ID != student_id) {
        previous_student = current_student;
        current_student = current_student->next;
    }
    if (current_student == nullptr) {
        // Student not found in the course
        return;
    }

    // Remove the student from the course's student list
    // i have to use the previous to link with the next student inorder to delete it properly
    if (previous_student == nullptr) {
        // The student is at the head of the list so we delete it just like normal list
        current_course->data.head = current_student->next;
    } else
	{
        // The student is in the middle or at the end of the list , same with above
        previous_student->next = current_student->next;
    }
    delete current_student;
    current_course->data.max_student++;
}

