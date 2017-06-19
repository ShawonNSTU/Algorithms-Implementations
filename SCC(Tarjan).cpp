#include <bits/stdc++.h>
using namespace std;
const int MAX=123456;
typedef vector<int> vi;
vi dfs_num,dfs_low,S,visited,AdjList[MAX];
int numSCC,dfsNumberCounter;
void tarjanSCC(int u)
{
    dfs_low[u]=dfs_num[u]=dfsNumberCounter++;               // dfs_low[u] <= dfs_num[u]
    S.push_back(u);                                 // stores u in a vector based on order of visitation
    visited[u]=1;
    for(int j=0;j<(int)AdjList[u].size();j++){
        int v=AdjList[u][j];
        if(dfs_num[v]==0) tarjanSCC(v);
        if(visited[v]==1)                               // condition for update
            dfs_low[u]=min(dfs_low[u],dfs_low[v]);
    }
    if(dfs_low[u]==dfs_num[u]){                         // if this is a root (start) of an SCC
        printf("SCC %d: ",++numSCC);                    // this part is done after recursion
        while(1){
            int v=S.back(); S.pop_back();visited[v]=0;
            printf("%d ",v);
            if(u==v) break;
        }
        printf("\n");
    }
}
int main()
{
    int N,E,u,v;
    scanf("%d %d",&N,&E);
    for(int i=1;i<=E;i++){
        scanf("%d %d",&u,&v);
        AdjList[u].push_back(v);
    }
    dfs_num.assign(N,0); dfs_low.assign(N,0); visited.assign(N,0);
    dfsNumberCounter=numSCC=0;
    for(int i=0;i<N;i++){
        if(dfs_num[i]==0) tarjanSCC(i);
    }
}

/*
8 9
0 1
5 7
6 4
3 2
7 6
2 1
4 5
1 3
3 4
*/
