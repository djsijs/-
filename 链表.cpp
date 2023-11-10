#include <iostream>
using namespace std;

typedef struct LNode {
	int data;
	struct LNode *next;
} ListNode, *LinkList;

//创建链表
int createLinkList(LinkList &L) {
	int k = 0;
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
		k++;
	}
	return k;
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

//删除重复元素
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

// 链表逆置
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

//转换为循环链表
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

// 输出循环链表
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

// 删除当前指向的节点
void deleteCurrentNode(LinkList L) {
	if (L == nullptr || L->next == nullptr) {
		return;
	}

	LinkList nextNode = L->next;
	L->data = nextNode->data;
	L->next = nextNode->next;

	delete nextNode;
}

//约瑟夫
void josephusCircle(LinkList L, int m) {
	if (L == nullptr || L->next == nullptr || m <= 0) {
		return;
	}

	LinkList p = L;
	if (m == 1) {
		while (p->next != p) {
			//删除当前指向的节点
			deleteCurrentNode(p);
			//输出循环链表
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
//			printf("没找到！\n");
//		else
//			printf("数值%d位于第%d位！", a, p);
//	}
	return 0;
}
