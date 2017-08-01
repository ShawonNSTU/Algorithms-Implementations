#include <bits/stdc++.h>
#define MAX_NODE 50005
using namespace std;
vector<int>AdjList[MAX_NODE];
vector<int>lca_height,lca_dfs_list,lca_first,lca_tree;
vector<bool>lca_dfs_used;
map<pair<int,int> , int >weight;
void LCA_DFS(int v,int h=0)
{
    lca_dfs_used[v] = true;
    lca_height[v] = h;
    lca_dfs_list.push_back(v);
    for(int i : AdjList[v]){
        if(!lca_dfs_used[i]){
            LCA_DFS(i,h+weight[{v,i}]);
            lca_dfs_list.push_back(v);
        }
    }
}
void LCA_BUILD_TREE(int node,int b,int e)
{
    if(b == e){
        lca_tree[node] = lca_dfs_list[b];
        return;
    }
    int Left = node << 1;
    int Right = (node << 1) + 1;
    int mid = (b + e) >> 1;
    LCA_BUILD_TREE(Left,b,mid);
    LCA_BUILD_TREE(Right,mid+1,e);
    if(lca_height[lca_tree[Left]] < lca_height[lca_tree[Right]]){
        lca_tree[node] = lca_tree[Left];
    }
    else{
        lca_tree[node] = lca_tree[Right];
    }
}
void LCA_PREPARE(int n,int root)
{
    lca_height.resize(n);
    lca_dfs_used.assign(n,0);
    lca_dfs_list.reserve(n*2);
    LCA_DFS(root);
    int m = (int) lca_dfs_list.size();
    lca_tree.assign(m * 4 + 1, -1);
    LCA_BUILD_TREE(1,0,m-1);
    lca_first.assign(n,-1);
    for(int i=0; i<m; i++){
        int v = lca_dfs_list[i];
        if(lca_first[v] == -1){
            lca_first[v] = i;
        }
    }
}
int LCA_TREE_MIN(int node,int b,int e,int i,int j)
{
    if(i > e || j < b) return -1;
    if(b >= i && e <= j) return lca_tree[node];
    int Left = node << 1;
    int Right = (node << 1) + 1;
    int mid = (b + e) >> 1;
    int p1 = LCA_TREE_MIN(Left,b,mid,i,j);
    int p2 = LCA_TREE_MIN(Right,mid+1,e,i,j);
    if(p1 == -1) return p2;
    else if(p2 == -1) return p1;
    else return lca_height[p1] < lca_height[p2] ? p1 : p2;
}
int LCA(int u,int v)
{
    int left = lca_first[u];
    int right = lca_first[v];
    if(left > right){
        swap(left,right);
    }
    return LCA_TREE_MIN(1,0,(int)lca_dfs_list.size()-1,left,right);
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n-1; i++){
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        AdjList[u].push_back(v);
        AdjList[v].push_back(u);
        weight[{u,v}] = w;
        weight[{v,u}] = w;
    }
    int root = 0;
    LCA_PREPARE(n,root);
    int Q;
    scanf("%d",&Q);
    while(Q--){
        int v1,v2;
        scanf("%d %d",&v1,&v2);
        int v = LCA(v1,v2);
        int lca = lca_height[v];
        int l = lca_height[v1];
        int r = lca_height[v2];
        printf("%d\n",(l-lca)+(r-lca));
    }
    return 0;
}
