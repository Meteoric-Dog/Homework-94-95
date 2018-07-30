#pragma once
#include<iostream>

using namespace std;

#define STUDENT_FILE "StudentList.txt"

#define DAY_DISPLAY "Day:"
#define MONTH_DISPLAY "Month:"
#define YEAR_DISPLAY "Year:"

#define PEOPLE_MARK 0
#define STAFF_MARK 1
#define STUDENT_MARK 2
#define TEACHER_MARK 3

#define MIN_SCORE 5.0

struct Date {
	int day;
	int month;
	int year;

	Date() {
		this->day = 1;
		this->month = 1;
		this->year = 1970;
	}

	Date(int day, int month, int year) {
		this->day = day;
		this->month = month;
		this->year = year;
	}

	void DisplayInfo() {
		cout << DAY_DISPLAY << this->day << endl;
		cout << MONTH_DISPLAY << this->month << endl;
		cout << YEAR_DISPLAY << this->year << endl;
	}

	friend istream& operator>>(istream& is, Date& obj) {
		is >> obj.day;
		is >> obj.month;
		is >> obj.year;
		return is;
	}

	friend ostream& operator<<(ostream& os, Date& obj) {
		os << obj.day << " " << obj.month << " " << obj.year << endl;
		return os;
	}
};