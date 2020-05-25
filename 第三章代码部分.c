#include <iostream>
//2020-5-12 16:17:01

//定义一个栈,初始化操作

#define MaxSize 10;                 //定义栈中元素的最大个数
typedef struct{
    ElemType data[MaxSize];         // 静态数组存放栈中元素
    int top;                        // 栈顶指针
} SqStack;

//初始化栈
viod InitStack(SqStack &S){
    S.top = -1 ;                    //初始化栈顶指针
} 

//判断栈空
bool StackEmpty(SqStack S){
    if(S.top=1);                    // 栈空
        return  true;               
    else
        return false;               // 不空
}

void testStack(){
    SqStack S;                      //声明一个顺序栈(分配空间)
    InitStack(S);                  
    //后续操作  增删改查
}

//###########################################################

//进栈操作

#define MaxSize 10;                 //定义栈中元素的最大个数
typedef struct{
    ElemType data[MaxSize];         // 静态数组存放栈中元素
    int top;                        // 栈顶指针
} SqStack;


//新元素入栈
bool Push(SqStack &&S, ElemType x){
    if(S.top==MaxSize-1)            // 栈满,报错
        return false
    S.top = S.top+1                 // 指针先加1
    S.data[S.top] = x;              // 新元素入栈
    //上面两行代码等价于    S.data[++S.top] = x;     ++在前,则是先加,后用
    return  true;
}

//###########################################################

// 出栈和读取栈顶元素操作
#define MaxSize 10;                 //定义栈中元素的最大个数
typedef struct{
    ElemType data[MaxSize];         // 静态数组存放栈中元素
    int top;                        // 栈顶指针
} SqStack;

// 出栈
bool Pop(SqStack &S, ElemType &x){
    if(S.top=-1)                   // 栈空,报错
        return false;                
    x = S.data[S.top];              //栈顶元素先出栈
    S.top = S.top -1;               //指针再减1
    //上面两行代码等价于 x = S.data[S.top--];       //先用 后减
    return true;
}

//读取栈顶元素
bool GetTop(SqStack S, ElemType &x){
    if(S.top==1)                    // 栈空,报错
        return false;
    x = S.data[S.top];              // x记录栈顶元素
    return true;                                          
}

//###########################################################

// 共享栈
#define MaxSize 10;                 //定义栈中元素的最大个数
typedef struct{
    ElemType data[MaxSize];         // 静态数组存放栈中元素
    int top0;                       // 0号栈栈顶指针
    int top1;                       // 1号栈栈顶指针
} SqStack;

// 初始化栈
void InitStack(ShStack &S){
    S.top0 = -1;                    // 初始化栈顶指针
    S.top1 = MaxSize ;
}

// 栈满的条件   top0 + 1 == top1


//###########################################################

//顺序队列

#define MaxSize 10                  //定义队列中元素的最大个数
typedef struct{
    ElemType data[MaxSize];         //用静态数组存放队列元素
    int front , rear;               // 队头指针和对尾指针
}SqQueue;

//初始化队列
void InitQueue(SqQueue &Q){
    //初始时 队列,对尾指针指向0
    Q.rear = Q.front = 0;
}

// 判断队列是否为空
bool QueueEmpty(SqQueue Q){
    if(Q.rear==Q.front)             // 队空条件
        return true;
    else
        return false;
}


void testQueue(){
    // 声明一个队列(顺序存储)
    SqQueue Q;
    InitQueue(Q);
    // 后续操作........
}

//###########################################################

//循环队列------- 入队操作
#define MaxSize 10                  //定义队列中元素的最大个数
typedef struct{
    ElemType data[MaxSize];         //用静态数组存放队列元素
    int front , rear;               // 队头指针和对尾指针
}SqQueue;

//判断队列是否为空
bool QueueEmpty(SqQueue Q){
    if(Q.rear==Q.front)             //队空条件
        return true;
    else
        return false;
}

