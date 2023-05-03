#include"AllStruct.h"

void ViewTheScoreboardOfCourse(course_node *courses, string course_id){
    cout<<"Please enter the course id of the course you want to view the score board: ";
    getline(cin,course_id);
    while(courses->next!=nullptr){
        if(courses->data.course_id==course_id)
            break;
        courses=courses->next;
    }
    cout<<"This is the score board of this course"<<endl;
    int i=1;
    cout<<"Course name: "<<courses->data.course_name<<endl;
    cout<<"Teacher: "<<courses->data.teacher_name<<endl;
    cout<<"Class name: "<<courses->data.class_name<<endl;
    while(courses->data.head!=nullptr){
        cout<<i++<<". "<<courses->data.head->data.last_name<<" "<<courses->data.head->data.first_name<<" "<<courses->data.head->data.ID<<" "<<courses->data.head->data.date_of_birth<<" "<<courses->data.head->data.s.midterm<<" "<<courses->data.head->data.s.final<<" "<<courses->data.head->data.s.other<<" "<<courses->data.head->data.s.total<<endl;
        courses->data.head=courses->data.head->next;
    }
}