#include "AllStruct.h"

void ExportListOfStudentInCourse(ofstream &fout, course_node *courses, string course_id) {
    course_node *course_cur = courses;
    if (!course_cur) {
        cout << "Can't find any course in this semester." << endl;
        return;
    }
    while (course_cur && course_cur->data.course_id != course_id)
        course_cur = course_cur->next;
    if (!course_cur) {
        cout << "Wrong course ID. Please try again." << endl;
        return;
    }
    student_node *student_cur = course_cur->data.head;
    if (!student_cur) {
        cout << "There's no student in this course." << endl;
        return;
    }
    while (student_cur) {
        fout << student_cur->data.No << "," << student_cur->data.ID << "," << student_cur->data.first_name << ","
             << student_cur->data.last_name << endl;
        student_cur = student_cur->next;
    }
}

void ImportScoreboard(ifstream &fin, course_node *&courses, string course_id) {
    int count = 0;
    course_node *course_cur = courses;
    if (!course_cur) {
        cout << "Can't find any course in this semester." << endl;
        return;
    }
    while (course_cur && course_cur->data.course_id != course_id)
        course_cur = course_cur->next;
    if (!course_cur) {
        cout << "Wrong course ID. Please try again." << endl;
        return;
    }
    student_node *student_cur = course_cur->data.head;
    if (!student_cur) {
        cout << "There's no student in this course." << endl;
        return;
    }
    string line;
    while (getline(fin, line)) {
        stringstream split(line);
        string std_data;
        getline(split, std_data, ',');
        if (std_data != student_cur->data.No) {
            count++;
            student_cur = student_cur->next;
            continue;
        }
        getline(split, std_data, ',');
        if (std_data != student_cur->data.ID) {
            count++;
            student_cur = student_cur->next;
            continue;
        }
        getline(split, std_data, ',');
        if (std_data != student_cur->data.first_name) {
            count++;
            student_cur = student_cur->next;
            continue;
        }
        getline(split, std_data, ',');
        if (std_data != student_cur->data.last_name) {
            count++;
            student_cur = student_cur->next;
            continue;
        }
        getline(split, std_data, ',');
        student_cur->data.s.total = stof(std_data);
        getline(split, std_data, ',');
        student_cur->data.s.final = stof(std_data);
        getline(split, std_data, ',');
        student_cur->data.s.midterm = stof(std_data);
        getline(split, std_data);
        student_cur->data.s.other = stof(std_data);
        student_cur = student_cur->next;
    }
    if (count != 0)
        cout << "There's " << count << " error record in this file." << endl;
}