#include <iostream>
using namespace std;

typedef struct LNode {
	int data;
	struct LNode *next;
} ListNode, *LinkList;

//��������
int createLinkList(LinkList &L) {
	int k = 0;
	//����������ͷ�ڵ�
	L = (LinkList)malloc(sizeof(ListNode));
	L->next = NULL;
	//�����̺����ݵĽڵ�
	int a;
	cin >> a;
	while (a != -1) {
		LinkList s = (LinkList)malloc(sizeof(ListNode));
		s->data = a;
		//�����ɵĽڵ�ŵ�ͷ�ڵ�ĺ���
		s->next = L->next;
		L->next = s;
		cin >> a;
		k++;
	}
	return k;
}

//��ʾ����
void DisplayLinkList(ListNode *L) {
	ListNode *p = L->next;
	while (p != NULL) {
		printf("%d\t", p->data);
		p = p->next;
	}
	printf("\n");
}

//�������� --��ֵ�������
int LocateElem(LinkList L, int e) {
	LinkList p = L->next;
	int j = 1;
	while (p && p->data != e) {
		p = p->next;
		j++;
	}
	if (!p)
		return -1;
	return j;
}

//��λ����
LinkList GetElem(LinkList L, int i) {
	LinkList p = L;
	int j = 0;
	while (p && j < i) {
		p = p->next;
		j++;
	}
	if (!p || j > i)
		return NULL;
	return p;
}

//���ݲ���
int LinkListInsert(LinkList &L) {
	int a, i;
	printf("����������ֵ\n");
	cin >> a;
	printf("����������λ��\n");
	cin >> i;

	// �ҵ�ǰһ���ڵ��ָ��
	LinkList p = GetElem(L, i - 1);
	if (p == NULL) { // �Ҳ���ǰһ���ڵ�
		printf("�޷����뵽ָ��λ��\n");
		return -1;
	}

	LinkList q = p->next;
	// �����µĽڵ��ָ��
	LinkList s = (LinkList)malloc(sizeof(ListNode));
	s->data = a;
	// �������ɵ����ݲ���
	s->next = q;
	p->next = s;

	return 0;
}

//ɾ���ظ�Ԫ��
void delRepeat(LinkList &L, int m) {
	LinkList p = L, q;
	int a[m + 1] = {0};
	while (p->next) {
		int i = p->next->data;
		if (a[i] == 0) {
			a[i] = 1;
			p = p->next;
		} else {
			q = p->next;
			p->next = q->next;
			free(q);
		}
	}
}

// ��������
void reverseList(LinkList &L) {
	LinkList prev = nullptr;
	LinkList curr = L->next;
	while (curr != nullptr) {
		LinkList nextTemp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = nextTemp;
	}
	L ->next = prev;
}

//ת��Ϊѭ������
void ConvertToCircularList(LinkList &L) {
	if (L == nullptr || L->next == nullptr) {
		return;
	}
	L = L->next;
	LinkList p = L;
	while (p->next != nullptr) {
		p = p->next;
	}
	p->next = L;

}

// ���ѭ������
void PrintCircularList(LinkList L) {
	if (L == nullptr) {
		return;
	}

	LinkList p = L;
	do {
		cout << p->data << " ";
		p = p->next;
	} while (p != L);
	cout << endl;
}

// ɾ����ǰָ��Ľڵ�
void deleteCurrentNode(LinkList L) {
	if (L == nullptr || L->next == nullptr) {
		return;
	}

	LinkList nextNode = L->next;
	L->data = nextNode->data;
	L->next = nextNode->next;

	delete nextNode;
}

//Լɪ��
void josephusCircle(LinkList L, int m) {
	if (L == nullptr || L->next == nullptr || m <= 0) {
		return;
	}

	LinkList p = L;
	if (m == 1) {
		while (p->next != p) {
			//ɾ����ǰָ��Ľڵ�
			deleteCurrentNode(p);
			//���ѭ������
			PrintCircularList(p);
		}
		return;
	}
	while (p->next != p) {
		for (int i = 1; i < m - 1; i++) {
			p = p->next;
		}

		LinkList deletedNode = p->next;
		p->next = deletedNode->next;
		delete deletedNode;

		p = p->next;
		PrintCircularList(p);
	}

	delete p;
}

int main() {
	LinkList L;
	int k = createLinkList(L);
	DisplayLinkList(L);
	ConvertToCircularList(L);
	PrintCircularList(L);
	josephusCircle(L, 1);
//	LinkListInsert(L);
//	DisplayLinkList(L);
//	int a;
//	while (~scanf("%d", &a)) {
//		int p = LocateElem(L, a);
//		if (p == -1)
//			printf("û�ҵ���\n");
//		else
//			printf("��ֵ%dλ�ڵ�%dλ��", a, p);
//	}
	return 0;
}
