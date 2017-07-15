#include <bits/stdc++.h>
using namespace std;
int arr[30005];
int tree[30005*4];
int visited[1000005],result[200005];
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
   int n,q;
   scanf("%d",&n);
   for(int i=1;i<=n;i++){
    scanf("%d",&arr[i]);
   }
   scanf("%d",&q);
   int l,r;
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
    for(int i=1;i<=q;i++){
        printf("%d\n",result[i]);
    }
    return 0;
}
