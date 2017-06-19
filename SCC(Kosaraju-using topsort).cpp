#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
const int MAX=123456;
stack<int>stk;
vi AdjList[MAX],RevList[MAX],Component[MAX];
int visited[MAX],mark;
void dfs(int u)
{
    visited[u]=1;
    for(int i=0;i<(int)AdjList[u].size();i++){
        int v=AdjList[u][i];
        if(visited[v]==0) dfs(v);
        }
        stk.push(u);
 }
void dfs2(int u,int mark)
{
    Component[mark].push_back(u);           //save the nodes of the new component
    visited[u]=1;
    for(int i=0;i<(int)RevList[u].size();i++){
        int v=RevList[u][i];
        if(visited[v]==0) dfs2(v,mark);
        }
}
int main()
{
    mark = 0; /* mark is to name the component */
    int n,e,u,v;
    scanf("%d %d",&n,&e);
    for(int i=1;i<=e;i++){
        scanf("%d %d",&u,&v);
        AdjList[u].push_back(v);
        RevList[v].push_back(u);
    }
    //         topological sort
    memset(visited,0,sizeof(visited));
    for(int i=1;i<=n;i++){
        if(visited[i]==0) dfs(i);
         }
    memset(visited,0,sizeof(visited));
    while(!stk.empty()){
        int u=stk.top();
        stk.pop();
        if(visited[u]==0){
            mark = mark+1;              //A new component found, it will be identified by mark
            dfs2(u,mark);
              }
        }
    for(int i=1;i<=mark;i++){
            for(int j=0;j<(int)Component[i].size();j++) cout<<Component[i][j]<<" ";
            printf("\n");
    }
    return 0;
}
