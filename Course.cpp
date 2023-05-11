#include "Course.h"

void importStudenttoCourse(course &courses, ifstream &fin, string sy_name) {
    fin.open(courses.course_id + "_" + sy_name + ".csv");
    if (fin.good()) {
        student_node *cur;
        string line;
        while (getline(fin, line)) {
            //Create new node
            if (!courses.head) {
                courses.head = new student_node;
                cur = courses.head;
            } else {
                cur->next = new student_node;
                cur = cur->next;
            }
            stringstream split(line);

            getline(split, cur->data.No, ',');
            getline(split, cur->data.ID, ',');
            getline(split, cur->data.first_name, ',');
            getline(split, cur->data.last_name);

            cur->next = nullptr;
        }
        fin.close();
    }
}

void exportStudentOfCourse(course course, ofstream &fout, string sy_name) {
    fout.open(course.course_id + "_" + sy_name + ".csv");
    student_node *cur = course.head;
    while (cur != nullptr) {
        fout << cur->data.No << ",";
        fout << cur->data.ID << ",";
        fout << cur->data.first_name << ",";
        fout << cur->data.last_name << endl;
        cur = cur->next;
    }
    fout.close();
}

void deleteAllCourse(course_node *&head) {
    while (head) {
        course_node *tmp = head;
        head = head->next;
        deleteStudent(tmp->data.head);
        delete tmp;
    }
}

void viewListofCourse(course_node *head) {
    while (head != nullptr) {
        cout << "Course Name: " << head->data.course_name << endl;
        cout << "Course ID: " << head->data.course_id << endl;
        cout << "Teacher of the course: " << head->data.teacher_name << endl;
        cout << "Class Name: " << head->data.class_name << endl;
        cout << "Max number of student of the course is: " << head->data.max_student << endl;
        cout << "Number of course credit: " << head->data.num_of_credit << endl;
        cout << "Session: S" << head->data.session;
        switch (head->data.session) {
            case 1:
                cout << "(7:30)" << endl;
                break;
            case 2:
                cout << "9:30" << endl;
                break;
            case 3:
                cout << "13:30" << endl;
                break;
            case 4:
                cout << "15:30" << endl;
                break;
            default:
                cout << " ";
        }
        cout << "Class will study on: " << head->data.day_of_week << endl;
        head = head->next;
    }
}

void updateCourseIn4(course_node *courses, string course_id) {
    course_node *cur = courses;
    while (cur != nullptr && cur->data.course_id != course_id)
        cur = cur->next;
    if (cur == nullptr) {
        cout << "Course not found." << endl;//ko tim thay va cut ngay
        return;
    }
    cout << "Enter newly updated information for course " << course_id << ":" << endl;
    cout << "Course name: ";
    cin.ignore();
    getline(cin, cur->data.course_name);
    cout << "Teacher of the course: ";
    getline(cin, cur->data.teacher_name);
    cout << "Class name: ";
    getline(cin, cur->data.class_name);
    cout << "Number of course credits: ";
    cin >> cur->data.num_of_credit;
    cout << "Maximum number of students: ";
    cin >> cur->data.max_student;
    cout << "Session: S";
    cin >> cur->data.session;
    cout << "Day of the week (Monday-Saturday): ";
    cin.ignore();
    getline(cin, cur->data.day_of_week);
    cout << "Course information updated successfully." << endl;
}

