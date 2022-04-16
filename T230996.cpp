#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
#define N 10
int row,col;//输入的行与列 
int vector[N][N];//输入的棋盘 
int occupy[N][N];//判断一次消除中该点是否被消除过 
typedef struct {
    int row,col;
}message;//记录点的信息（行与列） 

stack<message> nextsearch(int i,int j,stack<message> T)//对该点四周进行试探{
    occupy[i][j]=1;//对此棋标记为占领 
    if(vector[i][j]==vector[i][j+1]&&j+1<col&&occupy[i][j+1]==0){
       message right;
       right.row=i;
       right.col=j+1;
       T.push(right);
       T=nextsearch(i,j+1,T);   
    }//向右试探 
    if(vector[i][j]==vector[i][j-1]&&j>0&&occupy[i][j-1]==0)//记得下一个点不要越界{
       message left;
       left.row=i;
       left.col=j-1;
       T.push(left);
       T=nextsearch(i,j-1,T);   
    }//向左试探 
    if(vector[i][j]==vector[i+1][j]&&i+1<row&&occupy[i+1][j]==0){
       message up;
       up.row=i+1;
       up.col=j;
       T.push(up);
       T=nextsearch(i+1,j,T);   
    }//想上试探 
    if(vector[i][j]==vector[i-1][j]&&i>0&&occupy[i-1][j]==0){
       message down;
       down.row=i-1;
       down.col=j;
       T.push(down);
       T=nextsearch(i-1,j,T);   
    }//向下试探 
    return T;
}

void search(int i,int j){
      stack<message> T;//将符合的器的信息放入栈中 
      message cur;
      cur.col=j;
      cur.row=i;
      T.push(cur);//第一格棋的信息首先压入栈中 
      T=nextsearch(i,j,T);
      int sum=T.size();
      if(sum>=3){//栈的大小大于3才能输出 
        for(int i=1;i<=sum;i++){
            vector[T.top().row][T.top().col]=0;
            T.pop();
          }
    }
}

int main(){
    cin>>row>>col;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++) cin>>vector[i][j];
    } 
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++) {
            if(vector[i][j]!=0) {
            memset(occupy,0,sizeof(occupy));//一次判断中记得把上次占领的信息清零 
            search(i,j);
        }
        }
    } 
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++) cout<<vector[i][j]<<" ";
        if(i!=row-1) cout<<endl;
    }
}
