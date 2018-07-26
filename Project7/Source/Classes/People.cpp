#include"People.h"

People::People() :Name(NULL), Birthday(), ID_Code(0) {
}

People::People(People * people) {
	int name_size = strlen(people->Name);
	this->Name = new char[name_size + 1];
	memcpy(this->Name, people->Name, name_size);
	this->Name[name_size] = 0;

	this->Birthday = people->Birthday;
	this->ID_Code = people->ID_Code;	
}

People::People(const char * Name, Date Birthday, int ID_Code): Birthday(Birthday), ID_Code(ID_Code) {
	int name_size = strlen(Name);
	this->Name = new char[name_size + 1];
	memcpy(this->Name, Name, name_size);
	this->Name[name_size] = 0;
}

People::~People() {
	if (this->Name)
		delete[]this->Name;
}

char *People::GetName() {
//	return this->Name;
	int name_leng = strlen(this->Name);
	char *temp = new char[name_leng + 1];

	memcpy(temp, this->Name, name_leng);
	temp[name_leng] = 0;
	return temp;
}

void People::SetName(char *Name) {
	if (this->Name)
		delete[] this->Name;
	this->Name = NULL;
	
	if (!Name)
		return;

	int leng = strlen(Name);
	this->Name = new char[leng + 1];

	memcpy(this->Name, Name, leng);
	this->Name[leng] = 0;
}

Date People::GetBirthday() {
	return this->Birthday;
}

void People::SetBirthday(Date Birthday) {
	this->Birthday = Birthday;
}

int People::GetID_Code() {
	return this->ID_Code;
}

void People::SetID_Code(int ID_Code) {
	this->ID_Code = ID_Code;
}

void People::PrintInfo() {
	cout << PEOPLE_DISPLAY << endl;
	cout << NAME_DISPLAY << this->Name << endl;
	cout << BIRTHDAY_DISPLAY << endl;
	this->Birthday.DisplayInfo();
}

int People::GetMark() {
	return PEOPLE_MARK;
}
