#pragma once
#include<fstream>
#include "People.h"
#include "Staff.h"
#include "Student.h"
#include "Teacher.h"
#include "../DefinedType.h"

class Node {
public:
	People *data;
	Node *next;

public:
	Node();
	Node(Node *node);
	Node(People *data);
	~Node();

public: 
	static int Count_People(Node *head);
	static int Count_Staffs(Node *head);
	static int Count_Students(Node *head);
	static int Count_Teachers(Node *head);

	static void Add_Node(Node *&head, Node *element);

	static void Sort_By_Type(Node *&head);
	static void Swap_Node(Node *&pre, Node *&x, Node *&y);
	static int Convert_Mark(People *data);

	static void Print_Student_Info(Node *head, int score_condition);
	static void Display_All(Node *head);

	static Node *Clone(Node *list);
	static void RemoveElement(Node *node);

	static void SaveStudentList(const char *file_name, Node *head);
	static void LoadStudentList(const char *file_name, Node *&head);
};
