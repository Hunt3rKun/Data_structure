#include <stdio.h>
#define MAXL 100		//最大长度
struct Rec{
    int key;
    char data;
};

void CreateList(Rec R[],int keys[],int n)	//创建顺序表
{
    for (int i=0;i<n;i++)			//R[0..n-1]存放排序记录
        R[i].key=keys[i];
}
void DispList(Rec R[],int n)	//输出顺序表
{
    for (int i=0;i<n;i++)
        printf("%d ",R[i].key);
    printf("\n");
}

void ShellSort(Rec R[],int n)	//对R[0..n-1]按递增有序进行希尔排序
{	int i,j,d;
    Rec tmp;
    d=n/2;					//增量置初值
    while (d>0)
    {	for (i=d;i<n;i++) 		//对所有组采用直接插入排序
        {	tmp=R[i];			//对相隔d个位置一组采用直接插入排序
            j=i-d;
            while (j>=0 && tmp.key<R[j].key)
            {	R[j+d]=R[j];
                j=j-d;
            }
            R[j+d]=tmp;
        }
        printf("  d=%d: ",d); DispList(R,n);
        d=d/2;				//减小增量
    }
}
int main()
{
    int n=10;
    Rec R[MAXL];
    int a[]={9,8,7,6,5,4,3,2,1,0};
    CreateList(R,a,n);
    printf("排序前:"); DispList(R,n);
    ShellSort(R,n);
    printf("排序后:"); DispList(R,n);
    return 1;
}