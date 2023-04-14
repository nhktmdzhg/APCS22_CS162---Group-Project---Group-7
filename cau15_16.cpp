#include "AllStruct.h"

void viewListOfClass(classes_node *Classes) {
    classes_node *cur = Classes;
    while (cur) {
        cout << cur->data.class_name << endl;
        cur = cur->next;
    }
}

void viewStudentsInClass(classes_node *Classes) {
    classes_node *cur = Classes;
    cout << "Enter the class you would like to see the list: ";
    string cn;
    getline(cin, cn);
    while (cur->data.class_name != cn) cur = cur->next;
    student_node *tmp = cur->data.head;
    while (tmp) {
        cout << tmp->data.last_name << " " << tmp->data.first_name << endl;
        tmp = tmp->next;
    }
}