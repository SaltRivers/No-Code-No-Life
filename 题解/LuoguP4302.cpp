#include <bits/stdc++.h>
using namespace std;
string st;
int n,m[110],dp[110][110];

bool check(int l,int r,int len){
    for(int i=l;i<=r;i++)
        if(st[i]!=st[(i-l)%len+l])return false;
    return true;
}

int main(){
	cin>>st;
    n=st.size();
    st=' '+st;
    for(int i=1;i<=9;i++)m[i]=1;
    for(int i=10;i<=99;i++)m[i]=2;
    m[100]=3;
    memset(dp,0x3f,sizeof(dp));
	for(int i=1;i<=n;i++) dp[i][i]=1;
	 for(int l=2;l<=n;l++){
        for(int i=1,j=i+l-1;j<=n;i++,j++){
            for(int k=i;k<j;k++){
            	dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
			}
			for(int k=i;k<j;k++){
            	int len=k-i+1;
            	if(l%len!=0) continue;
            	if(check(i,j,len)) dp[i][j]=min(dp[i][j],dp[i][k]+2+m[l/len]);
			}
	    }
	}
	printf("%d",dp[1][n]);
    return 0;
} 
