#include <bits/stdc++.h>
#define pii pair<int,int>
#define maxx 100005
using namespace std;
int arr[maxx];
struct info{
    int mx,mn;
};
info tree[maxx*4];
void build(int node,int a,int b)
{
    if(a==b){
        tree[node].mx=arr[a];
        tree[node].mn=arr[a];
        return;
    }
    int Left = node << 1;
    int Right = (node << 1) + 1;
    int mid = (a + b) >> 1;
    build(Left, a, mid);
    build(Right, mid + 1, b);
    tree[node].mx=max(tree[Left].mx,tree[Right].mx);
    tree[node].mn=min(tree[Left].mn,tree[Right].mn);
}
pair<int,int> query(int node,int a,int b,int i,int j)
{
    if(i>b or j<a) return pii(-1,-1);
    if(a>=i and b<=j){
        return pii(tree[node].mn,tree[node].mx);
    }
    int Left = node << 1;
    int Right = (node << 1) + 1;
    int mid = (a + b) >> 1;
    pii q1=query(Left,a,mid,i,j);
    pii q2=query(Right,mid+1,b,i,j);
    if(q1.first==-1&&q1.second==-1) return q2;
    else if(q2.first==-1&&q2.second==-1) return q1;
    else{
        int l=min(q1.first,q2.first);
        int r=max(q1.second,q2.second);
        return pii(l,r);
    }
}
int main()
{
    int T,n,d;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        scanf("%d %d",&n,&d);
        for(int i=1;i<=n;i++){
            scanf("%d",&arr[i]);
        }
        build(1,1,n);
        int diff=0;
        for(int i=1;i<=n-d;i++){
            pii min_max=(diff,query(1,1,n,i,i+d-1));
            diff=max(diff,(min_max.second-min_max.first));
        }
        printf("Case %d: %d\n",t,diff);
    }
    return 0;
}
