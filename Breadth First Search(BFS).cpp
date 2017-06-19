#include <bits/stdc++.h>
using namespace std;
bool visited[100];
vector<int>edges[100];
void bfs(int u)
{
    queue<int>Q;
    Q.push(s);
    visited[s]=1;
    while(!Q.empty()){
        int u=Q.front();
        cout<<u<<" ";
        Q.pop();
        for(int i=0;i<edges[u].size();i++){
            if(visited[edges[u][i]]!=1){
                int v=edges[u][i];
                visited[v]=1;
                Q.push(v);
            }
        }
    }
}
int main()
{
    int n,e,u,v,start;
    cin>>n>>e;
    for(int i=1;i<=e;i++){
        cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u); // used for undirected graph. . .
    }
    cin>>start;
    bfs(start);
    return 0;
}
