#include <iostream>
#include <cstring>
#define MAXSIZE 1000
using namespace std;

//˳��ջ
typedef struct {
	char data[MAXSIZE];
	int top;
} SeqStack;

//��ʼ��
int InitStack(SeqStack &s) {
	s.top = -1; //ջ��Ϊ��ջ
	return 1;
}

//��ջ
int Push(SeqStack &s, char e) {
	if (s.top == MAXSIZE - 1) {
		return -1;
	}
	s.top++;
	s.data[s.top] = e;
	return 1;
}

//��ջ
int Pop(SeqStack &s, char &e) {
	if (s.top == -1) {
		return -1;
	}
	e = s.data[s.top];
	s.top--;
	return 1;
}

//�߳�ջ����ʾ����
void PopandDisplay(SeqStack &s) {
	char e;
	while (s.top != -1) {
		Pop(s, e);
		cout << e << "\t";
	}
	cout << endl;
}

//��ʾջ������(�׵�ͷ)
void DisplayStack(SeqStack s) {
	for (int i = s.top; i >= 0; i--) {
		cout << s.data[i] << "\t";
	}
	cout << endl;
}

//�ж������Ƿ�ƥ��
int judge(SeqStack &s, char *str) {
	char e;
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == '{' || str[i] == '(' || str[i] == '[') {
			Push(s, str[i]);
		}

		if (str[i] == '}' || str[i] == ')' || str[i] == ']') {
			if (s.top == -1) {
				return -1;
			}
			if (str[i] == '}') {
				Pop(s, e);
				if (e != '{') {
					return -1;
				}
			}
			if (str[i] == ')') {
				Pop(s, e);
				if (e != '(') {
					return -1;
				}
			}
			if (str[i] == ']') {
				Pop(s, e);
				if (e != '[') {
					return -1;
				}
			}
		}

	}
	if (s.top != -1) {
		return -1;
	}
	return 1;
}

int main() {
	SeqStack s;
	InitStack(s);

	char str[100];
	cin >> str;
	if (judge(s, str) == 1) {
		cout << "�ɹ�" << endl;
	} else {
		cout << "ʧ��" << endl;
	}

	return 0;
}
