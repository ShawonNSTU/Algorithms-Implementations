#include <bits/stdc++.h>
#define MAX_V 40
#define INF 1000000000
using namespace std;
typedef vector<int> vi;

int res[MAX_V][MAX_V], max_flow, f, s, t;
vi p;

void augmentPath(int v,int minEdge)
{
  if(v == s){
    f = minEdge;
    return;
  }
  else if(p[v] != -1){
    augmentPath(p[v],min(minEdge,res[p[v]][v]));
    res[p[v]][v] -= f;
    res[v][p[v]] += f;
  }
}
int main()
{
    int V,k,vertex,weight;
    scanf("%d %d %d",&V,&s,&t);
    memset(res,0,sizeof res);
    for(int i=0; i<V; i++){
        scanf("%d",&k);
        for(int j=0; j<k; j++){
            scanf("%d %d",&vertex,&weight);
            res[i][vertex] = weight;
        }
    }
    max_flow = 0;
    while(1){
        f = 0;
        vi dist(MAX_V,INF);
        dist[s] = 0;
        queue<int> q;
        q.push(s);
        p.assign(MAX_V,-1);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            if(u == t) break;
            for(int v=0; v<MAX_V; v++){
                if(res[u][v] > 0 && dist[v] == INF){
                    dist[v] = dist[u] + 1;
                    q.push(v);
                    p[v] = u;
                }
            }
        }
    augmentPath(t,INF);
    if(f == 0) break;
    max_flow += f;
  }
  printf("%d\n",max_flow);
  return 0;
}
