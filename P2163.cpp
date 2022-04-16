#include<bits/stdc++.h>
using namespace std;
#define MAXN 500000
typedef long long ll;
int n,m;
struct y{
 int val,num;
}y_[MAXN];
int ans[4*MAXN+5];
int ranks[MAXN];

inline ll read(){
    char ch=getchar();ll x=0,f=1;
    while(ch<'0' || ch>'9') {
       if(ch=='-') f=-1;
         ch=getchar();
    }
    while(ch<='9' && ch>='0') {
       x=x*10+ch-'0';
       ch=getchar();
    }
    return x*f;
}

struct node{
    int x,y;
}t[MAXN+1];

struct nod{
    int x,y,id;
}a[5*MAXN];
int tr[2*MAXN+1];

int lowbit(int x){
    return x&-x;
}

void add(int x,int k){
   x++;
   while(x<=2*MAXN+1){
        tr[x]+=k;
        x+=lowbit(x);
    }
}

int sum(int x){
    int s=0;
    x++;
    while(x){
        s+=tr[x];
        x-=lowbit(x); 
    }
    return s;
}

bool cmpy(y a,y b){
    if(a.val==b.val) return a.num<b.num;
    else return a.val<b.val;
}
bool cmp(node a,node b){
    return a.x<b.x;
}
bool cmpp(nod a,nod b){
    return a.x<b.x;
}

int find(int x)// 2分查找找出离散化后的y
{
   int l = 1, r =n;
   if(x<y_[l].val) return 0;
   while(l<r)
   {
    int mid =(l+r+1)/2;
    if(y_[mid].val<=x)
      l=mid;
    else
      r=mid-1;
   }
   return l;
}

int main(){
    n=read(),m=read();
    for(int i=1;i<=n;i++){
        t[i].x=read(),t[i].y=read();
    }
    int cnt=0;
    for(int i=1;i<=m;i++){//询问矩阵拆成四个点
        int xa=read(),ya=read(),xb=read(),yb=read();
        cnt++;a[cnt].id=cnt;a[cnt].x=xb;a[cnt].y=yb;
        cnt++;a[cnt].id=cnt;a[cnt].x=xb;a[cnt].y=ya-1;
        cnt++;a[cnt].id=cnt;a[cnt].x=xa-1;a[cnt].y=yb;
        cnt++;a[cnt].id=cnt;a[cnt].x=xa-1;a[cnt].y=ya-1;
    }
    sort(t+1,t+n+1,cmp);
    sort(a+1,a+cnt+1,cmpp);
    for(int i=1;i<=n;i++){
        y_[i].val=t[i].y;
        y_[i].num=i;
    }
    sort(y_+1,y_+n+1,cmpy);//对y进行排序
    for(int i=1;i<=n;i++){
        ranks[y_[i].num]=i; 
    } 
    int now=1;
    int index;
    for(int i=1;i<=cnt;i++){//树状数组求逆序对
        while(t[now].x<=a[i].x && now<=n) {;
            index=ranks[now];
            add(index,1);
            now++;
        }
        index=find(a[i].y);
        ans[a[i].id]=sum(index);
    }
    for(int i=1;i<=cnt;i+=4){
        printf("%d\n",ans[i]-ans[i+1]-ans[i+2]+ans[i+3]);
    }
    return 0;
}
