#include<iostream>
#include <algorithm>
#define il inline
#define MAXN 405
#define MAXM 10005
#define ll long long
#define eps (1e-8)
#define re register
using namespace std;
il int read()
{
    re int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
    return x*f;
}
int n,m,f;
int fa[MAXN];
struct Edge
{
	int u,v,c,t;
	double w;
}e[200005];

bool cmp(Edge a,Edge b){
	return a.w<b.w;
}

int find(int x){
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}

bool Kruskal(double L){
  for(int i=1;i<=m;i++)
      e[i].w=(double)e[i].c+(double)e[i].t*L;
  for(int i=1;i<=n;i++) fa[i]=i;
  sort(e+1,e+1+m,cmp);
  double res=0;
  int cnt=0;
  for(int i=1;i<=m;i++){
  	int xx=find(e[i].u),yy=find(e[i].v);
  	if(xx!=yy){
  		int cnt=0;
  		res+=e[i].w;	
			fa[xx]=yy;
			if(cnt==n-1) break;
	  }
  }
  return ((double)f-res)>=0.0;
}
int main(){
	n=read();m=read();f=read();
	for(int i=1;i<=m;i++){
	   e[i].u=read(),e[i].v=read(),e[i].c=read(),e[i].t=read();
	} 
	 double l=0.0,r=1e9,mid;
	 while(r-l>=eps){
	 	mid=(l+r)/2;
	 	if(Kruskal(mid)) l=mid;
	 	else r=mid;
	 }
	 printf("%.4lf",l);
} 
