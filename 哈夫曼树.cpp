#include <iostream>
using namespace std;

//�������ڵ�
typedef struct {
	int weight;	//���ݻ�Ȩ��
	int parent;	//˫��
	int lchild; //����
	int rchild;	//�Һ���
} HTNode;

int n;

//��ʼ������
int InitHTree(HTNode htree[]) {	//�޲Σ���ΪHTree��ȫ�ֱ���
	cout << "������Ҷ�ӽڵ�ĸ���" << endl;
	cin >> n;
	cout << "������" << n << "��Ҷ�ӽڵ��Ȩ��:" << endl;
	for (int i = 0; i < n; i++) {
		int w;
		cin >> w;
		//0~n-1��Ҷ�ӳ�ʼ��
		htree[i].weight = w;
		htree[i].parent = -1;
		htree[i].lchild = -1;
		htree[i].rchild = -1;
	}
	//��֧�ڵ��ʼ��
	for (int i = n; i < 2 * n - 1; i++) {
		htree[i].weight = -1;
		htree[i].parent = -1;
		htree[i].lchild = -1;
		htree[i].rchild = -1;
	}
}

//��ʾ��������������
void DisplayHTree(HTNode htree[]) {
	cout << "No.\tWeight\tParent\tLchild\tRchild" << endl;
	for (int i = 0; i < 2 * n - 1; i++) {
		cout << i << "\t";
		cout << htree[i].weight << "\t";
		cout << htree[i].parent << "\t";
		cout << htree[i].lchild << "\t";
		cout << htree[i].rchild << endl;
	}
}

//��ѡ������С������
void selectMin(HTNode htree[], int i, int &p1, int &p2) {
	long min1 = 9999, min2 = 9999;
	int j;
	for (j = 0; j <= i; j++) {
		if (htree[j].parent == -1) {
			if (min1 > htree[j].weight) {
				min1 = htree[j].weight;	//��С��Ȩ��
				p1 = j;	//��СȨ�ص����
			}
		}
	}

	for (j = 0; j <= i; j++) {
		if (htree[j].parent == -1 && j != p1) {
			if (min2 > htree[j].weight) {
				min2 = htree[j].weight;	//��С��Ȩ��
				p2 = j;	//��СȨ�ص����
			}
		}
	}
}

//������������
void createHTree(HTNode htree[]) {
	int p1, p2;
	for (int i = n; i < 2 * n - 1; i++) {
		selectMin(htree, i - 1, p1, p2);
		htree[i].lchild = p1;
		htree[i].rchild = p2;
		htree[i].weight = htree[p1].weight + htree[p2].weight;
		htree[p1].parent = i;
		htree[p2].parent = i;
	}
}

//·���ĵݹ��㷨
void HTreePath(HTNode htree[], int i, int j) {
	int a, b;
	a = i;
	b = j = htree[i].parent; //i�ĸ��ڵ�
	if (htree[j].parent != -1) {
		i = j;
		HTreePath(htree, i, j);
	}
	if (htree[b].lchild == a) {
		cout << 0;
	} else {
		cout << 1;
	}
}

//���ݹ������������
void HCoding(HTNode htree[]) {
	int i, j;
	for (int i = 0; i < n; i++) {
		j = 0;
		cout << endl << htree[i].weight << "\t";
		HTreePath(htree, i, j); //�ݹ麯��
	}
}


int main() {
	HTNode HTree[200];
	InitHTree(HTree);
	createHTree(HTree);
	DisplayHTree(HTree);
	HCoding(HTree);
	return 0;
}
