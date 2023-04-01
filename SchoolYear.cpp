#include "AllStruct.h"

void importSchoolYear(SchoolYear *&sy, ifstream &fin, int numOfSchoolYear) {
    int i = 0;
    while (!fin.eof()) {
        getline(fin, sy[i].SchoolYearName);
        int sem1, sem2, sem3;
        fin >> sem1 >> sem2 >> sem3;
        if (sem1 == 0) sy[i].semester1 = nullptr;
        else sy[i].semester1 = new semester;
        if (sem2 == 0) sy[i].semester2 = nullptr;
        else sy[i].semester2 = new semester;
        if (sem3 == 0) sy[i].semester3 = nullptr;
        else sy[i].semester3 = new semester;
        ++i;
    }
    numOfSchoolYear = i;
}

void createNewSchoolYear(SchoolYear *&sy, int &numOfSchoolYear) {
    cout << "Input school year you want to create: ";
    getline(cin, sy[numOfSchoolYear].SchoolYearName);
    sy[numOfSchoolYear].semester1 = nullptr;
    sy[numOfSchoolYear].semester2 = nullptr;
    sy[numOfSchoolYear].semester3 = nullptr;
    ++numOfSchoolYear;
}

void exportSchoolYear(SchoolYear *sy, int numOfSchoolYear, ofstream &fout) {
    for (int i = 0; i < numOfSchoolYear; ++i) {
        fout << sy[i].SchoolYearName << endl;
        if (!sy[i].semester1) fout << "0 ";
        else fout << "1 ";
        if (!sy[i].semester2) fout << "0 ";
        else fout << "1 ";
        if (!sy[i].semester3) fout << "0" << endl;
        else fout << "1" << endl;
    }
}

void importClass(classes_node *&head, ifstream &fin) {
    classes_node *cur;
    while (!fin.eof()) {
        if (!head) {
            head = new classes_node;
            cur = head;
        } else {
            cur->next = new classes_node;
            cur = cur->next;
        }
        getline(fin, cur->data.class_name);
        cur->next = nullptr;
    }
}

void addNewClass(classes_node *&head) {
    classes_node *cur = head;
    while (cur->next) cur = cur->next;
    cur->next = new classes_node;
    cur = cur->next;
    cout << "Input class name: ";
    getline(cin, cur->data.class_name);
    cur->next = nullptr;
}

void exportClass(classes_node *head, ofstream &fout) {
    while (head) {
        fout << head->data.class_name << endl;
        head = head->next;
    }
}