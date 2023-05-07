#include "AllStruct.h"

void importSchoolYear(SchoolYear *&sy, ifstream &fin, int &numOfSchoolYear) {
    int i = 0;
    string line;
    while (getline(fin, line)) {
        stringstream split(line);
        string sy_name, sem[3];
        getline(split, sy_name, ' ');
        getline(split, sem[0], ' ');
        getline(split, sem[1], ' ');
        getline(split, sem[2]);
        sy[i].SchoolYearName = sy_name;
        for (int j = 0; j < 3; j++)
            sy[i].semester[j] = (sem[j] == "0") ? nullptr : new semester;
        ++i;
    }
    numOfSchoolYear = i;
}

void createNewSchoolYear(SchoolYear *&sy, int &numOfSchoolYear) {
    cout << "Input school year you want to create: ";
    cin.ignore();
    getline(cin, sy[numOfSchoolYear].SchoolYearName);
    for (int i = 0; i < 3; i++)
        sy[numOfSchoolYear].semester[i] = nullptr;
    ++numOfSchoolYear;
}

void exportSchoolYear(SchoolYear *sy, int numOfSchoolYear, ofstream &fout) {
    for (int i = 0; i < numOfSchoolYear; ++i) {
        fout << sy[i].SchoolYearName << " ";
        if (!sy[i].semester[0]) fout << "0 ";
        else fout << "1 ";
        if (!sy[i].semester[1]) fout << "0 ";
        else fout << "1 ";
        if (!sy[i].semester[2]) fout << "0" << endl;
        else fout << "1" << endl;
    }
}

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
    classes_node *cur = head;
    while (cur->next) cur = cur->next;
    cur->next = new classes_node;
    cur = cur->next;
    cout << "Input class name: ";
    cin.ignore();
    getline(cin, cur->data.class_name);
    cur->next = nullptr;
}

void exportClass(classes_node *head, ofstream &fout) {
    while (head) {
        fout << head->data.class_name << endl;
        head = head->next;
    }
}

void choose_current_sem(SchoolYear *&sy, int &numOfSchoolYear, semester *&current_sem, int &cur_sem, SchoolYear &cur_sy) {
    cout << "Please input school year: ";
    string sy_in;
    cin.ignore();
    getline(cin, sy_in);
    for (int i = 0; i < numOfSchoolYear; i++) {
        if (sy_in == sy[i].SchoolYearName) {
            cout << "Input semester: ";
            int sem;
            cin >> sem;
            if (sem >= 1 && sem <= 3) {
                if (sy[i].semester[sem - 1] == nullptr)
                    cout << "Semester 1 isn't created before." << endl;
                else {
                    current_sem = sy[i].semester[sem - 1];
                    cur_sem = sem;
                    cur_sy = sy[i];
                }
            } else
                cout << "Invalid semester" << endl;
            return;
        }
    }
    cout << "Invalid school year." << endl;
}

void importCourseToSemester(SchoolYear &sy, int sem, ifstream &fin, semester *cur_sem) {
    fin.open(sy.SchoolYearName + "_sem" + to_string(sem) + ".csv");
    if (fin.good()) {
        course_node *cur;
        string line;
        while (getline(fin, line)) {
            if (!sy.semester[sem - 1]->head) {
                sy.semester[sem - 1]->head = new course_node;
                cur = sy.semester[sem - 1]->head;
            } else {
                cur->next = new course_node;
                cur = cur->next;
            }
            stringstream split(line);
            getline(split, cur->data.course_name, ',');
            getline(split, cur->data.course_id, ',');
            getline(split, cur->data.class_name, ',');
            getline(split, cur->data.teacher_name, ',');
            getline(split, cur->data.day_of_week, ',');
            string num_string;
            getline(split, num_string, ',');
            cur->data.session = stoi(num_string);
            getline(split, num_string, ',');
            cur->data.num_of_credit = stoi(num_string);
            getline(split, num_string);
            cur->data.max_student = stoi(num_string);
            ifstream course_in;
            importStudenttoCourse(cur->data, course_in);
            cur->next = nullptr;
        }
        fin.close();
    }
}

void exportCourseOfSemester(SchoolYear &sy, int sem, ofstream &fout) {
    fout.open(sy.SchoolYearName + "_sem" + to_string(sem) + ".csv");
    course_node *cur = sy.semester[sem - 1]->head;
    while (cur) {
        fout << cur->data.course_name << ",";
        fout << cur->data.course_id << ",";
        fout << cur->data.class_name << ",";
        fout << cur->data.teacher_name << ",";
        fout << cur->data.day_of_week << ",";
        fout << cur->data.session << ",";
        fout << cur->data.num_of_credit << ",";
        fout << cur->data.max_student << endl;
        cur = cur->next;
    }
    fout.close();
}