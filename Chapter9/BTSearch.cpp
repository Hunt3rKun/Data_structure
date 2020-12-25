#include <cstdio>
#include <cstdlib>
struct BSTnode{
    int key;
    char data;
    struct BSTnode * lchild, *rchild;
};
bool InsertBST(BSTnode *&bt,int k)
{
    if (!bt)
    {
        bt=(BSTnode *)malloc(sizeof(BSTnode));
        bt->key=k;
        bt->lchild=bt->rchild=NULL;
        return true;
    }
    else if (k==bt->key)
        return false;
    else if (k<bt->key)
        return InsertBST(bt->lchild,k);	//���뵽bt�ڵ����������
    else
        return InsertBST(bt->rchild,k);  //���뵽bt�ڵ����������
}
int SearchBST(BSTnode *bt,int k)
//�Եݹ鷽ʽ����Ӹ��ڵ㵽���ҵ��Ľڵ��·��
{
    if (!bt)
        return 0;
    else if (k==bt->key)
    {
        printf("%3d",bt->key);
        return 1;
    }
    else if (k<bt->key)
        SearchBST(bt->lchild,k);  //���������еݹ����
    else
        SearchBST(bt->rchild,k);  //���������еݹ����
    printf("%3d",bt->key);
}
void Delete1(BSTnode *p,BSTnode *&r) //��ɾ�ڵ�p������������rָ��������
{	BSTnode *q;
    if (r->rchild)		//�ݹ��ҽڵ�r�������½ڵ�
        Delete1(p,r->rchild);
    else						//�ҵ��������½ڵ�r����û����������
    {	p->key=r->key;			//���ڵ�r��ֵ��ŵ��ڵ�p�У��ڵ�ֵ�����
        p->data=r->data;
        q=r;					//ɾ���ڵ�r
        r=r->lchild;			//���ýڵ�r�����������
        free(q);				//�ͷŽڵ�r�Ŀռ�
    }
}
void Delete(BSTnode *&p)		//�Ӷ�����������ɾ��p�ڵ�
{
    BSTnode *q;
    if (!p->rchild)		//p�ڵ�û�������������
    {
        q=p;p=p->lchild;free(q);
    }
    else if (!p->lchild)	//p�ڵ�û�������������
    {
        q=p;p=p->rchild;free(q);
    }
    else Delete1(p,p->lchild);	//p�ڵ�������������������������
}
bool DeleteBST(BSTnode *&bt,int k)
//��bt��ɾ���ؼ���Ϊk�Ľڵ�
{
    if (!bt) return false;		//����ɾ��ʧ��
    else
    {
        if (k<bt->key)
            return DeleteBST(bt->lchild,k);		//�ݹ�����������ɾ���ؼ���Ϊk�Ľڵ�
        else if (k>bt->key)
            return DeleteBST(bt->rchild,k);		//�ݹ�����������ɾ���ؼ���Ϊk�Ľڵ�
        else									//k=bt->key�����
        {
            Delete(bt);							//����Delete(bt)����ɾ��bt�ڵ�
            return true;
        }
    }
}
void DispBST(BSTnode *bt)
//�����ű�ʾ���������������bt
{
    if (bt!=NULL)
    {
        printf("%d",bt->key);
        if (bt->lchild!=NULL || bt->rchild!=NULL)
        {
            printf("(");
            DispBST(bt->lchild);
            if (bt->rchild!=NULL) printf(",");
            DispBST(bt->rchild);
            printf(")");
        }
    }
}
BSTnode *CreateBST(int A[],int n)
//������A�еĹؼ��ֽ���һ�ö���������
{
    BSTnode *bt=NULL;         			//��ʼʱbtΪ����
    int i=0;
    while (i<n)
        if (InsertBST(bt,A[i])==1)		//��A[i]�������������T��
        {
            printf("    ��%d��,����%d:",i+1,A[i]);
            DispBST(bt);
            printf("\n");
            i++;
        }
    return bt;               			//���ؽ����Ķ����������ĸ�ָ��
}

int main()
{
    BSTnode *bt;
    int k=6;
    int a[]={4,9,0,1,8,6,3,5,2,7},n=10;
    printf("����һ��BST��:\n");
    bt=CreateBST(a,n);
    printf("���ҹؼ���%d������:\n",k);
    SearchBST(bt,k);
    printf("\n");
    printf("ɾ���ڵ�6:\n");
    DeleteBST(bt,6);
    DispBST(bt);
    return 0;
 }