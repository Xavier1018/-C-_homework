#include <iostream>
#include <string>

using namespace std;

// Class representing university staff
class UniversityStaff {
public:
    // Default constructor
    UniversityStaff() : name("") {}
    // Constructor with name parameter
    UniversityStaff(string theName) : name(theName) {}
    // Copy constructor
    UniversityStaff(const UniversityStaff& theObject) : name(theObject.name) {}
    // Function to get the name
    string getName() const { return name; }
    // Overloaded assignment operator
    UniversityStaff& operator=(const UniversityStaff& rtSide) {
        if (this != &rtSide) {
            name = rtSide.name;
        }
        return *this;
    }
    // Friend function to overload input operator
    friend istream& operator>>(istream& inStream, UniversityStaff& staffObject) {
        inStream >> staffObject.name;
        return inStream;
    }
    // Friend function to overload output operator
    friend ostream& operator<<(ostream& outStream, const UniversityStaff& staffObject) {
        outStream << staffObject.name;
        return outStream;
    }

private:
    string name; // Name of the university staff
};

// Class representing a student
class Student {
public:
    // Default constructor
    Student() : universityName(""), regNumber(0), proctor() {}
    // Constructor with parameters
    Student(string universityName, int regNumber, UniversityStaff proctor)
        : universityName(universityName), regNumber(regNumber), proctor(proctor) {}
    // Copy constructor
    Student(const Student& other)
        : universityName(other.universityName), regNumber(other.regNumber), proctor(other.proctor) {}
    // Function to get university name
    string getUniversityName() const { return universityName; }
    // Function to get registration number
    int getRegNumber() const { return regNumber; }
    // Function to get proctor (UniversityStaff)
    UniversityStaff getProctor() const { return proctor; }
    // Function to set university name
    void setUniversityName(const string& universityName) { this->universityName = universityName; }
    // Function to set registration number
    void setRegNumber(int regNumber) { this->regNumber = regNumber; }
    // Function to set proctor (UniversityStaff)
    void setProctor(const UniversityStaff& proctor) { this->proctor = proctor; }
    // Overloaded assignment operator
    Student& operator=(const Student& other) {
        if (this != &other) {
            universityName = other.universityName;
            regNumber = other.regNumber;
            proctor = other.proctor;
        }
        return *this;
    }

private:
    string universityName; // Name of the university
    int regNumber; // Registration number of the student
    UniversityStaff proctor; // Proctor (supervisor) of the student
};

// Class representing a science student, inheriting from Student class
class ScienceStudent : public Student {
public:
    // Default constructor
    ScienceStudent() : Student(), discipline(""), course("") {}
    // Constructor with parameters
    ScienceStudent(string universityName, int regNumber, UniversityStaff proctor, string discipline, string course)
        : Student(universityName, regNumber, proctor), discipline(discipline), course(course) {}
    // Copy constructor
    ScienceStudent(const ScienceStudent& other)
        : Student(other), discipline(other.discipline), course(other.course) {}
    // Function to get discipline
    string getDiscipline() const { return discipline; }
    // Function to get course
    string getCourse() const { return course; }
    // Function to set discipline
    void setDiscipline(const string& discipline) { this->discipline = discipline; }
    // Function to set course
    void setCourse(const string& course) { this->course = course; }
    // Overloaded assignment operator
    ScienceStudent& operator=(const ScienceStudent& other) {
        if (this != &other) {
            Student::operator=(other);
            discipline = other.discipline;
            course = other.course;
        }
        return *this;
    }

private:
    string discipline; // Discipline of the science student
    string course; // Course of the science student
};

int main() {
    // Creating UniversityStaff objects
    UniversityStaff staff1("Dr. Smith");
    UniversityStaff staff2("Prof. Johnson");

    // Creating Student objects
    Student student1("University of ABC", 12345, staff1);
    Student student2("University of XYZ", 67890, staff2);

    // Displaying Student information
    cout << "Student 1: " << student1.getUniversityName() << ", " << student1.getRegNumber() << ", Proctor: " << student1.getProctor() << endl;
    cout << "Student 2: " << student2.getUniversityName() << ", " << student2.getRegNumber() << ", Proctor: " << student2.getProctor() << endl;

    // Creating ScienceStudent objects
    ScienceStudent scStudent1("University of ABC", 12345, staff1, "Physics", "Undergraduate");
    ScienceStudent scStudent2("University of XYZ", 67890, staff2, "Chemistry", "Postgraduate");

    // Displaying ScienceStudent information
    cout << "Science Student 1: " << scStudent1.getUniversityName() << ", " << scStudent1.getRegNumber()
        << ", Proctor: " << scStudent1.getProctor() << ", Discipline: " << scStudent1.getDiscipline()
        << ", Course: " << scStudent1.getCourse() << endl;
    cout << "Science Student 2: " << scStudent2.getUniversityName() << ", " << scStudent2.getRegNumber()
        << ", Proctor: " << scStudent2.getProctor() << ", Discipline: " << scStudent2.getDiscipline()
        << ", Course: " << scStudent2.getCourse() << endl;

    // Testing copy constructor and assignment operator
    ScienceStudent scStudent3(scStudent1);
    ScienceStudent scStudent4 = scStudent2;

    // Displaying copied ScienceStudent information
    cout << "Science Student 3 (copied from 1): " << scStudent3.getUniversityName() << ", " << scStudent3.getRegNumber()
        << ", Proctor: " << scStudent3.getProctor() << ", Discipline: " << scStudent3.getDiscipline()
        << ", Course: " << scStudent3.getCourse() << endl;
    cout << "Science Student 4 (assigned from 2): " << scStudent4.getUniversityName() << ", " << scStudent4.getRegNumber()
        << ", Proctor: " << scStudent4.getProctor() << ", Discipline: " << scStudent4.getDiscipline()
        << ", Course: " << scStudent4.getCourse() << endl;

    return 0;
}
