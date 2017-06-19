#include <bits/stdc++.h>
#define mx 10005
using namespace std;
int arr[mx];
int N,Q;
struct info {
    vector<int>v;
} tree[mx * 4];
void build(int node,int a,int b)
{
    if(a == b){
        tree[node].v.push_back(arr[a]);
        return;
    }
    int Left = node << 1;
    int Right = (node << 1) + 1;
    int mid = (a + b) >> 1;
    build(Left, a, mid);
    build(Right, mid+1, b);
    merge(tree[Left].v.begin(),tree[Left].v.end(),
          tree[Right].v.begin(),tree[Right].v.end(),
          back_inserter(tree[node].v));
}
int query(int node,int a,int b,int i,int j,int k)
{
    if(i>b||j<a) return 0;
    if(a>=i&&b<=j)
        return lower_bound(tree[node].v.begin(),tree[node].v.end(),k)-tree[node].v.begin();
    int Left=node<<1;
    int Right=(node<<1)+1;
    int mid=(a+b)>>1;
    int q1=query(Left,a,mid,i,j,k);
    int q2=query(Right,mid+1,b,i,j,k);
    return q1+q2;
}
int main()
{
    int l,r,x;
    cin>>N>>Q;
    for(int i=1;i<=N;i++) scanf("%d",&arr[i]);
    build(1,1,N);
    for(int i=1;i<=Q;i++){
        scanf("%d %d %d",&l,&r,&x);
        int ans=query(1,1,N,l,r,arr[x]);
        int left=l-1;
        ans+=left;
        if(arr[ans+1]==arr[x]) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
