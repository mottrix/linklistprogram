#include<iostream>
using namespace std;

class Node {

public:
	friend class linkList;
	Node* next;
	int data;
	Node(int data) { this->data = data; }

};
class linkList {
public:
	linkList() { first = NULL; last = NULL; }
	//~linkList();
	void addNode(int data);
	void deleteNode(int x);
	void display();
	linkList* mergeList(linkList* l2);
	int addaval(int& x);
	Node* first;
	Node* last;
//private:
	//Node* first;
	//Node* last;

};
class Qunue {
public:
	//Qunue(int data) {
		//frant=new Node(data);
		//rear = frant;
		//frant->next = NULL;
	
	Qunue() {
		frant = NULL;
		rear = NULL;
	}
	void Add(int data);
	void Delete();
	void display();

private:
	Node* frant;
	Node* rear;
};
void Qunue::Add(int data ) {
	Node* newnode = new Node(data);
	newnode->next = NULL;
	if (frant == NULL) {
		rear = newnode;
		frant = newnode;
	}
	else {

		rear->next = newnode;
		rear = newnode;
	}
	
	
	
}

void Qunue::Delete() {
	Node* curpt = frant;
	if (frant == NULL) {
		cout << " .The Qunnue is empty !!" << endl;
	}
	else if (curpt->next == NULL) {
		frant = rear;
	}
	else {
		frant = frant->next;
	}
}
void Qunue::display()
{
	system("cls");
	Node* curpt = frant;
	do {
	cout << curpt->data << endl;
	curpt = curpt->next;
	} while (curpt!= NULL);

}
class Stack {
public:
	Stack() {
		Node* newpt;
		top = first->next;
		first = newpt;
		

	}
	void pop();
	void push(int data);

private:
	Node* top=NULL;
	Node* first=NULL;
};
void Stack::push(int data) {
	Node *newStake=top;
	newStake->next = NULL;
	if (top == NULL) {
		cout << " .The tack is empty .";

	}
	else {
		cin >> newStake->data;
		top = top->next;
		top = newStake;
		cout << "true";
	}
}
void linkList::addNode(int data) {
	Node* newNode = new Node(data);
	if (this->first == NULL)
	{
		this->first = newNode;
		this->last = newNode;
		last->next = last;
	}
	else {
		last->next = newNode;
		last = newNode;
		newNode->next = first;
	}
}

linkList* linkList::mergeList(linkList* l2) {

	Node* Acurent = this->first;
	Node* Bcurent = l2->first;
	Node* Abehind = NULL;
	Node* Bbehind = NULL;

	linkList* newlist = new linkList();

	while (Bbehind != l2->last && Abehind != this->last) {
		if (Acurent->data >= Bcurent->data) {
			newlist->addNode(Bcurent->data);
			Bbehind = Bcurent;
			Bcurent = Bcurent->next;
		}
		else {
			newlist->addNode(Acurent->data);
			Abehind = Acurent;
			Acurent = Acurent->next;
		}
	}

	while (Acurent != this->first) {
		newlist->addNode(Acurent->data);
		Acurent = Acurent->next;
	}

	while (Bcurent != l2->first) {
		newlist->addNode(Bcurent->data);
		Bcurent = Bcurent->next;
	}

	return newlist;
}

void linkList::deleteNode(int x) {
	Node* curpt = first, * behind = NULL;
	
	do {
		if (x == curpt->data) {
			if (curpt == first)
			{
				first = curpt->next;
				Node* temp = curpt->next;
				delete curpt;
				curpt = temp;
				break;
			}
			else if (curpt == last)
			{
				last = behind;
				last->next = first;
				Node* temp = curpt->next;
				delete curpt;
				curpt = temp;
				break;
			}
			else {
				behind->next = curpt->next;
				Node* temp = curpt->next;
				delete curpt;
				curpt = temp;
			}
			
		}

		else {
			behind = curpt;
			curpt = curpt->next;
		}

	} while (behind != last);
	
}
int &addaval(int &x) {
	;
	for (int i = 2; i < x / 2; i++) {
		if (x % i == 0) {
			break;
		}
		else
			return x;
	}
}

void linkList::display() {
	system("cls");
	Node* curpt = first;
	do {
		cout << curpt->data<<endl;
		curpt = curpt->next;
	} while (curpt != first);
}



int main() {
	linkList* lList1 = new linkList();
	linkList* lList2 = new linkList();
	Qunue test;
	Stack tesst;
	test.Add(5);
	test.Add(7);
	test.Add(9);
	test.Add(10);
	tesst.push(9);
		//lList1->9ddNode(1);
		//lList1->addNode(2);
		//lList1->addNode(4);
		//lList1->addNode(8);
		//lList2->addNode(3);
		//lList2->addNode(5);
		//lList2->addNode(6);
		//lList2->addNode(7);

		//linkList* newlist = lList1->mergeList(lList2);
		//newlist->display();
		//test.display();
		//cout << "ihvasiueh" << endl;
		//test.Delete();
		//test.display();

		getchar();
}