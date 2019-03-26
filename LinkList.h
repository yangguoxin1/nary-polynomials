
//----------链表函数的具体实现代码-----------
Status MakeNode(Link &p, ElemType e)
{
    // 分配由p指向的值为e的结点，并返回OK；若分配失败。则返回ERROR
    p = (Link)malloc(sizeof(LNode));
    if (!p)
        return ERROR;
    p->data = e;
    return OK;
}//MakeNode

void FreeNode(Link &p)
{
    // 释放p所指结点
    free(p);
}//FreeNode

Status InitList(LinkList &L)
{
    // 构造一个空的线性链表
    Link p;
    p = (Link)malloc(sizeof(LNode)); // 生成头结点
    if (p)
    {
        p->next = NULL;
        L.head = L.tail = p;
        L.len = 0;
        return OK;
    }
    else
        return ERROR;//内存分配不够
}//InitList


Status DelFirst( Link h, Link &q)
{
    // h指向L的一个结点，把h当做头结点，删除链表中的第一个结点并以q返回。
    // 若链表为空(h指向尾结点)，q=NULL，返回FALSE
    if(h->next==NULL) return ERROR;
    q = h->next;
    h->next = q->next;
    q->next = NULL;
    return OK;
}//DelFirst
Status ClearList(LinkList &L)
{
//将线性表L制空，并释放原链表的结点空间
    Link q;
    while(DelFirst( L.head, q))
    {
        free(q);
    }
    L.len=0;
    L.tail=L.head;
    return OK;

}

Status DestroyList(LinkList &L)
{
//销毁线性表L，L不负存在
    ClearList(L);
    free(L.head);
    return OK;
}

Status InsFirst(Link h, Link s)
{
// h指向L的一个结点，把h当做头结点，将s所指结点插入在第一个结点之前
    s->next = h->next;
    h->next = s;
    return OK;
}//InsFirst


Status Append(LinkList &L, Link s)
{
    // 将指针s(s->data为第一个数据元素)所指(彼此以指针相链,以NULL结尾)的
    //  一串结点链接在线性链表L的最后一个结点之后,并改变链表L的尾指针指向新
    //  的尾结点
    int i = 1;
    L.tail->next = s;
    while (s->next)
    {
        s = s->next;
        i++;
    }
    L.tail = s;
    L.len += i;
    return OK;
}//Append

Position GetHead(LinkList L)
{
    // 返回线性链表L中头结点的位置
    return L.head;
}//GetHead

Status SetCurElem(Link &p, ElemType e)
{
    // 已知p指向线性链表中的一个结点，用e更新p所指结点中数据元素的值
    p->data = e;
    return OK;
}//SetCurElem

Position PriorPos(LinkList L,Link p)
{
    // 已知p指向线性链表L中的一个结点，返回p所指结点的直接前驱的位置
    //  若无前驱，则返回NULL
    Link q = L.head;
    if(q->next->data == p->data) return NULL;
    do
    {
        q=q->next;
    }
    while(q->next->data != p->data);
    return q;
}//PriorPos

Status ListEmpty(LinkList L)
{
    // 若线性链表L为空表，则返回TRUE，否则返回FALSE
    if (L.len)
        return FALSE;
    else
        return TRUE;
}//ListEmpty
Status LocateElemP(LinkList L, ElemType e,Position &q, int(*compare)(ElemType, ElemType))
{
    // 若升序链表L中存在与e满足判定函数cprintf(("**"));ompare()取值为0的元素，则q指示L中
    // 第一个值为e的结点的位置，并返回TRUE；否则q指示第一个与e满足判定函数
    // compare()取值>0的元素的前驱的位置。并返回FALSE。（用于一元多项式）
    Link p = L.head;
    if( ListEmpty(L) || compare(p->next->data, e)>0 )
    {
        q=p;
        return FALSE;
    }
    do
    {
        p = p->next;
    }
    while (p && (compare(p->data, e)<0));   // 没到表尾且p->data.expn<e.expn
    if (!p) // 到表尾或compare(p->data,e)>0
    {
        q = L.tail;
        return FALSE;
    }
    else if(compare(p->data, e)>0) // 找到
    {
        q = PriorPos(L,p);
        return FALSE;
    }
    else
    {
        q=p;
        return TRUE;
    }
}//LocateElemP


Position NextPos(Link p)
{
    // 已知p指向线性链表L中的一个结点，返回p所指结点的直接后继的位置
    //  若无后继，则返回NULL
    return p->next;
}//NextPos

ElemType GetCurElem(Link p)
{
    // 已知p指向线性链表中的一个结点，返回p所指结点中数据元素的值
    return p->data;
}//GetCurElem









