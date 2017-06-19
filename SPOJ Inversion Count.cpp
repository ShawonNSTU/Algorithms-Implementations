#include <bits/stdc++.h>
#define mx 200005
using namespace std;
int arr[mx];
struct info{
    vector<int>v;
    int lo,hi;
    long long cnt;
};
info tree[mx*4];
void build(int node,int a,int b)
{
    if(a==b){
        tree[node].v.push_back(arr[a]);
        tree[node].lo=tree[node].hi=a;
        tree[node].cnt=0;
        return;
    }
    int left=node<<1;
    int right=(node<<1)+1;
    int mid=(a+b)>>1;
    build(left,a,mid);
    build(right,mid+1,b);
    int l=(tree[left].hi-tree[left].lo)+1;
    int r=(tree[right].hi-tree[right].lo)+1;
    tree[node].lo=tree[left].lo;
    tree[node].hi=tree[right].hi;
    tree[node].cnt=tree[left].cnt+tree[right].cnt;
    int i,j;
    for(i=0,j=0;i<l&&j<r;){
        if(tree[left].v[i]<tree[right].v[j]){
            tree[node].v.push_back(tree[left].v[i]);
            ++i;
        }
        else{
            tree[node].v.push_back(tree[right].v[j]);
            ++j;
            tree[node].cnt+=( (long long) l - (long long) i );
        }
    }
    while(i<l){
        tree[node].v.push_back(tree[left].v[i]);
        ++i;
    }
    while(j<r){
        tree[node].v.push_back(tree[right].v[j]);
        ++j;
    }
}
void Clear(int n)
{
    for(int i=1;i<=n*4;i++) tree[i].v.clear();
}
int main()
{
    int T;
    scanf("%d",&T);
    getchar();
    while(T--){
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%d",arr+i);
        getchar();
        getchar();
        build(1,0,n-1);
        printf("%lld\n",tree[1].cnt);
        Clear(n);
    }
    return 0;
}
