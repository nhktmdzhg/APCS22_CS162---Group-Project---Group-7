#include "Login.h"

struct SchoolYear {
    string SchoolYearName;
    int start_year;
    semester semester1, semester2, semester3;
};

struct student {
    int No,ID,dob_day,dob_month,dob_year;
    string first_name, last_name;
    bool isMale;
    int social_id;
    score s;
};

struct classes {
    student *studentArray;
    string class_name;
};

struct course {
    int course_id, num_of_credit, max_student;
    int day_of_week;//Monday is 1 and Saturday is 6
    int session;
    string course_name;
    string class_name;
    string teacher_name;
    student *studentArray;
};

struct semester {
    int sd_day, sd_month, sd_year, ed_day, ed_month, ed_year;
    course *courseArray;
};

struct score {
    int total,final,midterm,other;
};