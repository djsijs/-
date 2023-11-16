#include <iostream>
#include <stack>
#include <string>

using namespace std;

const int MAXSIZE = 100;

//˳��ջ
typedef struct {
	int data[MAXSIZE];
	int top;
} SeqStack;

// �жϲ����������ȼ�
int getPriority(char op) {
	if (op == '+' || op == '-')
		return 1;
	else if (op == '*' || op == '/' || op == '%')
		return 2;
	else if (op == '^')
		return 3;
	else
		return 0;
}

// ���������ʽת��Ϊ��׺���ʽ
string infixToPostfix(string infix) {
	string postfix = "";
	SeqStack opStack;
	opStack.top = -1;

	for (int i = 0; i < infix.length(); i++) {
		char ch = infix[i];

		// ����ǲ�������ֱ���������׺���ʽ
		if (isdigit(ch)) {
			postfix += ch;
		}
		// ����������ţ���ջ
		else if (ch == '(') {
			opStack.data[++opStack.top] = ch;
		}
		// ����������ţ���ջ�еĲ�����������ֱ������������
		else if (ch == ')') {
			while (opStack.top != -1 && opStack.data[opStack.top] != '(') {
				postfix += opStack.data[opStack.top--];
			}
			opStack.top--; // ����������
		}
		// ����ǲ��������Ƚ����ȼ��������ջ�����
		else {
			while (opStack.top != -1 && getPriority(opStack.data[opStack.top]) >= getPriority(ch)) {
				postfix += opStack.data[opStack.top--];
			}
			opStack.data[++opStack.top] = ch;
		}
	}

	// ��ջ��ʣ��Ĳ������������׺���ʽ
	while (opStack.top != -1) {
		postfix += opStack.data[opStack.top--];
	}

	return postfix;
}

int main() {
	string infix;
	cout << "�������������ʽ��";
	cin >> infix;

	string postfix = infixToPostfix(infix);
	cout << "��׺���ʽΪ��" << postfix << endl;

	return 0;
}