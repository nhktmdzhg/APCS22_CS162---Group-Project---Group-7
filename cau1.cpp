
#include"Login.h"
void createNewSchoolYear(SchoolYear& sy, bool isAdmin) {
    if (!isAdmin) {
        cout << "Access denied. Only admins can create a new school year." << endl;
        return;
    }


    cout << "Enter the school year name: ";
    getline(cin, sy.SchoolYearName);
    cout << "Enter the start year: ";
    cin >> sy.start_year;

  
    cout << "Creating Semester 1..." << endl;
    createNewSemester(sy.semester1, isAdmin);


    cout << "Creating Semester 2..." << endl;
    createNewSemester(sy.semester2, isAdmin);

  
    cout << "Creating Semester 3..." << endl;
    createNewSemester(sy.semester3, isAdmin);

    cout << "New school year created successfully." << endl;
}
void createNewSemester(semester& sem, bool isAdmin) {
    if (!isAdmin) {
        cout << "Access denied. Only admins can create a new semester." << endl;
        return;
    }


    cout << "Enter the start date (day month year): ";
    cin >> sem.sd_day >> sem.sd_month >> sem.sd_year;
    cout << "Enter the end date (day month year): ";
    cin >> sem.ed_day >> sem.ed_month >> sem.ed_year;

  
    cout << "Creating courses..." << endl;
    createCourses(sem.courseArray, isAdmin);

    cout << "New semester created successfully." << endl;
}
