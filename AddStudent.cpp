#include "AllStruct.h"

void addStudentToClass(classes &c, ifstream &fin) {
    fin.open(c.class_name + ".csv");
    student_node *cur;
    string line;
    while (getline(fin, line)) {
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
        getline(split, no, ',');
        cur->data.No = no;

        getline(split, ID, ',');
        cur->data.ID = ID;

        getline(split, first_name, ',');
        cur->data.first_name = first_name;

        getline(split, last_name, ',');
        cur->data.last_name = last_name;

        getline(split, gender, ',');
        cur->data.isMale = (gender == "Male");

        getline(split, dob, ',');
        cur->data.date_of_birth = dob;

        getline(split, social_id);
        cur->data.social_id = social_id;

        cur->next = nullptr;
    }
    fin.close();
}

void createNewStudentAccount(student_node *students, User_node *users) {
    User_node *cur;
    if (users == nullptr) {
        users = new User_node;
        cur = users;
    } else {
        cur = users;
        while (cur->next != nullptr)
            cur = cur->next;
    }
    cur->data.username = students->data.ID;
    cur->data.password = students->data.date_of_birth;
    cur->data.isAdmin = false;
    cur->data.Name = students->data.first_name + " " + students->data.last_name;
    string dob = students->data.date_of_birth;
    cur->data.birthday = dob.substr(0, 2) + "/" + dob.substr(2, 2) + "/" + dob.substr(4, 4);
}