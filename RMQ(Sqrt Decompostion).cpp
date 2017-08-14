#include <bits/stdc++.h>
#define MAXN 100005
#define SQRSIZE 500
#define INF 1000000000
using namespace std;
int arr[MAXN];
int blk_sz;
struct info{
    int mn;
};
info block[SQRSIZE];
int query(int l,int r)
{
    int min_val = INF;
    while(l < r and l % blk_sz != 0 and l != 0){
        min_val = min(min_val,arr[l]);
        l++;
    }
    while(l + blk_sz <= r){
        min_val = min(min_val,block[l/blk_sz].mn);
        l += blk_sz;
    }
    while(l <= r){
        min_val = min(min_val,arr[l]);
        l++;
    }
    return min_val;
}
void preprocess(int input[],int n)
{
    for(int i=0; i<SQRSIZE; i++){
        block[i].mn = INF;
    }
    int blk_idx = -1;
    blk_sz = sqrt(n);
    for(int i=0; i<n; i++){
        arr[i] = input[i];
        if(i % blk_sz == 0){
            blk_idx++;
        }
        block[blk_idx].mn = min(block[blk_idx].mn,arr[i]);
    }
    return ;
}
int main()
{
    int n;
    scanf("%d",&n);
    int input[n];
    for(int i=0; i<n; i++){
        scanf("%d",&input[i]);
    }
    preprocess(input,n);
    int l,r,q;
    scanf("%d",&q);
    for(int i=0; i<q; i++){
        scanf("%d %d",&l,&r);
        printf("%d\n",query(l,r));
    }
    return 0;
}
