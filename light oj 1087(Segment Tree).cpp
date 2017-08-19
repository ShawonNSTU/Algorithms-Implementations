#include <bits/stdc++.h>
#define MAX 150005
int n,p,arr[MAX];
struct info{
    int pick;
};
info tree[MAX * 4];
using namespace std;
void build(int node,int b,int e)
{
    if (b == e){
        if(b <= n) tree[node].pick = 1;
        else tree[node].pick = 0;
        return;
    }
    int Left = node << 1;
    int Right = (node << 1) + 1;
    int mid = (b + e) >> 1;
    build(Left,b,mid);
    build(Right,mid+1,e);
    tree[node].pick = tree[Left].pick + tree[Right].pick;
}
void update(int node,int b,int e,int i)
{
    if(i > e || i < b) return;
    if(b == e){
        tree[node].pick = 1;
        return;
    }
    int Left = node << 1;
    int Right = (node << 1) + 1;
    int mid = (b + e) >> 1;
    update(Left,b,mid,i);
    update(Right,mid+1,e,i);
    tree[node].pick = tree[Left].pick + tree[Right].pick;
}
int query(int node,int b,int e,int i)
{
    int Left = node << 1;
    int Right = (node << 1) + 1;
    int mid = (b + e) >> 1;
    if(tree[Left].pick >= i){
        if(b == mid){
            tree[Left].pick = 0;
            p = arr[b];
        }
        else p = query(Left,b,mid,i);
    }
    else{
        if(mid+1 == e){
            tree[Right].pick = 0;
            p = arr[e];
        }
        else p = query(Right,mid+1,e,i-tree[Left].pick);
    }
    tree[node].pick = tree[Left].pick + tree[Right].pick;
    return p;
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int t=1; t<=T; t++){
        int q;
        scanf("%d %d",&n,&q);
        for(int i=1; i<=n; i++){
            scanf("%d",&arr[i]);
        }
        build(1,1,MAX);
        printf("Case %d:\n",t);
        char ch;
        int idx;
        for(int i=1; i<=q; i++){
            scanf(" %c %d",&ch,&idx);
            if(ch == 'a'){
                ++n;
                arr[n] = idx;
                update(1,1,MAX,n);
            }
            else{
                if(tree[1].pick < idx) printf("none\n");
                else printf("%d\n",query(1,1,MAX,idx));
            }
        }
    }
}
