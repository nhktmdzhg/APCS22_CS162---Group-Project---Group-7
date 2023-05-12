#include "Student.h"

struct course {
    int num_of_credit, max_student;
    string day_of_week;
    int session;
    string course_name;
    string course_id;
    string class_name;
    string teacher_name;
    student_node *head;
    course()
            : num_of_credit(4), max_student(50), day_of_week(), session(), course_name(), course_id(), class_name(),
              teacher_name(),
              head(nullptr) {}
};

struct course_node {
    course data;
    course_node *next;

    course_node() : data(), next(nullptr) {}
};

void importStudenttoCourse(course_node *&courses, ifstream &fin, string sy_name);

void exportStudentOfCourse(course course, ofstream &fout, string sy_name);

void deleteAllCourse(course_node *&head);

void viewListofCourse(course_node *head);

void updateCourseIn4(course_node *courses, string course_id);

void addStudentToCourse(course_node *courses, string course_id, student_node *new_student, string sy_name);

void removeStudentFromCourse(course_node *courses, string course_id, string student_id, string sy_name);

void viewStudentCourse(string student_id, course_node *courses);

void viewListOfStudentInCourse(course_node *courses, string course_id);

void ExportListOfStudentInCourse(ofstream &fout, course_node *courses, string course_id, string sy_name);

void ImportScoreboard(ifstream &fin, course_node *&courses, string course_id, string sy_name);

void ExportScoreboard(ofstream &fout, course_node *courses, string course_id, string sy_name);

void ViewTheScoreboardOfCourse(course_node *courses, string course_id);

void updateStudentResult(string student_id, string course_id, course_node* courses);

void viewStudentScoreboard(string student_id, course_node *courses);