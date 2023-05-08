#include "AllStruct.h"

void finalMarksOfCourses(semester *sem, string class_name) {
    course_node* cur = new course_node;
    cur = sem->head;
    while(cur) {
        if(cur->data.class_name != class_name) cur = cur->next;
        else if (cur->data.class_name == class_name) {
            student_node* tmp = cur->data.head;
            float finals = 0.0;
            int n = 0;
            while(tmp) {
                finals += tmp->data.s.final;
                n++;
            }
            finals = (float)(finals/n);
            cout << "Mark of course " << cur->data.course_name << " is " << finals << "." << endl;
            delete[] tmp;
        }
    }
    delete[] cur;
}

void gpaOfCoursesInSemester(semester *sem, string class_name) {
    course_node* cur = new course_node;
    cur = sem->head;
    float semgpa = 0.0;
    int course = 0;
    while(cur) {
        if(cur->data.class_name != class_name) cur = cur->next;
        else if(cur->data.class_name == class_name) {
            float stu_gpa = 0.0;
            int n;
            student_node* tmp = cur->data.head;
            while(tmp) {
                stu_gpa += tmp->data.s.gpa;
                n++;
            }
            stu_gpa = (float)(stu_gpa/n);
            semgpa += stu_gpa;
            course++;
            delete[] tmp;
        }
    }
    semgpa = (float)(semgpa/course);
    cout << "Semester gpa of the class is " << semgpa << "."<< endl;
    delete[] cur;
}

void gpaOfClass(course_node* courses, string classname) {
    course_node* cur = new course_node;
    cur = courses;
    float class_gpa = 0.0;
    int course = 0;
    while(cur) {
        if(cur->data.class_name != classname) cur = cur->next;
        else if(cur->data.class_name == classname) {
            float stu_gpa = 0.0;
            int n;
            student_node* tmp = cur->data.head;
            while(tmp) {
                stu_gpa += tmp->data.s.gpa;
                n++;
            }
            stu_gpa = (float)(stu_gpa/n);
            class_gpa += stu_gpa;
            course++;
            delete[] tmp;
        }
    }
    class_gpa = (float)(class_gpa/course);
    cout << "The class overall gpa is " << class_gpa << "." << endl;
    delete[] cur;
}

void viewScoreboardOfClass(SchoolYear sy, course_node *courses, classes_node *classes) {
    string classname;
    int Sem;
    cout << "Enter the class you would like to see the scoreboard: ";
    cin >> classname;
    cout << "Enter current semester: ";
    cin >> Sem;
    finalMarksOfCourses(sy.semester[Sem], classname);
    gpaOfCoursesInSemester(sy.semester[Sem], classname);
    gpaOfClass(courses, classname);

}

void viewStudentScoreboard(course_node *courses) {
    string stu_id;
    cout << "Enter student's ID to view scoreboard: ";
    cin >> stu_id;
    course_node* cur = new course_node;
    cur = courses;
    cout << "This student's scoreboard: " << endl;
    while(cur) {
        student_node* stu = new student_node;
        stu = cur->data.head;
        while(stu) {
            if(stu->data.ID != stu_id) stu = stu->next;
            else if(stu->data.ID == stu_id) {
                cout << cur->data.course_name << ":" << endl;
                cout << "Total: " << stu->data.s.total << endl;
                cout << "GPA: " << stu->data.s.gpa << endl;
                cout << "Final: " << stu->data.s.final << endl;
                cout << "Midterm: " << stu->data.s.midterm << endl;
                cout << "Others: " << stu->data.s.other << endl;
                break;
            }
        }
        delete[] stu;
        cur = cur->next;
    }
    delete[] cur;
}