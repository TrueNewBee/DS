//2020-5-24 17:56:29

// 二叉树的顺序存储

#define MaxSize 100;
struct TreeNode{
    ElemType  value;                 // 结点中的数据元素
    bool  isEmpty;                   // 结点是否为空 
}

// 定义一个长度为MaxSize的数组t,按照从上至下,从左至有的顺序储存完全二叉树中的结点
TreeNode t[MaxSize];              


// 二叉树的链式存储
struct ElempType{
    int value;
};

typedef struct BiTNode{
    ElempType data;
    struct BiTNode  *lchild, *rchild;
}BiTNode, *BiTree;

// 定义一棵书
BiTree root = NULL;

// 插入根节点
root = (BiTree)malloc(sizeof(BiTNode));
root->data = {1};
root=>lchild = NULL;
root->rchild = NULL;

// 插入新结点
BiTNode *p = (BiTNode *)malloc(sizeof(BiTNode));
p->data = {2};
p->lchild = NULL;
p->rchild = NULL;
root->lchild = p;                   // 作为根节点的左孩子



// 二叉树的链式存储

// 二叉树的结点(链式存储)
typedef struct BiTnode{                 // 数据域
    struct  BiTNode *lchild, *rchild;   // 左, 右孩子指针
    struct  BiTNode *parent;            // 父结点指针
}BiTNode, *BiTree;

// Q: 如何找到指定结点p的父节点
// A: 只能从根开始遍历寻找


// 先序遍历
/**
 * 操作过程如下
 * 1. 若二叉树为空,则什么也不做
 * 2. 若二叉树费控:
 *  2.1 访问根节点
 *  2.2 先序遍历左子树
 *  2.3 先序遍历右子树
 **/ 
// ps : 由于是递归调用,故时间复杂度为(O(h))
typedef struct BiTNode{
    ElempType data;
    struct BiTNode  *lchild, *rchild;
}BiTNode, *BiTree;

// 先序遍历
void PreOrder(BiTree T){
    if(T!=NULL){
        visit(T);                           // 访问根节点
        PerOreder(T->lchild);               // 递归遍历左子树
        PerOreder(T->rchild);               // 递归遍历右子树
    }
}

// 中序遍历
/**
 * 操作过程如下
 * 1. 若二叉树为空,则什么也不做
 * 2. 若二叉树费控:
 *  2.1 先序遍历左子树
 *  2.2 访问根节点
 *  2.3 先序遍历右子树
 **/ 
typedef struct BiTNode{
    ElempType data;
    struct BiTNode  *lchild, *rchild;
}BiTNode, *BiTree;

// 中序遍历
void PreOrder(BiTree T){
    if(T!=NULL){
        PerOreder(T->lchild);               // 递归遍历左子树    
        visit(T);                           // 访问根节点
        PerOreder(T->rchild);               // 递归遍历右子树
    }
}

// 后续遍历 (同上)


// 求树的深度(应用)

int treeDepth(BiTree T){
    if (T == NULL){
        return 0;
    }else{
        int l = treeDepth(T->lchild);
        int l = treeDepth(T->rchild);
        // 树的深度= Max(左子树深度,右子树深度)+1
        return l> r ? l+1: r+1;
    }
}


// 二叉树的层寻遍历代码实现

/**
 * 算法思想:
 * 1. 初始化一个辅助队列
 * 2. 根节点入队
 * 3. 若队列非空, 则队头节点出队,访问改节点,并将其左右孩子入队尾(如果有的话)
 * 4. 重复3知道队列为空
 * */

