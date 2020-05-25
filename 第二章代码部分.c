//按位序插入(不带头结点)
#include <iostream>
typedef struct LNode{	// 定义单链表节点类型
	ElemType data;		// 每个节点存放一个数据元素
	struct LNode *next;	// 指针指向下一个节点
}LNode, *LinkList;		// 通过typedef函数,定义的链表和结点别名

//直接写 前插操作逻辑

//前插操作: 在p结点之前插入元素e
bool InsertPrioNode (LNode *p, ElemType e){
	if (p==NULL)
		return false;
	LNode *s = (LNode *)malloc(sizeof(LNode));
	if(s==NULL) 		//内存分配失败
		return false;
	s->next = p->next;
	p->next = s;		//新结点s链接到p之后
	s->data = p->data;	//将p中元素复制到s中
	p->data = e;		// p中元素覆盖为e
	return true;		
}

//王道书里面的,直接给穿了  LNode *s
bool InserPriorNode(LNode*p, LNode *s){
	if(p==NULL || s==NULL)
		return false;
    s->next = p->next;
    p->next = s;         // s练到p之后
    ElemType temp = p->next;    //交换数据域部分
    p->data = s->data;
    s-data = temp;
    return true;
    

}

//############################################

//按位序删除(带头结点)
#include <iostream>
typedef struct LNode{	// 定义单链表节点类型
	ElemType data;		// 每个节点存放一个数据元素
	struct LNode *next;	// 指针指向下一个节点
}LNode, *LinkList;		// 通过typedef函数,定义的链表和结点别名

bool ListDelete(LinkList &L, int i , ElemType &e){
	if (i<1)
		return false;
	LNode *p;			// 指针p指向当前扫描到的结点
	int j = 0;			// 当前p指向的第几个结点
	p = L;				// L指向头结点,头结点是0个结点(不存数据)
	while (p!NULL && j<i-1) {	// 循环找到第i-1个结点
		p = p->next;
		j++;
	}
	if(p == NULL)		// i值不合法
		return false;
	if(p->next == NULL)	//第i-1个结点之后已无其他结点
		return false;
	
	LNode *q = p->next;	//令q指向被删除结点
	e = q->data;		// 用e返回元素的值
	p->next = q->next;	//将*q结点从链中"断开"
	free(q);			// 释放结点的存储空间
	return true;		// 删除成功

}


//###########################################

//指定结点的删除

bool DeleteNode(LNode *p){
	if (p== NUll)
		return false;
	LNode *q = p->next;			// 令q指向*p的后继结点
	p->data = p->next->data;	// 和后继结点交换数据域
	p->next = q->next;			// 将*q结点从链中"断开"
	free(q);					// 释放后继结点的存储空间
	return true;
}

2020-5-9 21:08:35 明天继续

2020-5-10 10:39:37
//#####################################################

//按位查找,返回第i个元素(带头结点)
LNode*GetElem(LinkList L, int i ){
	if(i<0)
		return NULL;			//输入的值不合法
	LNode *p;					//指针p当前扫描到的结点
	int j = 0;					//当前p指向的第几个结点
	p = L;						//L指向头结点,头结点是第0个结点(不存数据)
	while(p!=NULL && j<i){		//循环找到第i个结点
		p = p->next;
		j++;
	}
	return p;
}

//王道书版:按位查找,返回第i个元素(带头结点)

LNode*GetElem(LinkList L, int i ){
	int j = 1;
	LNode *p = L->next;
	if(i==0)
		return L;				//返回头结点
	if(i<1)
		return NULL;
	while(p!=NULL && j<i){
		p = p->next;
		j++;
	}	
	return p;
}

//###########################################

// 按值查找,找到数据域 ==e 的结点
LNode *LocateElem(LinkList L, ElemType e){
	LNode *p = L->next;
	//从第1个结点开始查找数据域为e的结点
	while (p != NULL && p->data != e)
		p = p->next;
	return p ;					// 找到后返回该结点指针,否则返回NULL
}


//###########################################

//求表的长度

int Length(LinkList){
	int len = 0;				// 统计表长
	LNode *p = L;
	while (p->next != null){
		p = o->next;
		len++;
	}
	return len;

}

//###########################################

//双链表的初始化(带头结点)

//初始化双链表
typedef struct DNode{
	ElemType  data;
	struct DNode *prior, *next;
}DNode, *DLinklist;


bool InitDLinkList(DLinkList &L){
	L = (DNode *)malloc(sizeof(DNode));		//分配一个头结点
	if(L==NULL)								// 内存不足,分配失败
		return false;						
	L->prior = NULL;						// 头结点的prior永远指向NULL
	L->next = NULL;							// 头结点之后暂时还没有结点
	return true;		
}
 
// 判断双链表是否为空(带头结点)
bool Empty(DLinklist L){
	if(L->next == NULL)
		return true;
	else
		return false;
}

