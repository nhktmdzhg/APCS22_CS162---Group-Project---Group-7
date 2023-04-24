#include"AllStruct.h"

void viewStudentCourse(string student_id, course_node *courses){
    cout<<"Please enter the id to view that student courses: ";
    getline(cin,student_id);
    while(courses){
        while(courses->data.head){
            if(courses->data.head->data.ID==student_id){
                cout << "Course Name: " << courses->data.course_name << endl;
		        cout << "Course ID: " << courses->data.course_id << endl;
		        cout << "Teacher of the course: " << courses->data.teacher_name << endl;
		        cout << "Class Name: " << courses->data.class_name << endl;
		        cout << "Max number of student of the course is: " << courses->data.max_student << endl;
		        cout << "Number of course credit: " << courses->data.num_of_credit << endl;
		        cout << "Session: " << courses->data.session << endl;
		        cout << "Class will study on: " << courses->data.day_of_week << endl;
                break;
            }
            courses->data.head=courses->data.head->next;
        }
        courses=courses->next;
    }
    
}