#include "Login.h"

struct score {
    int total,final,midterm,other;
};

struct student {
    int No,ID;
    string first_name, last_name, date_of_birth;
    bool isMale;
    int social_id;
    score s;
};

struct student_node {
    student data;
    student_node *next;
};

struct course {
    int course_id, num_of_credit, max_student;
    int day_of_week;//Monday is 1 and Saturday is 6
    int session;
    string course_name;
    string class_name;
    string teacher_name;
    student_node *head;
};

struct course_node {
    course data;
    course_node *next;
};

struct semester {
    int sd_day, sd_month, sd_year, ed_day, ed_month, ed_year;
    course_node *head;
};

struct SchoolYear {
    string SchoolYearName;
    semester *semester1, *semester2, *semester3;
};

struct classes {
    student_node *head;
    string class_name;
};

struct classes_node {
    classes data;
    classes_node *next;
};

void importSchoolYear(SchoolYear *&sy, ifstream &fin, int numOfSchoolYear);

void createNewSchoolYear(SchoolYear *&sy, int &numOfSchoolYear);

void exportSchoolYear(SchoolYear *sy, int numOfSchoolYear, ofstream &fout);

void importClass(classes_node *&head, ifstream &fin);

void addNewClass(classes_node *&head); //câu 2

void exportClass(classes_node *head, ofstream &fout);

void addStudentToClass(classes &c, ifstream &fin); //câu 3

void createSemester(SchoolYear *&sy, semester *&current_sem); //câu 6

void addCourse(semester *&current_sem); //câu 7 (trong semester có course rồi nên update cái đó nha :v)

void importStudenttoCourse(course &courses, ifstream &fin); //câu 8

void viewListofCourse(course_node *head); //câu 9