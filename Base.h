#include<stdio.h>
#include <stdlib.h>  //malloc system
//函数结果状态代码
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2
//Status是函数的类型，其值是函数结果状态代码
typedef int Status;
typedef struct term //项的表示，多项式的项作为LinkList的数据元素
{
    float coef;//系数
    int expn;//指数
    bool operator==(const term t)const
    {
        return(this->coef == t.coef&&this->expn == t.expn);
    }
    bool operator!=(const term t)const
    {
        return(this->coef != t.coef || this->expn != t.expn);  //运算符重载
    }
} term,ElemType; //两个类型：term用于本ADT，ElemType为LinkList的数据对象名;
/*------线性表的定义---------*/

typedef struct LNode //节点类型
{
    ElemType  data;//这里表示了每一项，其指数和系数
    struct LNode *next;
}*Link,*Position;

typedef struct //链表类型
{
    Link head, tail;//分别指向线性链表中的头结点和最后一个结点
    int len;//指示线性链表中数据元素的个数
} LinkList; //每一项组成一个列表

typedef LinkList polynomial;
