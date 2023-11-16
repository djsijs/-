#include <iostream>
#include <stack>
#include <string>

using namespace std;

const int MAXSIZE = 100;

//顺序栈
typedef struct {
	int data[MAXSIZE];
	int top;
} SeqStack;

// 判断操作符的优先级
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

// 将算术表达式转换为后缀表达式
string infixToPostfix(string infix) {
	string postfix = "";
	SeqStack opStack;
	opStack.top = -1;

	for (int i = 0; i < infix.length(); i++) {
		char ch = infix[i];

		// 如果是操作数，直接输出到后缀表达式
		if (isdigit(ch)) {
			postfix += ch;
		}
		// 如果是左括号，入栈
		else if (ch == '(') {
			opStack.data[++opStack.top] = ch;
		}
		// 如果是右括号，将栈中的操作符弹出，直到遇到左括号
		else if (ch == ')') {
			while (opStack.top != -1 && opStack.data[opStack.top] != '(') {
				postfix += opStack.data[opStack.top--];
			}
			opStack.top--; // 弹出左括号
		}
		// 如果是操作符，比较优先级后决定入栈或输出
		else {
			while (opStack.top != -1 && getPriority(opStack.data[opStack.top]) >= getPriority(ch)) {
				postfix += opStack.data[opStack.top--];
			}
			opStack.data[++opStack.top] = ch;
		}
	}

	// 将栈中剩余的操作符输出到后缀表达式
	while (opStack.top != -1) {
		postfix += opStack.data[opStack.top--];
	}

	return postfix;
}

int main() {
	string infix;
	cout << "请输入算术表达式：";
	cin >> infix;

	string postfix = infixToPostfix(infix);
	cout << "后缀表达式为：" << postfix << endl;

	return 0;
}