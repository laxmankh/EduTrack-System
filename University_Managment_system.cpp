#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Class to represent a Student
class Student {
public:
    int id;
    string name;
    string course;
    float grade;

    Student(int id, string name, string course, float grade)
        : id(id), name(name), course(course), grade(grade) {}

    void display() {
        cout << "ID: " << id << ", Name: " << name << ", Course: " << course << ", Grade: " << grade << endl;
    }
};

// Class to represent Faculty
class Faculty {
public:
    int id;
    string name;
    string subject;

    Faculty(int id, string name, string subject)
        : id(id), name(name), subject(subject) {}

    void display() {
        cout << "ID: " << id << ", Name: " << name << ", Subject: " << subject << endl;
    }
};

// Main System Class
class UniversitySystem {
private:
    vector<Student> students;
    vector<Faculty> faculty;

public:
    // Insert Student
    void insertStudent() {
        int id;
        string name, course;
        float grade;
        cout << "Enter Student ID: ";
        cin >> id;
        cout << "Enter Student Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Course: ";
        getline(cin, course);
        cout << "Enter Grade: ";
        cin >> grade;

        students.emplace_back(id, name, course, grade);
        cout << "Student added successfully!\n";
    }

    // Display Students
    void displayStudents() {
        if (students.empty()) {
            cout << "No student records available.\n";
            return;
        }
        cout << "Student Records:\n";
        for ( auto& student : students) {
            student.display();
        }
    }

    // Search Student
    void searchStudent() {
        int id;
        cout << "Enter Student ID to search: ";
        cin >> id;
        for (auto& student : students) {
            if (student.id == id) {
                student.display();
                return;
            }
        }
        cout << "Student with ID " << id << " not found.\n";
    }

    // Update Student
    void updateStudent() {
        int id;
        cout << "Enter Student ID to update: ";
        cin >> id;
        for (auto& student : students) {
            if (student.id == id) {
                cout << "Enter new Name: ";
                cin.ignore();
                getline(cin, student.name);
                cout << "Enter new Course: ";
                getline(cin, student.course);
                cout << "Enter new Grade: ";
                cin >> student.grade;
                cout << "Student record updated successfully!\n";
                return;
            }
        }
        cout << "Student with ID " << id << " not found.\n";
    }

    // Delete Student
    void deleteStudent() {
        int id;
        cout << "Enter Student ID to delete: ";
        cin >> id;
        for (auto it = students.begin(); it != students.end(); ++it) {
            if (it->id == id) {
                students.erase(it);
                cout << "Student record deleted successfully!\n";
                return;
            }
        }
        cout << "Student with ID " << id << " not found.\n";
    }

    // Insert Faculty
    void insertFaculty() {
        int id;
        string name, subject;
        cout << "Enter Faculty ID: ";
        cin >> id;
        cout << "Enter Faculty Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Subject: ";
        getline(cin, subject);

        faculty.emplace_back(id, name, subject);
        cout << "Faculty added successfully!\n";
    }

    // Display Faculty
    void displayFaculty() {
        if (faculty.empty()) {
            cout << "No faculty records available.\n";
            return;
        }
        cout << "Faculty Records:\n";
        for ( auto& f : faculty) {
            f.display();
        }
    }
};

// Main Function
int main() {
    UniversitySystem uniSystem;
    int choice;

    do {
        cout << "\nUniversity Management System\n";
        cout << "1. Insert Student Data\n";
        cout << "2. Display Student Data\n";
        cout << "3. Search Student Data\n";
        cout << "4. Update Student Data\n";
        cout << "5. Delete Student Data\n";
        cout << "6. Insert Faculty Data\n";
        cout << "7. Display Faculty Data\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                uniSystem.insertStudent();
                break;
            case 2:
                uniSystem.displayStudents();
                break;
            case 3:
                uniSystem.searchStudent();
                break;
            case 4:
                uniSystem.updateStudent();
                break;
            case 5:
                uniSystem.deleteStudent();
                break;
            case 6:
                uniSystem.insertFaculty();
                break;
            case 7:
                uniSystem.displayFaculty();
                break;
            case 8:
                cout << "Exiting the system...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 8);

    return 0;
}
