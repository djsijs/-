#include <iostream>
using namespace std;

//链表节点
typedef struct node {
	int data;
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
int EnQueue(LinkQueue &q, int e) {
	QNode *p = (QNode *)malloc(sizeof(QNode));
	p->data = e;
	//把节点插到队列中
	p->next = q.rear->next;
	q.rear->next = p;
	q.rear = p;
}

//出队
int DeQueue(LinkQueue &q, int &e) {
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
		cout << p->data << "\t";
		p = p->next;
	}
	cout << endl;
}

//判断队列是否为空

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
