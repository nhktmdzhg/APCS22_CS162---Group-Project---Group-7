#include "AllStruct.h"

void addStudentToClass(classes &c, ifstream &fin) {
    fin.open(c.class_name + ".csv");
    student_node *cur;
    while (!fin.eof()) {
        //tạo node mới
        if (!c.head) {
            c.head = new student_node;
            cur = c.head;
        } else {
            cur->next = new student_node;
            cur = cur->next;
        }
        string no, ID, first_name, last_name, gender, dob, social_id;
        //lấy data
        getline(fin, no, ',');
        cur->data.No = stoi(no);

        getline(fin, ID, ',');
        cur->data.ID = stoi(ID);

        getline(fin, first_name, ',');
        cur->data.first_name = first_name;

        getline(fin, last_name, ',');
        cur->data.last_name = last_name;

        getline(fin, gender, ',');
        cur->data.isMale = (gender == "Male");

        getline(fin, dob, ',');
        cur->data.date_of_birth = dob;

        getline(fin, social_id, '\n');
        cur->data.social_id = stoi(social_id);

        cur->next = nullptr;
    }
    fin.close();
}