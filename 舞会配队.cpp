#include <iostream>
using namespace std;

typedef struct {
	char name[10];
	char sex;
} Person;

//����ڵ�
typedef struct node {
	Person data;
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
int EnQueue(LinkQueue &q, Person e) {
	QNode *p = (QNode *)malloc(sizeof(QNode));
	p->data = e;
	//�ѽڵ�嵽������
	p->next = q.rear->next;
	q.rear->next = p;
	q.rear = p;
}

//����
int DeQueue(LinkQueue &q, Person &e) {
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
		cout << p->data.name << "\t";
		p = p->next;
	}
	cout << endl;
}

//������

int main() {
	LinkQueue Boys, Girls;
	InitQueue(Boys);
	InitQueue(Girls);
	cout << "������������" << endl;
	int n;
	cin >> n;
	Person p;
	for (int i = 0; i < n; i++) {
		cout << "������������" << endl;
		cin >> p.name;
		cout << "�������Ա�" << endl;
		cin >> p.sex;
		if (p.sex == 'F') {
			EnQueue(Girls, p);
		} else {
			EnQueue(Boys, p);
		}
	}
	cout << "�У�" << endl;
	DisplayQueue(Boys);
	cout << "Ů��" << endl;
	DisplayQueue(Girls);

	Person boy, girl;
	cout << "�������������������ӵ������" << endl;
	int k;
	cin >> k;

	for (int i = 1; i <= k; i++) {
		DeQueue(Boys, boy);
		DeQueue(Girls, girl);
		cout << "(" << boy.name << "," << girl.name << ")" << endl;

		EnQueue(Boys, boy);
		EnQueue(Girls, girl);
	}

	return 0;
}
