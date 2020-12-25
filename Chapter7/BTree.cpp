#include <stdio.h>
#include <malloc.h>
struct BTreeNode{
    char data;
    struct BTreeNode * lchild;
    struct BTreeNode * rchild;
};
void Create_BTree(BTreeNode *& b,const char *str)
{
    BTreeNode *St[100],*p = NULL;
    int top = -1,k,j=0;
    char ch;
    b = NULL;
    ch = str[j];
    while (ch!='\0')
    {
        switch(ch)
        {
            case '(':top++;St[top]=p;k=1; break;
            case ')':top--;break;
            case ',':k=2; break;
            default:p=(BTreeNode *)malloc(sizeof(BTreeNode));
                p->data=ch;p->lchild=p->rchild=NULL;
                if (b==NULL)
                    b=p;
                else
                {
                    switch(k)
                    {
                        case 1:St[top]->lchild=p;break;
                        case 2:St[top]->rchild=p;break;
                    }
                }
        }
        j++;
        ch=str[j];
    }
}
void DestroyBTree(BTreeNode *&b)	//销毁二叉树
{	if (b)
    {	DestroyBTree(b->lchild);
        DestroyBTree(b->rchild);
        free(b);
    }
}
bool PreisEqual(BTreeNode *a,BTreeNode *b)
{
    if(!a&&!b)
        return true;
    if(!a||!b)
        return false;
    if(a->data == b->data)
        return PreisEqual(a->lchild,b->lchild) && PreisEqual(a->rchild,b->rchild);
    else
        return false;
}
int InisEqual(BTreeNode *a, BTreeNode *b)         //中序遍历
{
    if(!a&&!b)
        return true;
    if(!a||!b)
        return false;
    if(InisEqual(a->lchild,b->lchild))
        return a->data == b->data  && InisEqual(a->rchild,b->rchild);
    else
        return false;
}
int PostisEqual(BTreeNode *a, BTreeNode *b)
{
    if(!a&&!b)
        return true;
    if(!a||!b)
        return false;
    if(PostisEqual(a->lchild,b->lchild))
        return (PostisEqual(a->rchild,b->rchild) && a->data == b->data)  ;
    else
        return false;
}

int main()
{
    BTreeNode *a;
    BTreeNode *b;
    BTreeNode *c;
    Create_BTree(a,"A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))");
    Create_BTree(b,"A(B(D(,G),C(E,F))");
    Create_BTree(c,"A(B(D(,G),C(E,F))");
    if (PreisEqual(a,b))
    {
        printf("两棵二叉树相等\n");
    } else
        printf("两棵二叉树不相等\n");
    if (InisEqual(c,b))
    {
        printf("两棵二叉树相等\n");
    } else
        printf("两棵二叉树不相等\n");
    if (PostisEqual(c,b))
    {
        printf("两棵二叉树相等\n");
    } else
        printf("两棵二叉树不相等\n");
}
