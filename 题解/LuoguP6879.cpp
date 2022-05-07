#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=202;
int n,L,ans,a[N],t[N],f[N][N][N][2];
signed main(){
	scanf("%lld%lld",&n,&L);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	a[n+1]=L;
	for(int i=1;i<=n;i++)scanf("%lld",&t[i]);
	memset(f,0x3f,sizeof f);
	f[0][0][0][0]=f[0][0][0][1]=0;
	for(int l=0;l<=n;l++)
		for(int r=0;r<=n;r++){
			if(l+r>=n)break;
			for(int k=0;k<=n;k++){
			    int tmp=f[l][r][k][0];
			    if(tmp<=1e13){
					   f[l+1][r][k+(t[n-l]>=tmp+a[n-l+1]-a[n-l])][0]=min(f[l+1][r][k+(t[n-l]>=tmp+a[n-l+1]-a[n-l])][0],tmp+a[n-l+1]-a[n-l]);
					   f[l][r+1][k+(t[r+1]>=tmp+L-a[n-l+1]+a[r+1])][1]=min(f[l][r+1][k+(t[r+1]>=tmp+L-a[n-l+1]+a[r+1])][1],tmp+L-a[n-l+1]+a[r+1]);
				}
				tmp=f[l][r][k][1];
				if(tmp<=1e13){
					   f[l][r+1][k+(t[r+1]>=tmp+a[r+1]-a[r])][1]=min(f[l][r+1][k+(t[r+1]>=tmp+a[r+1]-a[r])][1],tmp+a[r+1]-a[r]);
					   f[l+1][r][k+(t[n-l]>=tmp+L-a[n-l]+a[r])][0]=min(f[l+1][r][k+(t[n-l]>=tmp+L-a[n-l]+a[r])][0],tmp+L-a[n-l]+a[r]);
				}
			}
	    }
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			for(int k=0;k<=n;k++)if(min(f[i][j][k][0],f[i][j][k][1])<1e15)ans=max(ans,k);
	printf("%lld\n",ans);
	return 0;
}
