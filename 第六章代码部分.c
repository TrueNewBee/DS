// 2020-6-2 19:32:35


// 邻接矩阵法

# define MaxVerTexNum 100                       // 顶点数目的最大值
typedef struct{
    char Vex[MaxVerTexNum];                     // 顶点表
    int Edge[MaxVerTexNum][MaxVerTexNum];       // 邻接矩阵,边表
    int vexnum, arcnum;                         // 图的当前顶点数和边数/弧数
}MGraph;


// 带权图(网)
# define MaxVertexNum 100                       // 顶点数目的最大值
# define INFINITY 最大的int值                    // 宏定义常量 无穷 
typedef char VertexType;                        // 定点的数据类型
typedef int EdgeType;                           // 带权图中边上权值的数据类型
typedef struct{
    VertexType Vex[MaxVerTexNum];               // 顶点
    EdgeType Edge[MaxVerTexNum][MaxVerTexNum];  // 边的权
    int vexnum, arcnum;                         // 图的当前顶点数和弧数
};



// 链接表法(顺序+链式存储)
// "边/弧长"
typedef struct ArcNode{
    int adjvex;                 // 边/弧指向哪个节点
    struct ArcNode *next;       // 指向下一条弧的指针
    // InfoType info;           // 边权值
}ArcNode;

// "顶点"
typedef struct VNode{
    VertexType data;            // 顶点信息
    ArcNode *first;             // 第一条边/弧长
}VNode, AdjList[MaxVertexNum];

// 用邻接表存储的图
typedef struct{
    AdjList vertices;
    int vexnum, arcnum;
};



// 广度优先遍历
bool visited[MAX_VERTEX_NUM];   // 访问标记数组

// 广度优先遍历
void BFS(Graph G, int v){       // 从顶点v竹筏,广度优先遍历图G
    visit(v);                   // 访问初始顶点v
    visited[v]=TRUE;            // 对v做已访问标记
    Enqueue(Q, v);              // 顶点v入队列Q
    while(!isEmpty(Q)){         
        DeQueue(Q,v);           // 顶点v出队
        for(w=FirstNeighbor(G,v);w>=0;w=NextNeighbot(G,v,w))
            // 检测v所有邻接表
            if(!visited[w]){    // w为v的尚未访问的邻接顶点
                visit(w);       // 访问顶点w
                visited[w] = TRUE;  // 对w做已访问标记
                EnQueue(Q,w);       // 顶点w入队列
            }//if
    }//while
}



// BFS算法(Final版)
bool visited[MAX_VERTEX_NUM];       // 访问标记数组
void BFSTraverse(Graph G){          // 对图G进行广度优先遍历
    for (i=0;i<G.vexnum;++i)
        visited[i] = FALSE;         // 访问标记数组初始化
    InitQueue(Q);                   // 初始化辅助队列Q
    For(i=0; i<G.vexnum;++i)        // 讲0号顶点开始遍历
        if(!visited[i])             // 对每个连通分量调用一次BFS
            BFS(G,i);               // vi未访问过,从vi开始BFS
}

// 广度优先遍历
void BFS(Graph G, int v){           // 从顶点v除法,广度优先遍历G
    visit(v);                       // 访问初始化顶点v
    visited[v] = TRUE;              // 对v做已访问标记
    Enqueue(Q,v);                   // 顶点v入队列Q
    while(!isEmpty(Q)){
        DeQueue(Q, v);              // 顶点v出队列
        for(w=FirstNeighbor(G,v);w>=0;w=NextNeighbot(G, v, w))
            // 检测v所有邻接点
            if(!visited[w]){        // w为v的尚未访问的邻接顶点
                visit(w);           // 访问顶点w
                visited[w]=TRUE;    // 对w做已访问标记
                EnQueue(Q,w);       // 顶点w入队  
            }
    }
}



// DFS算法(Final版)
bool visited(MAX_VERTEX_NUM);       // 访问标记数组
void DFSTraverse(Graph G){          // 对图G进行深度优先遍历
    for (v=0;v<G.vexnum;++v)
        visited[v]=FALSE;           // 初始化已访问标记数据
    for (v=0; v<G.vexnum;++v)       // 本代码中是从v=0开始比那里
        if(!visited[v])
            DFS(G,v);
}

