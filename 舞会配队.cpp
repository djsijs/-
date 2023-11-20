#include <iostream>
using namespace std;

typedef struct {
	char name[10];
	char sex;
} Person;

//链表节点
typedef struct node {
	Person data;
	struct node *next;
} QNode;

//队列节点
typedef struct {
	QNode *front;
	QNode *rear;
} LinkQueue;

//初始化
int InitQueue(LinkQueue &q) {
	//头节点生成
	QNode *p = (QNode *)malloc(sizeof(QNode));
	p->next = nullptr;
	//队列的设置
	q.front = p;
	q.rear = p;
}

//入队
int EnQueue(LinkQueue &q, Person e) {
	QNode *p = (QNode *)malloc(sizeof(QNode));
	p->data = e;
	//把节点插到队列中
	p->next = q.rear->next;
	q.rear->next = p;
	q.rear = p;
}

//出队
int DeQueue(LinkQueue &q, Person &e) {
	if (q.front == q.rear) {
		return -1;
	}
	//拿到队列中的第一个节点
	QNode *p = q.front->next;
	e = p->data;
	q.front->next = p->next;
	//判断删除的节点是否是最后一个节点
	if (p == q.rear) {
		q.rear = q.front;
	}
	free(p);
}

//显示队列数据
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

//舞会配队

int main() {
	LinkQueue Boys, Girls;
	InitQueue(Boys);
	InitQueue(Girls);
	cout << "请输入人数：" << endl;
	int n;
	cin >> n;
	Person p;
	for (int i = 0; i < n; i++) {
		cout << "请输入姓名：" << endl;
		cin >> p.name;
		cout << "请输入性别：" << endl;
		cin >> p.sex;
		if (p.sex == 'F') {
			EnQueue(Girls, p);
		} else {
			EnQueue(Boys, p);
		}
	}
	cout << "男：" << endl;
	DisplayQueue(Boys);
	cout << "女：" << endl;
	DisplayQueue(Girls);

	Person boy, girl;
	cout << "请输入你想输出几次配队的情况：" << endl;
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
