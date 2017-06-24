#include <bits/stdc++.h>
#define mx 50005
using namespace std;
typedef vector<int> vi;
vi ts,AdjList[mx],RevList[mx];
int SCC[mx],in[mx],out[mx];
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
void Count(int u)
{
    visited[u]=1;
    for(int i=0;i<(int)AdjList[u].size();i++){
        int v=AdjList[u][i];
        if(SCC[u]!=SCC[v]){
            in[SCC[v]]++;
            out[SCC[u]]++;
        }
        if(!visited[v]) Count(v);
    }
}
void Clear(int n)
{
    for(int i=1;i<=n;i++){
        AdjList[i].clear();
        RevList[i].clear();
        SCC[i]=out[i]=in[i]=0;
    }
    ts.clear();
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        int n,m,u,v,mark=0;
        scanf("%d %d",&n,&m);
        for(int i=1;i<=m;i++){
            scanf("%d %d",&u,&v);
            AdjList[u].push_back(v);
            RevList[v].push_back(u);
        }
        memset(visited,0,sizeof(visited));
        for(int i=1;i<=n;i++){
            if(!visited[i]) dfs(i);
        }
        reverse(ts.begin(),ts.end());
        memset(visited,0,sizeof(visited));
        for(int i=0;i<(int)ts.size();i++){
            if(!visited[ts[i]]){
                ++mark;
                findSCC(ts[i],mark);
            }
        }
        memset(visited,0,sizeof(visited));
        for(int i=1;i<=n;i++){
            if(!visited[i]) Count(i);
        }
        int foo,curr;
        foo=curr=0;
        for(int i=1;i<=mark&&mark>1;i++){
            if(in[i]==0) ++foo;
            if(out[i]==0) ++curr;
        }
        printf("Case %d: %d\n",t,max(foo,curr));
        Clear(n);
    }
    return 0;
}
