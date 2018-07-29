#pragma once
#include"../DefinedType.h"
#include"People.h"

#define STAFF_DISPLAY "---Staff information---"
#define DIP_DISPLAY "Department id:"
#define JD_DISPLAY "Joined date:"
#define LEVEL_DISPLAY "Level:"

class Staff : public People {
protected:
	int Department_ID;
	Date Joined_Date;
	int Level;

public:
	Staff();
	Staff(Staff *staff);
	Staff(const char *Name, Date Birthday, int ID_Code, int Department_ID, Date Joined_Date, int Level);
	virtual ~Staff();

public:
	void SetDepartment_ID(int Department_ID);
	int GetDepartment_ID();

	void SetJoined_Date(Date Joined_Date);
	Date GetJoined_Date();

	void SetLevel(int Level);
	int GetLevel();

public:
	virtual void PrintInfo();
	virtual int GetMark();
};