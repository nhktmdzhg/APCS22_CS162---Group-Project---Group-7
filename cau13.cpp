#include"AllStruct.h"
#include"Login.h"

void delete_Course(semester& sem, int course_id){
    for(course_node* cur_course = sem.head; cur_course->next != nullptr; cur_course = cur_course->next){
        if(cur_course->next->data.course_id == course_id){
            course_node* tmp = cur_course->next;
            cur_course->next = tmp->next;
            delete tmp;
            return;
        }
    }
}