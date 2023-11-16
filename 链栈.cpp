#include <iostream>

using namespace std;

//链表节点定义
typedef struct node {
	int data;
	struct node *next;
} ListNode, *LinkStack;

//初始化
int InitStack(LinkStack &L) {
	L = (LinkStack)malloc(sizeof(ListNode));
	L->next = nullptr;
}

//入栈
int Push(LinkStack &L, int e) {
	//生成元素的链表节点
	LinkStack p = (LinkStack)malloc(sizeof(ListNode));
	p->data = e;
	//把节点插入到链表中
	p->next = L->next;
	L->next = p;
	return 1;
}

//出栈
int Pop(LinkStack &L, int &e) {
	LinkStack p = L->next;
	if (p == nullptr) {
		return -1;//没有节点
	}
	L->next = p->next;
	return 1;
}

//显示栈里面的元素
void DisplayStack(LinkStack L) {
	LinkStack p = (LinkStack)malloc(sizeof(ListNode));
	p = L->next;
	while (p != nullptr) {
		cout << p->data << "\t";
		p = p->next;
	}
	cout << endl;
}

//进制转换
void Conversion(LinkStack &L, int n) {
	while (n != 0) {
		Push(L, n % 2);
		n /= 2;
	}
}

int main() {
	LinkStack L,S;
	InitStack(L);

	int n, e;
	cin >> n;
	Conversion(L, n);
	DisplayStack(L);
	Pop(L, e);
	DisplayStack(L);

	return 0;
}
