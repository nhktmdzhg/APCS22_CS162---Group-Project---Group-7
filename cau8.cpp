#include"AllStruct.h"

void importStudenttoCourse(course &courses, ifstream &fin) {
    fin.open(courses.course_id + ".csv");
    student_node *cur;
    string line;
    while (getline(fin, line)) {
        //Create new node
        if (!courses.head) {
            courses.head = new student_node;
            cur = courses.head;
        } else {
            cur->next = new student_node;
            cur = cur->next;
        }
        stringstream split(line);

        getline(split, cur->data.No, ',');
        getline(split, cur->data.ID, ',');
        getline(split, cur->data.first_name, ',');
        getline(split, cur->data.last_name, ',');

        string genderStr;
        getline(split, genderStr, ',');
        cur->data.isMale = (genderStr == "Male");

        getline(split, cur->data.date_of_birth, ',');
        getline(split, cur->data.social_id);

        cur->next = nullptr;
    }
    fin.close();
}