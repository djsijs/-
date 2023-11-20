#include <iostream>
#define MAXSIZE 10
using namespace std;

typedef struct {
	int data[MAXSIZE];
	int front;
	int rear;
	int num;
} SeqQueue;

//��ʼ��
int InitQueue(SeqQueue &q) {
	q.front = 0;
	q.rear = 0;
	q.num = 0;
	return 1;
}

//����
int EnQueue(SeqQueue &q, int e) {
//	if (QueueFull(q))
	if (q.num == MAXSIZE)
		return -1;
	q.data[q.rear] = e;
	q.rear = (q.rear + 1) % MAXSIZE;
	q.num++;
	return 1;
}

//����
int DeQueue(SeqQueue &q, int &e) {
//	if (QueueFull(q))
	if (q.num == MAXSIZE)
		return -1;
	e = q.data[q.front];
	q.front = (q.front + 1) % MAXSIZE;
	q.num--;
	return 1;
}

//�ж϶��еĳ���
int QueueLength(SeqQueue q) {
//	return (q.rear - q.front + MAXSIZE) % MAXSIZE;
	return q.num;
}

//�ж϶����Ƿ�Ϊ��
int QueueEmpty(SeqQueue q) {
	if (QueueLength(q) == 0) {
		return 1;
	}
	return 0;
}

//�ж϶���������
int QueueFull(SeqQueue q) {
	//QueueLength(q) == MAXSIZE - 1
	//QueueLength(q)==0&&q.rear!=q.front
	if (QueueLength(q) == 0 && q.rear != q.front) {
		return 1;
	} else {
		return 0;
	}
}

//��ʾ��������
void DisplayQueue(SeqQueue q) {
	for (int i = q.front; i < q.rear; i++) {
		cout << q.data[i] << "\t";
	}
	cout << endl;
}

//���й����ģ���㷨
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
