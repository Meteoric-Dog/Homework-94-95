#pragma once
#include"Classes/Node.h"

int main() {
	////9.1-9.3 TEST
	//Node *node=NULL;

	//int amount = 5;
	//People **student = new People *[amount];
	//People **teacher = new People *[amount];
	//People **staff = new People *[amount];
	//const char *meteor = "hello";
	//float temp = 11.1;

	//for (int i = 0; i < amount; i++) {
	//	Date date(i, i, i);
	//
	//	float *score = new float[i + 1];
	//	for (int j = 0; j < i + 1; j++) {
	//		score[j] = 10 + (i / temp);
	//		//cout << score[j] << endl;
	//	}
	//	student[i] = new Student(meteor, date, i, i, i + 1, score);
	//	delete[]score;

	//	Date joined_date(i - 20, i - 20, i - 20);
	//	staff[i] = new Staff(meteor, date, i - 20, i - 20, joined_date, i-20);

	//	Date joined_date2(i - 10, i - 10, i - 10);
	//	teacher[i] = new Teacher(meteor, date, i - 10, i - 10, joined_date2, i - 10, i + 10, SubjectEnum::MATHS, SubjectEnum::PHYS);

	//	Node::Add_Node(node, new Node(student[i]));
	//	Node::Add_Node(node, new Node(staff[i]));
	//	Node::Add_Node(node, new Node(teacher[i]));
	//}	

	//Node::Sort_By_Type(node);
	//
	//cout << Node::Count_People(node) << endl;
	//cout << Node::Count_Staffs(node) << endl;              //staff=teacher+other worker
	//cout << Node::Count_Students(node) << endl;
	//cout << Node::Count_Teachers(node) << endl;
	//cout << endl;

	//Node::Print_Student_Info(node, MIN_SCORE);

	//cout << "------------------------------" << endl;

	//Node *clone = Node::Clone(node);     
	//Node::Print_Student_Info(clone, MIN_SCORE);

	////9.4 TEST
	//float *score = new float[4];
	//Student *student = new Student("meteor", Date(), 0, 0, 0, score);
	////Teacher *teacher = new Teacher("hello", Date(), 5, 5, Date(), 6, 7, SubjectEnum::ENGLISH, SubjectEnum::MATHS);
	////Staff *staff = new Staff("hello", Date(), 8, 8, Date(), 8);
	//
	//Node *node = new Node(student);
	//Node::RemoveElement(node);

	//delete student;

	Node *head = NULL;
	const char *meteor = "hello world";
	int amount = 5;
	for (int i = 0; i < amount; i++) {
		float *score = NULL;
		if (i == 0)
			score = NULL;
		else {
			score = new float[i];
			for (int j = 0; j < i; j++)
				score[j] = i;
		}
		Student *student = new Student(meteor, Date(), i, i, i, score);
		Node::Add_Node(head, new Node(student));
		if (score)
			delete[]score;
		delete student;
	}
	
	Node::SaveStudentList(STUDENT_FILE, head);
	delete head;
	head = NULL;
	Node::LoadStudentList(STUDENT_FILE, head);
	Node::Display_All(head);
	delete head;

	system("pause");	
	return 0;
}