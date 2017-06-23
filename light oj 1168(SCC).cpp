#include <bits/stdc++.h>
#define mx 1000
using namespace std;
typedef vector<int> vi;
vi ts,AdjList[mx],RevList[mx];
int SCC[mx],out[mx];
bool visited[mx];
void dfs(int u)
{
    visited[u]=1;
    for(int i=0;i<(int)AdjList[u].size();i++){
        int v=AdjList[u][i];
        if(!visited[v]) dfs(v);
    }
    ts.push_back(u);
}
void findSCC(int u,int mark)
{
    SCC[u]=mark;
    visited[u]=1;
    for(int i=0;i<(int)RevList[u].size();i++){
        int v=RevList[u][i];
        if(!visited[v]) findSCC(v,mark);
    }
}
void Outdegree_Count(int u)
{
    visited[u]=1;
    for(int i=0;i<(int)AdjList[u].size();i++){
        int v=AdjList[u][i];
        if(SCC[u]!=SCC[v]) out[SCC[u]]++;
        if(!visited[v]) Outdegree_Count(v);
    }
}
void Clear()
{
    for(int i=0;i<mx;i++){
        AdjList[i].clear();
        RevList[i].clear();
        SCC[i]=out[i]=0;
    }
    ts.clear();
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        int n,k,u,v,mark=0;
        vi node;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&k);
            for(int j=1;j<=k;j++){
                scanf("%d %d",&u,&v);
                AdjList[u].push_back(v);
                RevList[v].push_back(u);
                node.push_back(u);
                node.push_back(v);
            }
            sort(node.begin(),node.end());
        }
        memset(visited,0,sizeof(visited));
        int cnt=0;
        for(int i=0;i<(int)node.size();i++){
            if(!visited[node[i]]){ ++cnt; dfs(node[i]); }
        }
        if(cnt>1){
            printf("Case %d: ",t);
            printf("NO\n");
            Clear();
            continue;
        }
        memset(visited,0,sizeof(visited));
        reverse(ts.begin(),ts.end());
        for(int i=0;i<(int)ts.size();i++){
            if(!visited[ts[i]]){
                ++mark;
                findSCC(ts[i],mark);
            }
        }
        memset(visited,0,sizeof(visited));
        for(int i=0;i<(int)node.size();i++){
            if(!visited[node[i]]) Outdegree_Count(node[i]);
        }
        int one=0,zero=0;
        for(int i=1;i<=mark;i++){
            if(out[i]==1) ++one;
            else if(out[i]==0) ++zero;
        }
        printf("Case %d: ",t);
        if(one==mark-1 and zero==1 and SCC[0]>0) printf("YES\n");
        else printf("NO\n");
        Clear();
    }
    return 0;
}
