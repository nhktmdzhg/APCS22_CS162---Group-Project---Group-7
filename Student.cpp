#include "Student.h"

void createNewStudentAccount(student_node *students, User_node *users) {
    User_node *cur;
    if (users == nullptr) {
        users = new User_node;
        cur = users;
    } else {
        cur = users;
        while (cur->next != nullptr)
            cur = cur->next;
        cur->next = new User_node;
        cur = cur->next;
    }
    cur->data.username = students->data.ID;
    cur->data.password = students->data.date_of_birth;
    cur->data.isAdmin = false;
    cur->data.Name = students->data.first_name + " " + students->data.last_name;
    string dob = students->data.date_of_birth;
    cur->data.birthday = dob.substr(0, 2) + "/" + dob.substr(2, 2) + "/" + dob.substr(4, 4);
}

void deleteStudent(student_node *&head) {
    while (head) {
        student_node *tmp = head;
        head = head->next;
        delete tmp;
    }
}

int getStudentCount(student_node *head) {
    int count = 0;
    student_node *cur_student = head;
    while (cur_student != nullptr) {
        count++;
        cur_student = cur_student->next;
    }
    return count;
}