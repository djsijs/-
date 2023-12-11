#include <iostream>
using namespace std;
#define MAX_VEX_NUM 100

int visited[MAX_VEX_NUM];

//�߱�ڵ�
typedef struct node {
	int adjVex;//�ڽӵ�����
	int weight;//Ȩ��
	struct node *next;//ָ��
} ArcNode;

//����ڵ�
typedef struct {
	int data;
	ArcNode *firstArc;//��һ���߱�ڵ�
} VexNode;

//�ڽӱ�
typedef struct {
	VexNode vertices[MAX_VEX_NUM];
	int vexnum, arcnum;
} ALGraph;

//���ݶ�����Ϣ�ҵ������е��±�
int LocateVex(ALGraph g, int v) {
	for (int i = 0; i < g.vexnum; i++) {
		if (g.vertices[i].data == v) {
			return i;
		}
	}
	return -1;
}

void vreateGraph(ALGraph &g) {
	cout << "������ͼ�Ķ�������";
	cin >> g.vexnum;
	cout << "������ͼ�ı�����";
	cin >> g.arcnum;

	for (int i = 0; i < g.vexnum; i++) {
		cout << "�������" << i + 1 << "������";
		cin >> g.vertices[i].data;
		g.vertices[i].firstArc = nullptr;
	}

	int v1, v2;
	for (int k = 1; k <= g.arcnum; k++) {
		cout << "�������" << k << "����(v1,v2)=";
		cin >> v1 >> v2;

		int i = LocateVex(g, v1);
		int j = LocateVex(g, v2);

		//���ɽڵ�
		ArcNode *p = (ArcNode *)malloc(sizeof(ArcNode));
		p->adjVex = j;
		p->weight = 0;
		//�ڵ���붥���ָ����(ͷ��)
		p->next = g.vertices[i].firstArc;
		g.vertices[i].firstArc = p;


		p = (ArcNode *)malloc(sizeof(ArcNode));
		p->adjVex = i;
		p->weight = 0;
		//�ڵ���붥���ָ����(ͷ��)
		p->next = g.vertices[j].firstArc;
		g.vertices[j].firstArc = p;
	}
}

void displayGraph(ALGraph g) {
	for (int i = 0; i < g.vexnum; i++) {
		cout << g.vertices[i].data << " ";

		//��������е�����
		ArcNode *p = g.vertices[i].firstArc;
		while (p) {
			cout << "--->[" << g.vertices[p->adjVex].data << "," << p->weight << "]";
			p = p->next;
		}
		cout << endl;
	}
}

//����
//�õ���һ���ڽӵ�
int firstAdjVex(ALGraph g, int v) {
	ArcNode *p;
	p = g.vertices[v].firstArc;
	if (p)
		return p->adjVex;
	else
		return -1;
}

//������һ���ڽӵ�
int nextAdjVex(ALGraph g, int v, int w) {
	ArcNode *p;
	p = g.vertices[v].firstArc;
	while (p && p->adjVex != w)
		p = p->next;
	if (!p || !p->next)
		return -1;
	else
		return p->next->adjVex;
}

void DFS(ALGraph g, int v) {
	int v1, w1;
	v1 = g.vertices[v].data;
	visited[v] = 1;
	printf("%d ", v1);
	for (w1 = firstAdjVex(g, v); w1 >= 0; w1 = nextAdjVex(g, v, w1))
		if (!visited[w1])
			DFS(g, w1);
}

void DFSTraverse(ALGraph G) {
	for (int v = 0; v < G.vexnum; v++)
		visited[v] = 0;
	for (int v = 0; v < G.vexnum; v++) {
		if (!visited[v])
			DFS(G, v);
	}
}

int main() {
	ALGraph G;
	vreateGraph(G);

	displayGraph(G);
	DFSTraverse(G);
	return 0;
}
