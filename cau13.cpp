#include"AllStruct.h"

void delete_Course(semester *sem, string course_id) {
    for (course_node *cur_course = sem->head; cur_course->next != nullptr; cur_course = cur_course->next) {
        if (cur_course->next->data.course_id == course_id) {
            course_node *tmp = cur_course->next;
            cur_course->next = tmp->next;
            deleteStudent(tmp->data.head);
            delete tmp;
            return;
        }
    }
    cout << "Wrong course ID." << endl;
}