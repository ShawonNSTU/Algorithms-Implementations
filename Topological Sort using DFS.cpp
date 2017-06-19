#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
vi ts,AdjList[1000];
bool dfs_num[1000];
void dfs2(int u)
{
    dfs_num[u]=1;
    for(int j=0;j<AdjList[u].size();j++){
        int v=AdjList[u][j];
        if(dfs_num[v]==0) dfs2(v);
    }
    ts.push_back(u);
}
int main()
{
    int node,edge,u,v;
    scanf("%d %d",&node,&edge);
    for(int i=0;i<edge;i++){
        scanf("%d %d",&u,&v);
        AdjList[u].push_back(v);
    }
    memset(dfs_num,0,sizeof(dfs_num));
    for(int i=1;i<=node;i++){
        if(dfs_num[i]==0) dfs2(i);
    }
    reverse(ts.begin(),ts.end());
    for(int i=0;i<ts.size();i++) printf("%d ",ts[i]);
}
