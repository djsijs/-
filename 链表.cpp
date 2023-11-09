#include <iostream>
using namespace std;

typedef struct LNode {
	int data;
	struct LNode *next;
} ListNode, *LinkList;

//��������
void createLinkList(LinkList &L) {
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
	}

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

int main() {
	LinkList L;
	createLinkList(L);
	DisplayLinkList(L);
	LinkListInsert(L);
	DisplayLinkList(L);
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
