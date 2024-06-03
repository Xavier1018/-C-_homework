#include <iostream>
#include <string>

using namespace std;

class UniversityStaff {
public:
    UniversityStaff(string theName = "") : name(theName) {}
    string getName() const { return name; }
    friend istream& operator>>(istream& inStream, UniversityStaff& staffObject) {
        return inStream >> staffObject.name;
    }
    friend ostream& operator<<(ostream& outStream, const UniversityStaff& staffObject) {
        return outStream << staffObject.name;
    }
private:
    string name;
};

class Student {
public:
    Student(string uniName = "", int regNumber = 0, const UniversityStaff& proctor = UniversityStaff())
        : uniName(uniName), regNumber(regNumber), proctor(proctor) {}
    string getUniName() const { return uniName; }
    int getRegNumber() const { return regNumber; }
    UniversityStaff getProctor() const { return proctor; }
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

class ScienceStudent : public Student {
public:
    ScienceStudent(string uniName = "", int regNumber = 0, const UniversityStaff& proctor = UniversityStaff(), string scienceDiscipline = "", string courseType = "")
        : Student(uniName, regNumber, proctor), scienceDiscipline(scienceDiscipline), courseType(courseType) {}
    string getScienceDiscipline() const { return scienceDiscipline; }
    string getCourseType() const { return courseType; }
    friend istream& operator>>(istream& inStream, ScienceStudent& scienceStudentObject) {
        return inStream >> static_cast<Student&>(scienceStudentObject) >> scienceStudentObject.scienceDiscipline >> scienceStudentObject.courseType;
    }
    friend ostream& operator<<(ostream& outStream, const ScienceStudent& scienceStudentObject) {
        return outStream << static_cast<const Student&>(scienceStudentObject) << ", Science Discipline: " << scienceStudentObject.scienceDiscipline << ", Course Type: " << scienceStudentObject.courseType;
    }
private:
    string scienceDiscipline;
    string courseType;
};

int main() {
    UniversityStaff proctor("Dr. Smith");
    Student student("University of Science", 12345, proctor);
    ScienceStudent scienceStudent("University of Science", 54321, proctor, "Physics", "Undergraduate");

    cout << "Student Info:\n";
    cout << student << endl;

    cout << "\nScience Student Info:\n";
    cout << scienceStudent << endl;

    return 0;
}
