#include <stdio.h>
#include <cstdlib>

struct LinkNode{
    struct LinkNode *next;
    int data;
};
void Create_List_R(LinkNode *&L,int a[],int n)          //β�巨
{
    LinkNode *s,*r;
    L = (LinkNode *)malloc(sizeof(LinkNode));
    L->next = NULL;
    r = L;                                  //rʼ��ָ��β���,��ʼʱָ��ͷ���
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
        pre=p;					//pre��pͬ������һ�����
        p=pre->next;
    }
    free(pre);					//��ʱpΪNULL,preָ��β���,�ͷ���
}

void PrintList(LinkNode *L)         //��ӡ������
{
    LinkNode *p = L->next;
    while (p)
    {
        printf("%d  ",p->data);
        p = p->next;
    }
    printf("\n");
}

void Set_Sort(LinkNode *&L)         //������Ԫ�ذ�������������
{
    LinkNode *p,*pre,*q;
    p=L->next->next;
    L->next->next=NULL;		//����ԭ������ĵ�һ�����
    while (p)
    {	q=p->next;			//qָ����Ƚϵ�������ֹ����ʧ
        pre=L;
        while (pre->next && pre->next->data<p->data)
            pre=pre->next;
        p->next=pre->next;
        pre->next=p;
        p=q;            //p����ָ��δ�Ƚϵ�����
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
            s=(LinkNode *)malloc(sizeof(LinkNode));	//���ƽ��
            s->data=pa->data;
            tc->next=s;tc=s;
            pa=pa->next;
        }
        else if (pa->data>pb->data)
        {
            s=(LinkNode *)malloc(sizeof(LinkNode));	//���ƽ��
            s->data=pb->data;
            tc->next=s;tc=s;
            pb=pb->next;
        }
        else        //�ظ���Ԫ��ֻ����һ��
        {
            s=(LinkNode *)malloc(sizeof(LinkNode));
            s->data=pa->data;
            tc->next=s;tc=s;
            pa=pa->next;
            pb=pb->next;
        }
    }
    if (pb) pa=pb;	//�������µĽ��
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
        if (pb && pb->data==pa->data)			//��pa���ֵ��B��
        {
            s=(LinkNode *)malloc(sizeof(LinkNode));
            s->data=pa->data;
            tc->next=s;tc=s;
        }
        pa=pa->next;
    }
    tc->next=NULL;
}
void Subs(LinkNode *ha,LinkNode *hb,LinkNode *&hc)	//�������򼯺ϵĲ�
{
    LinkNode *pa=ha->next,*pb,*s,*tc;
    hc=(LinkNode *)malloc(sizeof(LinkNode));
    tc=hc;
    while (pa)
    {
        pb=hb->next;
        while (pb && pb->data<pa->data)
            pb=pb->next;
        if (!(pb && pb->data==pa->data))		//��pa���ֵ����B��
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
