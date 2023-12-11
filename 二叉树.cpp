#include <iostream>
using namespace std;
typedef int Elemtype;

typedef struct node {
	Elemtype data;
	struct node *left, *right;
} BiNode, *BiTree;

//��ʼ��
int InitTree(BiTree &t) {
	t = nullptr;
}

//�����ڵ�
int createTreeNode(BiTree &t, Elemtype n) {
	t = (BiTree)malloc(sizeof(BiNode));
	t->data = n;
	t->left = nullptr;
	t->right = nullptr;
}

//�������
void preOrder(BiTree t) {
	if (t) {
		cout << t->data << "\t";
		preOrder(t->left);
		preOrder(t->right);
	}
}

//�������
void inOrder(BiTree t) {
	if (t) {
		inOrder(t->left);
		cout << t->data << "\t";
		inOrder(t->right);
	}
}

//�������
void postOrder(BiTree t) {
	if (t) {
		postOrder(t->left);
		postOrder(t->right);
		cout << t->data << "\t";
	}
}

void creat(BiTree &t) {
	Elemtype k;
	cin >> k;
	if (k == NULL) {
		return;
	} else {
		t = (BiTree)malloc(sizeof(BiNode));
		creat(t->left);
		creat(t->right);
	}
}

void insert(BiTree &t, Elemtype k) {
	if (t == nullptr) {
		createTreeNode(t, k);
		return;
	}
	if (t->data > k) {
		insert(t->left, k);
	} else if (t->data < k) {
		insert(t->right, k);
	}
}

//ͨ����չ�����������������
int createBiTree(BiTree &t) {
	char ch;
	cin >> ch;
	if (ch == '#') {
		t = nullptr;
	} else {
		t = (BiTree)malloc(sizeof(BiNode));
		t->data = ch - '0';
		createBiTree(t->left);
		createBiTree(t->right);
	}
}

//����x�ڶ������е�λ��
BiTree searchNode(BiTree t, Elemtype x) {
	if (t != nullptr) {
		if (t->data == x) {
			return t;
		} else {
			if (searchNode(t->left, x) != nullptr) {
				return searchNode(t->left, x);
			} else if (searchNode(t->right, x) != nullptr) {
				return searchNode(t->right, x);
			}
		}
	}
	return nullptr;
}

//�������ڵ������
void countNode(BiTree t, int &num) {
	if (t != nullptr) {
		num++;
		countNode(t->left, num);
		countNode(t->right, num);
	}
}

//�����������
int treeDepth(BiTree t) {
	int depth = 0, ldepth = 0, rdepth = 0;
	if (t != nullptr) {
		ldepth = treeDepth(t->left);
		rdepth = treeDepth(t->right);
		depth = (ldepth > rdepth ? ldepth : rdepth) + 1;
	}
	return depth;
}

//Ҷ�ӽڵ������
void countLeaf(BiTree t, int &num) {
	if (t != nullptr) {
		countLeaf(t->left, num);
		countLeaf(t->right, num);
		if (t->left == nullptr && t->right == nullptr) {
			num++;
		}
	}
}

int main() {
	BiNode *root;
	InitTree(root);
//	int n = 4;
//	int k;
//	for (int i = 0; i < n; i++) {
//		cin >> k;
//		insert(root, k);
//	}


	createBiTree(root);

//	cout << treeDepth(root) << endl;
	int num;
	countLeaf(root, num);
	cout << num << endl;

//	int num = 0;
//	countNode(root, num);
//	cout << num;

//	BiTree t = searchNode(root, 1);
//	if (t == nullptr) {
//		cout << "�Ҳ���" << endl;
//	} else {
//		cout << t->data << endl;
//	}


	cout << "���������" << endl;
	preOrder(root);
	cout << endl << "���������" << endl;
	inOrder(root);
	cout << endl << "���������" << endl;
	postOrder(root);
	return 0;
}