viod testDLinkList(){
	//初始化双联链表
	DLinkList L;
	InitDLinkList(L);
	// 后续代码
}

//###########################################

// 双链表的后插入操作(按位序插入(就是找到该i-1结点,进行后插),前插操作(找到该结点的前一个结点,进行后插)都是在后插基础上)

// 在p结点之后插入s结点
boo InsertNextDNode(DNode *p, DNode *s){
	if(p==NULL || s==NULL)	//	非法参数
		return false;
	s->next = p ->next;
	if (p->next != NULL)		//如果p结点有后继结点
		p->next->prior = s;
	s->prior = p;
	p->next = s;
	return true;
}

//###########################################

//双链表的删除
// 删除p结点的后继结点
bool DeleteNextDNode(DNode *p){
	if (P==NULL)	
		return false;
	DNode *p = p->next;			//找到p的后继结点q
	if (q->next!=NULL)
		return false;			// p没有后继
	p->next =q->next;	
	if (q->next!=NULL)			//q结点不是最后一个结点
		q->next->prior = p;		
	free(q);					// 释放结点空间
	return true;	
}

//销毁一个双链表
void DestoryList(DLinklist &L){
	//循环释放各个数据结点
	while(L->next!=NULL)
		DeleteNextDNode(L);
	free(L);					//释放头结点
	L = NULL;					//头指针指向NULL
}

//###########################################

//双链表的遍历
//后向遍历
while(p!=NULL){
	//对结点p做相应处理,如打印
	p=p->next;
} 

//向前遍历
while(p!=NULL){
	//对结点p做相应处理,如打印
	p=p->prior;
} 

//向前遍历(跳过头结点)
while(p->prior!=NULL){
	//对结点p做相应处理,如打印
	p=p->prior;
} 

//###########################################

//循环单链表
typedef struct DNode{
	ElemType  data;
	struct DNode *prior, *next;
}DNode, *DLinklist;

//初始化一个循环单链表
bool InitDLinkList(DLinkList &L){
	L = (DNode *)malloc(sizeof(DNode));		//分配一个头结点
	if(L==NULL)								// 内存不足,分配失败
		return false;						
	L->next = L;							// 头结点next指向头结点
	return true;		
}
// 判断循环单链表是否为空
bool Empty(DLinklist L){
	if(L->next == L)
		return true;
	else
		return false;
}
//判断结点p是否为循环单链表的表未结点
bool isTail(LinkList L, LNode *p){
	if (p->next==L)
		return true;
	else
		return false;
}

viod testDLinkList(){
	//初始化双联链表
	DLinkList L;
	InitDLinkList(L);
	// 后续代码
}


//###########################################

//循环单双链表
typedef struct DNode{
	ElemType  data;
	struct DNode *prior, *next;
}DNode, *DLinklist;

//初始化空的循环双链表
bool InitDLinkList(DLinkList &L){
	L = (DNode *)malloc(sizeof(DNode));		//分配一个头结点
	if(L==NULL)								// 内存不足,分配失败
		return false;						
	L->prior = L;							// 头结点prior指向头结点
	L->next = L;							// 头结点的next指向头结点
	return true;		
}
// 判断循环双链表是否为空
bool Empty(DLinklist L){
	if(L->next == L)
		return true;
	else
		return false;
}
//判断结点p是否为循环双链表的表尾结点
bool isTail(LinkList L, LNode *p){
	if (p->next==L)
		return true;
	else
		return false;
}

viod testDLinkList(){
	//初始化双联链表
	DLinkList L;
	InitDLinkList(L);
	// 后续代码
}

//###########################################
// 双链表的插入
//在p结点之后插入s结点
bool InserNextDNode(DNode *p, DNode *s){
	s->next = p->next;				//将结点*s插入到结点*p之后
	p->next->prior = s;
	s->prior = p;
	p->next = s;
}

//###########################################
// 删除p的后继结点q
p->next = q->next;
q->next->prior = p;
free(q);



//###########################################
// 用代码定义一个静态链表(王道版)
# define MaxSize 10					//静态链表的最大长度
typedef struct{						//静态链表结构类型的定义
	ElemType data;					//存储数据元素
	int next;						//下一个元素的数组下标
}SLinkList[MaxSize];	

void  testSLinkList(){
	SLinkList a;					// a是一个静态链表
	// ....后续代码
}

//等价于如下↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓
//定义一个静态链表
# define MaxSize 10					//静态链表的最大长度
struct Node{						//静态链表结构类型的定义
	ElemType data;					//存储数据元素
	int next;						//下一个元素的数组下标
};
// 可用SLinkList定义 "一个长度为MaxSize的Node型数组"
typedef  struct Node SLinkList[MaxSize];		//主要是强调我是一个表,不是数组

void  testSLinkList(){
	struct Node a[MaxSize];			// a是一个Node型数组
	// ....后续代码
}

2020-5-10 19:14:43 先写于此,其他的明天继续





