#include<iostream>
#include<cstring>
using namespace std;
#define N 100
#include<map>

int findTheLongestSubstring(string s) {
        int res = 0,dis = 0;
        /*前缀区间定义，00000代表五元音全偶*/
        int bitArray = 0;
        map<int, int> bit_to_site;
        map<int, int>::iterator iter;
        bit_to_site.insert({0,-1});
        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            switch(c){
                case 'a': bitArray ^= 1; break;
                case 'e': bitArray ^= 2; break;
                case 'i': bitArray ^= 4; break;
                case 'o': bitArray ^= 8; break;
                case 'u': bitArray ^= 16; break;
                default:break;
            }
            iter = bit_to_site.find(bitArray);
            if(iter == bit_to_site.end()){
                bit_to_site.insert({bitArray, i});
            }
            dis = i - bit_to_site[bitArray];
            res = max(dis,res);
        }
        return res;
    }

int main(){
    string s;
    getline(cin,s);
    int res=findTheLongestSubstring(s);
    cout<<res;
} 
ver 1.0更新（自己写的）：

将状态由二进制转换为十进制，将状态作为下标，数组中存储最小状态的位置。

#include<iostream>
#include<cstring>
using namespace std;
#define N 100

int findTheLongestSubstring(string s) {
     int length=s.size();
     int res=0;
     int state[32]; 
     int sum[5];
     int dis;
     memset(state,0,sizeof(state));
     memset(sum,0,sizeof(sum));
     state[0]=-1;
     for(int i=0;i<length;i++){
        char c = s[i];
         switch(c){
                case 'a': sum[0]=(sum[0]+1)%2; break;//0状态为偶，1状态为奇 
                case 'e': sum[1]=(sum[1]+1)%2; break;
                case 'i': sum[2]=(sum[2]+1)%2; break;
                case 'o': sum[3]=(sum[3]+1)%2; break;
                case 'u': sum[4]=(sum[4]+1)%2; break;
                default:break;
            }
            int index=sum[0]*1+sum[1]*2+sum[2]*4+sum[3]*8+sum[4]*16;//二进制向十进制转换成数组的下标 
            if(state[index]==0) state[index]=i;
            else{
                dis=i-state[index];
                res=max(dis,res);
            }
     }
     return res; 
} 

int main(){
    string s;
    getline(cin,s);
    int res=findTheLongestSubstring(s);
    cout<<res;
} 
