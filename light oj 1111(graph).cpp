#include <bits/stdc++.h>
using namespace std;
vector<int>road[10005],reach1,reach2,k;
int ii;
bool visited[1005];
void dfs(int src)
{
    visited[src]=1;
    if(!ii){
        reach1.push_back(src);
        reach2=reach1;
    }
    else{
        for(int l=0;l<(int)reach1.size();l++){
            if(src==reach1[l]) reach2.push_back(src);
        }
    }
    for(int i=0;i<(int)road[src].size();i++){
        int u=road[src][i];
        if(!visited[u]) dfs(u);
    }
}
int main()
{
    int u,v,T,K,N,M;
    cin>>T;
    for(int i=1;i<=T;i++){
        k.clear();
        cin>>K>>N>>M;
        for(int j=0;j<K;j++){
            cin>>u;
            k.push_back(u);
        }
        for(int j=0;j<=N+1;j++) road[j].clear();
        for(int j=0;j<M;j++){
            cin>>u>>v;
            road[u].push_back(v);
        }
        for(ii=0;ii<K;ii++){
            memset(visited,0,sizeof(visited));
            dfs(k[ii]);
            reach1=reach2;
            if(ii!=K-1) reach2.clear();
        }
        cout<<"Case "<<i<<": "<<reach2.size()<<endl;
        reach2.clear();
        reach1.clear();
    }
    return 0;
}