//入队
bool EnQueue(SqQueue &Q, ElemType x){
    if((Q.rear+1)%MaxSize==Q.front)
        return false;               //队满则报错
    Q.data[Q.rear] = x;             // 新元素插入队尾
    Q.rear = (Q.rear+1)%MaxSize;    //队尾指针加1取模(就是取余操作)
    // 用模运算将存储空间在逻辑上变成了"环状"
    return true;
}

//###########################################################
// 循环队列---出队

// 出队(删除一个队头元素,并用x返回)
bool DeQueue(SqQueue &Q, ElemType &x){
    if(Q.rear==Q.front)
        return false;               // 队空则报错
    x = Q.data[Q.front];            
    Q.front = (Q.front+1)%MaxSize;  // 队头指针后移
    return true;
}

// 获得队头元素的值,用x返回
bool GetHead(SqQueue Q, ElemType &x){
    if(Q.rear == Q.front)
        return false;               // 队空则报错
    x = Q.data[Q.front];            
    return true;
}

//记住如下内容
# 队列元素个数
(rear+MaxSize-front)%MaxSize

# 以下内容都是: 指向队尾元素的后一个位置(下一个应该是插入位置)
//方案一 : 判断队列已满/已空(浪费空间,其他的2,3方案都不浪费)
#define MaxSize 10                  //定义队列中元素的最大个数
typedef struct{
    ElemType data[MaxSize];         //用静态数组存放队列元素
    int front , rear;               // 队头指针和对尾指针
    // 初始化时 front  rear 都是为0
}SqQueue;

# 队列已满的条件: 队尾指针的再下一个位置是队头
(Q.rear+1)%MaxSize == Q.front

# 队空条件
Q.rear == Q.front

//方案二 : 判断队列已满/已空
#define MaxSize 10                  //定义队列中元素的最大个数
typedef struct{
    ElemType data[MaxSize];         //用静态数组存放队列元素
    int front , rear;               // 队头指针和对尾指针
    int size;                       // 队列当前长度
    // 初始化时 front  rear size 都是为0
}SqQueue;

# 插入成功      size++
# 删除成功      size--

# 队满条件      size==MaxSize
#队空条件       size==0


//方案三  : 判断队列已满/已空
#define MaxSize 10                  //定义队列中元素的最大个数
typedef struct{
    ElemType data[MaxSize];         //用静态数组存放队列元素
    int front , rear;               // 队头指针和对尾指针
    int tag;                       // 最近进行的是删除/插入
    // 初始化时 front=rear=0  tag=0
}SqQueue;

#每次删除操作成功时,都令tag=0;
#每次插入操作成功时,都令tag=1;
//只有删除操作,才可能导致队空
# 队空条件      front==rear && tag==0
//只有插入操作,才可能导致队满
# 队满条件      front==rear && tag==1
 

//###########################################################
//其他出题方法

# 以下都是指向队尾元素(已截图,详情看截图3.5)
2020-5-12 21:43:53(明天继续)

2020-5-13 09:41:13(继续干起来)
//队列的连式存储

//初始化(带头结点)
typedef struct LinkNode{
    ElemType data;
    struct LinkNode *next;
}LinkNode;

typedef struct{
    LinkNode *front, *rear;
}LinkQueue;

//初始化(带头结点)
void InitQueue(LinkQueue &Q){
    //初始时 front, rear都指向头结点
    Q.front = Q.rear=(LinkNode*)malloc(sizeof(LinkNode));
    Q.front->next=NULL;
}

//判断队列是否为空
bool IsEmpty(LinkQueue Q){
    if(Q.front=Q.rear)
        return true;
    else
        return false;
}

void testLinkQueue(){
    LinkQueue Q;                    //声明一个队列
    InitQueue(Q);                   // 初始化队列
    //...后续操作.........
}

//################################################
//初始化(不带头结点)

//初始化队列(不带头结点)
void InitQueue(LinkQueue &Q){
    // 初始化 front, rear 都指向NULL
    Q.front = NULL;
    Q.rear = NULL;
}

