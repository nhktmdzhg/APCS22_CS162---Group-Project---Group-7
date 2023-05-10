#include "Menu.h"

struct score {
    double total, final, midterm, other;

    score() : total(-1), final(-1), midterm(-1), other(-1) {}
};

struct student {
    string No, ID;
    string first_name, last_name, date_of_birth;
    bool isMale;
    string social_id;
    score s;

    student() : No(), ID(), first_name(), last_name(), date_of_birth(), isMale(), social_id(), s() {}
};

struct student_node {
    student data;
    student_node *next;

    student_node() : data(), next(nullptr) {}
};

void createNewStudentAccount(student_node *students, User_node *users);

void deleteStudent(student_node *&head);

int getStudentCount(student_node *head);