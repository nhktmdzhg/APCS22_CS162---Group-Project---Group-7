#include "AllStruct.h"

void importSchoolYear(SchoolYear *&sy, ifstream &fin, int &numOfSchoolYear) {
    int i = 0;
    string line;
    while (getline(fin, line)) {
        stringstream split(line);
        string sy_name, sem1, sem2, sem3;
        getline(split, sy_name, ' ');
        getline(split, sem1, ' ');
        getline(split, sem2, ' ');
        getline(split, sem3);
        sy[i].SchoolYearName = sy_name;
        sy[i].semester1 = (sem1 == "0") ? nullptr : new semester;
        sy[i].semester2 = (sem2 == "0") ? nullptr : new semester;
        sy[i].semester3 = (sem3 == "0") ? nullptr : new semester;
        ++i;
    }
    numOfSchoolYear = i;
}

void createNewSchoolYear(SchoolYear *&sy, int &numOfSchoolYear) {
    cout << "Input school year you want to create: ";
    cin.ignore();
    getline(cin, sy[numOfSchoolYear].SchoolYearName);
    sy[numOfSchoolYear].semester1 = nullptr;
    sy[numOfSchoolYear].semester2 = nullptr;
    sy[numOfSchoolYear].semester3 = nullptr;
    ++numOfSchoolYear;
}

void exportSchoolYear(SchoolYear *sy, int numOfSchoolYear, ofstream &fout) {
    for (int i = 0; i < numOfSchoolYear; ++i) {
        fout << sy[i].SchoolYearName << " ";
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

void choose_current_sem(SchoolYear *&sy, int &numOfSchoolYear, semester *&current_sem) {
    cout << "Please input school year: ";
    string sy_in;
    cin.ignore();
    getline(cin, sy_in);
    for (int i = 0; i < numOfSchoolYear; i++) {
        if (sy_in == sy[i].SchoolYearName) {
            cout << "Input semester: ";
            int sem;
            cin >> sem;
            switch (sem) {
                case 1:
                    if (!sy[i].semester1)
                        cout << "Semester 1 isn't created before." << endl;
                    else
                        current_sem = sy[i].semester1;
                    break;
                case 2:
                    if (!sy[i].semester2)
                        cout << "Semester 2 isn't created before." << endl;
                    else
                        current_sem = sy[i].semester2;
                    break;
                case 3:
                    if (!sy[i].semester3)
                        cout << "Semester 3 isn't created before." << endl;
                    else
                        current_sem = sy[i].semester3;
                    break;
                default:
                    cout << "Invalid semester." << endl;
            }
            return;
        }
    }
    cout << "Invalid school year." << endl;
}
