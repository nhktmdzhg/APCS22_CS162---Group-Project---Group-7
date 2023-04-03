#include"Login.h"
#include"AllStruct.h"

void importStudenttoCourse(course& courses, ifstream& fin) {
	fin >> courses.course_id;
	fin >> courses.num_of_credit;
	fin >> courses.max_student;
	fin >> courses.day_of_week;
	fin >> courses.session;
    getline(fin, courses.course_name);
	getline(fin, courses.class_name);
	getline(fin, courses.teacher_name);
	courses.head = new student_node;
	student_node* cur = courses.head;
	while (!fin.eof()) {
		fin >> cur->data.No;
		fin >> cur->data.ID;
		getline(fin, cur->data.first_name);
		getline(fin, cur->data.last_name);
		getline(fin, cur->data.date_of_birth);
		fin >> cur->data.isMale;
		fin >> cur->data.social_id;
		fin >> cur->data.s.midterm;
		fin >> cur->data.s.final;
		fin >> cur->data.s.total;
		fin >> cur->data.s.other;
		cur->next = new student_node;
		cur = cur->next;
	}
	cur->next = nullptr;
}