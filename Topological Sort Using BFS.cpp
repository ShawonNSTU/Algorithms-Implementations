#include <bits/stdc++.h>
#define MAX 1234567
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
vi TPS,AdjList[MAX];
int indegree[MAX],bfs_num[MAX];
void bfs2(int s)
{
    queue<int>Q;
    Q.push(s);
    bfs_num[s]=1;
    while(!Q.empty()){
        int u=Q.front();
        TPS.push_back(u);
        Q.pop();
        int sz=AdjList[u].size();
        for(int i=0;i<sz;i++){
            int v=AdjList[u][i];
            bfs_num[v]=1;
            indegree[v]--;
            if(indegree[v]==0) Q.push(v);
        }
    }
}
int main()
{
    int node,edge,u,v;
    scanf("%d %d",&node,&edge);
    memset(indegree,0,sizeof(indegree));
    memset(bfs_num,0,sizeof(bfs_num));
    for(int i=0;i<edge;i++){
        scanf("%d %d",&u,&v);
        AdjList[u].push_back(v);
        indegree[v]++;
    }
    for(int i=1;i<=node;i++){
        if(bfs_num[i]==0&&indegree[i]==0) bfs2(i);
    }
    int sz=TPS.size();
    for(int i=0;i<sz;i++) printf("%d ",TPS[i]);
}
