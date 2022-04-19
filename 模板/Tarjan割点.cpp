#include<bits/stdc++.h>
using namespace std;
struct edge{
    int nxt,mark;
}pre[200010];
int n,m,idx,cnt,tot;
int head[100010],DFN[100010],LOW[100010];
bool cut[100010];
void add (int x,int y)
{
    pre[++cnt].nxt=y;
    pre[cnt].mark=head[x];
    head[x]=cnt;
}
void tarjan (int u,int fa)
{
    DFN[u]=LOW[u]=++idx;
    int child=0;
    for (int i=head[u];i!=0;i=pre[i].mark)
    {
        int nx=pre[i].nxt;
        if (!DFN[nx])
        {
            tarjan (nx,fa);
            LOW[u]=min (LOW[u],LOW[nx]);
            if (LOW[nx]>=DFN[u]&&u!=fa)
                cut[u]=1;
            if(u==fa)
                child++;
        }
        LOW[u]=min (LOW[u],DFN[nx]);
    }
    if (child>=2&&u==fa)
        cut[u]=1;
}
int main()
{
    memset (DFN,0,sizeof (DFN));
    memset (head,0,sizeof (head));
    scanf ("%d%d",&n,&m);
    for (int i=1;i<=m;i++)
    {
        int a,b;
        scanf ("%d%d",&a,&b);
        add (a,b);
        add (b,a);
    }
    for (int i=1;i<=n;i++)
        if (DFN[i]==0)
            tarjan (i,i);
    for (int i=1;i<=n;i++)
        if (cut[i])
            tot++;
    printf ("%d\n",tot);
    for (int i=1;i<=n;i++)
        if (cut[i])
            printf ("%d ",i);
    return 0;
}
