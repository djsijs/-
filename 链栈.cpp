#include <iostream>

using namespace std;

//����ڵ㶨��
typedef struct node {
	int data;
	struct node *next;
} ListNode, *LinkStack;

//��ʼ��
int InitStack(LinkStack &L) {
	L = (LinkStack)malloc(sizeof(ListNode));
	L->next = nullptr;
}

//��ջ
int Push(LinkStack &L, int e) {
	//����Ԫ�ص�����ڵ�
	LinkStack p = (LinkStack)malloc(sizeof(ListNode));
	p->data = e;
	//�ѽڵ���뵽������
	p->next = L->next;
	L->next = p;
	return 1;
}

//��ջ
int Pop(LinkStack &L, int &e) {
	LinkStack p = L->next;
	if (p == nullptr) {
		return -1;//û�нڵ�
	}
	L->next = p->next;
	return 1;
}

//��ʾջ�����Ԫ��
void DisplayStack(LinkStack L) {
	LinkStack p = (LinkStack)malloc(sizeof(ListNode));
	p = L->next;
	while (p != nullptr) {
		cout << p->data << "\t";
		p = p->next;
	}
	cout << endl;
}

//����ת��
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
