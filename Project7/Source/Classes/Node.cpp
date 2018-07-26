#include "Node.h"

Node::Node():data(NULL),next(NULL) {
}

Node::Node(Node *node) {
	switch (node->data->GetMark()) {
	case PEOPLE_MARK:
		this->data = new People(node->data);
		break;
	case STAFF_MARK:
		this->data = new Staff((Staff *)node->data);
		break;
	case STUDENT_MARK:
		this->data = new Student((Student*)node->data);
		break;
	case TEACHER_MARK:
		this->data = new Teacher((Teacher *)node->data);
		break;
	}	
	this->next = NULL;
}

Node::Node(People * data) {
	switch (data->GetMark()) {
	case PEOPLE_MARK:
		this->data = new People(data);
		break;
	case STAFF_MARK:
		this->data = new Staff((Staff *)data);
		break;
	case STUDENT_MARK:
		this->data = new Student((Student*)data);
		break;
	case TEACHER_MARK:
		this->data = new Teacher((Teacher *)data);
		break;
	}
	this->next = NULL;
}

Node::~Node() {
	this->next->~Node();            //delete this->next;
	delete this->data;
}

int Node::Count_People(Node * head) {
	int count = 0;
	while (head) {
	    if (head->data)
		    count++;
		head = head->next;
	}
	return count;
}

int Node::Count_Staffs(Node * head)
{
	int count = 0;
	while (head) {
		//other solution: typeid(*(head->data)).name() compare to Staff and Teacher
		if (head->data)
		    if ((head->data->GetMark() == STAFF_MARK) || (head->data->GetMark() == TEACHER_MARK))     
			    count++;
		head = head->next;
	}
	return count;
}

int Node::Count_Students(Node * head) {
	int count = 0;
	while (head) {
		if (head->data)
		    if (head->data->GetMark() == STUDENT_MARK)       //typeid  ...
			    count++;
		head = head->next;
	}
	return count;
}

int Node::Count_Teachers(Node * head) {
	int count = 0;
	while (head) {
		if (head->data)
		    if (head->data->GetMark() == TEACHER_MARK)     //typeid ...
     			count++;
		head = head->next;
	}
	return count;
}

void Node::Add_Node(Node *&head, Node * element) {
	if (!head) {
		head = element;
		return;
	}

	Node *iter = head;
	while (iter->next)
		iter = iter->next;
	iter->next = element;
}

void Node::Sort_By_Type(Node *&head) {
	if (head == NULL)
		return;
	Node *pre = NULL, *first = head, *second;
	int amount = Node::Count_People(head) - 1;
	
	for (int i = 0; i < amount; i++) {
		pre = NULL;
		first = head;

		while (first->next) {
			second = first->next;
			if (Node::Convert_Mark(first->data) > Node::Convert_Mark(second->data))    
				Node::Swap_Node(pre, first, second);
			if (pre == NULL)
				head = first;
			pre = first;
			first = first->next;
		}
	}
}

void Node::Swap_Node(Node *&pre, Node *& x, Node *& y) {
	if (pre != NULL)
		pre->next = y;
	x->next = y->next;
	y->next = x;

	Node *temp = x;
	x = y;
	y = temp;

	//other solution: swap only values between 2 nodes
	//People *temp=x->data; x->data=y->data; y->data=temp;
}

int Node::Convert_Mark(People *data) {        //to make sort order
	int result = -1;
	if (data == NULL)
		return 5;

	switch (data->GetMark()) {
	case STAFF_MARK:
		result = 1;
		break;
	case TEACHER_MARK:
		result = 2;
		break;
	case STUDENT_MARK:
		result = 3;
		break;
	case PEOPLE_MARK:
		result = 4;
		break;
	}

	return result;
}

void Node::Print_Student_Info(Node * head, int score_condition) {
	Node *iter = head;	
	while (iter) {
		if (iter->data)
			if (iter->data->GetMark() == STUDENT_MARK)
				if (((Student*)iter->data)->Get_Average_Score() > score_condition) {
					iter->data->PrintInfo();
					cout << endl;
				}	
		iter = iter->next;
	}
}

void Node::Display_All(Node * head) {
	while (head) {
		if (head->data) {
			head->data->PrintInfo();
			cout << endl;
		}
		head = head->next;
	}
}

Node * Node::Clone(Node *list) {
	if (list == NULL)
		return NULL;
	Node *result = new Node(list);
	result->next = Node::Clone(list->next);
	return result;
}
