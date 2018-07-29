#include"Staff.h"

Staff::Staff() :People(), Department_ID(0), Joined_Date(), Level(0) {
}

Staff::Staff(Staff * staff) : People(staff) {	
	this->Department_ID = staff->Department_ID;
	this->Joined_Date = staff->Joined_Date;
	this->Level = staff->Level;
}

Staff::Staff(const char * Name, Date Birthday, int ID_Code, int Department_ID, Date Joined_Date, int Level): People(Name, Birthday, ID_Code), Department_ID(Department_ID), Joined_Date(Joined_Date), Level(Level) {
}

Staff::~Staff() {
//	People::~People();
	cout << "deleted staff" << endl;
}

void Staff::SetDepartment_ID(int Department_ID) {
	this->Department_ID = Department_ID;
}

int Staff::GetDepartment_ID() {
	return this->Department_ID;
}

void Staff::SetJoined_Date(Date Joined_Date) {
	this->Joined_Date = Joined_Date;
}

Date Staff::GetJoined_Date() {
	return this->Joined_Date;
}

void Staff::SetLevel(int Level) {
	this->Level = Level;
}

int Staff::GetLevel() {
	return this->Level;
}

void Staff::PrintInfo() {
	People::PrintInfo();
	
	cout << STAFF_DISPLAY << endl;
	cout << DIP_DISPLAY << this->Department_ID << endl;
	cout << JD_DISPLAY << endl;
	this->Joined_Date.DisplayInfo();
	cout << LEVEL_DISPLAY << this->Level << endl;
}

int Staff::GetMark() {
	return STAFF_MARK;
}
