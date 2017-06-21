/// Idea :
/// You have to think about the amount of distinct numbers you have
/// (at most: 2*50000 for the ranges, plus 50000 for the query points).
/// For example, if I give you these ranges: [1,60000000],[40000000,90000000]
/// and these query points: 1000000,50000000,100000000
/// then you can reduce the problem (without changing the final answer) to a smaller problem.
/// In this case, the ranges
/// become: [1,5],[3,6], and the query points become: 2,4,7. For "both problems", the answers are 1,2,0.


#include <bits/stdc++.h>
#define mx 150005
#define pii pair<int,int>
using namespace std;
struct info{
    int prop,sum;
};
info tree[mx*4];
void build(int node,int a,int b)
{
    if(a==b){
        tree[node].prop=0;
        tree[node].sum=0;
        return;
    }
    int left=node<<1;
    int right=(node<<1)+1;
    int mid=(a+b)>>1;
    build(left,a,mid);
    build(right,mid+1,b);
    tree[node].sum=tree[node].prop=0;
}
void update(int node,int a,int b,int i,int j,int value)
{
    if(i>b or j<a) return;
    if(a>=i and b<=j){
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
    if(i>b or j<a) return 0;
    if(a>=i and b<=j){
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
    int T,n,Q,q,l,r;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        map<int,int>mp;
        vector<int>arr,Query;
        vector<pii>range;
        scanf("%d %d",&n,&Q);
        for(int i=1;i<=n;i++){
            scanf("%d %d",&l,&r);
            arr.push_back(l);
            arr.push_back(r);
            range.push_back(pii(l,r));
        }
        for(int i=1;i<=Q;i++){
            scanf("%d",&q);
            Query.push_back(q);
            arr.push_back(q);
        }
        sort(arr.begin(),arr.end());
        int curr=1;
        for(int i=0;i<(2*n)+Q;i++){
            if(mp.find(arr[i])==mp.end()) mp[arr[i]]=curr++;
        }
        --curr;
        build(1,1,curr);
        for(int i=0;i<n;i++){
            l=mp[range[i].first];
            r=mp[range[i].second];
            update(1,1,curr,l,r,1);
        }
        printf("Case %d:\n",t);
        for(int i=0;i<Q;i++){
            q=mp[Query[i]];
            printf("%d\n",query(1,1,curr,q,q));
        }
    }
}
