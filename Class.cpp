#include "Class.h"

void importClass(classes_node *&head, ifstream &fin) {
    classes_node *cur;
    string line;
    while (getline(fin, line)) {
        if (!head) {
            head = new classes_node;
            cur = head;
        } else {
            cur->next = new classes_node;
            cur = cur->next;
        }
        cur->data.class_name = line;
        cur->next = nullptr;
    }
}

void addNewClass(classes_node *&head) {
    classes_node *cur;
    if (!head) {
        head = new classes_node;
        cur = head;
    } else {
        cur = head;
        while (cur->next)
            cur = cur->next;
        cur->next = new classes_node;
        cur = cur->next;
    }
    cout << "Input class name: ";
    cin.ignore();
    getline(cin, cur->data.class_name);
    cur->next = nullptr;
}

void exportClass(classes_node *head, ofstream &fout) {
    classes_node *cur = head;
    while (cur) {
        fout << cur->data.class_name << endl;
        cur = cur->next;
    }
}

void deleteClass(classes_node *&head) {
    while (head) {
        classes_node *tmp = head;
        head = head->next;
        delete tmp;
    }
}

void addStudentToClass(classes &c, ifstream &fin) {
    fin.open(c.class_name + ".csv");
    if (fin.good()) {
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
}

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
    cin.ignore();
    getline(cin, cn);
    while (cur && cur->data.class_name != cn) cur = cur->next;
    if (!cur) {
        cout << "Can't find class." << endl;
        return;
    }
    student_node *tmp = cur->data.head;
    while (tmp) {
        cout << tmp->data.first_name << " " << tmp->data.last_name << endl;
        tmp = tmp->next;
    }
}

void viewScoreboardOfClass(string class_name, course_node *courses, classes_node *classes) {
    classes_node *cur_class = classes;
    while (cur_class != nullptr && cur_class->data.class_name != class_name)
        cur_class = cur_class->next;
    if (cur_class == nullptr) {
        cout << "Can't find class." << endl;
        return;
    }
    student_node *cur_student = cur_class->data.head;
    if (cur_student == nullptr) {
        cout << "There's no student in this class." << endl;
        return;
    }
    cout << "This is scoreboard of class " << class_name << ":" << endl;
    while (cur_student != nullptr) {
        double overall_gpa = 0;
        int num_of_all_credit = 0;
        cout << cur_student->data.No << ". " << cur_student->data.first_name << " " << cur_student->data.last_name
             << ":" << endl;
        cout << "- ID: " << cur_student->data.ID << endl;
        course_node *cur_course = courses;
        while (cur_course != nullptr) {
            student_node *std = cur_course->data.head;
            while (std != nullptr && std->data.ID != cur_student->data.ID)
                std = std->next;
            if (std != nullptr) {
                cout << "- Course: " << cur_course->data.course_name << " (" << cur_course->data.course_id << ")"
                     << endl;
                cout << "  Final mark: " << std->data.s.final << "; GPA: " << std->data.s.total << endl;
                overall_gpa += std->data.s.total * cur_course->data.num_of_credit;
                num_of_all_credit += cur_course->data.num_of_credit;
            }
            cur_course = cur_course->next;
        }
        cout << "Overall GPA: " << overall_gpa / num_of_all_credit << endl;
        cur_student = cur_student->next;
    }
}