void addStudentToCourse(course_node *courses, string course_id, student_node *new_student, string sy_name) {
    course_node *cur_course = courses;

    while (cur_course) {
        if (cur_course->data.course_id == course_id) {

            if (getStudentCount(cur_course->data.head) == cur_course->data.max_student) {
                cout << "Error: The course has reached its maximum student limit." << endl;
                return;
            }
            student_node *cur_student = cur_course->data.head;
            cout << "Input student ID: ";
            cin.ignore();
            getline(cin, new_student->data.ID);

            cout << "Input first name: ";
            getline(cin, new_student->data.first_name);

            cout << "Input last name: ";
            getline(cin, new_student->data.last_name);

            cout << "Input date of birth (dd/mm/yyyy): ";
            string dob;
            getline(cin, dob);
            new_student->data.date_of_birth = dob.substr(0, 2) + dob.substr(3, 2) + dob.substr(6, 4);

            cout << "Input gender (Male/Female): ";
            string genderStr;
            getline(cin, genderStr);
            new_student->data.isMale = (genderStr == "Male");

            cout << "Input social ID: ";
            getline(cin, new_student->data.social_id);

            new_student->next = nullptr;

            if (cur_student == nullptr) {
                new_student->data.No = "1";
                cur_course->data.head = new_student;
            } else {
                while (cur_student->next != nullptr) {
                    cur_student = cur_student->next;
                }
                new_student->data.No = to_string(stoi(cur_student->data.No) + 1);
                cur_student->next = new_student;
            }
            ofstream course_out;
            exportStudentOfCourse(cur_course->data, course_out, sy_name);
            cout << "Student added to the course successfully." << endl;
            return;
        }
        cur_course = cur_course->next;
    }

    cout << "Error: Course not found." << endl;
}

void removeStudentFromCourse(course_node *courses, string course_id, string student_id, string sy_name) {
    // Find the course
    course_node *course_ptr = courses;
    while (course_ptr != nullptr && course_ptr->data.course_id != course_id) {
        course_ptr = course_ptr->next;
    }
    if (course_ptr == nullptr) {
        cout << "Error: Cannot find the course with id " << course_id << endl;
        return;
    }

    // Find the student in the course
    student_node *prev = nullptr;
    student_node *current = course_ptr->data.head;
    // keeping track of the prev and next student inorder to delete
    while (current != nullptr && current->data.ID != student_id) {
        prev = current;
        current = current->next;
    }
    if (current == nullptr) {
        cout << "Error: Cannot find the student with id " << student_id << " in the course "
             << course_ptr->data.course_name << endl;
        return;
    }

    // Remove the student from the course
    if (prev == nullptr) {

        // The first student is the one to be removed
        course_ptr->data.head = current->next;
    } else {
        prev->next = current->next;
    }
    delete current;
    prev = prev->next;
    while (prev != nullptr) {
        prev->data.No = to_string(stoi(prev->data.No) - 1);
        prev = prev->next;
    }
    ofstream course_out;
    exportStudentOfCourse(course_ptr->data, course_out, sy_name);

    cout << "Successfully removed student with id " << student_id << " from the course " << course_ptr->data.course_name
         << endl;
}

void viewStudentCourse(string student_id, course_node *courses) {
    cout << "Please enter the id to view that student courses: ";
    getline(cin, student_id);
    while (courses) {
        student_node *cur = courses->data.head;
        while (cur) {
            if (cur->data.ID == student_id) {
                cout << "Course Name: " << courses->data.course_name << endl;
                cout << "Course ID: " << courses->data.course_id << endl;
                cout << "Teacher of the course: " << courses->data.teacher_name << endl;
                cout << "Class Name: " << courses->data.class_name << endl;
                cout << "Max number of student of the course is: " << courses->data.max_student << endl;
                cout << "Number of course credit: " << courses->data.num_of_credit << endl;
                cout << "Session: " << courses->data.session << endl;
                cout << "Class will study on: " << courses->data.day_of_week << endl;
                break;
            }
            cur = cur->next;
        }
        courses = courses->next;
    }

}

void viewListOfStudentInCourse(course_node *courses, string course_id) {
    bool found_course = false;
    int count = 1;
    while (courses != nullptr) {
        if (courses->data.course_id == course_id) {
            found_course = true;
            student_node *students = courses->data.head;
            while (students != nullptr) {
                cout << " the number" << " " << count << " student  : " << endl;
                // Print out the student information
                cout << "Student ID: " << students->data.ID << endl;
                cout << "Name: " << students->data.first_name << " " << students->data.last_name << endl;
                cout << "Date of Birth: " << students->data.date_of_birth << endl;
                cout << "Gender: " << (students->data.isMale ? "Male" : "Female") << endl;
                cout << "Social ID: " << students->data.social_id << endl;
                students = students->next;
                cout << endl;
            }
            break;
        }
        courses = courses->next;
    }
    if (!found_course) {
        cout << "Course ID " << course_id << " not found" << endl;
    }
}

