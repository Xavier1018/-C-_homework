#include <iostream>
#include <string>

using namespace std;

// Class representing University staff
class UniversityStaff {
public:
    // Constructors
    UniversityStaff(string theName = "") : name(theName) {}

    // Accessor method
    string getName() const { return name; }

    // Overloaded stream extraction and insertion operators as friend functions
    friend istream& operator>>(istream& inStream, UniversityStaff& staffObject) {
        return inStream >> staffObject.name;
    }

    friend ostream& operator<<(ostream& outStream, const UniversityStaff& staffObject) {
        return outStream << staffObject.name;
    }

private:
    string name;
};

// Class representing a student
class Student {
public:
    // Constructors
    Student(string uniName = "", int regNumber = 0, const UniversityStaff& proctor = UniversityStaff())
        : uniName(uniName), regNumber(regNumber), proctor(proctor) {}

    // Accessor methods
    string getUniName() const { return uniName; }
    int getRegNumber() const { return regNumber; }
    UniversityStaff getProctor() const { return proctor; }

    // Overloaded stream extraction and insertion operators as friend functions
    friend istream& operator>>(istream& inStream, Student& studentObject) {
        return inStream >> studentObject.uniName >> studentObject.regNumber >> studentObject.proctor;
    }

    friend ostream& operator<<(ostream& outStream, const Student& studentObject) {
        return outStream << "University Name: " << studentObject.uniName << ", Registration Number: " << studentObject.regNumber << ", Proctor: " << studentObject.proctor.getName();
    }

private:
    string uniName;
    int regNumber;
    UniversityStaff proctor;
};

// Class representing a science student, inheriting from Student
class ScienceStudent : public Student {
public:
    // Constructors
    ScienceStudent(string uniName = "", int regNumber = 0, const UniversityStaff& proctor = UniversityStaff(), string scienceDiscipline = "", string courseType = "")
        : Student(uniName, regNumber, proctor), scienceDiscipline(scienceDiscipline), courseType(courseType) {}

    // Accessor methods
    string getScienceDiscipline() const { return scienceDiscipline; }
    string getCourseType() const { return courseType; }

    // Overloaded stream extraction and insertion operators as friend functions
    friend istream& operator>>(istream& inStream, ScienceStudent& scienceStudentObject) {
        // Calls the base class' (Student) operator>> to read base class data first
        return inStream >> static_cast<Student&>(scienceStudentObject) >> scienceStudentObject.scienceDiscipline >> scienceStudentObject.courseType;
    }

    friend ostream& operator<<(ostream& outStream, const ScienceStudent& scienceStudentObject) {
        // Calls the base class' (Student) operator<< to print base class data first
        return outStream << static_cast<const Student&>(scienceStudentObject) << ", Science Discipline: " << scienceStudentObject.scienceDiscipline << ", Course Type: " << scienceStudentObject.courseType;
    }

private:
    string scienceDiscipline;
    string courseType;
};

int main() {
    // Creating a UniversityStaff object
    UniversityStaff proctor("Dr. Smith");

    // Creating a Student object and printing its information
    Student student("University of Science", 12345, proctor);
    cout << "Student Info:\n";
    cout << student << endl;

    // Creating a ScienceStudent object and printing its information
    ScienceStudent scienceStudent("University of Science", 54321, proctor, "Physics", "Undergraduate");
    cout << "\nScience Student Info:\n";
    cout << scienceStudent << endl;

    return 0;
}

