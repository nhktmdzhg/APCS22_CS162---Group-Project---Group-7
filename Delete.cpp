#include "AllStruct.h"

void deleteStudent(student_node *&head) {
    while (head) {
        student_node *tmp = head;
        head = head->next;
        delete tmp;
    }
}

void deleteClass(classes_node *&head) {
    while (head) {
        classes_node *tmp = head;
        head = head->next;
        delete tmp;
    }
}

void deleteSemester(SchoolYear &sy) {
    if(sy.semester1) deleteCourse(sy.semester1->head);
    if(sy.semester2) deleteCourse(sy.semester2->head);
    if(sy.semester3) deleteCourse(sy.semester3->head);
    delete sy.semester1;
    delete sy.semester2;
    delete sy.semester3;
}

void deleteCourse(course_node *&head) {
    while (head) {
        course_node *tmp = head;
        head = head->next;
        deleteStudent(tmp->data.head);
        delete tmp;
    }
}