void ExportListOfStudentInCourse(ofstream &fout, course_node *courses, string course_id, string sy_name) {
    course_node *course_cur = courses;
    if (!course_cur) {
        cout << "Can't find any course in this semester." << endl;
        return;
    }
    while (course_cur && course_cur->data.course_id != course_id)
        course_cur = course_cur->next;
    if (!course_cur) {
        cout << "Wrong course ID. Please try again." << endl;
        return;
    }
    fout.open(course_id + "_" + sy_name + "_sb.csv");
    student_node *student_cur = course_cur->data.head;
    if (!student_cur) {
        cout << "There's no student in this course." << endl;
        return;
    }
    while (student_cur) {
        fout << student_cur->data.No << "," << student_cur->data.ID << "," << student_cur->data.first_name << ","
             << student_cur->data.last_name << endl;
        student_cur = student_cur->next;
    }
    fout.close();
}

void ImportScoreboard(ifstream &fin, course_node *&courses, string course_id, string sy_name) {
    int count = 0;
    course_node *course_cur = courses;
    if (!course_cur) {
        cout << "Can't find any course in this semester." << endl;
        return;
    }
    while (course_cur && course_cur->data.course_id != course_id)
        course_cur = course_cur->next;
    if (!course_cur) {
        cout << "Wrong course ID. Please try again." << endl;
        return;
    }
    fin.open(course_id + "_" + sy_name + "_sb.csv");
    if (fin.good()) {
        student_node *student_cur = course_cur->data.head;
        string line;
        while (getline(fin, line)) {
            stringstream split(line);
            string std_data;
            getline(split, std_data, ',');
            if (std_data != student_cur->data.No) {
                count++;
                student_cur = student_cur->next;
                continue;
            }
            getline(split, std_data, ',');
            if (std_data != student_cur->data.ID) {
                count++;
                student_cur = student_cur->next;
                continue;
            }
            getline(split, std_data, ',');
            if (std_data != student_cur->data.first_name) {
                count++;
                student_cur = student_cur->next;
                continue;
            }
            getline(split, std_data, ',');
            if (std_data != student_cur->data.last_name) {
                count++;
                student_cur = student_cur->next;
                continue;
            }
            getline(split, std_data, ',');
            student_cur->data.s.total = stod(std_data);
            getline(split, std_data, ',');
            student_cur->data.s.final = stod(std_data);
            getline(split, std_data, ',');
            student_cur->data.s.midterm = stod(std_data);
            getline(split, std_data);
            student_cur->data.s.other = stod(std_data);
            student_cur = student_cur->next;
        }
        if (count != 0)
            cout << "There's " << count << " error when import scoreboard of course " << course_id << "." << endl;
        fin.close();
    }
}

void ExportScoreboard(ofstream &fout, course_node *courses, string course_id, string sy_name) {
    course_node *course_cur = courses;
    if (!course_cur) {
        cout << "Can't find any course in this semester." << endl;
        return;
    }
    while (course_cur && course_cur->data.course_id != course_id)
        course_cur = course_cur->next;
    if (!course_cur) {
        cout << "Wrong course ID. Please try again." << endl;
        return;
    }
    fout.open(course_id + "_" + sy_name + "_sb.csv");
    student_node *student_cur = course_cur->data.head;
    while (student_cur) {
        fout << student_cur->data.No << ",";
        fout << student_cur->data.ID << ",";
        fout << student_cur->data.first_name << ",";
        fout << student_cur->data.last_name << ",";
        fout << student_cur->data.s.total << ",";
        fout << student_cur->data.s.final << ",";
        fout << student_cur->data.s.midterm << ",";
        fout << student_cur->data.s.other << endl;
        student_cur = student_cur->next;
    }
    fout.close();
}