//二叉树的结点(链式存储)
typedef struct BiTNode{
    char data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

// 链式队列结点
typedef struct LinkNode{
    // 存放指针而不是结点
    BiTNode *data;
    struct LinkNode *next;
}LinkNode;

typedef struct{
    LinkNode *front, *rear;             // 队头队尾
}LinkQueue;



// 层序遍历
void LevelOrder(BiTree T){
    LinkQueue Q;
    InitQueue(Q);                       // 初始化辅助队列
    BiTree(Q,T);                                      
    EnQueue(Q, T);                      // 将跟结点入队
    while(!IsEmpty(Q)){                 // 队列不空则循环
        DeQueue(Q, p);                  // 队列头结点出队
        visit(p);                       // 访问出队结点
        if(p->lchild != NULL)
            EnQueue(Q, p->lchild);      // 左孩子入队
        if(p->rchild!= NULL)
            EnQueue(Q,p->rchild);       // 右孩子入队
    }
}


// 中序遍历
/**
 * 思如:
 * 从根节点出发,重新进行一次中序遍历,
 * 指针q记录当前访问的结点
 * 指针pre记录上一个被访问的结点
 * 1.当q==p时,pre为前驱
 * 2. 当pre==q时,q为后驱
 * */

//中序遍历
void InOrder(BiTree T){
    if (T!=NULL){
        InOrder(T->lchild);                 // 递归遍历左子树
        visit(T);                           // 访问跟结点
        InOrder(T->rchild);                 // 访问右结点
    }
    
}



// 线索二叉树的存储结构

// *lchild  data  *rchild     术语: 二叉链表
// *lchild  ltag data  rtag *rchild   术语: 线索链表
// tag==0  表示指针指向孩子
// tag==1  表示指针执向线索

//二叉树的结点(链式存储)
typedef struct BiTNode{
    ElempType data;
    struct BiTNode  *lchild,*rchild;
}BiTNode, *BiTree;

// 线索二叉树结点
typedef struct ThreadNode{
    ElempType data;
    struct ThreadNode  *lchild,*rchild;
    int ltag,rtag;                          // 左,右线索标志
}ThreadNode,*ThreadTree;



// 用土办法找到中序前驱
// 中序遍历
void InOrder(BiTree T){
    if(T!=NULL){
        InOrder(T->lchild);                 // 递归遍历左子树
        visit(T);                           // 访问根结点
        InOrder(T->lchild);                 // 递归遍历左子树
    }
}

// 访问结点q
void visit(BinTNode *q){
    if(q==p)                                // 当前访问结点刚好是结点p
        final = pre;                        // 找到p的前驱
    else
         pre =q;                            // pre指向当前访问的结点
}
//辅助全局变量,用于查找结点p的前驱
BinTNode *p;                                // p指向目标结点
BinTNode *pre=NULL;                         // 指向当前访问结点的前驱
BinTNode *final=NULL;                       // 用于记录最终结果




// 中序线索化
// 全局变量pre, 执行那个当前访问结点的前驱
ThreadNode *pre = NULL;

// 中序线索化二叉树T
void CreateInThread(ThreadTree T){
    pre=NULL;                               // pre初始化NULL
    if (T!=NULL){                           // 非空二叉树才能线索化
        InThread(T);                        // 中序线索化二叉树
        if(pre->rchild==NULL)
            pre->rtag=1;                    // 处理遍历的最后一个结点
    }
    
}

// 线索二叉树结点
typedef struct ThreadNode{
    ElempType data;
    struct ThreadNode  *lchild,*rchild;
    int ltag,rtag;                          // 左,右线索标志
}ThreadNode,*ThreadTree;

// 中序遍历二叉树,一遍遍历一遍线索化
void InOrder(BiTree T){
    if(T!=NULL){
        InOrder(T->lchild);                 // 中序遍历左子树
        visit(T);                           // 访问根结点
        InOrder(T->lchild);                 // 中序遍历左子树
    }
}

void visit(ThreadNode *q){
    if(q->lchild==NULL){                    // 左子树为空,建立前驱线索
        q->lchild=pre;
        q->ltag=1;
    }
    if (pre!=NULL&&pre->rchild==NULL){
        pre->rchild=q;                      // 建立前驱结点的后继线索
        pre->rtag=1;
    }
    pre=q;
}




//先序线索化
// 全局变量pre,指向当前访问结点的前驱
ThreadNode *pre = NULL;

// 先序线索化二叉树T
void CreatePreThread(ThreadTree T){
    pre=NULL;                               // pre初始化NULL
    if (T!=NULL){                           // 非空二叉树才能线索化
        PreThread(T);                        // 先序线索化二叉树
        if(pre->rchild==NULL)
            pre->rtag=1;                    // 处理遍历的最后一个结点
    }
}

// 线索二叉树结点
typedef struct ThreadNode{
    ElempType data;
    struct ThreadNode  *lchild,*rchild;
    int ltag,rtag;                          // 左,右线索标志
}ThreadNode,*ThreadTree;

// 先序遍历二叉树,一遍遍历一遍线索化
void InOrder(BiTree T){
    if(T!=NULL){
        visit(T);                           // 访问根结点        
        if(T->ltag==0)                      // lchild不是前驱结点
            PreThread(T->lchild);
        PreThread(T->rchild);
    }
}

void visit(ThreadNode *q){
    if(q->lchild==NULL){                    // 左子树为空,建立前驱线索
        q->lchild=pre;
        q->ltag=1;
    }
    if (pre!=NULL&&pre->rchild==NULL){
        pre->rchild=q;                      // 建立前驱结点的后继线索
        pre->rtag=1;
    }
    pre=q;
}



//后序线索化
// 全局变量pre,指向当前访问结点的前驱
ThreadNode *pre = NULL;

// 后序线索化二叉树T
void CreatePostThread(ThreadTree T){
    pre=NULL;                               // pre初始化NULL
    if (T!=NULL){                           // 非空二叉树才能线索化
        InThread(T);                        // 中序线索化二叉树
        if(pre->rchild==NULL)
            pre->rtag=1;                    // 处理遍历的最后一个结点
    }
}

// 线索二叉树结点
typedef struct ThreadNode{
    ElempType data;
    struct ThreadNode  *lchild,*rchild;
    int ltag,rtag;                          // 左,右线索标志
}ThreadNode,*ThreadTree;

// 先序遍历二叉树,一遍遍历一遍线索化
void PostThread(BiTree T){
    if(T!=NULL){
        PostThread(T->lchild);              // 后序遍历左子树
        PostThread(T->rchild);              // 后序遍历右子树
        visit(T);                           // 访问根结点        
    }
}

void visit(ThreadNode *q){
    if(q->lchild==NULL){                    // 左子树为空,建立前驱线索
        q->lchild=pre;
        q->ltag=1;
    }
    if (pre!=NULL&&pre->rchild==NULL){
        pre->rchild=q;                      // 建立前驱结点的后继线索
        pre->rtag=1;
    }
    pre=q;
}




// 中序线索二叉树找中序后继
// 找到以p为根的子树种,第一个被中序遍历的结点
ThreadNode *Firstnode(ThreadNode *p){
    //循环找到最左下结点(不一定是叶结点)
    while(p->ltag==0) p==p->lchild;
    return p;
}

// 在中序线索二叉树中找到结点p的后继结点
ThreadNode *Nextnode(ThreadNode *p){
    // 又子树中最左下结点
    if(p->rtag==0) return Firstnode(p->rchild);
    else return p->rchild;              // rtag==1 直接返回后继线索
}

// 对中序线索二叉树进行中序遍历(利用线索实现的非递归算法) 空间复杂度为O(1)
void Inorder(ThreadTree *T){
    for(ThreadNode *p=Firstnode(T);p!=null;p=Nextnode(p))
        visit(p);
}

// 在中序线索二叉树中找到指定结点*p的中序后继next
// 1.若p->rtag=1 , 则next=p->rchild
// 2.若p->rtag==0       p必有右孩子



// 中序线索二叉树找中序前驱
//找到以p为根的子树中,最后一个被中序遍历的结点
ThreadNode *Lastnode(ThreadNode *p){
    //循环找到最右下结点(不一定是叶结点)
    while(p->rtag==0) p==p->rchild;
    return p;
}

// 在中序线索二叉树中找到结点p的前驱结点
ThreadNode *Prenode(ThreadNode *p){
    // 又子树中最左下结点
    if(p->ltag==0) return Lastnode(p->lchild);
    else return p->lchild;              // rtag==1 直接返回后继线索
}

// 对中序线索二叉树进行逆向遍历(利用线索实现的非递归算法) 空间复杂度为O(1)
void RevInorder(ThreadTree *T){
    for(ThreadNode *p=Lastnode(T);p!=null;p=Prenode(p))
        visit(p);
}

// 在中序线索二叉树中找到指定结点*p的中序前驱pre
// 1.若p->ltag==1, 则pre=p->lchild
// 2.若p->ltag==0    p必有左孩子


// 2020-5-24 23:33:13  撸完代码 睡觉去 记得推到git上面和博客上面

//2020-5-25 15:17:54
// 树的双亲表示法(顺序存储)
// 双亲表示法:每个节点中保存指向双亲的 '指针'

#define MAX_TREE_SIZE 100           // 树种最多结点数
typedef struct{                     // 树的结点定义
    ElempType data;                 // 数据元素
    int parent;                     // 双亲位置域
}PTNode;

typedef struct{                     // 树的类型定义
    PTNode nodes[MAX_TREE_SIZE];    // 双亲表示
    int n;                          // 结点数
}PTree;



// 孩子表示法(顺序+链式存储)
struct CTNode{
    int child;                      // 孩子结点在数组中的位置
    struct CTNode *next;            // 下一个孩子
};

typedef struct{
    ElempType data;
    struct CTNode *firstChild;      // 第一个孩子
} CTBox;

typedef struct{
    CTBox nodes[MAX_TREE_SIZE];
    int n, r;                       // 结点数和根的位置
}CTree;



// 孩子兄弟表示法(链式存储) 推荐: 孩左,兄右(树转二叉树)
// 树的存储---孩子兄弟表示法
typedef struct CSNode{
    ElempType data;                 // 数据域
    struct CSNod                    // 第一个孩子和右兄弟指针
    *firstchild, // 看作左指针
    *nextsibling;// 看作右指针
}CSNode, *CSTree;


// 树的先根遍历
// 先根遍历:若树非空,先访问根节点,再一次对每棵子树进行先根遍历
// 树的先根遍历序列与这颗树相应二叉树的先序序列相同

// 树的先根遍历  伪代码
void PreOrder(TreeNode *R){
    if(R!=NULL){
        visit(R);                   // 访问根节点
        while(R还有下一个子树T)
            PreOrder(T);            // 先根遍历下一课子树
    }
}


// 树的先根遍历
// 先根遍历:若树非空,先访问根节点,再一次对每棵子树进行后根遍历
// 树的后根遍历序列与这颗树相应二叉树的中序序列相同
// 树的后根遍历  伪代码
void PreOrder(TreeNode *R){
    if(R!=NULL){
        while(R还有下一个子树T)
            PreOrder(T);            // 先根遍历下一课子树
                visit(R);                   // 访问根节点
    }
}



//二叉排序树的查找
// 左子树结点值<根节点值<右子树结点值

/**过程:
 * 若树非空,目标值与根节点的值比较:
 * 若相等,则查找成功;
 * 若小于根节点,则在左子树上查找,否则在右子树上查找
 * 查找成功,返回结点指针;查找失败返回NULL;
 * */

//二叉排序树结点
typedef struct BSTNode{
    int key;
    struct BSTNode *lchild, *rchild;
}BSTNode,*BSTree;

// 在二叉排序树种查找值为key的结点(while循环)最坏空间复杂度O(1)
BSTNode *BSTSearch(BSTree T, int key){
    while(T!=NULL&& key!=T->key){       // 若树空或等于根节点值,则结束循环
        if(key<T->key) T=T->lchild;     // 小于,则在左子树上查询
        else T=T->rchild;               // 大鱼,则在右子树上查询
    }
    return T;
}

// 在二叉排序树种查找值为key的结点(递归实现)最坏空间复杂度O(h)
BSTNode *BSTSearch(BSTree T, int key){
    if(T==NULL)
        return NULL;                    // 查询失败
    if (key==T->key)
        return T;                       // 查询成功
    else if(key<T->key)
        return BSTSearch(T->lchild, key);   // 在左子树中找
    else
        return BSTSearch(T->rchild, key);   // 在右子树中找
}



// 二叉排序树的插入
// 在二叉排序树插入关键字为k的新结点(递归实现)  最坏空间复杂度O(h)
int BST_Insert(BSTree &T, int k){
    if(T==NULL){                            // 原树为空,新插入的结点为根节点
        T=(BSTree)malloc(sizeof(BSTNode));
        T->key=k;
        T->lchild=T->rchild=NULL;
        return 1;                           // 返回1,插入成功
    }
    else if(k==T->key)                      // 书中存在相同关键字结点,插入失败
        return 0;
    else if(k<T->key)                       // 查到T的左子树
        return BST_Insert(T->lchild, k);
    else                                    // 查到T的右子树
        return BST_Insert(T->rchild, k);
}
//2020-5-25 16:48:51









