#include <cstdio>
#include <cstdlib>

#define	MAXV 100
#define INF 32367
struct Arcnode{               //��
    int adjvex;
    struct Arcnode * nextarc;     //ָ����һ���ߵ�ָ��
    int weight;
};
struct Vexnode{             //���
    Arcnode *firstarc;        //ָ���һ����
};

struct AdjGraph{
    Vexnode adjlist[MAXV];
    int n,e;
};
void CreateAdj(AdjGraph *&G,int A[MAXV][MAXV],int n,int e) //����ͼ���ڽӱ�
{
    int i,j;
    Arcnode *p;
    G=(AdjGraph *)malloc(sizeof(AdjGraph));
    for (i=0;i<n;i++)
        G->adjlist[i].firstarc=NULL;
    for (i=0;i<n;i++)
        for (j=n-1;j>=0;j--)
            if (A[i][j]!=0 && A[i][j]!=INF)
            {	p=(Arcnode *)malloc(sizeof(Arcnode));
                p->adjvex=j;
                p->weight=A[i][j];
                p->nextarc=G->adjlist[i].firstarc;
                G->adjlist[i].firstarc=p;
            }
    G->n=n; G->e=e;
}

void DispAdj(AdjGraph *G)	//����ڽӱ�G
{
    Arcnode *p;
    for (int i=0;i<G->n;i++)
    {
        p=G->adjlist[i].firstarc;
        printf("%2d: ",i);
        while (p)
        {
            printf("%2d[%d]��",p->adjvex,p->weight);
            p=p->nextarc;
        }
        printf("��\n");
    }
}
void Dijkstra(AdjGraph *G,int v)
{
    int dist[MAXV];
    int prev[MAXV];
    bool s[MAXV];
    for (int i = 0; i < G->n; i++)
        dist[i] = MAXV;
    for (Arcnode *p = G->adjlist[v].firstarc; p; p = p->nextarc)
        dist[p->adjvex] = p->weight;
    for (int i = 0; i < G->n; i++)
    {
        s[i] = false;
        if (dist[i] == MAXV)
            prev[i] = 0;
        else
            prev[i] = v;
    }

    dist[v] = 0;
    s[v] = true;

    for ( int i = 2; i <= G->n; i++)
    {
        int temp = MAXV;
        int u = v;
        for (int j = 1; j <= G->n; j++)
            if (!s[j] && dist[j] < temp)
            {
                u = j;
                temp = dist[j];
            }
        s[u] = true;

        //����dist
        for (Arcnode *p = G->adjlist[u].firstarc; p;p = p->nextarc)
        {
            int newdist = p->weight+dist[u];
            if (newdist < dist[p->adjvex])
            {
                dist[p->adjvex] = newdist;
                prev[p->adjvex] = u;
            }
        }
    }
    for( int i=1;i<G->n;i++)
        printf("Դ�㵽��%d���������̾���Ϊ��%d \n",i,dist[i]);

}
int main()
{
    int v=0;
    AdjGraph *G;
    int A[MAXV][MAXV]={
            {0,5,INF,7,INF,INF},
            {INF,0,4,INF,INF,INF},
            {8,INF,0,INF,INF,9},
            {INF,INF,5,0,INF,6},
            {INF,INF,INF,5,0,INF},
            {3,INF,INF,INF,1,0}};
    int n=6, e=10;
    CreateAdj(G,A,n,e);
    printf("����ڽӱ�\n");
    DispAdj(G);
    printf("���·��:\n");
    Dijkstra(G,v);
    return 0;
}