#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
#define maxm 850
#define pp pair<double,int>//注意不要顺手写成int,int 
#define mp make_pair
using namespace std;
int n,m,tot;
int h[maxm],vis[maxm];
double px[maxm],py[maxm],dis[maxm];
struct node{
	int to,nxt;
	double val;
}e[maxm*maxm*2];

inline void add(int x,int y,double z){
	e[++tot].to=y;
	e[tot].nxt=h[x];
	e[tot].val=z;
	h[x]=tot;
	return;
}//建边 

inline double calc(int i,int j){
	return sqrt((px[i]-px[j])*(px[i]-px[j])+(py[i]-py[j])*(py[i]-py[j]));
}//计算两点距离 

void dij(){
	priority_queue<pp,vector<pp >,greater<pp> > q;//堆优化
	for (int i=1;i<=m+5;++i) dis[i]=1e9;//初始化 
	dis[m+1]=0;//从m+1出发 
	q.push(mp(0,m+1));
	while (!q.empty()){
		int u=q.top().second;
		q.pop();
		if (vis[u]) continue;
		vis[u]=1;
		for (int i=h[u];i;i=e[i].nxt){
			int v=e[i].to;
			if (dis[v]>max(dis[u],e[i].val)){
				dis[v]=max(dis[u],e[i].val);//松弛 
				q.push(mp(dis[v],v));
			}
		}
	}
	return;
}

int main(){
	cin>>n>>m;
	for (int i=1;i<=m;++i){
		cin>>px[i]>>py[i];
		add(m+1,i,px[i]);
		add(i,m+1,px[i]);
		add(m+2,i,double(n)-px[i]);
		add(i,m+2,double(n)-px[i]);
		//m+1是沙滩的左边界，m+2是沙滩的右边界
		//求的就是m+1到m+2的路径最大值最小 
	}
	for (int i=1;i<m;++i){
		for (int j=i+1;j<=m;++j){
			add(i,j,calc(i,j)/2.0);
			add(j,i,calc(i,j)/2.0);
		}
	}//两两加边，两个圆相切时刚好联通，所以要除以2 
	dij();
	printf("%.2lf",dis[m+2]);//保留两位小数 
	return 0;
}
