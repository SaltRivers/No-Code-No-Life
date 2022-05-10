#include<iostream>
#include<cstring>
#define MAXN 205
using namespace std;

int alter(char c){
	if(c=='W') return 1;
	if(c=='I') return 2;
	if(c=='N') return 3;
	if(c=='G') return 4;
}

int st[5],dp[MAXN][MAXN][5];
bool can[5][5][5];
string s,g;

int main(){
	for(int i=1;i<=4;i++) scanf("%d",&st[i]);
	for(int i=1;i<=4;i++) 
	{
        for(int j=1;j<=st[i];j++) 
		{
            cin>>g;
            can[i][alter(g[0])][alter(g[1])]=true;
        }
    }
    cin>>s;
    int length=s.size();
    s=" "+s;
    for(int i=1;i<=length;i++) dp[i][i][alter(s[i])]=1;
    for(int len=2;len<=length;len++)
         for(int l=1;l<=length-len+1;l++){
         	int r=l+len-1;
         	for(int k=l;k<=r-1;k++){
         		for(int x=1;x<=4;x++)
         		 for(int y=1;y<=4;y++)
				  for(int z=1;z<=4;z++)
				   if(dp[l][k][x]&&dp[k+1][r][y]&&can[z][x][y]) dp[l][r][z]=1; 
			 }
		 }
	bool f=false;	 
	if(dp[1][length][1]) {f=true;printf("W");}
    if(dp[1][length][2]) {f=true;printf("I");}
    if(dp[1][length][3]) {f=true;printf("N");}
    if(dp[1][length][4]) {f=true;printf("G");}
    if(!f) printf("The name is wrong!");	 
} 
