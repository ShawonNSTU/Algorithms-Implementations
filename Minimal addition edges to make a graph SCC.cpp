#include <bits/stdc++.h>
using namespace std;
const int MAX=10005;
typedef vector<int> vi;
vi S,AdjList[MAX];
int dfs_num[MAX],dfs_low[MAX],visited[MAX],belong[MAX];
int flag[MAX],in[MAX],out[MAX];
int numSCC,dfsNumberCounter,SCC;
void tarjanSCC(int u)
{
    dfs_low[u]=dfs_num[u]=++dfsNumberCounter;
    S.push_back(u);
    visited[u]=1;
    for(int j=0;j<(int)AdjList[u].size();j++){
        int v=AdjList[u][j];
        if(dfs_num[v]==0) tarjanSCC(v);
        if(visited[v]==1)
            dfs_low[u]=min(dfs_low[u],dfs_low[v]);
    }
    if(dfs_low[u]==dfs_num[u]){                  // if this is a root (start) of an SCC
        while(1){
            int v=S.back(); S.pop_back();visited[v]=0;
            belong[v]=SCC;
            if(u==v) break;
        }
        SCC++;
    }
}
void dfs2(int u)
{
    flag[u]=1;
    for(int i=0;i<AdjList[u].size();i++){
        int v=AdjList[u][i];
        if(belong[u]!=belong[v]){
            in[belong[v]]++;
            out[belong[u]]++;
        }
        if(flag[v]==0) dfs2(v);
    }
}
void Clear(int N)
{
    for(int i=1;i<=N+2;i++){
        dfs_num[i]=0; dfs_low[i]=0; visited[i]=0;
        belong[i]=0; flag[i]=0;
        in[i]=0; out[i]=0;
        AdjList[i].clear();
    }
}
int main()
{
    int N,E,u,v;
    scanf("%d %d",&N,&E);
    Clear(N);
    for(int i=1;i<=E;i++){
        scanf("%d %d",&u,&v);
        AdjList[u].push_back(v);
    }
    dfsNumberCounter=numSCC=SCC=0;
    for(int i=1;i<=N;i++){
        if(dfs_num[i]==0) tarjanSCC(i);
    }
    for(int i=1;i<=N;i++){
        if(flag[i]==0){
            dfs2(i);
        }
    }
    int mIn,mOut;
    mIn=mOut=0;
    for(int i=0;i<SCC&&SCC>1;i++){
        if(in[i]==0) ++mOut;
        if(out[i]==0) ++mIn;
    }
    printf("%d\n",max(mOut,mIn));
    return 0;
}
