#include <iostream>
#include "队列.cpp"
using namespace std;
#define MAX_VERTEX_NUM 100

int visited[MAX_VERTEX_NUM];

//无向图
typedef struct {
	int vexs[MAX_VERTEX_NUM]; //一维数组存顶点信息
	int arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; //存关系
	int vexnum, arcnum;
} MGraph; //m--matrix 矩阵


//根据顶点信息找到数组中的下标
int LocateVex(MGraph g, int v) {
	for (int i = 0; i < g.vexnum; i++) {
		if (g.vexs[i] == v) {
			return i;
		}
	}
	return -1;
}

void createGraph(MGraph &g) {
	cout << "请输入图的顶点数：";
	cin >> g.vexnum;
	cout << "请输入图的边数：";
	cin >> g.arcnum;

	for (int i = 0; i < g.vexnum; i++) {
		cout << "请输入顶点g.vex[" << i << "]:";
		cin >> g.vexs[i];
	}

	for (int k = 1; k <= g.arcnum; k++) {
		cout << "请输入第" << k << "条边(v1,v2)=";
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

//找v0第一个邻接点
int firstAdjVex(MGraph g, int v0) {
	for (int j = 0; j < g.vexnum; j++) {
		if (g.arcs[v0][j] == 1 && visited[j] == 0) {
			return j;
		}
	}
	return -1;
}

//查找v0关于w的下一个邻接点
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

//深度搜索
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

//广搜
void BFS(MGraph g, int v0) {
	//定义队列变量
	SeqQueue q;
	InitQueue(q);
	int w, k;
	//输出节点
	printf("%d\t", g.vexs[v0]);
	visited[v0] = 1;
	//进队
	EnQueue(q, v0);
	while (!QueueEmpty(q)) {
		DeQueue(q, w);
		for (k = 0; k < g.vexnum; k++) {
			if (g.arcs[w][k] == 1 && visited[k] == 0) {
				//输出节点
				printf("%d\t", g.vexs[k]);
				//设为已经访问过
				visited[k] = 1;
				//进队
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
		//进行广度遍历
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
