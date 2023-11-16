#include <iostream>
#define MAXSIZE 1000
using namespace std;

//˳��ջ
typedef struct {
	int data[MAXSIZE];
	int top;
} SeqStack;

//��ʼ��
int InitStack(SeqStack &s) {
	s.top = -1; //ջ��Ϊ��ջ
	return 1;
}

//��ջ
int Push(SeqStack &s, int e) {
	if (s.top == MAXSIZE - 1) {
		return -1;
	}
	s.top++;
	s.data[s.top] = e;
	return 1;
}

//��ջ
int Pop(SeqStack &s, int &e) {
	if (s.top == -1) {
		return -1;
	}
	e = s.data[s.top];
	s.top--;
	return 1;
}

//�߳�ջ����ʾ����
void PopandDisplay(SeqStack &s) {
	int e;
	while (s.top != -1) {
		Pop(s, e);
		cout << e << "\t";
	}
	cout << endl;
}

//��ʾջ������(�׵�ͷ)
void DisplayStack(SeqStack s) {
	for (int i = 0; i <= s.top; i++) {
		cout << s.data[i] << "\t";
	}
	cout << endl;
}

//��ʾջ������(ͷ����)
void DisplayStack1(SeqStack s) {
	for (int i = s.top; i >= 0; i--) {
		cout << s.data[i] << "\t";
	}
	cout << endl;
}

//����ת��
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
