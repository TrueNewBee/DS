// 是在看英语难受,,看数据结构

//已经截图 明天再写

// 62020-5-20 22:56:15
// 明天早上5点半起来撸代码
// 已经看完第四章  撸代码

// 串的顺序存储

#define MAXLEN 255              // 预定义最大串长为255
typedef struct{
    // 静态数组实现(定长顺序存储)
    char ch[MAXLEN];            // 每个分量存储一个字符
    int length;                 // 串的实际长度
}SString;


typedef struct{
    // 静态数组实现(堆分配存储)
    char *ch;                   // 按串长分配存储区, ch指向穿的基地址
    int   length;               // 串的长度
}HString;   

HString S;
// 用完需要手动free
S.ch = (char *) mallco(MAXLEN * sizeof(char));


//串的连式存储
// 结合链表的知识考虑优缺点
// 存储密度低,每个字符1B,每个指针4B
typedef struct StringNode{
    char ch;                    //  每个节点存1个字符
    struct StringNode * next;
}StringNode, *StringNode;

// 存储密度提高了
typedef struct StringNode{
    char ch[4];                 // 每个节点存多个字符
    struct StringNode * next;
}StringNode, *Stirng ;


// 基本操作实现
// SubString(&Sub,pos,len):求子串
S.ch = "wangdao";
S.length = 7;

//求子串
bool SubString(SString &Sub, SString S, int pos, int len){
    // 子串范围越界
    if (pos+len-1 > S.length)
        return  false;
    for(int i = pos; i<pos+len; i++)
        Sub.ch[i-pos+1] = S.ch[i];
    Sub.length = len;
    return true;
}


// 比较操作  StrCompare(S, T)

// 比较操作. 若S>T, 则返回值>0;若S=T. 则返回值=0; 若S<T, 则返回值<0

int StrCompare(SString S, SString T){
    for(int i=1; i<=S.length && i<=T.length; i++){
        if(S.ch[i]!=T.ch[i])
            return S.ch[i]-T.ch[i];
    }
    // 扫描过的所有字符都相同.则长度长的串更大
    return S.length-T.length;
}


// 定位操作
// Index(S, T) 定位操作
int Index(SString S, SString T){
    int i = 1, n =StrLength(S), m=StrLength(T);
    SString sub;                // 用于暂存子串
    while(i<=n-m+1){
        SubString (sub, S, i, m);
        if(StrCompare(sub, T)!=0)   ++i;
        else return i;          // 返回子串在主串的位置
    }
    return 0;                   // S中不存在与T相等的子串
} 


// 朴素模式匹配算法
int Index(SString S, SString T){
    int k = 1;
    int i = k, j=1;
    while(i<=S.length && j<T.length){
        if(S.ch[j]=T.ch[j]){
            ++i;
            ++j;                // 继续比较后继字符
        }else{
            k++;
            i=k;
            j=1;
        }
    }
    if(j>T.length)
        return k;
    else
        return 0;
}


// 课本中的朴素模式匹配
int Index(SString S, SString T){
    int i = 1, j=1;
    while(i<=S.length && j<T.length){
        if(S.ch[j]=T.ch[j]){
            ++i;
            ++j;                // 继续比较后继字符
        }else{
            i=i-j+2;
            j=1;                // 指针后退重新开始匹配
        }
    }
    if(j>T.length)
        return i-T.length;
    else
        return 0;
}


// KMP算法代码

int Index_KMP(SString S, SString T, int next[]){
    int i = 1, j =1;
    while(i<=S.length & j<=T.length){
        if(j==0|| S.ch[i]==T.ch[j]){
            ++j;
            ++i;                // 继续比较后继字符
        }
        else
            i=next[j];          // 模式串向右移动
    }
    if(j>T.length)
        return i-T.length;      // 匹配成功
    else
        return 0;
}

