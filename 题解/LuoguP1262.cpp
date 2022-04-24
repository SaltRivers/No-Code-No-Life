#include<iostream>
#include<stdio.h>
#include<cstring>
#include<stack>
#include<queue> 
#define MAXN 8005
#define inf (int)0x3f3f3f3f 
using namespace std;

struct edge{
	int to,next;
}e[2*MAXN];


int head[MAXN],cost[MAXN],dfn[MAXN],low[MAXN],vis[MAXN],sd[MAXN],mi[MAXN];
int in[MAXN],top;
int n,p,id,num,cnt;

inline int read()
{
    int x=0;
    char c=getchar();
    bool flag=0;
    while(c<'0'||c>'9'){if(c=='-')flag=1;   c=getchar();}
    while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return flag?-x:x;
}

void add(int v,int t){
	e[++id].to=t;
	e[id].next=head[v];
	head[v]=id;
}

stack<int> s;
void tarjan(int x){
	low[x]=dfn[x]=++num;
	s.push(x);
	vis[x]=1;
	for(int i=head[x];i;i=e[i].next)
	{
		int v=e[i].to;
	    if(!dfn[v])
	    {
	 	    tarjan(v);
		    low[x]=min(low[x],low[v]);
	    }
	    else if(vis[v])
	    low[x]=min(low[x],dfn[v]);
	}
	if(dfn[x]==low[x])
	{
		cnt++;
		int y;
		while (1)
		{
			y=s.top();
			s.pop();
			sd[y]=cnt;
			vis[y]=0;
			mi[cnt]=min(mi[cnt],cost[y]);
			if(y==x) break;
		}
	}
}

int main(){
	n=read(),p=read();
	memset(cost,inf,sizeof(cost));
	memset(mi,inf,sizeof(mi));
	int a,c;
	for(int i=1;i<=p;i++){
		a=read();c=read();
		cost[a]=c;
	}
	p=read();
	int v,t;
	for(int i=1;i<=p;i++){
		v=read(),t=read();
		add(v,t);
	}
	for(int i=1;i<=n;i++)
	  if(!dfn[i]&&cost[i]!=inf) tarjan(i);
	for(int i=1;i<=n;i++)      //在这里我们用dfn数组来判断它是否被遍历过 
	if(!dfn[i])
	{
		printf("NO\n");
		printf("%d\n",i);
		return 0;
	}
	
   for(int i=1;i<=n;i++)
	for(int j=head[i];j;j=e[j].next)
	if(sd[i]!=sd[e[j].to])
	{
	    in[sd[e[j].to]]++;   //记录入度 
	}
	
	printf("YES\n");
	int ans;
	for(int i=1;i<=cnt;i++)
	{
	   if(!in[i])
	   { 
	       ans+=mi[i];
	   }
    }
	printf("%d\n",ans);
	return 0;
} 
