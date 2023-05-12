#include "Semester.h"

struct SchoolYear {
    string SchoolYearName;
    semester *semester[3];
};

void choose_current_sem(SchoolYear *&sy, int &numOfSchoolYear, semester *&current_sem, int &cur_sem, SchoolYear &cur_sy);

void importSchoolYear(SchoolYear *&sy, ifstream &fin, int &numOfSchoolYear);

void createNewSchoolYear(SchoolYear *&sy, int &numOfSchoolYear);

void exportSchoolYear(SchoolYear *sy, int numOfSchoolYear, ofstream &fout);

void deleteSemester(SchoolYear &sy);

void createSemester(SchoolYear *&sy, int numOfSchoolYear);

void importCourseToSemester(SchoolYear &sy, int sem, ifstream &fin);

void exportCourseOfSemester(SchoolYear &sy, int sem, ofstream &fout);