#include<iostream>
#include<cstring>
#include<algorithm>
#define MAXN 10005
using namespace std;

struct edge{
	int to,next;
}e[MAXN*2];

int head[MAXN],low[MAXN],dfn[MAXN],sd[MAXN],cd[MAXN],rd[MAXN],stack[MAXN],vis[MAXN];
int id,timelock,cnt,n,top;

void add(int u,int v){
	e[++id].to=v;
	e[id].next=head[u];
	head[u]=id;
}

void tarjan(int x){
	dfn[x]=low[x]=++timelock;
	stack[++top]=x;
	vis[x]=1;
	for(int i=head[x];i;i=e[i].next){
		int v=e[i].to;
		if(!dfn[v]){
			tarjan(v);
			low[x]=min(low[x],low[v]);
		}
		else if(vis[v])
	        low[x]=min(low[x],dfn[v]);
	}
	if(dfn[x]==low[x]){
		cnt++;
		while(stack[top+1]!=x){
			int y=stack[top];
			vis[y]=0;
			sd[y]=cnt;
			top--;
		}
	}
}

inline int read()
{
    int x=0;
    char c=getchar();
    bool flag=0;
    while(c<'0'||c>'9'){if(c=='-')flag=1;   c=getchar();}
    while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return flag?-x:x;
} 

int main(){
	n=read();
	for(int i=1;i<=n;i++){
		int x=read();
		while(x!=0){
			add(i,x);
			x=read();
		}
	}
	for(int i=1;i<=n;i++)
	   if(!dfn[i]) tarjan(i);
	for(int i=1;i<=n;i++)
	   for(int j=head[i];j;j=e[j].next)
	    if(sd[i]!=sd[e[j].to])
	{
	    rd[sd[e[j].to]]++;
		cd[sd[i]]++;  
	}
	int ans1=0,ans2=0;
	for(int i=1;i<=cnt;i++){
		if(rd[i]==0) ans1++;
		if(cd[i]==0) ans2++; 
	}
	if(cnt==1) cout<<1<<endl<<0;
    else
        cout<<ans1<<endl<<max(ans1,ans2);
}
