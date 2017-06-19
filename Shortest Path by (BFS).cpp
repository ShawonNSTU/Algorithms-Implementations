#include <bits/stdc++.h>
using namespace std;
bool visited[100];
vector<int>edges[100];
int p[100];
void bfs(int strt,int des)
{
    queue<int>Q;
    Q.push(strt);
    visited[strt]=1;
    while(!Q.empty()){
        int u=Q.front();
        Q.pop();
        for(int i=0;i<edges[u].size();i++){
            if(visited[edges[u][i]]!=1){
                int v=edges[u][i];
                visited[v]=1;
                p[v]=u;
                Q.push(v);
            }
            if(visited[des]==1) break;
        }
    }
    if(visited[des]!=1){
        cout<<"No path from start to destination";
        return;
    }
    vector<int>path;
    path.push_back(des);
    int backtrack=des;
    while(backtrack!=strt){
        backtrack=p[backtrack];
        path.push_back(backtrack);
    }
    reverse(path.begin(),path.end());
    for(int i=0;i<path.size();i++) cout<<path[i]<<" ";
    return ;
}
int main()
{
    int n,e,strt,des,u,v;
    cin>>n>>e;
    for(int i=1;i<=e;i++){
        cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    cin>>strt>>des;
    bfs(strt,des);
    return 0;
}
