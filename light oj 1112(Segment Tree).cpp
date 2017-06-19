#include <bits/stdc++.h>
#define LL long long
#define mx 100005
using namespace std;

LL sack[mx];
LL n,Q,p,q,mx_node,ans;

struct info {
    LL money;
} tree[mx * 3];

void Clear()
{
    for(LL i=1;i<=mx_node;i++)
        tree[i].money=0;
}

void build(LL node, LL a, LL b)
{
    if (a == b){
        tree[node].money = sack[a];
        mx_node=max(mx_node,node);
        return;
    }
    LL Left = node << 1;
    LL Right = (node << 1) + 1;
    LL mid = (a + b) >> 1;
    build(Left, a, mid);
    build(Right, mid + 1, b);
    tree[node].money = tree[Left].money + tree[Right].money;
}

LL update2(LL node, LL a, LL b, LL i)
{
    if (i > b || i < a)
        return 0;
    if (a == i and b==i){
        ans=tree[node].money;
        tree[node].money=0;
        return ans;
    }
    LL Left = node << 1;
    LL Right = (node << 1) + 1;
    LL mid = (a + b) >> 1;
    update2(Left, a, mid, i);
    update2(Right, mid + 1, b, i);
    tree[node].money = tree[Left].money + tree[Right].money;

    return ans;
}

void update1(LL node, LL a, LL b, LL i, LL value)
{
    if (i > b || i < a)
        return;
    if (a == i and b==i){
        tree[node].money+=value;
        return;
    }
    LL Left = node << 1;
    LL Right = (node << 1) + 1;
    LL mid = (a + b) >> 1;
    update1(Left, a, mid, i, value);
    update1(Right, mid + 1, b, i, value);
    tree[node].money = tree[Left].money + tree[Right].money;
}

LL query(LL node, LL a, LL b, LL i, LL j)
{
    if (i > b || j < a)
        return 0;

    if (a >= i and b <= j)
        return tree[node].money;

    LL Left = node << 1;
    LL Right = (node << 1) + 1;
    LL mid = (a + b) >> 1;
    LL q1 = query(Left, a, mid, i, j);
    LL q2 = query(Right, mid + 1, b, i, j);

    return q1 + q2;
}

int main()
{
   int t,type;
   scanf("%d",&t);
   for(int tt=1;tt<=t;tt++){
    printf("Case %d:\n",tt);
    scanf("%lld %lld",&n,&Q);
    for(int i=0;i<n;i++) scanf("%lld",&sack[i]);
    build(1,0,n-1);
    for(int i=1;i<=Q;i++){
        scanf("%d",&type);
        if(type==1){
            scanf("%lld",&p);
            printf("%lld\n",update2(1,0,n-1,p));
        }
        else if(type==2){
            scanf("%lld %lld",&p,&q);
            update1(1,0,n-1,p,q);
        }
        else{
            scanf("%lld %lld",&p,&q);
            printf("%lld\n",query(1,0,n-1,p,q));
        }
    }
    Clear();
   }
   return 0;
}
