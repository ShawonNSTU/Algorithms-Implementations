#include <bits/stdc++.h>
#define ll long long
#define MAX_NODE 1234567
using namespace std;
typedef pair<ll,ll> pll;
ll d[MAX_NODE],sd[MAX_NODE];
map<ll,vector<ll> >ed,cost;
map<ll,vector<ll> >::iterator it;
void dijk(ll src,ll dst)
{
    priority_queue<pll,vector<pll>,greater<pll> >pq;
    pq.push(pll(0,src));
    d[src]=0;
    while(!pq.empty()){
        pll temp=pq.top();
        pq.pop();
        ll u=temp.second;
        ll dis=temp.first;
        for(ll i=0;i<ed[u].size();i++){
            ll v=ed[u][i];
            if(dis+cost[u][i]<d[v]){
                sd[v]=d[v];
                d[v]=dis+cost[u][i];
                pq.push(pll(d[v],v));
            }
            else if(dis+cost[u][i]<sd[v]&&dis+cost[u][i]!=d[v]){
                sd[v]=dis+cost[u][i];
                pq.push(pll(sd[v],v));
            }
        }
    }
}
int main()
{
    ll n,m,u,v,w,t;
    cin>>t;
    for(ll k=1;k<=t;k++){
        cin>>n>>m;
        for(int i=1;i<=n;i++) d[i]=sd[i]=LLONG_MAX;
        ed.clear();
        cost.clear();
        for(int i=1;i<=m;i++){
            cin>>u>>v>>w;
            ed[u].push_back(v);
            ed[v].push_back(u);
            cost[u].push_back(w);
            cost[v].push_back(w);
        }
        dijk(1,n);
        printf("Case %lld: %lld\n",k,sd[n]);
    }
    return 0;
}
