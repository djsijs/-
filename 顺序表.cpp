#include <iostream>
#include <algorithm>
#define MaxSize 100
typedef int Elemtype;
using namespace std;

typedef struct {
	Elemtype *data;
	Elemtype last;
	Elemtype length;
} SeqList;

//��ʼ��˳���
int InitList(SeqList &L) {
	L.data = (Elemtype *)malloc(MaxSize * sizeof(int));
	L.last = -1;
	L.length = 0;
	return 1; //��ʾ�ɹ�
}


//��������
int ListInsert(SeqList &L, int i, int e) {
	if (i < 1 || i > L.length + 1) {
		return 0;
	}
	for (int j = L.length; j >= i; j--) {
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = e;
	L.length++;
	return 1;
}

//����Ԫ��
int LocateElem(SeqList L, int e) {
	for (int i = 0; i < L.length; i++) {
		if (L.data[i] == e) {
			return i + 1;
		}
	}
	return -1;
}

//����ֵ
int Find(SeqList L, int e) {
	return L.data[e - 1];
}

//ɾ��Ԫ��
int ListDelete(SeqList &L, int i) {
	if (i < 1 || i > L.length) {
		return 0;
	}
	for (int j = i - 1; j < L.length; j++) {
		L.data[j] = L.data[j + 1];
	}
	L.length--;
	return 1;
}

//ɾ������ָ��Ԫ��
void ListAllDelete(SeqList &L, int e) {
	int k = 0;
	for (int i = 0; i < L.length; i++) {
		if (L.data[i] != e) {
			L.data[k++] = L.data[i];
		}
	}
	L.length = k;
}

//��ʾ˳����е�����
void DisplayList(SeqList L) {
	for (int i = 0; i < L.length; i++) {
		printf("%d ", L.data[i]);
	}
}

//�ж�˳����Ƿ�Ϊ��
bool ListEmpty(SeqList L) {
	//1Ϊ�գ�����Ϊ�ǿ�
	return L.length == 0;
}

//��С
bool cmp1(Elemtype &a, Elemtype &b) {
	return a > b;
}

//С����
bool cmp(Elemtype &a, Elemtype &b) {
	return a < b;
}

//�ϲ�˳���
void MergeSeqList(SeqList &L, SeqList &L1) {
	for (int i = 0; i < L1.length; i++) {
		L.data[i + L.length] = L1.data[i];
	}
	L.length += L1.length;
}

//��һ���������С��a���ұߴ���a
SeqList ordination(SeqList &L) {
	SeqList L1, L2;
	InitList(L1);
	InitList(L2);
	int a1 = L.data[0], i = 1;
	for (int k = 1; k < L.length; k++) {
		if (L.data[k] < a1) {
			L1.data[L1.length] = L.data[k];
			L1.length++;
		} else if (L.data[k] > a1) {
			L2.data[L2.length] = L.data[k];
			L2.length++;
		} else if (L.data[k] == a1) {
			i++;
		}
	}
	sort(L1.data, L1.data + L1.length, cmp);
	sort(L2.data, L2.data + L2.length, cmp);
	for (int k = 0; k < i; k++) {
		L1.data[L1.length + k] = a1;
		L1.length++;
	}

	MergeSeqList(L1, L2);
	return L1;
}

int main() {
	SeqList A, B, C;

	if (InitList(C)) {
		printf("˳����ʼ���ɹ���\n");

		//��������
//		for (int i = 1; i <= 10; i++) {
//			ListInsert(L, i, i * i);
//		}

		ListInsert(C, 1, 3);
		ListInsert(C, 1, 2);
		ListInsert(C, 2, 2);
		ListInsert(C, 3, 6);
		ListInsert(C, 3, 8);
		ListInsert(C, 1, 12);
		ListInsert(C, 3, 10);
		ListInsert(C, 2, 2);
		ListInsert(C, 3, 6);
		ListInsert(C, 2, 2);
		ListInsert(C, 1, 5);

		//��ʾ����
		DisplayList(C);
		printf("\n");
//		MergeSeqList(C, B);
//		MergeSeqList(C, A);
		sort(C.data, C.data + C.length, cmp);
//		SeqList L1 = ordination(L);
		DisplayList(C);
//		printf("\n������Ҫɾ����Ԫ�أ�\n");
//		int x;
//		cin >> x;
//		ListAllDelete(L, x);

//		printf("\n������Ҫ���ҵ�Ԫ�أ�\n");
//		int x;
//		cin >> x;
//		int p = LocateElem(L, x);
//		if (p != -1) {
//			printf("����%d����%dλ\n", x, p);
//		} else {
//			printf("û�ҵ���");
//		}

		//ɾ������
//		printf("\n");
//		int e;
//		ListDelete(L, 3, e);
//		DisplayList(L);


	} else {
		printf("˳����ʼ��ʧ�ܣ�");
	}

	return 0;
}
