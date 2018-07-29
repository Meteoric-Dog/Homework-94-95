#include"Student.h"	

Student::Student() :People(), Grade(0), NumberOfProject(0), Score(NULL) {
}

Student::Student(Student * student) : People(student) {
	this->Grade = student->Grade;
	this->NumberOfProject = student->NumberOfProject;

	this->Score = new float[this->NumberOfProject];
	for (int i = 0; i < this->NumberOfProject; i++)
		this->Score[i] = student->Score[i];
}

Student::Student(const char * Name, Date Birthday, int ID_Code, int Grade, int NumberOfProject, float * Score):
		 People(Name, Birthday, ID_Code), Grade(Grade), NumberOfProject(NumberOfProject) {	
	this->Score = new float[this->NumberOfProject];
	for (int i = 0; i < this->NumberOfProject; i++)
		this->Score[i] = Score[i];
}

Student::~Student() {
	if (!this->Score)
		delete[]Score;
	cout << "deteled student" << endl;
}

void Student::SetGrade(int Grade) {
	this->Grade = Grade;
}

int Student::GetGrade() {
	return this->Grade;
}

void Student::SetNumberOfProject(int NumberOfProject) {
	this->NumberOfProject = NumberOfProject;
}

int Student::GetNumberOfProject() {
	return this->NumberOfProject;
}

void Student::SetScore(float * Score) {
	if (this->Score)
		delete[]this->Score;
	this->Score = NULL;
	
	if (!Score)
		return;
	//Score's element amount < this->NumberOfProject => return 
	
	this->Score = new float[this->NumberOfProject];
	for (int i = 0; i < this->NumberOfProject; i++)
		this->Score[i] = Score[i];
}

float *Student::GetScore() {
	//return this->Score;

	float *temp = new float[this->NumberOfProject];
	for (int i = 0; i < this->NumberOfProject; i++)
		temp[i] = this->Score[i];
	return temp;
}

void Student::PrintInfo() {
	People::PrintInfo();
	
	cout << STUDENT_DISPLAY << endl;
	cout << GRADE_DISPLAY << this->Grade << endl;
	cout << PN_DISPLAY << this->NumberOfProject << endl;
	cout << SCORE_DISPLAY << endl;
	for (int i = 0; i < this->NumberOfProject; i++)
		cout << this->Score[i] << "; ";
	cout << endl;
}

float Student::Get_Average_Score() {
	return this->Calculate_Average_Score();
}

int Student::GetMark() {
	return STUDENT_MARK;
}

istream& operator>>(istream & is, Student *student) {
	string temp;
	getline(is, temp);
	int leng = temp.length();
	
	if (student->Name)
		delete[] student->Name;
	student->Name = new char[leng + 1];
	memcpy(student->Name, temp.c_str(), leng);
	student->Name[leng] = 0;

	Date tempDate;
	is >> tempDate;
	student->Birthday = tempDate;

	is >> student->Grade;
	is >> student->NumberOfProject;

	if (student->Score) {
		delete[] student->Score;
		student->Score = NULL;
	}
	if (student->NumberOfProject > 0) {
		student->Score = new float[student->NumberOfProject];
		for (int i = 0; i < student->NumberOfProject; i++)
			is >> student->Score[i];
		getline(is, temp);
	}
	else {
		getline(is, temp);
		getline(is, temp);
	}

	return is;
}

ostream& operator<<(ostream& os, Student *student) {
	os << student->Name<<endl;
	os << student->Birthday;
	os << student->Grade << " " << student->NumberOfProject << endl;
	if (student->NumberOfProject > 0) {
		for (int i = 0; i < student->NumberOfProject; i++)
			os << student->Score[i] << " ";
	}
	else
		os << "NULL";
	os << endl;

	return os;
}

float Student::Calculate_Average_Score() {
	float sum = 0.0;
	for (int i = 0; i < this->NumberOfProject; i++)
		sum += this->Score[i];
	return sum / this->NumberOfProject;
}
