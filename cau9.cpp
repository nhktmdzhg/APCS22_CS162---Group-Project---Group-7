#include"Login.h"
#include"AllStruct.h"

void viewListofCourse(course_node* head) {
	while (head->next != nullptr) {
		cout << "Course Name: " << head->data.course_name << endl;
		cout << "Course ID: " << head->data.course_id << endl;
		cout << "Teacher of the coure: " << head->data.teacher_name << endl;
		cout << "Class Name: " << head->data.class_name << endl;
		cout << "Max number of student of the course is: " << head->data.max_student << endl;
		cout << "Number of course credit: " << head->data.num_of_credit << endl;
		cout << "Session: " << head->data.session << endl;
		cout << "Class will study on: " << head->data.day_of_week << endl;
		head = head->next;
	}
}