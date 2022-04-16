#include<iostream>
#include<cstring>
#include<queue>
#define MAXN 3005  //城市数量 
#define MAXM 700005  //路径的数量 
using namespace std;

struct edge{
    int tot,time,next;
}e[MAXM];//存储路径

int rd()
{
    int s=0;
    char ch=getchar();
    while(ch<'0' || ch>'9')ch=getchar();
    while(ch>='0' && ch<='9')
    {
        s=(s<<3)+(s<<1)+(ch^48);
        ch=getchar();
    }
    return s;
}//快读 
struct node
{
    int dis,id;
    bool operator <(const node&a)const
    {
        return dis>a.dis;
    };
};//放入优先队列（小顶堆） 
priority_queue < node > q;
int n,m,id,head[MAXN],dis[MAXN],bomb[MAXN][MAXN],boundary[MAXN],cnt[MAXN],v[MAXN];

void add(int u,int v,int w){
    e[++id].tot=v;
    e[id].time=w;
    e[id].next=head[u];
    head[u]=id;
} 

void Fbo(){
    int l,temp;
    memset(cnt,0,sizeof(cnt));
    for(int i=1;i<=n;i++){
        l=rd();
        boundary[i]=l;//存储i被l个边界保护 
        if(l==0) continue;
        for(int j=1;j<=l;j++){
            temp=rd();
            cnt[temp]++;//存储temp所保护的城市数量 
            bomb[temp][cnt[temp]]=i;//指向当前所保护的城市 
        }
    }
}

void dijk(){
    memset(dis,0x3f,sizeof(dis));
    dis[1]=0;
    q.push((node){dis[1],1});//初始位置放入队列 
    while(!q.empty()){
        int index=q.top().id;
        int weight=q.top().dis;
        q.pop();
        if(v[index]==1) continue;//已访问的城市弹出 
        v[index]=1;
        for(int i=head[index];i;i=e[i].next){
            int y=e[i].tot,t=e[i].time;
            if(dis[y]>dis[index]+t){
                dis[y]=dis[index]+t;
                  if(boundary[y]==0)//如果不受保护入队 
                      q.push((node){dis[y],y});
            }
        }
        for(int i=1;i<=cnt[index];i++){//对当前城市所保护的进行轰炸 
            boundary[bomb[index][i]]--;
            dis[bomb[index][i]]=max(dis[index],dis[bomb[index][i]]);//到当前的时间和到要保护的城市的时间的最大值为更新后的到要保护的城市的时间 
            if(boundary[bomb[index][i]]==0)//不受保护后入队 
               q.push((node){dis[bomb[index][i]],bomb[index][i]});
        }
    }
}

int main(){
    n=rd();m=rd();
    int u,v,w;
    for(int i=1;i<=m;i++){
        u=rd();v=rd();w=rd();
        add(u,v,w);//加边 
    }
    Fbo();
    dijk();
    printf("%d\n",dis[n]);
}
