#include <bits/stdc++.h>
#define INF -100000000
using namespace std;
vector<int>AdjList[100];
int N,lvl1[100],lvl2[100];
void bfs(int s)
{
    queue<int>Q;
    Q.push(s);
    for(int i=0;i<N;i++) lvl1[i]=INF;
    lvl1[s]=0;
    while(!Q.empty()){
        int u=Q.front();
        Q.pop();
        for(int i=0;i<AdjList[u].size();i++){
            int v=AdjList[u][i];
            if(lvl1[v]==INF){
                lvl1[v]=lvl1[u]+1;
                Q.push(v);
            }
        }
    }
    return;
}
void bfs2(int s)
{
    queue<int>Q;
    Q.push(s);
    for(int i=0;i<N;i++) lvl2[i]=INF;
    lvl2[s]=0;
    while(!Q.empty()){
        int u=Q.front();
        Q.pop();
        for(int i=0;i<AdjList[u].size();i++){
            int v=AdjList[u][i];
            if(lvl2[v]==INF){
                lvl2[v]=lvl2[u]+1;
                Q.push(v);
            }
        }
    }
    return;
}
int main()
{
    int T,R,u,v,s,d;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        scanf("%d",&N);
        scanf("%d",&R);
        for(int i=1;i<=R;i++){
            scanf("%d %d",&u,&v);
            AdjList[u].push_back(v);
            AdjList[v].push_back(u);
        }
        scanf("%d %d",&s,&d);
        bfs(s);
        bfs2(d);
        int mx=INF;
        for(int i=0;i<N;i++){
            mx=max(mx,(lvl1[i]+lvl2[i]));
        }
        printf("Case %d: %d\n",t,mx);
        for(int i=0;i<N;i++) AdjList[i].clear();
    }
    return 0;
}
