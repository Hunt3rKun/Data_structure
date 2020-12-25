#include <stdio.h>
#define MAXI 20
#define MAXL 100
struct Idx
{
    int key;
    int link;
};

struct Rec
{	int key;
    char data;
};

int IdxSearch(Idx I[],int b,Rec R[],int n,int k) //�ֿ����
{
    int s=(n+b-1)/b;
    int count1=0,count2=0;
    int low=0,high=b-1,mid,i;
    printf("(1)�����������۰����\n");
    while (low<=high)
    {
        mid=(low+high)/2;
        printf("  ��%d�αȽ�:��[%d,%d]�бȽ�Ԫ��R[%d]:%d\n",count1+1,low,high,mid,R[mid].key);
        if (I[mid].key>=k)
            high=mid-1;
        else
            low=mid+1;
        count1++;
    }
    printf("�Ƚ�%d��,�ڵ�%d���в���Ԫ��%d\n",count1,low,k);
    i=I[high+1].link;
    printf("(2)�ڶ�Ӧ����˳�����:\n    ");
    while (i<=I[high+1].link+s-1)
    {	printf("%d ",R[i].key);
        count2++;
        if (R[i].key==k) break;
        i++;
    }
    printf("�Ƚ�%d��,��˳����в���Ԫ��%d\n",count2,k);
    if (i<=I[high+1].link+s-1)
        return i+1;
    else
        return 0;
}


int main()
{
    Rec R[MAXL];
    Idx I[MAXI];
    int n=25, i;
    int a[]={8,14,6,9,10,22,34,18,19,31,40,38,54,66,46,71,78,68,80,85,100,94,88,96,87};
    for (int i=0;i<n;i++)			//R[0..n-1]��������¼
        R[i].key=a[i];
    I[0].key=14;I[0].link=0;
    I[1].key=34;I[1].link=4;
    I[2].key=66;I[2].link=10;
    I[3].key=85;I[3].link=15;
    I[4].key=100;I[4].link=20;
    printf("�ؼ�������:");
    for (i=0;i<n;i++)
    {
        printf("%4d",R[i].key);
        if (((i+1)%5)==0) printf("   ");
        if (((i+1)%10)==0) printf("\n\t   ");
    }
    printf("\n");
    int k=46;
    printf("����%d�ıȽϹ�������:\n",k);

    if ((i=IdxSearch(I,5,R,25,k))!=-1)
        printf("Ԫ��%d��λ����%d\n",k,i);
    else
        printf("Ԫ��%d���ڱ���\n",k);
    return 0;
 }