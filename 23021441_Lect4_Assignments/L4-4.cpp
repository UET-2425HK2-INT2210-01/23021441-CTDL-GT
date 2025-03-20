#include <iostream>
using namespace std;

struct Student {
    int id;
    string name;
    string className;
};

const int MAX_STUDENTS = 1000;

Student studentList[MAX_STUDENTS];
int studentCount = 0;

void insertStudent(int id, string name, string className) {
    for (int i = 0; i < studentCount; ++i) {
        if (studentList[i].id == id) {
            return;
        }
    }

    if (studentCount < MAX_STUDENTS) {
        studentList[studentCount].id = id;
        studentList[studentCount].name = name;
        studentList[studentCount].className = className;
        studentCount++;
    }
}

void deleteStudent(int id) {
    for (int i = 0; i < studentCount; ++i) {
        if (studentList[i].id == id) {
            for (int j = i; j < studentCount - 1; ++j) {
                studentList[j] = studentList[j + 1];
            }
            studentCount--;
            break;
        }
    }
}

void printStudentInfo(int id) {
    for (int i = 0; i < studentCount; ++i) {
        if (studentList[i].id == id) {
            cout << studentList[i].name << ", " << studentList[i].className << endl;
            return;
        }
    }
    cout << "NA, NA" << endl;
}

int main() {
    string operation;
    while (getline(cin, operation)) {
        if (operation.empty()) break;

        if (operation.substr(0, 6) == "Insert") {
            int id;
            string name, className;
            size_t comma1 = operation.find(',');
            size_t comma2 = operation.find(',', comma1 + 1);

            id = stoi(operation.substr(7, comma1 - 7));
            name = operation.substr(comma1 + 1, comma2 - comma1 - 1);
            className = operation.substr(comma2 + 1);

            insertStudent(id, name, className);
        } else if (operation.substr(0, 6) == "Delete") {
            int id = stoi(operation.substr(7));
            deleteStudent(id);
        } else if (operation.substr(0, 5) == "Infor") {
            int id = stoi(operation.substr(6));
            printStudentInfo(id);
        }
    }

    return 0;
}
