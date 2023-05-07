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
        getline(split, cur->data.last_name);

        cur->next = nullptr;
    }
    fin.close();
}

void exportStudentOfCourse(course course, ofstream &fout) {
    fout.open(course.course_id + ".csv");
    student_node *cur = course.head;
    while (cur != nullptr) {
        fout << cur->data.No << ",";
        fout << cur->data.ID << ",";
        fout << cur->data.first_name << ",";
        fout << cur->data.last_name << endl;
        cur = cur->next;
    }
    fout.close();
}