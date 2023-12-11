#include <iostream>
using namespace std;

//哈夫曼节点
typedef struct {
	int weight;	//数据或权重
	int parent;	//双亲
	int lchild; //左孩子
	int rchild;	//右孩子
} HTNode;

int n;

//初始化操作
int InitHTree(HTNode htree[]) {	//无参，因为HTree是全局变量
	cout << "请输入叶子节点的个数" << endl;
	cin >> n;
	cout << "请输入" << n << "个叶子节点的权重:" << endl;
	for (int i = 0; i < n; i++) {
		int w;
		cin >> w;
		//0~n-1的叶子初始化
		htree[i].weight = w;
		htree[i].parent = -1;
		htree[i].lchild = -1;
		htree[i].rchild = -1;
	}
	//分支节点初始化
	for (int i = n; i < 2 * n - 1; i++) {
		htree[i].weight = -1;
		htree[i].parent = -1;
		htree[i].lchild = -1;
		htree[i].rchild = -1;
	}
}

//显示哈夫曼树的内容
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

//挑选两个最小的子树
void selectMin(HTNode htree[], int i, int &p1, int &p2) {
	long min1 = 9999, min2 = 9999;
	int j;
	for (j = 0; j <= i; j++) {
		if (htree[j].parent == -1) {
			if (min1 > htree[j].weight) {
				min1 = htree[j].weight;	//最小的权重
				p1 = j;	//最小权重的序号
			}
		}
	}

	for (j = 0; j <= i; j++) {
		if (htree[j].parent == -1 && j != p1) {
			if (min2 > htree[j].weight) {
				min2 = htree[j].weight;	//最小的权重
				p2 = j;	//次小权重的序号
			}
		}
	}
}

//创建哈夫曼树
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

//路径的递归算法
void HTreePath(HTNode htree[], int i, int j) {
	int a, b;
	a = i;
	b = j = htree[i].parent; //i的父节点
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

//根据哈夫曼树求编码
void HCoding(HTNode htree[]) {
	int i, j;
	for (int i = 0; i < n; i++) {
		j = 0;
		cout << endl << htree[i].weight << "\t";
		HTreePath(htree, i, j); //递归函数
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
