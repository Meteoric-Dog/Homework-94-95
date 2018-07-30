#pragma once
#include"../DefinedType.h"
#include<string>
#include<iostream>

using namespace std;

#define PEOPLE_DISPLAY "---People information---"
#define NAME_DISPLAY "People name:"
#define BIRTHDAY_DISPLAY "People birthday:"
#define ID_CODE_DISPLAY "People id code:"

class People {
protected:
	char *Name;
	Date Birthday;
	int ID_Code;
	
public:
	People();
	People(People *people);
	People(const char *Name, Date Birthday, int ID_Code);
	virtual ~People();

public:
	char *GetName();
	void SetName(char *SetName);

	Date GetBirthday();
	void SetBirthday(Date);

	int GetID_Code();
	void SetID_Code(int ID_Code);

public:
	virtual void PrintInfo();
	virtual int GetMark();
};