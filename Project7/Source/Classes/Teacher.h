#pragma once
#include"People.h"
#include"Staff.h"

#define TEACHER_DISPLAY "---Teacher information---"
#define CLASS_DISPLAY "Class:"
#define SUBJECT_1_DISPLAY "Subject:"
#define SUBJECT_2_DISPLAY "Second subject:"

enum SubjectEnum { MATHS = 0, PHYS, ENGLISH };

class Teacher : public People, public virtual Staff {
private:
	int Class;
	SubjectEnum Subject;
	SubjectEnum Second_Subject;

public:
	Teacher();
	Teacher(Teacher *teacher);
	Teacher(const char * Name, Date Birthday, int ID_Code, int Department_ID, Date Joined_Date,
		int Level, int Class, SubjectEnum Subject, SubjectEnum Second_Subject);
	~Teacher();

public:
	void SetClass(int Class);
	int GetClass();

	void SetSubject(SubjectEnum Subject);
	SubjectEnum GetSubject();

	void SetSecond_Subject(SubjectEnum Second_Subject);
	SubjectEnum GetSecond_Subject();

public:
	void PrintInfo();
	int GetMark();
};
