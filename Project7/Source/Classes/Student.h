#pragma once
#include"People.h"	
#include<iomanip>

#define STUDENT_DISPLAY "---Student information---"
#define GRADE_DISPLAY "Grade:"
#define PN_DISPLAY "Number of projects:"
#define SCORE_DISPLAY "Scores:"
#define SCORE_FORMAT 3

class Student : public People {
private:
	int Grade;
	int NumberOfProject;
	float *Score;

public:
	Student();
	Student(Student *student);
	Student(const char * Name, Date Birthday, int ID_Code, int Grade, int NumberOfProject, float *Score);
	~Student();

public:
	void SetGrade(int Grade);
	int GetGrade();

	void SetNumberOfProject(int NumberOfProject);
	int GetNumberOfProject();

	void SetScore(float *Score);
	float *GetScore();

public:
	void PrintInfo();
	float Get_Average_Score();
	int GetMark();

private:
	float Calculate_Average_Score();
};
