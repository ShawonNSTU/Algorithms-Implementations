#include <bits/stdc++.h>
#define maxx 200005
using namespace std;
int cnt=0,arr[maxx],dp[maxx];
struct info{
    int prop,sum,mx,mn;
};
info tree[maxx*4];
void build(int node,int a,int b)
{
    if(a==b){
        tree[node].prop=tree[node].sum=0;
        tree[node].mn=tree[node].mx = ++cnt;
        return;
    }
    int left=node<<1;
    int right=(node<<1)+1;
    int mid=(a+b)>>1;
    build(left,a,mid);
    build(right,mid+1,b);
    tree[node].prop=tree[node].sum=0;
    tree[node].mx=max(tree[left].mx,tree[right].mx);
    tree[node].mn=min(tree[left].mn,tree[right].mn);
}
void update(int node,int a,int b,int i,int j,int value)
{
    if(tree[node].mn>j or tree[node].mx<i) return;
    if(tree[node].mn>=i and tree[node].mx<=j){
        tree[node].sum+=((b-a+1)*value);
        tree[node].prop+=value;
        return;
    }
    int left=node<<1;
    int right=(node<<1)+1;
    int mid=(a+b)>>1;
    update(left,a,mid,i,j,value);
    update(right,mid+1,b,i,j,value);
    tree[node].sum=tree[left].sum+tree[right].sum+(b-a+1)*tree[node].prop;
}
int query(int node,int a,int b,int i,int j,int carry=0)
{
    if(tree[node].mn>j or tree[node].mx<i) return 0;
    if(tree[node].mn>=i and tree[node].mx<=j){
        return tree[node].sum+carry*(b-a+1);
    }
    int left=node<<1;
    int right=(node<<1)+1;
    int mid=(a+b)>>1;
    int q1=query(left,a,mid,i,j,carry+tree[node].prop);
    int q2=query(right,mid+1,b,i,j,carry+tree[node].prop);
    return q1+q2;
}
int main()
{
    ios_base::sync_with_stdio(true);

    int n,k,q,l,r;
    build(1,1,200000);
    scanf("%d %d %d",&n,&k,&q);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&l,&r);
        update(1,1,200000,l,r,1);
    }
    for(int i=1;i<=200000;i++){
        dp[i]=query(1,1,200000,i,i);
        if(dp[i]<k) dp[i]=dp[i-1];
        else dp[i]=dp[i-1]+1;
    }
    for(int i=1;i<=q;i++){
        scanf("%d %d",&l,&r);
        int ans=dp[r]-dp[l];
        if(dp[l]>dp[l-1]) ++ans;
        printf("%d\n",ans);
    }
    return 0;
}
