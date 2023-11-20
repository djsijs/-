#include <iostream>
using namespace std;

//����ڵ�
typedef struct node {
	int data;
	struct node *next;
} QNode;

//���нڵ�
typedef struct {
	QNode *front;
	QNode *rear;
} LinkQueue;

//��ʼ��
int InitQueue(LinkQueue &q) {
	//ͷ�ڵ�����
	QNode *p = (QNode *)malloc(sizeof(QNode));
	p->next = nullptr;
	//���е�����
	q.front = p;
	q.rear = p;
}

//���
int EnQueue(LinkQueue &q, int e) {
	QNode *p = (QNode *)malloc(sizeof(QNode));
	p->data = e;
	//�ѽڵ�嵽������
	p->next = q.rear->next;
	q.rear->next = p;
	q.rear = p;
}

//����
int DeQueue(LinkQueue &q, int &e) {
	if (q.front == q.rear) {
		return -1;
	}
	//�õ������еĵ�һ���ڵ�
	QNode *p = q.front->next;
	e = p->data;
	q.front->next = p->next;
	//�ж�ɾ���Ľڵ��Ƿ������һ���ڵ�
	if (p == q.rear) {
		q.rear = q.front;
	}
	free(p);
}

//��ʾ��������
void DisplayQueue(LinkQueue q) {
	if (q.front == q.rear) {
		return;
	}
	QNode *p = q.front->next;
	while (p != nullptr) {
		cout << p->data << "\t";
		p = p->next;
	}
	cout << endl;
}

//�ж϶����Ƿ�Ϊ��

int main() {
	LinkQueue q;
	InitQueue(q);
	for (int i = 1; i <= 10; i++) {
		EnQueue(q, i);
		DisplayQueue(q);
	}
	int e = 0;
	DeQueue(q, e);
	DisplayQueue(q);
	return 0;
}
