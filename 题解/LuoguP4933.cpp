#include<iostream>
#include<cstring>
#define mod  998244353
#define MAXN 1005
#define MAXV 40005
using namespace std;

int read(){
    int x=0,f=1;char ch=getchar();
    while (ch<'0' || ch>'9'){if (ch=='-')f=-1;ch=getchar();}
    while ('0'<=ch && ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
    return x*f;
}
int ans,a[MAXN],dp[MAXN][MAXV],vis[MAXN][MAXV];

void start(int nowi){
	for(int i=nowi-1;i>0;i--){
		if(!vis[i][a[nowi]-a[i]+20000]){
            dp[i][a[nowi]-a[i]+20000]++;
			vis[i][a[nowi]-a[i]+20000]=1;		
		}
		ans=(long long)(ans+dp[i][a[nowi]-a[i]+20000])%mod;
		dp[nowi][a[nowi]-a[i]+20000]=(long long)(dp[nowi][a[nowi]-a[i]+20000]+dp[i][a[nowi]-a[i]+20000])%mod;
	}
}

int main(){
	int n;
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	memset(vis,0,sizeof(vis[MAXN]));
	for(int i=1;i<=n;i++)
	    start(i);
	printf("%d",ans+n);   	
} 
