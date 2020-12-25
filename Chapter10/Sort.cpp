#include <stdio.h>
#define MAXL 100		//��󳤶�
struct Rec{
    int key;
    char data;
};

void CreateList(Rec R[],int keys[],int n)	//����˳���
{
    for (int i=0;i<n;i++)			//R[0..n-1]��������¼
        R[i].key=keys[i];
}
void DispList(Rec R[],int n)	//���˳���
{
    for (int i=0;i<n;i++)
        printf("%d ",R[i].key);
    printf("\n");
}

void ShellSort(Rec R[],int n)	//��R[0..n-1]�������������ϣ������
{	int i,j,d;
    Rec tmp;
    d=n/2;					//�����ó�ֵ
    while (d>0)
    {	for (i=d;i<n;i++) 		//�����������ֱ�Ӳ�������
        {	tmp=R[i];			//�����d��λ��һ�����ֱ�Ӳ�������
            j=i-d;
            while (j>=0 && tmp.key<R[j].key)
            {	R[j+d]=R[j];
                j=j-d;
            }
            R[j+d]=tmp;
        }
        printf("  d=%d: ",d); DispList(R,n);
        d=d/2;				//��С����
    }
}
int main()
{
    int n=10;
    Rec R[MAXL];
    int a[]={9,8,7,6,5,4,3,2,1,0};
    CreateList(R,a,n);
    printf("����ǰ:"); DispList(R,n);
    ShellSort(R,n);
    printf("�����:"); DispList(R,n);
    return 1;
}