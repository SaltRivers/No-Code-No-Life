BFS：
bool spfa(){   
     q.push(1);
     vis[1]=1;
   while(!q.empty()){
   	int x=q.front();q.pop();
   	vis[x]=0;
   	for(reg int i=head[x];i;i=edge[i].next){
   		int y=edge[i].to;
   		if(dis[y]>dis[x]+edge[i].cost){
   			dis[y]=dis[x]+edge[i].cost;
   			cnt[y]=cnt[x]+1;
   			if(cnt[y]>=n) return 1;//包含的边数 
   			if(!vis[y]){
   				cnt[y]++;
   				/*if(cnt[y]>=n) return 1; */
   				q.push(y);
   				vis[y]=1;
   			}
   		}
   	}
   }
   return 0;
}

DFS：
bool check(int k)
{
	vis[k]=1;
	for(int i=head[k];i;i=edge[i].next)
	{
		int y=edge[i].to;
		if(dis[k]+edge[i].cost<dis[y]){
			dis[y]=edge[i].cost+dis[k];
			if(!vis[y])
			{
				if(check(y))//前面搜到了负环 
					return 1;
			}
			else return 1;//一次深搜中搜了一个点两次,则存在负环。 
		}
	}
	vis[k]=0;
	return 0;
}

