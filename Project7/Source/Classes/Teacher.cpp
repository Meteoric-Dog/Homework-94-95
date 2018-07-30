#include "Teacher.h"

const char *SUBJECT_NAME[] = { "Maths","Physics","English" };

Teacher::Teacher():Staff(), Class(0), Subject(SubjectEnum::MATHS), Second_Subject(SubjectEnum::MATHS) {
}

Teacher::Teacher(Teacher * teacher) : Staff(teacher) {
	this->Class = teacher->Class;
	this->Subject = teacher->Subject;
	this->Second_Subject = teacher->Second_Subject;
}

Teacher::Teacher(const char * Name, Date Birthday, int ID_Code, int Department_ID, Date Joined_Date, int Level, int Class,
	SubjectEnum Subject, SubjectEnum Second_Subject) : Staff(Name, Birthday, ID_Code, Department_ID, Joined_Date, Level),
	Class(Class), Subject(Subject), Second_Subject(Second_Subject) {
}

Teacher::~Teacher() {
//	Staff::~Staff();
	cout << "deleted teacher" << endl;
}

void Teacher::SetClass(int Class) {
	this->Class = Class;
}

int Teacher::GetClass() {
	return this->Class;
}

void Teacher::SetSubject(SubjectEnum Subject) {
	this->Subject = Subject;
}

SubjectEnum Teacher::GetSubject() {
	return this->Subject;
}

void Teacher::SetSecond_Subject(SubjectEnum Subject) {
	this->Second_Subject = Second_Subject;
}

SubjectEnum Teacher::GetSecond_Subject() {
	return this->Second_Subject;
}

void Teacher::PrintInfo() {
	Staff::PrintInfo();

	cout << TEACHER_DISPLAY << endl;
	cout << CLASS_DISPLAY << this->Class << endl;
	cout << SUBJECT_1_DISPLAY << SUBJECT_NAME[this->Subject] << endl;
	cout << SUBJECT_2_DISPLAY << SUBJECT_NAME[this->Second_Subject] << endl;
}

int Teacher::GetMark() {
	return TEACHER_MARK;
}
