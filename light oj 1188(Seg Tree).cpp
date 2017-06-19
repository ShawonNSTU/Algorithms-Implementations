#include<bits/stdc++.h>

using namespace std;
int num,qry;
int ans[50002];
int tree[3*100001];
int a[100002];
struct info{
    int l,r,ind;
    bool operator < (const info & p)const
    {
        if(r!=p.r)return r < p.r;
        return l < p.l;
    }
}Q[50002];
void update(int node,int l,int r,int i,int val){

    if(l==i && r==i){
        tree[node]=val;
        return;
    }
    int mid=(l+r)/2;
    if(l<=i && mid >=i)update(node*2,l,mid,i,val);
    else update(node*2 +1,mid+1,r,i,val);
    tree[node]=tree[2*node]+tree[2*node +1];
}
int query(int node,int l,int r,int i,int j){

    if(i<=l && r<=j)return tree[node];
    int mid=(l+r)/2;
    int p=0,q=0;
    if(l <=j && mid>=i)p=query(node*2,l,mid,i,j);
    if(mid+1 <=j && r>=i)q=query(node*2 +1,mid+1,r,i,j);
    return p+q;
}
int main(void)
{
    int T,N=0;
    scanf("%d",&T);
    while(++N<=T){
        scanf("%d%d",&num,&qry);
        for(int i=0;i<num;i++)scanf("%d",&a[i]);
        int last[100002];
        memset(last,0,sizeof(last));
        for(int i=0;i<qry;i++){
            scanf("%d%d",&Q[i].l,&Q[i].r);
            Q[i].ind=i;
        }
        sort(Q,Q+qry);
        int k=0;
        for(int i=1;i<=num;i++){
            //printf("%d\n",i);
            if(last[a[i-1]]){
                update(1,1,num,last[a[i-1]],0);
            }
            last[a[i-1]]=i;
            update(1,1,num,i,1);
            while(Q[k].r==i){
                int res=query(1,1,num,Q[k].l,Q[k].r);
                ans[Q[k].ind]=res;
                k++;
            }
        }
        printf("Case %d:\n",N);
        for(int i=0;i<qry;i++)printf("%d\n",ans[i]);
    }
    return 0;
}
