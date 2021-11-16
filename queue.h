#pragma once
//them dau xoa cuoi
struct qNode{
	int data;
	qNode *next;
};
struct Queue{
	qNode *front;
	qNode *rear;
	Queue();
	bool empty();
	void push(int value);
	int pop(int &tmp);
	~Queue();
};
Queue::Queue(){
	front=NULL;
	rear=NULL;
}
bool Queue::empty(){
	return (front==NULL);
}
void Queue::push(int value){
	qNode *p= new qNode;
	p->data = value;
	p->next = NULL;
	if (front == NULL){
		front = p;
	}else {
		rear->next = p;
	}
	rear = p;
}
int Queue::pop(int &tmp) {
	if (empty()) return -1;
	qNode *p = front;
	tmp = front->data;
	front = front->next;
	delete p;
	return 1;
}
Queue::~Queue() {
	while (front != NULL)
	{
		qNode *tmp;
		tmp = front;
		front = front->next;
		delete tmp;
	}
}
