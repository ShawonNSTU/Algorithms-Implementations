#include <bits/stdc++.h>
#define MAX 100005
using namespace std;
int arr[MAX];
int tree[MAX*4];
void update(int node,int b,int e,int i,int newvalue)
{
    if(i>e||i<b) return;                                       // বাইরে চলে গিয়েছে
    if(b==e){                                                 // লিফ নোড
        tree[node]=newvalue;
        return;
    }
    int Left=node<<1;                                          // আরো ভাঙতে হবে
    int Right=(node<<1)+1;
    int mid=(b+e)/2;
    update(Left,b,mid,i,newvalue);
    update(Right,mid+1,e,i,newvalue);
    tree[node]=tree[Left]+tree[Right];
}
int query(int node,int b,int e,int i,int j)
{
    if(i>e||j<b) return 0;                                    //  বাইরে চলে গিয়েছে
    if(b>=i&&e<=j) return tree[node];                         // রিলেভেন্ট সেগমেন্ট
    int Left=node<<1;                                          // আরো ভাঙতে হবে
    int Right=(node<<1)+1;
    int mid=(b+e)/2;
    int p1=query(Left,b,mid,i,j);
    int p2=query(Right,mid+1,e,i,j);
    return p1+p2;                                            // বাম এবং ডান পাশের যোগফল
}
int main()
{
    int T;
   scanf("%d",&T);
   for(int t=1;t<=T;t++){
   int n,q;
   scanf("%d %d",&n,&q);
   for(int i=1;i<=n;i++){
    scanf("%d",&arr[i]);
   }
   int l,r,visited[MAX],result[MAX];
   memset(visited,0,sizeof(visited));
   vector<pair<int,pair<int,int> > >v;
   for(int i=1;i<=q;i++){
    scanf("%d %d",&l,&r);
    v.push_back(make_pair(r,make_pair(l,i)));
   }
   sort(v.begin(),v.end());
   int idx=0;
   for(int i=1;i<=n;i++){
    if(visited[arr[i]]){
        update(1,1,n,visited[arr[i]],0);
    }
    visited[arr[i]]=i;
    update(1,1,n,i,1);
    while(true){
        if(v[idx].first!=i) break;
        result[v[idx].second.second] = query(1,1,n,v[idx].second.first,v[idx].first);
        ++idx;
        }
    }
    printf("Case %d:\n",t);
    for(int i=1;i<=q;i++){
        printf("%d\n",result[i]);
    }
   }
}
