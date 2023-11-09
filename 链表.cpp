#include <iostream>
using namespace std;

typedef struct LNode {
	int data;
	struct LNode *next;
} ListNode, *LinkList;

//创建链表
void createLinkList(LinkList &L) {
	//生成无数据头节点
	L = (LinkList)malloc(sizeof(ListNode));
	L->next = NULL;
	//生成蕴含数据的节点
	int a;
	cin >> a;
	while (a != -1) {
		LinkList s = (LinkList)malloc(sizeof(ListNode));
		s->data = a;
		//把生成的节点放到头节点的后面
		s->next = L->next;
		L->next = s;
		cin >> a;
	}

}

//显示链表
void DisplayLinkList(ListNode *L) {
	ListNode *p = L->next;
	while (p != NULL) {
		printf("%d\t", p->data);
		p = p->next;
	}
	printf("\n");
}

//查找数据 --按值返回序号
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

//按位查找
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

//数据插入
int LinkListInsert(LinkList &L) {
	int a, i;
	printf("请输入插入的值\n");
	cin >> a;
	printf("请输入插入的位置\n");
	cin >> i;

	// 找到前一个节点的指针
	LinkList p = GetElem(L, i - 1);
	if (p == NULL) { // 找不到前一个节点
		printf("无法插入到指定位置\n");
		return -1;
	}

	LinkList q = p->next;
	// 生成新的节点的指针
	LinkList s = (LinkList)malloc(sizeof(ListNode));
	s->data = a;
	// 把新生成的数据插入
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
//			printf("没找到！\n");
//		else
//			printf("数值%d位于第%d位！", a, p);
//	}
	return 0;
}
