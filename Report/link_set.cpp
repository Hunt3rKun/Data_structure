#include <stdio.h>
#include <cstdlib>

struct LinkNode{
    struct LinkNode *next;
    int data;
};
void Create_List_R(LinkNode *&L,int a[],int n)          //尾插法
{
    LinkNode *s,*r;
    L = (LinkNode *)malloc(sizeof(LinkNode));
    L->next = NULL;
    r = L;                                  //r始终指向尾结点,开始时指向头结点
    for (int i = 0; i < n; i++) {
        s = (LinkNode *)malloc(sizeof(LinkNode));
        s->data = a[i];
        r->next = s;
        r = s;
    }
    r->next=NULL;
}
void DestroyList(LinkNode *&L)
{
    LinkNode *pre=L,*p=pre->next;
    while (p)
    {	free(pre);
        pre=p;					//pre、p同步后移一个结点
        p=pre->next;
    }
    free(pre);					//此时p为NULL,pre指向尾结点,释放它
}

void PrintList(LinkNode *L)         //打印单链表
{
    LinkNode *p = L->next;
    while (p)
    {
        printf("%d  ",p->data);
        p = p->next;
    }
    printf("\n");
}

void Set_Sort(LinkNode *&L)         //将集合元素按递增序列排序
{
    LinkNode *p,*pre,*q;
    p=L->next->next;
    L->next->next=NULL;		//保存原来链表的第一个结点
    while (p)
    {	q=p->next;			//q指向待比较的链表，防止链表丢失
        pre=L;
        while (pre->next && pre->next->data<p->data)
            pre=pre->next;
        p->next=pre->next;
        pre->next=p;
        p=q;            //p继续指向未比较的链表
    }
}

void Set_Union(LinkNode *&ha,LinkNode *&hb,LinkNode *& hc)
{
    LinkNode *pa = ha->next,*pb = hb->next,*s,*tc;
    hc = (LinkNode *)malloc(sizeof(LinkNode));
    tc = hc;
    while (pa && pb)
    {
        if (pa->data<pb->data)
        {
            s=(LinkNode *)malloc(sizeof(LinkNode));	//复制结点
            s->data=pa->data;
            tc->next=s;tc=s;
            pa=pa->next;
        }
        else if (pa->data>pb->data)
        {
            s=(LinkNode *)malloc(sizeof(LinkNode));	//复制结点
            s->data=pb->data;
            tc->next=s;tc=s;
            pb=pb->next;
        }
        else        //重复的元素只复制一个
        {
            s=(LinkNode *)malloc(sizeof(LinkNode));
            s->data=pa->data;
            tc->next=s;tc=s;
            pa=pa->next;
            pb=pb->next;
        }
    }
    if (pb) pa=pb;	//复制余下的结点
    while (pa)
    {
        s=(LinkNode *)malloc(sizeof(LinkNode));
        s->data=pa->data;
        tc->next=s;tc=s;
        pa=pa->next;
    }
    tc->next=NULL;

}


void InterSect(LinkNode *ha,LinkNode *hb,LinkNode *&hc)
{
    LinkNode *pa=ha->next,*pb,*s,*tc;
    hc=(LinkNode *)malloc(sizeof(LinkNode));
    tc=hc;
    while (pa)
    {
        pb=hb->next;
        while (pb && pb->data<pa->data)
            pb=pb->next;
        if (pb && pb->data==pa->data)			//若pa结点值在B中
        {
            s=(LinkNode *)malloc(sizeof(LinkNode));
            s->data=pa->data;
            tc->next=s;tc=s;
        }
        pa=pa->next;
    }
    tc->next=NULL;
}
void Subs(LinkNode *ha,LinkNode *hb,LinkNode *&hc)	//求两有序集合的差
{
    LinkNode *pa=ha->next,*pb,*s,*tc;
    hc=(LinkNode *)malloc(sizeof(LinkNode));
    tc=hc;
    while (pa)
    {
        pb=hb->next;
        while (pb && pb->data<pa->data)
            pb=pb->next;
        if (!(pb && pb->data==pa->data))		//若pa结点值不在B中
        {
            s=(LinkNode *)malloc(sizeof(LinkNode));
            s->data=pa->data;
            tc->next=s;tc=s;
        }
        pa=pa->next;
    }
    tc->next=NULL;
}

int main()
{
    LinkNode *ha,*hb,*hc;
    int a [] = {6,2,3,4,5,7,11};
    int b [] = {23,7,8,17,10,11,12,85};
    Create_List_R(ha,a,7);
    Create_List_R(hb,b,8);
    Set_Sort(ha);
    Set_Sort(hb);
    printf("A and B are sorted in increase: \n");
    PrintList(ha);
    PrintList(hb);
    Set_Union(ha,hb,hc);
    printf("A??B: ");
    PrintList(hc);
    InterSect(ha,hb,hc);
    printf("A??B: ");
    PrintList(hc);
    Subs(ha,hb,hc);
    printf("A-B: ");
    PrintList(hc);
    DestroyList(ha);
    DestroyList(hb);
    DestroyList(hc);
    return 0;
}