void ViewTheScoreboardOfCourse(course_node *courses, string course_id) {
    while (courses != nullptr) {
        if (courses->data.course_id == course_id)
            break;
        courses = courses->next;
    }
    if (courses == nullptr) {
        cout << "Can't find course ID." << endl;
        return;
    }
    cout << "This is the score board of this course: " << endl;
    int i = 1;
    cout << "Course name: " << courses->data.course_name << endl;
    cout << "Teacher: " << courses->data.teacher_name << endl;
    cout << "Class name: " << courses->data.class_name << endl;
    student_node *cur = courses->data.head;
    while (cur != nullptr) {
        cout << i++ << ". " << cur->data.first_name << " " << cur->data.last_name << endl;
        cout << "ID: " << cur->data.ID << endl;
        cout << "Midterm mark: " << cur->data.s.midterm << endl;
        cout << "Final mark: " << cur->data.s.final << endl;
        cout << "Other mark: " << cur->data.s.other << endl;
        cout << "Total mark:" << cur->data.s.total << endl;
        cur = cur->next;
    }
}

void updateStudentResult(string student_id, string course_id, course_node *courses) {
    course_node *cur_course = courses;
    while (cur_course != nullptr && cur_course->data.course_id != course_id)
        cur_course = cur_course->next;
    if (cur_course == nullptr) {
        cout << "Course not found." << endl;
        return;
    }
    student_node *cur_student = cur_course->data.head;
    while (cur_student != nullptr && cur_student->data.ID != student_id)
        cur_student = cur_student->next;
    if (cur_student == nullptr) {
        cout << "Student not found." << endl;
        return;
    }
    cout << "Update total mark: ";
    cin.ignore();
    cin >> cur_student->data.s.total;
    cout << "Update final mark: ";
    cin >> cur_student->data.s.final;
    cout << "Update midterm mark: ";
    cin >> cur_student->data.s.midterm;
    cout << "Update other mark: ";
    cin >> cur_student->data.s.other;
}

void viewStudentScoreboard(string student_id, course_node *courses) {
    course_node *cur = courses;
    double overall_gpa = 0;
    int num_of_all_credit = 0;
    cout << "This student's scoreboard: " << endl;
    while (cur) {
        student_node *stu = cur->data.head;
        while (stu) {
            if (stu->data.ID != student_id) stu = stu->next;
            else {
                cout << cur->data.course_name << ":" << endl;
                cout << "Total: " << stu->data.s.total << endl;
                cout << "Final: " << stu->data.s.final << endl;
                cout << "Midterm: " << stu->data.s.midterm << endl;
                cout << "Others: " << stu->data.s.other << endl;
                overall_gpa += stu->data.s.total * cur->data.num_of_credit;
                num_of_all_credit += cur->data.num_of_credit;
                break;
            }
        }
        cur = cur->next;
    }
    cout << "Overall GPA: " << overall_gpa / num_of_all_credit;
}

#include"Course.h"

void updateStudentResult(string student_id, string course_id, course_node* courses){
    cout<<"Please enter the course ID: ";
    getline(cin,course_id);
    cout<<"Please enter the student ID: ";
    getline(cin,student_id);
    while(courses->next && courses->data.course_id!=course_id) courses=courses->next;
    while(courses->data.head->next && courses->data.head->data.ID!=student_id) courses->data.head=courses->data.head->next;
    int score;char choice;
    do{
        cout<<"Please enter the score you want to change: ";
        string score_name;
        getline(cin,score_name);
        if(score_name=="midterm"){
            cin>>score;
            courses->data.head->data.s.midterm=score;
        }
        else if(score_name=="final"){
            cin>>score;
            courses->data.head->data.s.final=score;
        }
        else if(score_name=="total"){
            cin>>score;
            courses->data.head->data.s.total=score;
        }
        else{
            cin>>score;
            courses->data.head->data.s.other=score;
        }
        cout<<"Do you want to update more? (Y/N)";
        cin>>choice;
    }while(toupper(choice)=='Y');
}