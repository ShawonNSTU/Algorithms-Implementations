#include <bits/stdc++.h>
#define INF -100001
#define MAX 100005
using namespace std;
int arr[MAX];
struct info{
    int lo,hi,loValue,hiValue,maxValue;
};
info tree[MAX*4];
map<int,int>curr,mp;
void build(int node,int a,int b)
{
    if(a==b){
        tree[node].lo=tree[node].hi=arr[a];
        tree[node].loValue=tree[node].hiValue=curr[arr[a]]=1;
        tree[node].maxValue=1;
        return;
    }
    int left=node<<1;
    int right=(node<<1)+1;
    int mid=(a+b)>>1;
    build(left,a,mid);
    build(right,mid+1,b);
    int Max=max(tree[left].maxValue,tree[right].maxValue);
    curr[tree[left].lo]=curr[tree[right].hi]=curr[arr[mid+1]]=0;
    if(tree[left].hi==tree[right].lo){
        curr[arr[mid+1]]=tree[left].hiValue+tree[right].loValue;
    }
    Max=max(Max,curr[arr[mid+1]]);
    tree[node].lo=tree[left].lo;
    tree[node].hi=tree[right].hi;
    tree[node].loValue=max(curr[tree[node].lo],tree[left].loValue);
    tree[node].hiValue=max(curr[tree[node].hi],tree[right].hiValue);
    tree[node].maxValue=Max;
}
struct info query(int node,int a,int b,int i,int j)
{
    if(i>b or j<a){
        struct info infor;
        infor.lo=INF;
        infor.hi=infor.loValue=infor.hiValue=infor.maxValue=0;
        return infor;
    }
    if(a>=i and b<=j){
        struct info infor;
        infor.lo=tree[node].lo;
        infor.hi=tree[node].hi;
        infor.loValue=tree[node].loValue;
        infor.hiValue=tree[node].hiValue;
        infor.maxValue=tree[node].maxValue;
        return infor;
    }
    int left=node<<1;
    int right=(node<<1)+1;
    int mid=(a+b)>>1;
    struct info q1=query(left,a,mid,i,j);
    struct info q2=query(right,mid+1,b,i,j);
    if(q1.lo==INF) return q2;
    else if(q2.lo==INF) return q1;
    else{
        int mx;
        mp[q1.lo]=mp[q2.hi]=mp[arr[mid+1]]=0;
        if(q1.hi==q2.lo){
            mp[arr[mid+1]]=q1.hiValue+q2.loValue;
        }
        struct info infor;
        infor.lo=q1.lo;
        infor.hi=q2.hi;
        infor.loValue=max(q1.loValue,mp[q1.lo]);
        infor.hiValue=max(q2.hiValue,mp[q2.hi]);
        mx=max(q1.maxValue,q2.maxValue);
        infor.maxValue=max(mx,max(infor.hiValue,max(infor.loValue,mp[arr[mid+1]])));
        return infor;
    }
}
int main()
{
    int n,m,l,r;
    while(scanf("%d",&n) && n!=0){
        scanf("%d",&m);
        for(int i=1;i<=n;i++){
            scanf("%d",&arr[i]);
        }
        build(1,1,n);
        for(int i=1;i<=m;i++){
            scanf("%d %d",&l,&r);
            struct info ans=query(1,1,n,l,r);
            printf("%d\n",ans.maxValue);
        }
    }
    return 0;
}
