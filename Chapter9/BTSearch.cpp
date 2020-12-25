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
        return InsertBST(bt->lchild,k);	//插入到bt节点的左子树中
    else
        return InsertBST(bt->rchild,k);  //插入到bt节点的右子树中
}
int SearchBST(BSTnode *bt,int k)
//以递归方式输出从根节点到查找到的节点的路径
{
    if (!bt)
        return 0;
    else if (k==bt->key)
    {
        printf("%3d",bt->key);
        return 1;
    }
    else if (k<bt->key)
        SearchBST(bt->lchild,k);  //在左子树中递归查找
    else
        SearchBST(bt->rchild,k);  //在右子树中递归查找
    printf("%3d",bt->key);
}
void Delete1(BSTnode *p,BSTnode *&r) //被删节点p有左、右子树，r指向其左孩子
{	BSTnode *q;
    if (r->rchild)		//递归找节点r的最右下节点
        Delete1(p,r->rchild);
    else						//找到了最右下节点r（它没有右子树）
    {	p->key=r->key;			//将节点r的值存放到节点p中（节点值替代）
        p->data=r->data;
        q=r;					//删除节点r
        r=r->lchild;			//即用节点r的左孩子替代它
        free(q);				//释放节点r的空间
    }
}
void Delete(BSTnode *&p)		//从二叉排序树中删除p节点
{
    BSTnode *q;
    if (!p->rchild)		//p节点没有右子树的情况
    {
        q=p;p=p->lchild;free(q);
    }
    else if (!p->lchild)	//p节点没有左子树的情况
    {
        q=p;p=p->rchild;free(q);
    }
    else Delete1(p,p->lchild);	//p节点既有左子树又有右子树的情况
}
bool DeleteBST(BSTnode *&bt,int k)
//在bt中删除关键字为k的节点
{
    if (!bt) return false;		//空树删除失败
    else
    {
        if (k<bt->key)
            return DeleteBST(bt->lchild,k);		//递归在左子树中删除关键字为k的节点
        else if (k>bt->key)
            return DeleteBST(bt->rchild,k);		//递归在右子树中删除关键字为k的节点
        else									//k=bt->key的情况
        {
            Delete(bt);							//调用Delete(bt)函数删除bt节点
            return true;
        }
    }
}
void DispBST(BSTnode *bt)
//以括号表示法输出二叉排序树bt
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
//由数组A中的关键字建立一棵二叉排序树
{
    BSTnode *bt=NULL;         			//初始时bt为空树
    int i=0;
    while (i<n)
        if (InsertBST(bt,A[i])==1)		//将A[i]插入二叉排序树T中
        {
            printf("    第%d步,插入%d:",i+1,A[i]);
            DispBST(bt);
            printf("\n");
            i++;
        }
    return bt;               			//返回建立的二叉排序树的根指针
}

int main()
{
    BSTnode *bt;
    int k=6;
    int a[]={4,9,0,1,8,6,3,5,2,7},n=10;
    printf("创建一棵BST树:\n");
    bt=CreateBST(a,n);
    printf("查找关键字%d【逆序】:\n",k);
    SearchBST(bt,k);
    printf("\n");
    printf("删除节点6:\n");
    DeleteBST(bt,6);
    DispBST(bt);
    return 0;
 }