//判断队列是否为空(不带头结点)
bool IsEmpty(LinkQueue Q){
    if(Q.front==NULL)
        return true;
    else
        return false;
}

//################################################

// 入队(带头结点)
// 新元素入队(带头结点)
void EnQueue(LinkQueue &Q, ElemType x){
    LinkQueue *s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = null;
    Q.rear->next = s;               //新结点插入到rear之后
    Q.rear = s;                     //修改表尾指针
}

// 入队(不带头结点)

//新元素入队(不带头结点)
void EnQueue(LinkQueue &Q, ElemType x){
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data = x;
    s-next = NULL;
    // 不带头结点的队列,第一个元素入队是哦户需要特别处理 
    if(Q.front == NULL){            // 在空队列中插入第一个元素
        Q.front = s;                // 修改队头队尾指针
        Q.rear = s;
    }else{
        Q.rear->next = s;           //新结点插入到rear结点之后
        Q.rear =s;                  // 修改rear指针
    }
}

//################################################
//出队(带头结点)
//队头元素出队(不带头结点)
bool DeQueue(LinkQueue &Q, ElemType &x){
    if(Q.front==Q.rear)
        return false;               // 空队
    LinkNode *p = Q.front->next;
    x = p->data;                    // 用变量x返回队头元素
    Q.front->next = p->next;        // 修改头结点的next指针
    if(Q.rear==p)                   // 此次是最后一个结点出队
        Q.rear = Q.front;           // 修改rear指针
    free(p);                        // 释放结点空间
    return true;        
}

// 出队(不带头结点)
// 队头元素出队(不带头结点)
bool DeQueue(LinkQueue &Q, ElemType &x){
    if(Q.fron==NULL)
        return false;               // 空队
    LinkNode *p = Q.front;          // p指向此次出队的结点
    x = p->data;                    // 用变量x返回队列元素
    Q.front = p->next;              // 修改front 指针
    if(Q.rear==p){                  //  此次是最后一个结点出队
        Q.front =NULL;              // front 指向 NULL
        Q.rear = NULL;              // rear 指向NULL
    }
    free(P);                        // 释放结点空间
    return  true;           
}
// 链式存储一半不会满,除非内存不足!

//################################################
//栈的应用-----匹配括号算法

// 定义一个栈(可采用链栈,但是考试通常数组即可)
# define MaxSize(10)                // 定义栈中元素的最大个数
typedef struct{
    char data[MaxSize];             // 静态数组存放栈中的元素
    int top;                        // 栈顶指针
}SqStack;

// 考试中可直接使用基本操作,建议简要说明接口

//初始化栈
void InitStack(SqStack &S)

//判断栈是否为空
bool StackEmpty(SqStack S)

// 新元素入栈
bool Push(SqStack &S, char x)

//栈顶元素出栈,用x返回
bool Pop|(SqStack &S, char &x)


bool bracketCheck(char str[], int length){
    SqStack S;
    InitStack(S);                   // 初始化一个栈
    for (int i = 0; i<length; i++){
        if (str[i]=='(' || str[i]=='['||str[i]'{'){
            Push(S, str[i]);        // 扫描到左括号,入栈
        }else{
            if(StackEmpty(S))       // 扫描到右括号,且当前栈空
                return false;       // 匹配失败

            char topElem;
            Pop(S, topElem);        // 栈顶元素出栈
            if(str[i]==')' && topElem !='(')
                return  false;
            if(str[i]==']' && topElem !='[')
                return  false;    
            if(str[i]=='}' && topElem !='{')
                return  false;
        }
    }
    return StackEmpty(S);           // 检索全部括号后,栈空说明匹配成功
}

//################################################

// 一维数组的存储结构
ElemType a[10];                     // 定义一个一维数组

// 定义一个二维数组结构
ElemType b[2] [4];                  // 2行4列的二维数组  


2020-5-13 18:34:52 明天继续


