void DFS(Graph G, int v){           // 从顶点v除法,深度优先遍历图G
    visit(v);                       // 访问顶点v
    visted[v]=TRUE;                 // 设已访问标记
    for (w=FirstNeighbor(G,v);w>0;w=NextNeighbot(G,v,w)
        if(!visited[w]){            // w为u的尚未访问的邻接顶点
            DFS(G,w);
        }
}



// BFS邻接矩阵最短路径代码实现
// 求顶点 u到其他顶点到的最短路径
void BFS_MIN_Distance(Graph G, int u){
    //d[i]表示从u到i结点的最短路径
    for(i=0;i<G.vexnum;++i){
        d[i]=00;            // 初始化路径长度
        path[i] = -1;       // 最短路径从哪个顶点过来
    }
    d[u]=0;       
    visited[u]=TRUE;
    EnQueue(Q,u);
    while(!isEmpty(Q)){     // BFS算法主过程
        DeQueue(Q, u);      // 队头元素u出队
        for(w=FirstNeighbor(G, u);w>=0;w=NextNeighbot(G,u,w))
            if(!visited[w]){        // w为u的尚未访问的邻接顶点
                d[w]=d[u]+1;        // 路径长度加1
                path[w]=u;          // 最短路径应从u到w
                visited[w] = TRUE;  // 设已访问标记
                EnQueue(Q,w);       // 顶点w入队
            }
    }
}



// Floyd算法核心代码
//......准备工作,根据图的信息初始化矩阵A和path(如上图 30Floyd核心代码.png)
for(int k=0; k<n; k++){             // 考虑以vk作为中转点
    for(int i=0;i<n;i++){           // 遍历整个矩阵,i为行号,j为列号 
        for(int j=0;j<n;j++){
            if(A[i][j]>A[i][k]+A[k][j]){    // 以Vk为中转点的路径最短
                A[i][j]=A[i][k]+A[k][j];    // 更新最短路径长度
                path[i][j]=k;               // 中转点
            }
        }
    }
}



// 拓扑排序代码
bool TopologicalSort(Graph G){
    InitStack(S);                       // 初始化栈,存储入度为0的顶点
    for(int i=0;i<G.vexnum;i++)
        if(indegree[i]==0)
            Push(S,i);                  // 将所有入度为0的顶点进栈
    int count = 0;                      // 计数,记录当前已经输出的顶点数
    while(!isEmpty(S)){             // 栈不空,则存入度为0的顶点
        Pop(S,i);                   // 栈顶元素出栈
        print[count++]=i;           // 输出栈顶i
        for(p=G.vertices[i].fristarc;p;p=p->nextarc){
            // 将所有i指向的顶点的入度减1,并且将入度减为0的栈顶压入栈
            v=p->adjvex;
            if(!(--indegree[v]))
                Push(S,v);          // 入度为0,则入栈
        }
    }//while
    if(count<G.vexnum)
        return false;               // 排序失败,有向图中有贿赂
    else
        return true;                // 拓扑排序成功

}



// 逆拓扑排序的实现(DFS算法)
void DFTraverse(Graph G){           // 对图G进行深度优先遍历
    for(v=0;v<G.vexnum;++v)
        visited[v]=FALSE;           // 初始化已访问标记数据
    for(v=0;v<G.vexnum;++v)         // 本代码中v=0开始遍历
        if(!visited[v])
            DFS(G,v);               
}

void DFS(Graph G, int v){           // 从顶点v除法,深度优先遍历图G
    visited[v]=TRUE;                // 设已访问标记
    for(w=FirstNeighbor(G,v);w>=0;w=NextNeighbot(G,v,w))
        if(!visited[w]){            // w为u的尚未访问的邻接顶点
            DFS(G,W);
        }
        print(v);                   // 输出顶点
}

// 2020-6-2 20:59:14 终于弄完了 累死了