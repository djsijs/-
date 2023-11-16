#include <iostream>
#include <cstring>
#define MAXSIZE 1000
using namespace std;

//顺序栈
typedef struct {
	char data[MAXSIZE];
	int top;
} SeqStack;

//初始化
int InitStack(SeqStack &s) {
	s.top = -1; //栈置为空栈
	return 1;
}

//入栈
int Push(SeqStack &s, char e) {
	if (s.top == MAXSIZE - 1) {
		return -1;
	}
	s.top++;
	s.data[s.top] = e;
	return 1;
}

//出栈
int Pop(SeqStack &s, char &e) {
	if (s.top == -1) {
		return -1;
	}
	e = s.data[s.top];
	s.top--;
	return 1;
}

//边出栈边显示数据
void PopandDisplay(SeqStack &s) {
	char e;
	while (s.top != -1) {
		Pop(s, e);
		cout << e << "\t";
	}
	cout << endl;
}

//显示栈的数据(底到头)
void DisplayStack(SeqStack s) {
	for (int i = s.top; i >= 0; i--) {
		cout << s.data[i] << "\t";
	}
	cout << endl;
}

//判断括号是否匹配
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
		cout << "成功" << endl;
	} else {
		cout << "失败" << endl;
	}

	return 0;
}
