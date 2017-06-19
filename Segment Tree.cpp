#include <bits/stdc++.h>
using namespace std;
#define MAX 100005
int arr[MAX];
int tree[MAX*4];
void build(int node,int b,int e)
{
    if (b==e){
        tree[node]=arr[b];
        return;
    }
    int Left=node<<1;
    int Right=(node<<1)+1;
    int mid=(b+e)/2;
    build(Left,b,mid);
    build(Right,mid+1,e);
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
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
    build(1,1,n);
    update(1,1,n,2,0);
    cout<<query(1,1,n,1,3)<<endl;
    update(1,1,n,2,2);
    cout<<query(1,1,n,2,2)<<endl;
    return 0;
}
