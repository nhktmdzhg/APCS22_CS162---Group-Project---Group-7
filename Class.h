#include "SchoolYear.h"

struct classes {
    student_node *head;
    string class_name;
};

struct classes_node {
    classes data;
    classes_node *next;

    classes_node() : data(), next(nullptr) {}
};

void importClass(classes_node *&head, ifstream &fin);

void addNewClass(classes_node *&head);

void exportClass(classes_node *head, ofstream &fout);

void deleteClass(classes_node *&head);

void addStudentToClass(classes &c, ifstream &fin);

void viewListOfClass(classes_node *Classes);

void viewStudentsInClass(classes_node *Classes);

void viewScoreboardOfClass(string class_name, course_node *courses, classes_node *classes);