#include <iostream>
#include <string>
#include <stack>
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

//�ж��Ƿ��������
int Comop(char s) {
	switch (s) {
		case '+':
		case '^':
		case '-':
		case '*':
		case '/':
		case '%':
			return 1;
		default:
			return 0;
	}
}

//����
int Operation(int a, int b, char s) {
	switch (s) {
		case '+':
			return a + b;
		case '^':
			return a ^ b;
		case '-':
			return a - b;
		case '*':
			return a * b;
		case '/':
			return a / b;
		case '%':
			return a % b;
	}
	return 0;
}

//��׺���ʽ����
void Result(string str, SeqStack &s) {
	string k = "";
	for (int i = 0; i < str.length(); i++) {
		if (isdigit(str[i])) {
			k += str[i];
		} else if (str[i] == ' ') {
			if (k != "") {
				s.data[++s.top] = atoi(k.c_str());;
			}
			k = "";
		} else if (Comop(str[i])) {
			int b = s.data[s.top--];
			int a = s.data[s.top--];
			s.data[++s.top] = Operation(a, b, str[i]);
		}
	}
	cout << s.data[s.top--];
}

int main() {
	SeqStack s;
	string str;
	InitStack(s);
	Conversion(s, 12);
	DisplayStack1(s);
//	getline(cin, str);
//	Result(str, s);
	return 0;
}
