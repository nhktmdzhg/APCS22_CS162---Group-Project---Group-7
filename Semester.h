#include "Course.h"

struct semester {
    int sd_day, sd_month, sd_year, ed_day, ed_month, ed_year;
    course_node *head;

    semester() : sd_day(), sd_month(), sd_year(), ed_day(), ed_month(), ed_year(), head(nullptr) {}
};

void addCourse(semester *&current_sem, course_node *&added);

void delete_Course(semester *sem, string course_id);

void viewListOfCourse(semester *current_sem);