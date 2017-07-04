#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
vi AdjList[50005];
bool visited[50005];
int dp[50005],finish,idx,mx;
void dfs(int u)
{
    ++finish;
    visited[u]=1;
    for(int i : AdjList[u]){
        if(!visited[i]) dfs(i);
    }
    dp[u]= ++finish;
    visited[u]=0;
    if(dp[u]>mx){
        mx=dp[u];
        idx=u;
    }
    else if(dp[u]==mx){
        idx=min(idx,u);
    }
}
int main()
{
    int T,n,u,v;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        mx=0,idx=1;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d %d",&u,&v);
            AdjList[u].push_back(v);
        }
        memset(visited,0,sizeof(visited));
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            finish=0;
            if(!dp[i]) dfs(i);
        }
        printf("Case %d: %d\n",t,idx);
        for(int i=0;i<=n+1;i++) AdjList[i].clear();
    }
    return 0;
}
