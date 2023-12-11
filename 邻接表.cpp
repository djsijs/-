#include <iostream>
using namespace std;
#define MAX_VEX_NUM 100

int visited[MAX_VEX_NUM];

//边表节点
typedef struct node {
	int adjVex;//邻接点的序号
	int weight;//权重
	struct node *next;//指针
} ArcNode;

//顶点节点
typedef struct {
	int data;
	ArcNode *firstArc;//第一个边表节点
} VexNode;

//邻接表
typedef struct {
	VexNode vertices[MAX_VEX_NUM];
	int vexnum, arcnum;
} ALGraph;

//根据顶点信息找到数组中的下标
int LocateVex(ALGraph g, int v) {
	for (int i = 0; i < g.vexnum; i++) {
		if (g.vertices[i].data == v) {
			return i;
		}
	}
	return -1;
}

void vreateGraph(ALGraph &g) {
	cout << "请输入图的顶点数：";
	cin >> g.vexnum;
	cout << "请输入图的边数：";
	cin >> g.arcnum;

	for (int i = 0; i < g.vexnum; i++) {
		cout << "请输入第" << i + 1 << "个顶点";
		cin >> g.vertices[i].data;
		g.vertices[i].firstArc = nullptr;
	}

	int v1, v2;
	for (int k = 1; k <= g.arcnum; k++) {
		cout << "请输入第" << k << "条边(v1,v2)=";
		cin >> v1 >> v2;

		int i = LocateVex(g, v1);
		int j = LocateVex(g, v2);

		//生成节点
		ArcNode *p = (ArcNode *)malloc(sizeof(ArcNode));
		p->adjVex = j;
		p->weight = 0;
		//节点接入顶点的指针域(头插)
		p->next = g.vertices[i].firstArc;
		g.vertices[i].firstArc = p;


		p = (ArcNode *)malloc(sizeof(ArcNode));
		p->adjVex = i;
		p->weight = 0;
		//节点接入顶点的指针域(头插)
		p->next = g.vertices[j].firstArc;
		g.vertices[j].firstArc = p;
	}
}

void displayGraph(ALGraph g) {
	for (int i = 0; i < g.vexnum; i++) {
		cout << g.vertices[i].data << " ";

		//检查链表中的内容
		ArcNode *p = g.vertices[i].firstArc;
		while (p) {
			cout << "--->[" << g.vertices[p->adjVex].data << "," << p->weight << "]";
			p = p->next;
		}
		cout << endl;
	}
}

//深搜
//得到第一个邻接点
int firstAdjVex(ALGraph g, int v) {
	ArcNode *p;
	p = g.vertices[v].firstArc;
	if (p)
		return p->adjVex;
	else
		return -1;
}

//查找下一个邻接点
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
