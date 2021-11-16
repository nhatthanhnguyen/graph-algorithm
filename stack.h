#pragma once
//them vao dau, xoa dau
struct sNode{
	int data;
	sNode *next;
};
struct Stack{
	sNode *top;
	Stack();
	bool empty();
	void push(int value);
	int pop(int &tmp);
	~Stack();
};
Stack::Stack() {
	top=NULL;
}
bool Stack::empty() {
	return(top==NULL);
}
void Stack::push(int value) {
	sNode *p = new sNode;
	p->data=value;
	p->next=top;
	top=p;
}
int Stack::pop(int &tmp) {
	if (empty()) return -1;
	sNode *p = top;
	tmp=top->data;
	top=top->next;
	delete p;
	return 1;
}
Stack::~Stack() {
	while(top!=NULL){
		sNode *tmp ;
		tmp=top;
		top=top->next;
		delete tmp;
	}
}