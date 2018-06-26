#include <bits//stdc++.h>
#define MAXN 1000
using namespace std;
vector<int> AdjList[MAXN];
bool vis[MAXN];
int timer, dis[MAXN], low[MAXN];
set<int>AP;
void dfs(int u,int parent = -1)
{
    vis[u] = true;
    dis[u] = low[u] = timer++;
    int child = 0;
    for(int i=0; i<AdjList[u].size(); i++){
        int v = AdjList[u][i];
        if(v == parent)  continue;
        if(vis[v]) low[u] = min (low[u],dis[v]);
        else{
            dfs(v,u);
            ++child;
            low[u] = min (low[u],low[v]);
            if(low[v] >= dis[u] && parent != -1) AP.insert(u);   // u is articulation point
            if(low[v] > dis[u]){
                cout<<u<<" "<<v<<endl;
            }
        }
    }
    if(parent == -1 && child > 1) AP.insert(u);                 // u is articulation point
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int p=1; p<=m; p++){
        int a, b;
        scanf("%d %d",&a,&b);
        AdjList[a].push_back(b);
        AdjList[b].push_back(a);
    }
    timer = 0;
    for(int i=1; i<=n; ++i) vis[i] = false;
    dfs(1);
    for(auto i = AP.begin(); i != AP.end(); i++) cout<<*i<<endl;
    return 0;
}
