#include "AllStruct.h"

void addStudentToClass(classes &c, ifstream &fin) {
    fin.open(c.class_name + ".csv");
    student_node *cur;
    string line;
    while (getline(fin,line)) {
        //tạo node mới
        if (!c.head) {
            c.head = new student_node;
            cur = c.head;
        } else {
            cur->next = new student_node;
            cur = cur->next;
        }
        stringstream split(line);
        string no, ID, first_name, last_name, gender, dob, social_id;
        //lấy data
        getline(split,no,',');
        cur->data.No = stoi(no);

        getline(split, ID, ',');
        cur->data.ID = stoi(ID);

        getline(split, first_name, ',');
        cur->data.first_name = first_name;

        getline(split, last_name, ',');
        cur->data.last_name = last_name;

        getline(split, gender, ',');
        cur->data.isMale = (gender == "Male");

        getline(split, dob, ',');
        cur->data.date_of_birth = dob;

        getline(split, social_id);
        cur->data.social_id = stoi(social_id);

        cur->next = nullptr;
    }
    fin.close();
}