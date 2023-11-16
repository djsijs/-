#include <iostream>
#define MAXSIZE 1000
using namespace std;

//顺序栈
typedef struct {
	int data[MAXSIZE];
	int top;
} SeqStack;

//初始化
int InitStack(SeqStack &s) {
	s.top = -1; //栈置为空栈
	return 1;
}

//入栈
int Push(SeqStack &s, int e) {
	if (s.top == MAXSIZE - 1) {
		return -1;
	}
	s.top++;
	s.data[s.top] = e;
	return 1;
}

//出栈
int Pop(SeqStack &s, int &e) {
	if (s.top == -1) {
		return -1;
	}
	e = s.data[s.top];
	s.top--;
	return 1;
}

//边出栈边显示数据
void PopandDisplay(SeqStack &s) {
	int e;
	while (s.top != -1) {
		Pop(s, e);
		cout << e << "\t";
	}
	cout << endl;
}

//显示栈的数据(底到头)
void DisplayStack(SeqStack s) {
	for (int i = 0; i <= s.top; i++) {
		cout << s.data[i] << "\t";
	}
	cout << endl;
}

//显示栈的数据(头到底)
void DisplayStack1(SeqStack s) {
	for (int i = s.top; i >= 0; i--) {
		cout << s.data[i] << "\t";
	}
	cout << endl;
}

//进制转换
void Conversion(SeqStack &s, int n) {
	while (n != 0) {
		Push(s, n % 2);
		n = n / 2;
	}
}

int main() {
	SeqStack s;
	InitStack(s);
	Conversion(s, 13);
	DisplayStack1(s);
	PopandDisplay(s);
	DisplayStack1(s);
	return 0;
}
