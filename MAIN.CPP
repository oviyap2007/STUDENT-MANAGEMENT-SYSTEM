#include <bits/stdc++.h>
using namespace std;

struct Student {
    int roll;
    string name;
    int marks;
};

vector<Student> students;

void addStudent() {
    Student s;
    cout << "Enter Roll Number: ";
    cin >> s.roll;
    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, s.name);
    cout << "Enter Marks: ";
    cin >> s.marks;

    students.push_back(s);
    cout << "Student added successfully!\n";
}

void displayStudents() {
    if (students.empty()) {
        cout << "No students available.\n";
        return;
    }
    for (auto s : students) {
        cout << "Roll: " << s.roll
             << ", Name: " << s.name
             << ", Marks: " << s.marks << endl;
    }
}

void searchStudent() {
    int roll;
    cout << "Enter roll number to search: ";
    cin >> roll;

    for (auto s : students) {
        if (s.roll == roll) {
            cout << "Found -> "
                 << s.name << ", Marks: " << s.marks << endl;
            return;
        }
    }
    cout << "Student not found.\n";
}

void deleteStudent() {
    int roll;
    cout << "Enter roll number to delete: ";
    cin >> roll;

    for (int i = 0; i < students.size(); i++) {
        if (students[i].roll == roll) {
            students.erase(students.begin() + i);
            cout << "Student deleted.\n";
            return;
        }
    }
    cout << "Student not found.\n";
}

int main() {
    int choice;
    do {
        cout << "\n--- Student Management System ---\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}
