#include <iostream>
#include "����.cpp"
using namespace std;
#define MAX_VERTEX_NUM 100

int visited[MAX_VERTEX_NUM];

//����ͼ
typedef struct {
	int vexs[MAX_VERTEX_NUM]; //һά����涥����Ϣ
	int arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; //���ϵ
	int vexnum, arcnum;
} MGraph; //m--matrix ����


//���ݶ�����Ϣ�ҵ������е��±�
int LocateVex(MGraph g, int v) {
	for (int i = 0; i < g.vexnum; i++) {
		if (g.vexs[i] == v) {
			return i;
		}
	}
	return -1;
}

void createGraph(MGraph &g) {
	cout << "������ͼ�Ķ�������";
	cin >> g.vexnum;
	cout << "������ͼ�ı�����";
	cin >> g.arcnum;

	for (int i = 0; i < g.vexnum; i++) {
		cout << "�����붥��g.vex[" << i << "]:";
		cin >> g.vexs[i];
	}

	for (int k = 1; k <= g.arcnum; k++) {
		cout << "�������" << k << "����(v1,v2)=";
		int v1, v2;
		cin >> v1 >> v2;

		int i = LocateVex(g, v1);
		int j = LocateVex(g, v2);

		g.arcs[i][j] = 1;
		g.arcs[j][i] = 1;
	}
}

void displayGraph(MGraph g) {
	cout << "\t";
	for (int i = 0; i < g.vexnum; i++) {
		cout << g.vexs[i] << "\t";
	}
	cout << endl;
	for (int i = 0; i < g.vexnum; i++) {
		cout << g.vexs[i] << "\t";
		for (int j = 0; j < g.vexnum; j++) {
			cout << g.arcs[i][j] << "\t";
		}
		cout << endl;
	}
}

//��v0��һ���ڽӵ�
int firstAdjVex(MGraph g, int v0) {
	for (int j = 0; j < g.vexnum; j++) {
		if (g.arcs[v0][j] == 1 && visited[j] == 0) {
			return j;
		}
	}
	return -1;
}

//����v0����w����һ���ڽӵ�
int nextAdjVex(MGraph g, int v, int w) {
	if (v <= 0 || v >= g.vexnum)
		return -1;

	for (int j = w + 1; j < g.vexnum; j++) {
		if (g.arcs[v][j] == 1 && visited[j] == 0) {
			return j;
		}
	}
	return -1;
}

void DFS(MGraph g, int v) {
	int w;
	cout << g.vexs[v] << "\t";
	visited[v] = 1;
	w = firstAdjVex(g, v);
	while (w != -1) {
		if (!visited[w]) {
			DFS(g, w);
		}
		w = nextAdjVex(g, v, w);
	}
}

//�������
void TraverseGraph(MGraph G) {
	for (int v = 0; v < G.vexnum; v++)
		visited[v] = 0;
	cout << "DFS" << endl;
	for (int v = 0; v < G.vexnum; v++) {
		if (!visited[v])
			DFS(G, v);
	}
	cout << endl;
}

//����
void BFS(MGraph g, int v0) {
	//������б���
	SeqQueue q;
	InitQueue(q);
	int w, k;
	//����ڵ�
	printf("%d\t", g.vexs[v0]);
	visited[v0] = 1;
	//����
	EnQueue(q, v0);
	while (!QueueEmpty(q)) {
		DeQueue(q, w);
		for (k = 0; k < g.vexnum; k++) {
			if (g.arcs[w][k] == 1 && visited[k] == 0) {
				//����ڵ�
				printf("%d\t", g.vexs[k]);
				//��Ϊ�Ѿ����ʹ�
				visited[k] = 1;
				//����
				EnQueue(q, k);
			}
		}
	}
}

void TraverseGraph1(MGraph g) {
	int vi;
	for (vi = 0; vi < g.vexnum; vi++)
		visited[vi] = 0;

	cout << "BFS" << endl;
	for (vi = 0; vi < g.vexnum; vi++) {
		//���й�ȱ���
		if (!visited[vi])
			BFS(g, vi);
	}
}


int main() {
	MGraph G;
	createGraph(G);

	displayGraph(G);
	TraverseGraph(G);
	TraverseGraph1(G);
	return 0;
}
