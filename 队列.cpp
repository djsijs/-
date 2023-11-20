#include <iostream>
#define MAXSIZE 10
using namespace std;

typedef struct {
	int data[MAXSIZE];
	int front;
	int rear;
	int num;
} SeqQueue;

//初始化
int InitQueue(SeqQueue &q) {
	q.front = 0;
	q.rear = 0;
	q.num = 0;
	return 1;
}

//进队
int EnQueue(SeqQueue &q, int e) {
//	if (QueueFull(q))
	if (q.num == MAXSIZE)
		return -1;
	q.data[q.rear] = e;
	q.rear = (q.rear + 1) % MAXSIZE;
	q.num++;
	return 1;
}

//出队
int DeQueue(SeqQueue &q, int &e) {
//	if (QueueFull(q))
	if (q.num == MAXSIZE)
		return -1;
	e = q.data[q.front];
	q.front = (q.front + 1) % MAXSIZE;
	q.num--;
	return 1;
}

//判断队列的长度
int QueueLength(SeqQueue q) {
//	return (q.rear - q.front + MAXSIZE) % MAXSIZE;
	return q.num;
}

//判断队列是否为空
int QueueEmpty(SeqQueue q) {
	if (QueueLength(q) == 0) {
		return 1;
	}
	return 0;
}

//判断队列是满的
int QueueFull(SeqQueue q) {
	//QueueLength(q) == MAXSIZE - 1
	//QueueLength(q)==0&&q.rear!=q.front
	if (QueueLength(q) == 0 && q.rear != q.front) {
		return 1;
	} else {
		return 0;
	}
}

//显示队列数据
void DisplayQueue(SeqQueue q) {
	for (int i = q.front; i < q.rear; i++) {
		cout << q.data[i] << "\t";
	}
	cout << endl;
}

//队列管理的模拟算法
void Algorithm(SeqQueue &q, int a) {
	int e;
	if (a % 2 == 0) {
		DeQueue(q, e);
	} else {
		EnQueue(q, a);
	}
}

int main() {
	SeqQueue q;
	InitQueue(q);
	int a;
	cin >> a;
	do {
		Algorithm(q, a);
		DisplayQueue(q);
		cin >> a;
	} while (a != 0);
	return 0;
}
