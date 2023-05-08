#include "Menu.h"

struct score {
    float total, gpa, final, midterm, other;

    score() : total(-1), gpa(-1), final(-1), midterm(-1), other(-1) {}
};

struct student {
    string No, ID;
    string first_name, last_name, date_of_birth;
    bool isMale;
    string social_id;
    score s;

    student() : No(), ID(), first_name(), last_name(), date_of_birth(), isMale(), social_id(), s() {}
};

struct student_node {
    student data;
    student_node *next;

    student_node() : data(), next(nullptr) {}
};


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
            : num_of_credit(), max_student(50), day_of_week(), session(), course_name(), course_id(), class_name(),
              teacher_name(),
              head(nullptr) {}
};

struct course_node {
    course data;
    course_node *next;

    course_node() : data(), next(nullptr) {}
};

struct semester {
    int sd_day, sd_month, sd_year, ed_day, ed_month, ed_year;
    course_node *head;

    semester() : sd_day(), sd_month(), sd_year(), ed_day(), ed_month(), ed_year(), head(nullptr) {}
};

struct SchoolYear {
    string SchoolYearName;
    semester *semester[3];
};

struct classes {
    student_node *head;
    string class_name;
};

struct classes_node {
    classes data;
    classes_node *next;

    classes_node() : data(), next(nullptr) {}
};

void choose_current_sem(SchoolYear *&sy, int &numOfSchoolYear, semester *&current_sem, int &cur_sem, SchoolYear &cur_sy);

void importSchoolYear(SchoolYear *&sy, ifstream &fin, int &numOfSchoolYear);

void createNewSchoolYear(SchoolYear *&sy, int &numOfSchoolYear);

void exportSchoolYear(SchoolYear *sy, int numOfSchoolYear, ofstream &fout);

void deleteSemester(SchoolYear &sy);

void importClass(classes_node *&head, ifstream &fin);

void addNewClass(classes_node *&head);

void exportClass(classes_node *head, ofstream &fout);

void deleteClass(classes_node *&head);

void addStudentToClass(classes &c, ifstream &fin);

void createNewStudentAccount(student_node *students, User_node *users);

void deleteStudent(student_node *&head);

void createSemester(SchoolYear *&sy, semester *&current_sem, int numOfSchoolYear);

void importCourseToSemester(SchoolYear &sy, int sem, ifstream &fin);

void exportCourseOfSemester(SchoolYear &sy, int sem, ofstream &fout);

void addCourse(semester *&current_sem, course_node *&added);

void importStudenttoCourse(course &courses, ifstream &fin);

void exportStudentOfCourse(course course, ofstream &fout);

void delete_Course(semester *sem, string course_id); //câu 13

void deleteAllCourse(course_node *&head);

void viewListofCourse(course_node *head);

int getStudentCount(student_node *head);

void updateCourseIn4(course_node *courses, string course_id); //cau 10

void addStudentToCourse(course_node *courses, string course_id, student_node *new_student); //cau 11

void removeStudentFromCourse(course_node *courses, string course_id, string student_id); //cau 12

void viewStudentCourse(string student_id, course_node *courses); // cau 14

void viewListOfClass(classes_node *Classes); // cau 15

void viewStudentsInClass(classes_node *Classes); // cau 16

void viewListOfCourse(semester *current_sem); // cau 17

void viewListOfStudentInCourse(course_node *courses, string course_id); // cau 18

void ExportListOfStudentInCourse(ofstream &fout, course_node *courses, string course_id); // cau 19

void ImportScoreboard(ifstream &fin, course_node *&courses, string course_id); // cau 20

void ViewTheScoreboardOfCourse(course_node *courses, string course_id); // cau 21

void updateStudentResult(string student_id, string course_id, course_node *&courses); // cau 22

void viewScoreboardOfClass(string class_name, course_node *courses, classes_node *classes); // cau 23

void viewStudentScoreboard(string student_id, course_node *courses); // cau 24