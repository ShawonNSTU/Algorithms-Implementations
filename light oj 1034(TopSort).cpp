#include <bits/stdc++.h>
#define MAX 10001
using namespace std;
typedef vector<int> vi;
vi ts,AdjList[MAX];
bool visited[MAX];
void dfs(int u)
{
    visited[u]=1;
    for(int i : AdjList[u]){
        if(!visited[i]) dfs(i);
    }
    ts.push_back(u);
}
void Clear(int n)
{
    for(int i=1;i<=n;i++){
        AdjList[i].clear();
        visited[i]=0;
    }
    ts.clear();
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        int n,e,u,v,cnt=0;
        scanf("%d %d",&n,&e);
        for(int i=1;i<=e;i++){
            scanf("%d %d",&u,&v);
            AdjList[u].push_back(v);
        }
    /** Topological Sort **/
    memset(visited,0,sizeof(visited));
    for(int i=1;i<=n;i++){
        if(!visited[i]) dfs(i);
    }
    reverse(ts.begin(),ts.end());
    memset(visited,0,sizeof(visited));
    for(int i=0;i<ts.size();i++){
        if(!visited[ts[i]]){
            ++cnt;
            dfs(ts[i]);
          }
      }
      printf("Case %d: %d\n",t,cnt);
      Clear(n);
  }
    return 0;
}
