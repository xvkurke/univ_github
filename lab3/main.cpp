#include <iostream>
#include <fstream>
#include <list>

#include <iomanip>

#define FileName "data.txt"

constexpr auto ClassFormat = "Surname Name Math Physics PcScience AVG";

using namespace std;

class Student {
private:
	string surname;
	string name;
	int marks[3];
	float AVG;
public:

	Student() {}

	Student(string surname, string name, int* marks) {
		this->surname = surname;
		this->name = name;
		this->marks[0] = marks[0];
		this->marks[1] = marks[1];
		this->marks[2] = marks[2];
		this->AVG = (this->marks[0] + this->marks[1] + this->marks[2]) / 3;
	}

	friend ostream& operator<<(ostream& stream, const Student& obj);
	bool operator<(const Student& a) {
		return (this->AVG > a.AVG); 
	}
	float getAVG() { return AVG; }

};

ostream& operator <<(ostream& stream, const Student& obj) {
	return stream << obj.surname << " " << obj.name << " " << obj.marks[0] << " " << obj.marks[1] << " " << obj.marks[2] << " " << obj.AVG << endl;
}

int main() {
	list<Student> students;
	ifstream file;
	file.open(FileName);



	while (!file.eof()){
		string surname, name; int marks[3] = { 0,0,0 };
		file >> surname >> name >> marks[0] >> marks[1] >> marks[2];
		Student tmpStudentData(surname, name, marks);
		students.push_back(tmpStudentData);
	}

	students.sort();

	cout << ClassFormat << endl;

	for (Student i : students) {
		cout << i;
	}
}