#include "AllStruct.h"
/*void removeStudentFromCourse(course_node *courses, int course_id, int student_id) {
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
}*/
void removeStudentFromCourse(course_node* courses, string course_id, string student_id) 
{
    // Find the course
    course_node* course_ptr = courses;
    while (course_ptr != nullptr && course_ptr->data.course_id != course_id) {
        course_ptr = course_ptr->next;
    }
    if (course_ptr == nullptr) {
        cout << "Error: Cannot find the course with id " << course_id << endl;
        return;
    }

    // Find the student in the course
    student_node* prev = nullptr;
    student_node* current = course_ptr->data.head;
    // keeping track of the prev and next student inorder to delete
    while (current != nullptr && current->data.ID != student_id) 
	{
        prev = current;
        current = current->next;
    }
    if (current == nullptr) 
	{
        cout << "Error: Cannot find the student with id " << student_id << " in the course " << course_ptr->data.course_name << endl;
        return;
    }

    // Remove the student from the course
    if (prev == nullptr) 
	{
    	
        // The first student is the one to be removed
        course_ptr->data.head = current->next;
    } else 
	{
        prev->next = current->next;
    }
    delete current;

    cout << "Successfully removed student with id " << student_id << " from the course " << course_ptr->data.course_name << endl;
}

