#include<bits/stdc++.h>
using namespace std;
#define re register
#define il inline
il int read()
{
    re int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
    return x*f;
}//快读，不理解的同学用cin代替即可
#define inf 123456789
#define maxn 5005
#define maxm 200005
struct edge
{
	int v,w,next;
}e[maxm<<1];
//注意是无向图，开两倍数组
int head[maxn],dis[maxn],cnt,n,m,tot,now=1,ans;
//已经加入最小生成树的的点到没有加入的点的最短距离，比如说1和2号节点已经加入了最小生成树，那么dis[3]就等于min(1->3,2->3)
bool vis[maxn];
//链式前向星加边
il void add(int u,int v,int w)
{
	e[++cnt].v=v;
	e[cnt].w=w;
	e[cnt].next=head[u];
	head[u]=cnt;
}
//读入数据
il void init()
{
    n=read(),m=read();
    for(re int i=1,u,v,w;i<=m;++i)
    {
        u=read(),v=read(),w=read();
        add(u,v,w),add(v,u,w);
    }
}
il int prim()
{
	//先把dis数组附为极大值
	for(re int i=2;i<=n;++i)
	{
		dis[i]=inf;
	}
    //这里要注意重边，所以要用到min
	for(re int i=head[1];i;i=e[i].next)
	{
		dis[e[i].v]=min(dis[e[i].v],e[i].w);
	}
    while(++tot<n)//最小生成树边数等于点数-1
    {
        re int minn=inf;//把minn置为极大值
        vis[now]=1;//标记点已经走过
        //枚举每一个没有使用的点
        //找出最小值作为新边
        //注意这里不是枚举now点的所有连边，而是1~n
        for(re int i=1;i<=n;++i)
        {
            if(!vis[i]&&minn>dis[i])
            {
                minn=dis[i];
				now=i;
            }
        }
        ans+=minn;
        //枚举now的所有连边，更新dis数组
        for(re int i=head[now];i;i=e[i].next)
        {
        	re int v=e[i].v;
        	if(dis[v]>e[i].w&&!vis[v])
        	{
        		dis[v]=e[i].w;
        	}
		}
    }
    return ans;
}
int main()
{
    init();
    printf("%d",prim());
    return 0;
}
