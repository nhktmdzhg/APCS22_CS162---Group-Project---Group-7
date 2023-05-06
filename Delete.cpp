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
    for (int i = 0; i < 3; i++)
        if (sy.semester[i]) deleteAllCourse(sy.semester[i]->head);
    for (int i = 0; i < 3; i++)
        delete sy.semester[i];
}

void deleteAllCourse(course_node *&head) {
    while (head) {
        course_node *tmp = head;
        head = head->next;
        deleteStudent(tmp->data.head);
        delete tmp;
    }
}