#include <bits/stdc++.h>
#define MAX_NODE 100005
#define INF 1000000000
using namespace std;
vector<int>AdjList[MAX_NODE],lca_dfs_list;
int lca_dfs_used[MAX_NODE],lca_height[MAX_NODE],dfs_count[MAX_NODE];
int curr[MAX_NODE];
void DFS(int v,int h=1)
{
    lca_dfs_used[v] = true;
    lca_height[v] = h;
    lca_dfs_list.push_back(lca_height[v]);
    for(int i : AdjList[v]){
        if(!lca_dfs_used[i]){
            dfs_count[i]++;
            DFS(i,h+1);
            lca_dfs_list.push_back(lca_height[v]);
        }
    }
    lca_dfs_used[v] = false;
}
int LIS()
{
    int length = 0;
    int n = lca_dfs_list.size();
    int dp[n+1];
    dp[0] = -INF;
    for(int i=0; i<n; i++){
        dp[i+1] = INF;
    }
    for(int i=0; i<n; i++){
        int j = upper_bound(dp, dp+n+1, lca_dfs_list[i]) - dp;
        if(dp[j-1] < lca_dfs_list[i] && lca_dfs_list[i] < dp[j]){
            dp[j] = lca_dfs_list[i];
            length = max(length,j);
        }
    }
    return length;
}
int main()
{
    int n,e;
    scanf("%d %d",&n,&e);
    for(int i=1; i<=e; i++){
        int u,v;
        scanf("%d %d",&u,&v);
        AdjList[u].push_back(v);
        curr[v]++;
    }
    for(int i=1; i<=n; i++){
        if(dfs_count[i] < 1 && curr[i] == 0){
            dfs_count[i]++;
            DFS(i);
        }
    }
    printf("%d\n",LIS());
    return 0;
}
