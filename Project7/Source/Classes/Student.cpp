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
	People::~People();
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

float Student::Calculate_Average_Score() {
	float sum = 0.0;
	for (int i = 0; i < this->NumberOfProject; i++)
		sum += this->Score[i];
	return sum / this->NumberOfProject;
}
