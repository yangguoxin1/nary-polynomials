int cmp(term a, term b) // CreatPolyn()的实参
{
// 依a的指数值<、=或>b的指数值，分别返回-1、0或+1
    if (a.expn == b.expn)
        return 0;
    else if(a.expn > b.expn)
        return 1;
    else
        return -1;
}//cmp

void CreatPolyn(polynomial &P,int m)
{
    //输入m项的系数和指数，建立表示一元多项式的有序链表P
    InitList(P);//初始化-多项式链表
    Link h = GetHead(P);//设置头结点的数据元素
    term e = {0.0,-1}; //头结点设置
    Position q,s;
    SetCurElem(h, e);//设置头结点的元素
    for (int i = 1; i <= m; ++i)//依次输入m个非零项
    {
        printf("第%d项的系数:",i);
        scanf("%f",&e.coef);
        printf("第%d项的指数:",i);
        scanf("%d",&e.expn);
        if (!LocateElemP(P,e,q,(*cmp)))//当前链表中不存在该指数项
        {
                if (MakeNode(s, e))
                {
                    if(q->next==NULL) P.tail=s;
                    InsFirst(q,s);//生成结点并插入链表
                    P.len++;//课本上没有，感觉这个很有必要；
                }
        }
    }
}//CreatPolyn

int PolynLength(polynomial p)
{
    //返回一元多项式的长度
    return p.len;
}//PolynLength


void AddPolyn(polynomial &Pa, polynomial &Pb)
{
    //多项式加法:Pa = Pa+Pb,利用两个多项式的结点构成“和多项式”
    Position ha, hb, qa, qb;
    term a, b;
    float sum=0;
    ha = GetHead(Pa);
    hb = GetHead(Pb);//ha和hb分别指向Pa和Pb的头结点
    qa = NextPos(ha);
    qb = NextPos(hb);//qa和qb分别指向Pa和Pb中的当前结点
    //此时qa和qb都是指向多项式第一项
    while (qa && qb)//qa和qb非空
    {
        a = GetCurElem(qa);
        b = GetCurElem(qb); // a和b为两表中当前比较元素
        sum = 0;
        switch (cmp(a, b))//比较两者的指数值
        {
        case -1://多项式中PA中的结点的指数小
            ha = qa;
            qa = NextPos(ha);
            break;
        case 0://两者指数值相等
            sum = a.coef + b.coef;
            if (sum != 0)
            {
                //修改pa指向的该结点的系数值
                qa->data.coef = sum;
                //下一个
                ha = qa;
            }
            else
            {
                //删除结点
                Pa.len-=DelFirst( ha, qa);
                FreeNode(qa);
            }
            Pb.len-=DelFirst( hb, qb);//也删除掉qb的结点
            FreeNode(qb);//释放qb的空间
            //都往后移动一位
            qb = NextPos(hb);
            qa = NextPos(ha);
            break;
        case 1://多项式PB中的当前结点指数值小
            Pb.len-=DelFirst(hb, qb);//把当前结点从PB中删除，并用qb指向当前结点用以插入
            Pa.len+=InsFirst(ha, qb);//插入在ha前
            qb = NextPos(hb);
            qa = NextPos(ha);
            break;
        }//switch
    }//while
    if (!ListEmpty(Pb))
        Append(Pa, qb);//连接Pb中剩余结点
    FreeNode(hb);//释放Pb的头结点
}//AddPolyn

void MultiplyPolyn( polynomial &Pa, polynomial &Pb)
{
    //完成多项式乘法运算，即：PAxPb，并销毁一元多项式Pb
    Position ha, hb, qa, qb,s;
    polynomial Pc,Pd;
    InitList(Pd);
    term e;
    hb = GetHead(Pb);//ha和hb分别指向Pa和Pb的头结点
    qb = NextPos(hb);//qa和qb分别指向Pa和Pb中的当前结点
    while(qb)
    {
        ha = GetHead(Pa);
        qa = NextPos(ha);
        while(qa)
        {
            InitList(Pc);
            e.coef=qa->data.coef*qb->data.coef;
            e.expn=qa->data.expn+qb->data.expn;
            MakeNode(s,e);
            InsFirst(Pc.tail,s);
            Pc.tail=s;
            Pc.len++;
            ha=qa;
            qa=NextPos(ha);
        }
        AddPolyn(Pd,Pc);
        hb=qb;
        qb=NextPos(hb);
        FreeNode(hb);
    }
    DestroyList(Pb);
    Pa.head=Pd.head;
    Pa.tail=Pd.tail;
    Pa.len=Pd.len;
    FreeNode(Pd.head);
}
Status ListTraverse(LinkList L, void(*visit)(ElemType)){
    // 依次对L的每个数据元素调用函数visit()。一旦visit()失败，则操作失败
    Link p = L.head->next;
    int j;
    for (j = 1; j <= L.len; j++)
    {
        visit(p->data);
        p = p->next;
    }
    printf("\b "); //退格，每次输出多项式后删掉的最后输出的"+"
    if (L.len == 0)
        printf("0");
    return OK;
}//ListTraverse

void visit(ElemType e){
    if (e.coef > 0 && e.coef != 1 && e.expn != 0)
    {
        if(e.expn == 1)
            printf("%gx+", e.coef);
        else if  (e.expn > 0)
            printf("%gx^%d+", e.coef,e.expn);
    }
    else if (e.coef < 0 && e.expn != 0)
    {
        if(e.expn == 1)
            printf("(%g)x+", e.coef);
        else if (e.expn > 0)
            printf("(%g)x^%d+", e.coef,e.expn);
    }
    else if (e.coef == 1 && e.expn != 0)
    {
        if(e.expn == 1)
            printf("x+" );
        else if (e.expn > 0)
            printf("x^%d+",e.expn);
    }
    else if (e.expn == 0 && e.coef != 0)
        printf("%g+",e.coef);
    else;
}//visit
void PrintPolyn(polynomial P)
{
    //打印出一元多项式
    ListTraverse(P, visit);
    printf("\n");
}
